#ifndef FCT_HPP
#define FCT_HPP

#include "FFT.hpp"
#include <math.h>

using namespace std;

auto fastsin(double x);
void fillArray(Complex *in, Complex *out,int size);
void inverFill(Complex *in,Complex *out,int size);
void fct(Complex *in,double *out,int size);
void ifct(double *in,double *out,int size);

#endif