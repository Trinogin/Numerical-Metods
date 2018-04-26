#pragma warning(disable:4996)

#include<vld.h>
#include<math.h>
#include<stdlib.h>
#include"interface.h"
#include"impl.h"

double F(const double x)
{
	return sin(x);
	//return x;
}

int main(void)
{
	FILE* in;
	FILE* out;
	double* x;
	double* y;
	double integral;
	double integral_ex;
	double step;
	double eps;
	int i;
	int k;
	int n;

	in = fopen("MatlabFiles\\grid.txt", "r");
	if (in == NULL)
	{
		fprintf(stderr, "Error: no file for reading \n");
		return -1;
	}
	out = fopen("MatlabFiles\\result.txt", "w");

	fscanf(in, "%i", &n);
	fscanf(in, "%lf", &integral_ex);

	x = malloc(sizeof(double) * (n + 1));
	if (x == NULL)
	{
		fclose(in);
		fclose(out);
		fprintf(stderr, "Error: not enough memory \n");
		return -1;
	}
	y = malloc(sizeof(double) * (n + 1));
	if (y == NULL)
	{
		free(x);
		fclose(in);
		fclose(out);
		fprintf(stderr, "Error: not enough memory \n");
		return -1;
	}

	for (i = 2; i < n; i++)
	{
		ReadVector(in, i, x);
		//PrintVector(stdout, i , x);
		for (k = 1; k <= i; k++)
			y[k] = F(x[k]);

		step = x[2] - x[1];
		integral = Itergral_Trapezium(y, step, i);

		eps = fabs(integral - integral_ex);
		fprintf(out, "%lf \n", eps);
	}


	free(x);
	free(y);
	fclose(in);
	fclose(out);
	return 0;
}