#ifndef AUX_HPP
#define AUX_HPP

#include <iostream>
#include <valarray>
#include <complex>
#include <fstream>

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void print_vector(double *vec, int size);
void print_vector(Complex *data,int size);
double get_GPIO();



#endif
