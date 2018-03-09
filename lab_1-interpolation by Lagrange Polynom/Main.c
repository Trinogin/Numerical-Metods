#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<vld.h>
#include"Interface.h"
#include"Header_Lagrange.h"

#define UNUSED_PARAMETER(name) (void)name

// Function for the MaxEps on interval
double F(double x)
{
	double f_x;
	f_x = sin(x);
	return f_x;
}

// Function for Eps in point
double G(double x)
{
	double g_x;
	g_x = fabs(x);
	return g_x;
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
	double* point_x_uniform = NULL; // Grids for one point
	double* point_y_uniform = NULL;
	double* point_x_cheb = NULL;
	double* point_y_cheb = NULL;
	double point;
	double max_eps_uniform; // Max epsilon on interval for uniform grid
	double max_eps_cheb; // Max on interval for Chebyshev
	double q_eps_uniform; // Intermediate value for searching max epsilon
	double q_eps_cheb;
	double point_eps_uniform; // Epsilons for one point, for uniform and chebyshev grids
	double point_eps_cheb;

	// Streams to read grids
	FILE* input_x_uniform = NULL; // 2 grids
	FILE* input_x_cheb = NULL;
	FILE* input_point_uniform = NULL; // 2 grids for epsilon in one point
	FILE* input_point_cheb = NULL;
	FILE* input_x_points = NULL; // My points, intreval splitting


	// Streams to print computed eps
	FILE* output_max_eps_uniform = NULL; // For uniform grid 
	FILE* output_max_eps_cheb = NULL; // For chebyshev grid
	FILE* output_point_uniform = NULL; // For uniform grid in one point
	FILE* output_point_cheb = NULL; // For chebyshev grid in one point
	{
		// --------------------------------------------------------------------------------
		//  Opening streams to reading, all of this is filling by matlab code
		input_x_uniform = fopen("MatlabFiles\\x_uniform.txt", "r");
		if (input_x_uniform == NULL)
		{
			StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
				input_point_uniform, input_point_cheb);
			printf("Error: no file for reading: x_uniform.txt \n");
			return -1;
		}
		input_x_cheb = fopen("MatlabFiles\\x_cheb.txt", "r");
		if (input_x_cheb == NULL)
		{
			StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
				input_point_uniform, input_point_cheb);
			printf("Error: no file for reading: x_cheb.txt \n");
			return -1;
		}
		input_x_points = fopen("MatlabFiles\\x_points.txt", "r");
		if (input_x_points == NULL)
		{
			StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
				input_point_uniform, input_point_cheb);
			printf("Error: no file for reading: x_points.txt \n");
			return -1;
		}
		input_point_uniform = fopen("MatlabFiles\\point_uniform.txt", "r");
		if (input_point_uniform == NULL)
		{
			StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
				input_point_uniform, input_point_cheb);
			printf("Error: no file for reading: point_uniform.txt \n");
			return -1;
		}
		input_point_cheb = fopen("MatlabFiles\\point_cheb.txt", "r");
		if (input_point_uniform == NULL)
		{
			StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
				input_point_uniform, input_point_cheb);
			printf("Error: no file for reading: point_cheb.txt \n");
			return -1;
		}

		// Opening output streams, this is filling for creating graphics in matlab
		output_max_eps_uniform = fopen("MatlabFiles\\MaxEpsUnif.txt", "w");
		output_max_eps_cheb = fopen("MatlabFiles\\MaxEpsCheb.txt", "w");
		output_point_uniform = fopen("MatlabFiles\\PointEpsUniform.txt", "w");
		output_point_cheb = fopen("MatlabFiles\\PointEpsCheb.txt", "w");
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

		fscanf(input_point_uniform, "%i", &size_grid);
		point_x_uniform = (double*)malloc(sizeof(double)*(size_grid + 1));
		point_y_uniform = (double*)malloc(sizeof(double)*(size_grid + 1));

		fscanf(input_point_cheb, "%i", &size_grid);
		point_x_cheb = (double*)malloc(sizeof(double)*(size_grid + 1));
		point_y_cheb = (double*)malloc(sizeof(double)*(size_grid + 1));

		// Check the total memory allocate
		if (x_uniform == NULL || y_uniform == NULL
			|| x_cheb == NULL || y_cheb == NULL
			|| x_points == NULL || y_points == NULL
			|| point_x_uniform == NULL || point_y_uniform == NULL
			|| point_x_cheb == NULL || point_y_cheb == NULL)
		{
			MemFree(x_uniform, y_uniform, x_cheb, y_cheb, x_points, y_points,
				point_x_uniform, point_y_uniform, point_x_cheb, point_y_cheb);

			StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
				input_point_uniform, input_point_cheb);
			printf("Error: not enough memory \n");
			return -1;
		}
		// --------------------------------------------------------------------------------

	}

	// Reading [a ; b]
	ReadVector(input_x_points, size_points, x_points);
	// Fill y ([a : b])
	for (i = 1; i <= size_points; i++)
		y_points[i] = F(x_points[i]);

	point = 0.8;

	// Cycle by grid size
	for (i = 1; i <= size_grid; i++)
	{
		// Reading grid
		ReadVector(input_x_uniform, i, x_uniform);
		ReadVector(input_x_cheb, i, x_cheb);
		ReadVector(input_point_uniform, i, point_x_uniform);
		ReadVector(input_point_cheb, i, point_x_cheb);
		// HERE you can test readed values, smthg like PrintVector(stdout, i, x_uniform);

		// Filling y(x) for all grids
		for (j = 1; j <= i; j++)
		{
			y_uniform[j] = F(x_uniform[j]);
			y_cheb[j] = F(x_cheb[j]);
			point_y_uniform[j] = G(point_x_uniform[j]);
			point_y_cheb[j] = G(point_x_cheb[j]);
		}

		// ------------------------------------------------------------------------------
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

		// ------------------------------------------------------------------------------ 
		// The same with the one point and grids for this
		point_eps_uniform = fabs(G(point) - InterpolLagrangePol(i, point_x_uniform, point_y_uniform, point));
		point_eps_cheb = fabs(G(point) - InterpolLagrangePol(i, point_x_cheb, point_y_cheb, point));
		fprintf(output_point_uniform, "%.16lf \n", point_eps_uniform);
		fprintf(output_point_cheb, "%.16lf \n", point_eps_cheb);
		// -------------------------------------------------------------------------------
	}

	// --------------------------------------------------------------------------------
	// Clean all allocated memory
	MemFree(x_uniform, y_uniform, x_cheb, y_cheb, x_points, y_points,
		point_x_uniform, point_y_uniform, point_x_cheb, point_y_cheb);

	// Close all input streams
	StreamInClose(input_x_uniform, input_x_cheb, input_x_points,
		input_point_uniform, input_point_cheb);

	// Close all output streams
	fclose(output_max_eps_uniform);
	fclose(output_max_eps_cheb);
	fclose(output_point_uniform);
	fclose(output_point_cheb);

	return 0;
}