#include "Aux.hpp"


using namespace std;


void print_vector(double *vec, int size)
{
	ofstream file("file.bin",ios::app);
	if (file.is_open()){
		for (int i=0;i<size;i++){
			cout << vec[i] <<endl;
			file << vec[i] << endl;
		}
	}
	file.close();
}

void print_vector(Complex *data,int size){
	ofstream file("file.bin",ios::app);
	if (file.is_open()){
		for (int i=0;i<size;i++){
			if(imag(data[i])>=0){
				cout << real(data[i])<<"+"<<imag(data[i]) << "i" <<endl;
			}else{
				cout << real(data[i])<<imag(data[i]) << "i" <<endl;
			}
			
			file << data[i] << endl;
		}
	}
	file.close();
}



