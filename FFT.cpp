#include "FFT.hpp"

using namespace std;



void FFT_exec(Complex *x, int size)
{
	// DFT
	unsigned int N = size, k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	Complex phiT = Complex(cos(thetaT), sin(thetaT)), T;
	while (k > 1)
	{
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++)
		{
			//#pragma omp parallel for
			for (unsigned int a = l; a < N; a += n)
			{
				unsigned int b = a + k;
				Complex t = x[a] - x[b];
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	// Decimate
	unsigned int m = (unsigned int)log2(N);
	//#pragma omp parallel for
	for (unsigned int a = 0; a < N; a++)
	{
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		//#pragma omp critical
		if (b > a)
		{
			Complex t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
		x[a]=conj(x[a]);
	}

}

void fft(Complex *x,int arrSize)
{
	if(arrSize >0 && !(arrSize &(arrSize -1))){
		FFT_exec(x,arrSize);
	}else{
		cout << "O numero de elementos precisa ser potencia de 2"<<endl;
	}
}

void ifft(Complex *x, int size){
	const Complex isize=size;
	fft(x,size);
	for (int i=0; i < size; i++){
			x[i]=conj(x[i]);
		}
	for (int i=0; i < size; i++){
			x[i]=x[i]/isize;
		}
}



