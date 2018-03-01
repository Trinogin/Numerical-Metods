#include"Interface.h"

// Reading and printing is from 1 to n element. Without 0 in start. 
void ReadVector(FILE* stream, int n, double* vector)
{
	int i;

	for (i = 1; i <= n; i++)
		fscanf(stream, "%lf", &vector[i]);
}

void PrintVector(FILE* stream, int n, double* vector)
{
	int i;

	for (i = 1; i <= n; i++)
		fprintf(stream, "%.2lf ", vector[i]);
	fprintf(stream, "\n");
}
