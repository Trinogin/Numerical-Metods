#pragma warning(disable:4996)

#include<vld.h>
#include<math.h>
#include<stdlib.h>
#include"interface.h"
#include"impl.h"

double F(const double x)
{
	//return sin(x) / x;
	//return 1.0 / sqrt(x);
	return (x > 0 ? 1 : -1);
}

#define EPS 0.00000002

int main(void)
{
	FILE* in;
	FILE* out;
	double* x;
	//double* x_2;
	double* y;
	//double* y_2;
	double integral;
	//double integral_2;
	double integral_ex;
	double step;
	//double step_2;
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
	//out = fopen("MatlabFiles\\result_2.txt", "w");

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
	//x_2 = malloc(sizeof(double) * (n + 1));
	//y_2 = malloc(sizeof(double) * (n + 1));

	for (i = 2; i <= n; i++)
	{
		ReadVector(in, i, x);
		for (k = 1; k <= i; k++)
			y[k] = F(x[k]);
		step = x[2] - x[1];
		integral = Itergral_Trapezium(y, step, i);
		eps = fabs(integral - integral_ex);
		fprintf(out, "%.16lf \n", eps);
	}


	/*k = 3;
	eps = 1.0;
	while (eps >= EPS)
	{
		ReadVector(in, k, x);
		ReadVector(in, k * 2 - 1, x_2);

		step = x[2] - x[1];
		step_2 = x_2[2] - x_2[1];

		for (i = 1; i <= k; i++)
			y[i] = sin(x[i]);
		for (i = 1; i <= k * 2 - 1; i++)
			y_2[i] = sin(x_2[i]);

		integral = Itergral_Trapezium(y, step, k);
		integral_2 = Itergral_Trapezium(y_2, step_2, k * 2 - 1);

		eps = fabs(integral - integral_2) / 3.0;
		fprintf(out, "%.16lf \n", eps);

		k = k * 2 - 1;
	}

	fprintf(out, "\n End steps: %lf and %lf \n", step, step_2);
*/
	free(x);
	free(y);
	//free(x_2);
	//free(y_2);
	fclose(in);
	fclose(out);
	return 0;
}