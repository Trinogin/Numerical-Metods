#ifndef HEADER_LAGRANGE_INCLUDED
#define HEADER_LAGRANGE_INCLUDED

#pragma warning(disable:4996)

#define UNUSED_PARAMETER(name) (void)name

#include<math.h>

void ReadVector(FILE* stream, int n, double* vector);

void PrintVector(FILE* stream, int n, double* vector);

void InterpolLagrangePol(int n, double* x, double* y, double* p);

#endif //HEADER_LAGRANGE_INCLUDED