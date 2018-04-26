#pragma warning(disable:4996)

#include <math.h>
#include <cstdio>
#include <vld.h>
#include"interface.h"
#include"impl.h"

int main(void) 
{
	double* x = nullptr;
	double* y = nullptr;
	double* h = nullptr;
	double* l = nullptr;
	double* delta = nullptr;
	double* lambda = nullptr;
	double* b = nullptr;
	double* c = nullptr;
	double* d = nullptr;
	double* my_grid = nullptr;


	//double s;
	double f;

	int error = 0;

	int k;
	int j;
	int i;

	int n;
	int size_m_grid;

	FILE* in;
	FILE* in_scnd;

	FILE* out;
	//-----------------------------------------------------------------------------
	in = fopen("MatlabFiles\\grid.txt", "r");
	if (in == NULL)
	{
		fprintf(stderr, "Error no file for reading \n");
		return -1;
	}

	in_scnd = fopen("MatlabFiles\\r_grid.txt", "r");
	if (in_scnd == NULL)
	{
		fprintf(stderr, "Error no file for reading \n");
		return -1;
	}

	out = fopen("MatlabFiles\\result.txt", "w");
	//-----------------------------------------------------------------------------
	fscanf(in, "%i", &n);
	

	x = new double[n + 1];//(double*)malloc(sizeof(double) * (size + 1));						 //
	y = (double*)calloc(n + 1, sizeof(double));

	h = (double*)calloc(n + 1, sizeof(double));
	l = (double*)calloc(n + 1, sizeof(double));
	delta = (double*)calloc(n + 1, sizeof(double));
	lambda = (double*)calloc(n + 1, sizeof(double));
	c = (double*)calloc(n + 1, sizeof(double));
	b = (double*)calloc(n + 1, sizeof(double));
	d = (double*)calloc(n + 1, sizeof(double));


	//my_grid = (double*)malloc(sizeof(double) * (size_m_grid + 1));

	//error = memalloc(n, x, y, h, l, delta, lambda, b, c, d);
	if (error != 0)
	{
		fprintf(stderr, "Error: not enough memory for computing \n");
		memfree(x, y, h, l, delta, lambda, b, c, d);
		return -1;
	}


	//--------------------------------------
	//TODO: researching the spline method
	//int k;

	fscanf(in_scnd, "%i", &size_m_grid);

	my_grid = new double[size_m_grid + 1];

	ReadVector(in_scnd, size_m_grid, my_grid);

	for (i = 4; i <= n; i++)
	{
		ReadVector(in, i - 1, x);
		ReadVector(in, i - 1, y);

		error = computing(i - 1, x, y, h, l, delta, lambda, b, c, d);
		if (error != 0)
		{
			fprintf(stderr,
				"Error: in computing, thesame elements in x array x[%i] == x[%i]",
				error, error + 1);
			memfree(x, y, h, l, delta, lambda, b, c, d);
			return -1;
		}

		double step = (my_grid[size_m_grid - 1] - my_grid[0]) / (size_m_grid);
		//for (k  = 1; k <= size_m_grid; k++)
		for (double s = my_grid[0]; s < my_grid[size_m_grid - 1]; s += step)
		{
			//s = my_grid[k];
			for (j = 1; j <= i; j++)
			{
				if (s >= x[j - 1] && s <= x[j])
					break;
			}

			f = y[j] + b[j] * (s - x[j]) + c[j] * pow(s - x[j], 2) + d[j] * pow(s - x[j], 3);
			fprintf(out, "%lf ", f);
		}
		fprintf(out, "\n");
	}



	//for (s = start; s <= end; s += step)
	//{
	//	//find k, where s in [x_k-1; x_k]
	//	for (k = 1; k <= N; k++)
	//	{
	//		if (s >= x[k - 1] && s <= x[k])
	//			break;
	//	}
	//}
	//fclose(OutFile);


	delete[] x;
	free(y);
	free(h);
	free(l);
	free(delta);
	free(lambda);
	free(c);
	free(d);
	free(b);

	delete[] my_grid;
	//memfree(x, y, h, l, delta, lambda, b, c, d);
	fclose(in);
	fclose(in_scnd);
	fclose(out);
	return 0;
}