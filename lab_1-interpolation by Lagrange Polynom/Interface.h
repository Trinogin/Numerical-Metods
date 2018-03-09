#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLDUED

#pragma once

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

#define UNUSED_PARAMETER(name) (void)name

void ReadVector(FILE* stream, int n, double* vector);

void PrintVector(FILE* stream, int n, double* vector);

void MemFree(double* p_1, double* p_2, double* p_3, double* p_4, double* p_5, double* p_6,
	double* p_7, double* p_8, double* p_9, double* p_10);

void StreamInClose(FILE* s_1, FILE* s_2, FILE* s_3, FILE* s_4, FILE* s_5);

#endif // INTERFACE_H_INCLUDED