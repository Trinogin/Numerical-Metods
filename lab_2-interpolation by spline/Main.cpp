#pragma warning(disable:4996)

#include <math.h>
#include <cstdio>
#include <vld.h>
#include"interface.h"
#include"impl.h"

int main(void) 
{
	double* x;
	double* y;
	double* h;
	double* l;
	double* delta;
	double* lambda;
	double* b;
	double* c;
	double* d;
	double* my_grid;

	int error = 0;

	int k;
	int n;
	FILE* in;
	FILE* out;
	//-----------------------------------------------------------------------------
	in = fopen("MatlabFiles\\grid.txt", "r");
	if (in == NULL)
	{
		fprintf(stderr, "Error no file for reading \n");
		return -1;
	}

	out = fopen("MatlabFiles\\result.txt", "w");
	//-----------------------------------------------------------------------------
	fscanf(in, "%i", &n);
	
	my_grid = new double[n + 1];

	error = memalloc(n, x, y, h, l, delta, lambda, b, c, d);
	if (error != 0)
	{
		fprintf(stderr, "Error: not enough memory for computing \n");
		memfree(x, y, h, l, delta, lambda, b, c, d);
		return -1;
	}

	ReadVector(in, n, x);
	ReadVector(in, n, y);

	error  = computing(n, x, y, h, l, delta, lambda, b, c, d);
	if (error != 0)
	{
		fprintf(stderr,
			"Error: in computing, thesame elements in x array x[%i] == x[%i]",
			error, error + 1);
		memfree(x, y, h, l, delta, lambda, b, c, d);
		return -1;
	}

	//--------------------------------------
	//TODO: researching the spline method
	int k;
	double s;
	double start = x[0];
	double end = x[N - 1];
	double step = (end - start) / NUM_M_GRID;
	FILE* OutFile = fopen("MatlabFiles\\result.txt", "w");

	s = start;
	while (s <= end)
	{
		fprintf(OutFile, "%lf ", s);
		s += step;
	}
	fprintf(OutFile, "\n");

	for (s = start; s <= end; s += step)
	{
		//find k, where s in [x_k-1; x_k]
		for (k = 1; k <= N; k++)
		{
			if (s >= x[k - 1] && s <= x[k])
				break;
		}

		double F = y[k] + b[k] * (s - x[k]) + c[k] * pow(s - x[k], 2) + d[k] * pow(s - x[k], 3);
		fprintf(OutFile, "%lf ", F);
	}
	fclose(OutFile);

	delete[] my_grid;
	memfree(x, y, h, l, delta, lambda, b, c, d);
	fclose(in);
	fclose(out);
	return 0;
}