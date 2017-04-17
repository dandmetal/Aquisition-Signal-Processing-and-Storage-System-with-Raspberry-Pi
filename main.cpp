#include "FFT.hpp"
#include "DCT.hpp"
#include "DWT.hpp"
#include "FCT.hpp"
#include "SQLCon.hpp"
#include "Aux.hpp"
#include "I2C.hpp"
#include <chrono>


#define size 16

using namespace std;
using namespace std::chrono;

int main(){
	Complex test[size];
	I2C commu(0x08);
	commu.read_ADC(test,size);

	auto t1=high_resolution_clock::now();
	//dct(size,indct,outdct);
	//fct(infct,outfct,size);
	//dwt(size,indwt,outdwt);
	fft(test,size);
	auto t2=high_resolution_clock::now();
	auto timespam=duration_cast<microseconds>(t2 - t1);
	cout << "Tempo de execucao: " << timespam.count()  <<" microseconds" << endl;

	cout << "FFT" << endl;
	print_vector(test,size);

	cout << "FCT" << endl;
	//print_vector(outfct,size);

	//cout << "DCT"<<endl;
	//print_vector(outdct,size);

	cout << "DWT"<<endl;
	//print_vector(outdwt,size);

	cout << "SQL Results" << endl;
	SQLCon *c=new SQLCon("192.168.1.108:3306", "root", "root","test");
	c->create_table("RES","re","DOUBLE","imag","DOUBLE");
	c->sql_send_fft("RES","re","imag");


	delete c;
	return 0;
}
