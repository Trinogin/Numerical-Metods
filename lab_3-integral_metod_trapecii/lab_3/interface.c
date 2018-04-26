#include"interface.h"

void ReadVector(FILE* stream, int n, double* const vector)
{
	int i;

	for (i = 1; i <= n; i++)
		fscanf(stream, "%lf", &vector[i]);
}

void PrintVector(FILE* stream, int n, double const* const vector)
{
	int i;

	for (i = 1; i <= n; i++)
		fprintf(stream, "%.16lf ", vector[i]);
	fprintf(stream, "\n");
}