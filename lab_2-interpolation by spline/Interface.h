#ifndef INTERFACE_H_INCLUDED

#pragma warning (disable:4996)

#pragma once

#define INTERFACE_H_INCLUDED

#include<cstdio>

// Reading and printing is from 1 to n element. Without 0 in start. 
void ReadVector(FILE* stream, int n, double* const vector);

// 16 symbols after point
void PrintVector(FILE* stream, int n, double const* const vector);

// 0 - succes , 1 - error
int memalloc(const int size, double* x, double* y, double*h, double* l, double* delta, double* lambda,
	double* c, double* b, double* d);

// check memory for null, the same for memalloc (?)
void memfree(double* x, double* y, double*h, double* l, double* delta, double* lambda,
	double* c, double* b, double* d);

#endif // !INTERFACE_H_INCLUDED