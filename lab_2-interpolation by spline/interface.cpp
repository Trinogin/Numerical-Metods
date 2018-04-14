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
		fprintf(stream, "%16.lf ", vector[i]);
	fprintf(stream, "\n");
}

int memalloc(const int size,  double* x, double* y, double*h, double* l, double* delta, double* lambda,
	double* c, double* b, double* d)
{
	x = new double[size + 1];
	y = new double[size + 1];
	h = new double[size + 1];
	l = new double[size + 1];
	delta = new double[size + 1];
	lambda = new double[size + 1];
	c = new double[size + 1];
	b = new double[size + 1];
	d = new double[size + 1];

	return 0;
}

void memfree(double* x, double* y, double*h, double* l, double* delta, double* lambda,
	double* c, double* b, double* d)
{
	delete[] x;
	delete[] y;
	delete[] h;
	delete[] l;
	delete[] delta;
	delete[] lambda;
	delete[] c;
	delete[] d;
	delete[] b;
}