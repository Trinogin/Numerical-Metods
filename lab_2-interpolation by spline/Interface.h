#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLDUED

#pragma once

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

#define UNUSED_PARAMETER(name) (void)name

void ReadVector(FILE* stream, int n, double* const vector);

void PrintVector(FILE* stream, int n, double const* const vector);

#endif // INTERFACE_H_INCLUDED