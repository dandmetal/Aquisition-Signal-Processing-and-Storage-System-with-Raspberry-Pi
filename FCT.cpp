#include "FCT.hpp"


auto fastsin(double x) {
	return - sqrt(1 - x*x);
	}


void fillArray(Complex *in, Complex *out,int size){
	const int size2= size*2;
	for (int i=0; i < size2 ; i++){
		if ( i < size)
			out[i]=in[i];
		else
			out[i]=0;
	}
}

void inverFill(Complex *in,Complex *out,int size){
	Complex shift;
	const auto cmp=1i;
	const int size2=size*2;
	double calc,trig;
	for (int i=0;i <size2;i++){
		if (i==0)
			out[i]=in[0];
		else if(i<size){
			calc= (PI * i / (size2));
			trig=cos(calc);
			shift= trig - cmp*fastsin(trig);
			out[i]=in[i]*shift;
		}else if (i==size)
			out[i]=0;
		else{
			//calc= (PI * i / (size2));
			//trig=cos(calc);
			//shift= trig - cmp*fastsin(trig);
			//out[i]=-in[size2 - i]*shift;
			out[i]=conj(out[size2-i]);
		}
	}
	cout << "Termos do IFCT"  << endl;
	for (int i=0;i<size2;i++)
		cout << out[i] << endl;
}

void fct(Complex *in,double *out,int size){
	Complex shift;
	const int size2= size*2;
	const Complex two=2;
	const auto cmp=1i;
	double s,norm,calc,trig;
	Complex temp[size2];
	fillArray(in,temp,size);
	fft(temp,size2);
	for (int j=0; j < size ; j++){
		s = (j == 0) ? sqrt(.5) : 1.;
		norm=s * 0.5 * sqrt(2./size);
		calc= (- PI * j / (2 * size));
		trig=cos(calc);
		shift=two * ( trig + cmp*fastsin(trig));
		out[j]=norm *real(temp[j] * shift); 
	}
}

void ifct(double *in,double *out,int size){
	const int size2=size*2;
	double s,norm;
	Complex temp[size],temp2[size2];
	for (int i=0;i < size;i++){
		s = (i == 0) ? sqrt(.5) : 1.;
		norm=s * 0.5 * sqrt(2./size);
		in[i]=in[i]/norm;
		temp[i]=in[i];
	}
	inverFill(temp,temp2,size);
	ifft(temp2,size2);
	for(int i=0;i<size;i++){
		out[i]=real(temp2[i]);
	}
}

