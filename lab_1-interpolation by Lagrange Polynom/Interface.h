#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLDUED

#pragma once

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

#define UNUSED_PARAMETER(name) (void)name

void ReadVector(FILE* stream, int n, double* vector);

void PrintVector(FILE* stream, int n, double* vector);

void MemFree(double* p_1, double* p_2, double* p_3, double* p_4, double* p_5, double* p_6);

void StreamInClose(FILE* s_1, FILE* s_2, FILE* s_3);

#endif // INTERFACE_H_INCLUDED