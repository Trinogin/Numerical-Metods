#include<stdlib.h>
#include<stdio.h>
#include<vld.h>
#include"Header_Lagrange.h"

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

void InterpolLagrangePol(int n, double* x, double* y, double* p)
{
	UNUSED_PARAMETER (n);
	UNUSED_PARAMETER (x);
	UNUSED_PARAMETER (y);
	UNUSED_PARAMETER (p);
}

int main(void)
{
	int n;
	int a = 0;
	double* x = NULL;
	double* y = NULL;
	double* p = NULL;
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

	InterpolLagrangePol(n, x, y, p);
	//PrintVector(out, n, p);

	fclose(in);
	fclose(out);
	free(x);
	free(y);
	free(p);
	return 0;
}