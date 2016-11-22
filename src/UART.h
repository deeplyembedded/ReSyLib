/*
 * UART.h
 *
 *  Created on: 01.11.2016
 *  Author: Lukas Wendt, Dennis Kirsch, Cyrille Ngassam Nkwenga
 */

#ifndef UART_H_
#define UART_H_
#include <iostream>
enum UARTInterface : unsigned int {
	UART1 = 1,
	UART2 = 2,
	UART3 = 3, //UART3 only supports TX
	UART4 = 4,
	UART5 = 5
};

class UART {
public:
	UART(UARTInterface u);
	virtual ~UART();

	/**
	 * Has to be called before using send or recv.
	 * Always call it after creating an instance.
	 */
	void initialize();

	/**
	 * Send one character with UART interface.
	 * \param data Character which will be sent.
	 */
	void send(char data);

	/**
	 * Send exactly len character with UART interface.
	 * \param data Pointer to the character array which will be sent.
	 * \param len Length of character array.
	 */
	void send(char* data, int len);

	/**
	 * Blocking receive for one character with UART interface.
	 * \throws invalid_argument If function is called with UART3
	 * \return The character read.
	 */
	char recv();

	/**
	 * Blocking receive for len character with UART interface.
	 * The read data will be written in ret_data.
	 * \throws invalid_argument If function is called with UART3
	 */
	void recv(char* ret_data, int len);

private:
	UARTInterface uart_interface;
	int uart_fd;
	bool is_initialized;
};

#endif /* UART_H_ */
