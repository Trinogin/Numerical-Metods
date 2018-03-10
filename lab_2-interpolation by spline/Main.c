#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
#include"Interface.h"

int main(void)
{
	double* d = NULL;

	d = (double*)malloc(sizeof(double) * 6);


	ReadVector(stdin, 5, d);

	PrintVector(stdout, 5, d);
	free(d);
	return 0;
}