/*
 * UART.cpp
 *
 *  Created on: 01.11.2016
 *  Author: Lukas Wendt, Dennis Kirsch, Cyrille Ngassam Nkwenga
 */

#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <fstream>
#include <stdexcept>

#include "UART.h"

using namespace std;

UART::UART(UARTInterface u) : uart_interface(u), uart_fd(0), is_initialized(false){
}

UART::~UART() {
	close(uart_fd);
}

void UART::initialize(){
	if (!is_initialized){

		/* activate UART ports */
		std::fstream fileStream;
		fileStream.open("/sys/devices/bone_capemgr.9/slots", std::fstream::out);
		fileStream << ("BB-UART" + to_string(uart_interface));
		fileStream.flush();
		fileStream.close();

		uart_fd = open(("/dev/ttyO" + to_string(uart_interface)).c_str(), O_RDWR | O_NOCTTY);

		if (uart_fd >= 0){
			struct termios newtio;

			/* get attribute  termios struct for file descriptor */
			tcgetattr(uart_fd, &newtio);

			/* control modes:
			 	 - CS8: use UART with 8 bit data
			 	 - CLOCAL: ignore modem control lines
			 	 - CREAD: enable receiver */
			newtio.c_cflag |=  CS8 | CLOCAL | CREAD ;

			/* input modes:
			 	- IGNBRK: ignore break
 	 	 	 	- IGNPAR: ignore parity check */
			newtio.c_iflag = IGNBRK | IGNPAR;

			/* output modes: none */
			newtio.c_oflag = 0;

			/* local modes: none */
			newtio.c_lflag = 0;

			/* UNUSED: time after which 'read' function unblocks
			   since it is unused, 'read' will now return after VMIN bytes are read  */
			newtio.c_cc[VTIME] = 0;

			/* minimum amount of bytes to be read until 'read' function unblocks */
			newtio.c_cc[VMIN] = 1;

			/* save attributes for file descriptor and write back */
			tcflush(uart_fd, TCIFLUSH);
			tcsetattr(uart_fd, TCSANOW, &newtio);

			is_initialized = true;
		}
	}
}

void UART::send(char data){
	if (is_initialized){
		write(uart_fd, &data, 1);
	}
}

void UART::send(char* data, int len){
	if (is_initialized && len > 0){

		for(int i = 0; i < len; i++){
			this->send(data[i]);
		}
	}
}

char UART::recv(){
	if (uart_interface == UART3){
		throw invalid_argument( "UART3 is send only and doesn't support reading" );
	}

	char data = -1;

	if (is_initialized){
		read(uart_fd, &data, 1);
	}
	return data;
}

void UART::recv(char* ret_data, int len){
	if (uart_interface == UART3){
		throw invalid_argument( "UART3 is send only and doesn't support reading" );
	}

	if (is_initialized){

		for(int i = 0; i < len; i++){
			ret_data[i] = this->recv();
		}
	}
}
