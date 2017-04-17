#include "I2C.hpp"

I2C::I2C(int devId){
	fd=wiringPiI2CSetup (devId);
	/*
	if (fd == -1 ){
		cout << "Erro ao conectar com o dispositivo" << endl;
		exit(0);
	}else
		cout << "Conexao estabelecida" << endl;
	*/
}

void I2C::read_ADC(double* output,int size){
	//printf("Os numeros recebidos foram:\n");
	for (int i=0;i < size;i++){
		int numer= wiringPiI2CRead (fd) ;
		int number=wiringPiI2CRead (fd) ;
		if (numer == -1 || number ==-1){
			printf("Ocorreu um erro na conexao\n");
			exit(0);
			}
		int recived=numer;
		recived=(recived << 8) | number;
		printf("O numero e:%d       %d          %d\n",numer,number,recived);
		output[i]=recived;
	}
}


void I2C::read_ADC(Complex* output,int size){
	//printf("Os numeros recebidos foram:\n");
	for (int i=0;i < size;i++){
		int numer= wiringPiI2CRead (fd) ;
		int number=wiringPiI2CRead (fd) ;
		if (numer == -1 || number ==-1){
			printf("Ocorreu um erro na conexao\n");
			exit(0);
			}
		int recived=numer;
		recived=(recived << 8) | number;
		printf("O numero e:%d       %d          %d\n",numer,number,recived);
		output[i]=recived;
	}
}
