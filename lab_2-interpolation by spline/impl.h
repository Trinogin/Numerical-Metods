#ifndef IMPL_H_INCLUDED

#define IMPL_H_INCLUDED

#pragma once

// return 0 or number of the same elements (x[k] == x[k-1])
int computing(const int size, double* x, double* y, double*h, double* l, double* delta, double* lambda,
	double* c, double* b, double* d);

#endif // !IMPL_H_INCLUDED