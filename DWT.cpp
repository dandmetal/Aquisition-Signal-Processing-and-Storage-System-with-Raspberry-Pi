#include "DWT.hpp"


void calc_dwt(int N, double *in,double *out){
	double const coef= 4*sqrt(2);
	double const h0=(1+sqrt(3))/coef;
	double const h1=(3+sqrt(3))/coef;
	double const h2=(3-sqrt(3))/coef;
	double const h3=(1-sqrt(3))/coef;
	double const g0=h3;
	double const g1=-h2;
	double const g2=h1;
	double const g3=-h0;

	int i,j;
	const int half= N >> 1;
	//#pragma omp parallel for
	for (i = 0,j = 0; j < N-3; j += 2, i++) {
		out[i]= in[j]*h0 + in[j+1]*h1 + in[j+2]*h2 + in[j+3]*h3;
		out[i+half]= in[j]*g0 + in[j+1]*g1 + in[j+2]*g2 + in[j+3]*g3;
	}

	out[i]= in[N-2]*h0 + in[N-1]*h1 + in[0]*h2 + in[1]*h3;
	out[i+half] = in[N-2]*g0 + in[N-1]*g1 + in[0]*g2 + in[1]*g3;

}

void dwt(int N, double *in,double *out){
	if (N >= 4)
		calc_dwt(N,in,out);
	else
		cout << "Numero de elementos muito pequeno" <<endl;
	
}


void idwt(int N,double *in,double *out){
	double const coef= 4*sqrt(2);
	double const h0=(1+sqrt(3))/coef;
	double const h1=(3+sqrt(3))/coef;
	double const h2=(3-sqrt(3))/coef;
	double const h3=(1-sqrt(3))/coef;
	
	double const ih0=h2;
	double const ih1=h1;
	double const ih2=h0;
	double const ih3=h3;

	double const ig0=h3;
	double const ig1=-h0;
	double const ig2=h1;
	double const ig3=-h2;

	int i,j;
	const int half= N >> 1;
	const int halfpone=half+1;

	out[0]= in[half - 1]*ih0 + in[N-1]*ih1 + in[0]*ih2 + in[half]*ih3;
	out[1] = in[half - 1]*ig0 + in[N-1]*ig1 + in[0]*ig2 + in[half]*ig3;

	for (i = 0,j = 2; j < half -1; i++) {
		out[j++]= in[i]*ih0 + in[i+half]*ih1 + in[i+1]*ih2 + in[i+halfpone]*ih3;
		out[j++] = in[i]*ig0 + in[i+half]*ig1 + in[i+1]*ig2 + in[i+halfpone]*ig3;
	}

}















