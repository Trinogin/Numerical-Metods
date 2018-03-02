#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<vld.h>
#include"Interface.h"
#include"Header_Lagrange.h"

#define UNUSED_PARAMETER(name) (void)name

double F(double x)
{
	double f_x;
	 f_x = sin(x);
	// f_x = abs(x);
	return f_x;
}

int main(void)
{
	int size_grid;
	int size_points;

	double* x_uniform = NULL; // Uniform grid
	double* y_uniform = NULL;
	double* x_cheb = NULL; // Chebyshev grid
	double* y_cheb = NULL;
	double* x_points = NULL; // My points
	double* y_points = NULL;
	double point;

	UNUSED_PARAMETER(point);

	FILE* input_x_uniform = NULL; // Streams to read grids
	FILE* input_x_cheb = NULL;
	FILE* input_x_points = NULL;
// --------------------------------------------------------------------------------
	input_x_uniform = fopen("x_uniform.txt", "r");
	if (input_x_uniform == NULL)
	{
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: no file for reading: x_uniform.txt \n");
		return -1;
	}
	input_x_cheb = fopen("x_cheb.txt", "r");
	if (input_x_cheb == NULL)
	{
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: no file for reading: x_cheb.txt \n");
		return -1;
	}
	input_x_points = fopen("x_points.txt", "r");
	if (input_x_points == NULL)
	{
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: no file for reading: x_points.txt \n");
		return -1;
	}
// --------------------------------------------------------------------------------	
	fscanf(input_x_uniform, "%i", &size_grid);
	x_uniform = (double*)malloc(sizeof(double)*(size_grid + 1));
	y_uniform = (double*)malloc(sizeof(double)*(size_grid + 1));

	fscanf(input_x_cheb, "%i", &size_grid);
	x_cheb = (double*)malloc(sizeof(double)*(size_grid + 1));
	y_cheb = (double*)malloc(sizeof(double)*(size_grid + 1));

	fscanf(input_x_points, "%i", &size_points);
	x_cheb = (double*)malloc(sizeof(double)*(size_points + 1));
	//y_cheb = (double*)malloc(sizeof(double)*(size_points + 1));
	y_cheb = NULL;
	// Check the total memory allocate
	if (x_uniform == NULL || y_uniform == NULL
		|| x_cheb == NULL || y_cheb == NULL
		|| x_points == NULL || y_points == NULL)
	{
		MemFree(x_uniform, y_uniform, x_cheb, y_cheb, x_points, y_points);
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: not enough memory \n");
		return -1;
	}
// --------------------------------------------------------------------------------

	//ReadVector(in, n, x);
	//ReadVector(in, n, y);

	//PrintVector(out, n, x);
	//PrintVector(out, n, y);

	//x_test = InterpolLagrangePol(n, x, y, 0.0);
	//PrintVector(out, n, p);

	//printf("%lf \n", x_test);

	//fclose(in);
	//fclose(out);

	MemFree(x_uniform, y_uniform, x_cheb, y_cheb, x_points, y_points);
	StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
	// TO DO 
	// stream OUT close
	return 0;
}