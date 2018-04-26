#ifndef INTERFACE_H_INCLUDED

#pragma warning (disable:4996)

#pragma once

#define INTERFACE_H_INCLUDED

#include<stdio.h>

// Reading and printing is from 1 to n element. Without 0 in start. 
void ReadVector(FILE* stream, int n, double* const vector);

// 16 symbols after point
void PrintVector(FILE* stream, int n, double const* const vector);

#endif //INTERFACE_H_INCLUDED