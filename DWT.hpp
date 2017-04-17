#ifndef DWT_HPP
#define DWT_HPP

#include <iostream>
#include <math.h>
using namespace std;

void calc_dwt(int N , double *in , double *out);
void dwt(int N, double *in,double *out);
void idwt(int N,double *in,double *out);

#endif

