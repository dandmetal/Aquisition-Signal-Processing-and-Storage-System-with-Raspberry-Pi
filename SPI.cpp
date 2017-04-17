#include "SPI.hpp"

SPI::SPI(int channel, int speed){
	int err=wiringPiSPISetup (channel, speed) ;
	if (err == -1){
		cout << "Nao foi possivel estabelecer uma conexao'" << endl;
		exit(0);
	}else{
		cout << "Conexao estabelecida" << endl;
	}
}


void SPI::read_ADC(double* output,int size){
	unsigned char data[] ="1234";
	for (int i=0;i < size; i++){
		wiringPiSPIDataRW (channel, data, 4) ;
		output[i]=atoi((char*)data);
	}
}

void SPI::read_ADC(Complex* output,int size){
	unsigned char data[] ="1234";
	for (int i=0;i < size; i++){
		wiringPiSPIDataRW (channel, data, 4) ;
		output[i]=atoi((char*)data);
	}
}
