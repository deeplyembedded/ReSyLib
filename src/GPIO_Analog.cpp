/*
 * GPIO_Analog.cpp
 *
 *  Created on: 08.12.2015
 *      Author: Oli, Viktor
 */

#include "GPIO_Analog.h"
#include <string.h>
#include <dirent.h>
#include <string>
#include <iostream>
#include <unistd.h>

namespace RSL {

using namespace std;
using namespace RSL;


bool GPIO_Analog::initialized = false;

GPIO_Analog::GPIO_Analog(AINPin pin) {
	this->pin = pin;
}

GPIO_Analog::~GPIO_Analog() {
	shutdown();
}

void GPIO_Analog::initialize() {
	if (not initialized) {
		std::fstream fileStream;
		initialized = true;
		fileStream.open((SLOT_FILE_PATH).c_str(), fstream::out | fstream::in);
		fileStream << "cape-bone-iio";
		fileStream.flush();
		fileStream.close();

		analog_path = findHelperPath(analog_path);

		usleep(1000);
	}

	valueFileStream.open(analog_path + "/AIN" + to_string((int) pin), fstream::in);
	if (valueFileStream.fail())
		cout << "Failed to open valueFileStream!" << endl;
}

void GPIO_Analog::shutdown() {
	valueFileStream.close();
}

unsigned int GPIO_Analog::getValue() {
	string val;
	valueFileStream.seekg(0);
	valueFileStream >> val;

	return std::stoi(val);
}

string GPIO_Analog::findHelperPath(string containingDir) {
	DIR* openedDir = opendir(containingDir.c_str());
	struct dirent* readDir;

	if (openedDir) {

		while ((readDir = readdir(openedDir)) != NULL) {
			if (strstr(readDir->d_name, "helper.") != NULL) {
				closedir(openedDir);
				return containingDir + readDir->d_name;
			}
		}

		closedir(openedDir);
	}

	return "";
}

}

