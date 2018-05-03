#include<cstdio>
#include<cmath>
#include<vld.h>

#include"interface.h"
#include"impl.h"

int main(void)
{
	FILE* in;
	FILE* out;
	double* legandre_roots;
	double* weights;
	double exact_integral;
	double integral;
	double a;
	double b;
	double eps;
	int n;
	int i;

	in = fopen("MatlabFiles\\grid.txt", "r");
	if (in == NULL)
	{
		fprintf(stdout, "Error: no file for reading \n");
		return -1;
	}
	out = fopen("MatlabFiles\\result.txt", "w");

	fscanf(in, "%i", &n);
	fscanf(in, "%lf", &exact_integral);
	fscanf(in, "%lf", &a);
	fscanf(in, "%lf", &b);

	legandre_roots = new double[n + 1];
	weights = new double[n + 1];
	ReadVector(in, n, legandre_roots);
	ReadVector(in, n, weights);

	for (i = 2; i <= n; i++)
	{
		integral = GaussIntegral(i, a, b, legandre_roots, weights);
		eps = fabs(integral - exact_integral);
		fprintf(out, "%.16lf \n", eps);
	}

	fclose(in);
	fclose(out);
	delete[] legandre_roots;
	delete[] weights;
	return 0;
}