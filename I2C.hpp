#ifndef I2C_HPP
#define I2C_HPP

#include <wiringPiI2C.h>
#include <iostream>
#include <stdlib.h>
#include "FFT.hpp"


using namespace std;

class I2C{
private:
	int fd;
public:
	I2C(int devId);
	void read_ADC(double* output,int size);
	void read_ADC(Complex* output,int size);
};


#endif