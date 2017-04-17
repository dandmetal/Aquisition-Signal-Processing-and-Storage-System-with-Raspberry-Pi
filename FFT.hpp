#include <complex>
#include <iostream>
#include <valarray>

#ifndef FFT_HPP
#define FFT_HPP
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void FFT_exec(Complex *x, int size);
void fft(Complex *x,int arrSize);
void ifft(Complex *x, int size);
#endif
