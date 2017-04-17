#ifndef SPI_HPP
#define SPI_HPP

#include <wiringPiSPI.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "FFT.hpp"


using namespace std;

class SPI{
private:
	int channel;
public:
	SPI(int channel, int speed);
	void read_ADC(double* output,int size);
	void read_ADC(Complex* output,int size);
};


#endif
