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
	//f_x = fabs(x);
	return f_x;
}

int main(void)
{
	int size_grid;
	int size_points;
	int i;
	int j;
	int k;

	double* x_uniform = NULL; // Uniform grid
	double* y_uniform = NULL;
	double* x_cheb = NULL; // Chebyshev grid
	double* y_cheb = NULL;
	double* x_points = NULL; // My points
	double* y_points = NULL;
	double point;
	double max_eps_uniform;
	double max_eps_cheb;
	double q_eps_uniform;
	double q_eps_cheb;

	UNUSED_PARAMETER(point);

	FILE* input_x_uniform = NULL; // Streams to read grids
	FILE* input_x_cheb = NULL;
	FILE* input_x_points = NULL;

	FILE* output_max_eps_uniform = NULL; // Streams to print computed eps
	FILE* output_max_eps_cheb = NULL;


	// --------------------------------------------------------------------------------
	input_x_uniform = fopen("MatlabFiles\\x_uniform.txt", "r");
	if (input_x_uniform == NULL)
	{
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: no file for reading: x_uniform.txt \n");
		return -1;
	}
	input_x_cheb = fopen("MatlabFiles\\x_cheb.txt", "r");
	if (input_x_cheb == NULL)
	{
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: no file for reading: x_cheb.txt \n");
		return -1;
	}
	input_x_points = fopen("MatlabFiles\\x_points.txt", "r");
	if (input_x_points == NULL)
	{
		StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
		printf("Error: no file for reading: x_points.txt \n");
		return -1;
	}

	output_max_eps_uniform = fopen("MatlabFiles\\MaxEpsUnif.txt", "w");
	output_max_eps_cheb = fopen("MatlabFiles\\MaxEpsCheb.txt", "w");
	// --------------------------------------------------------------------------------	
	fscanf(input_x_uniform, "%i", &size_grid);
	x_uniform = (double*)malloc(sizeof(double)*(size_grid + 1));
	y_uniform = (double*)malloc(sizeof(double)*(size_grid + 1));

	fscanf(input_x_cheb, "%i", &size_grid);
	x_cheb = (double*)malloc(sizeof(double)*(size_grid + 1));
	y_cheb = (double*)malloc(sizeof(double)*(size_grid + 1));

	fscanf(input_x_points, "%i", &size_points);
	x_points = (double*)malloc(sizeof(double)*(size_points + 1));
	y_points = (double*)malloc(sizeof(double)*(size_points + 1));

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

	// Reading [a ; b]
	ReadVector(input_x_points, size_points, x_points);
	// Fill y ([a : b])
	for (i = 1; i <= size_points; i++)
		y_points[i] = F(x_points[i]);

	// Cycle by grid size
	for (i = 1; i <= size_grid; i++)
	{
		// Reading grid + fill y(x)
		ReadVector(input_x_uniform, i, x_uniform);
		ReadVector(input_x_cheb, i, x_cheb);
		//PrintVector(stdout, i, x_uniform);
		for (j = 1; j <= i; j++)
		{
			y_uniform[j] = F(x_uniform[j]);
			y_cheb[j] = F(x_cheb[j]);
		}

		// Computing EpsMax on the [a ; b] and writing to file
		max_eps_uniform = fabs(F(x_points[1]) - InterpolLagrangePol(i, x_uniform, y_uniform, x_points[1]));
		max_eps_cheb = fabs(F(x_points[1]) - InterpolLagrangePol(i, x_cheb, y_cheb, x_points[1]));
		for (k = 1; k <= size_points; k++)
		{
			q_eps_uniform = fabs(F(x_points[k]) - InterpolLagrangePol(i, x_uniform, y_uniform, x_points[k]));
			if (q_eps_uniform > max_eps_uniform)
				max_eps_uniform = q_eps_uniform;

			q_eps_cheb = fabs(F(x_points[k]) - InterpolLagrangePol(i, x_cheb, y_cheb, x_points[k]));
			if (q_eps_cheb > max_eps_cheb)
				max_eps_cheb = q_eps_cheb;
		}
		fprintf(output_max_eps_uniform, "%.16lf \n", max_eps_uniform);
		fprintf(output_max_eps_cheb, "%.16lf \n", max_eps_cheb);
	}

	// --------------------------------------------------------------------------------
	MemFree(x_uniform, y_uniform, x_cheb, y_cheb, x_points, y_points);
	StreamInClose(input_x_uniform, input_x_cheb, input_x_points);
	
	fclose(output_max_eps_uniform);
	fclose(output_max_eps_cheb);

	return 0;
}