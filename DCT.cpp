#include "DCT.hpp"

//Em desuso, utilizar a FCT

void dct(int N,double in[],double out[]){
	int k,n;
	#pragma omp parallel for private (n,k)
	for (k=0;k < N;++k){
		double sum=0;
		double s=(k == 0) ? sqrt(.5) : 1.;
		#pragma omp parallel for reduction(+:sum)
		for (n = 0; n < N; ++n) {
			sum += s * in[n] * cos(M_PI * (n + .5) * k / N);
		}
		out[k] = sum * sqrt(2. / N);
	}
}

void idct(int N,double in[],double out[]){
	int k,n;
	#pragma omp parallel for private (n,k)
	for (n = 0; n < N; ++n) {
		double sum = 0.;
		#pragma omp parallel for reduction(+:sum)
		for (k = 0; k < N; ++k) {
			double s = (k == 0) ? sqrt(.5) : 1.;
			sum += s * in[k] * cos(M_PI * (n + .5) * k / N);
			}
		out[n] = sum * sqrt(2. / N);
	}
}


