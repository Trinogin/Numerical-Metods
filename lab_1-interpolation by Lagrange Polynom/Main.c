#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<vld.h>
#include"Interface.h"
#include"Header_Lagrange.h"

double F(double x)
{
	double f_x;
	// f_x = sin(x);
	f_x = abs(x);
	return f_x;
}

int main(void)
{
	int n;
	int a = 0;
	double* x = NULL;
	double* y = NULL;
	double* p = NULL;
	double x_test;
	FILE* in;
	FILE* out;


	in = fopen("DataFile.txt", "r");
	out = stdout;

	if (in == NULL)
	{
		printf("Error: no file in directory \n");
		fclose(out);
		return -1;
	}
	a = fscanf(in, "%i", &n);
	if (a == -1)
	{
		printf("Error: file is empty \n");
		fclose(in);
		fclose(out);
		return -1;
	}

	x = (double*)malloc(sizeof(double)*(n + 1));
	if (x == NULL)
	{
		printf("Error: not enough memory \n");

		fclose(in);
		return -1;
	}
	y = (double*)malloc(sizeof(double)*(n + 1));
	if (y == NULL)
	{
		printf("Error: not enough memory \n");

		free(x);
		fclose(in);
		return -1;
	}
	p = (double*)malloc(sizeof(double)*(n + 1));
	if (p == NULL)
	{
		printf("Error: not enough memory \n");

		free(x);
		free(y);
		fclose(in);
		return -1;
	}

	ReadVector(in, n, x);
	ReadVector(in, n, y);

	PrintVector(out, n, x);
	PrintVector(out, n, y);

	x_test = InterpolLagrangePol(n, x, y, 0.0);
	//PrintVector(out, n, p);

	printf("%lf \n", x_test);

	fclose(in);
	fclose(out);

	free(x);
	free(y);
	free(p);
	return 0;
}