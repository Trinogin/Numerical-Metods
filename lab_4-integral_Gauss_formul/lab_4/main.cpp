#include<cstdio>
#include<cmath>
#include<vld.h>

#include"interface.h"
#include"impl.h"

#define N 1000

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
	out = fopen("MatlabFiles\\result_3.txt", "w");

	fscanf(in, "%i", &n);
	fscanf(in, "%lf", &exact_integral);
	fscanf(in, "%lf", &a);
	fscanf(in, "%lf", &b);

	legandre_roots = new double[n + 1];
	weights = new double[n + 1];
	ReadVector(in, n, legandre_roots);
	ReadVector(in, n, weights);

	//for (i = 2; i <= n; i++)
	//{
	//	integral = GaussIntegral(i, a, b, legandre_roots, weights);
	//	eps = fabs(integral - exact_integral);
	//	fprintf(out, "%.16lf \n", eps);
	//}

	//---------
	UNUSED_PARAMETER(eps);
	UNUSED_PARAMETER(integral);
	UNUSED_PARAMETER(i);
	//---------
	int j = 2;
	double I = exact_integral;

	while (j <= N)
	{
		double result = 0.0;
		double h = (b - a) / (double)j;
		double prev = a;
		for (int k = 0; k < j; k++) 
		{
			double next = prev + h;
			result += GaussIntegral(n, prev, next, legandre_roots, weights);
			prev = next;
		}
		fprintf(out, "%.16lf ", fabs(I - result));
		fprintf(out, "%.16lf \n", h);
		j++;
	}

	fclose(in);
	fclose(out);
	delete[] legandre_roots;
	delete[] weights;
	return 0;
}