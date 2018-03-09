#include"Header_Lagrange.h"

double InterpolLagrangePol(int n, double*  const x, double* const y, double point_x)
{
	double result = 0.0;
	double mult;
	int i;
	int j;

	for (i = 1; i <= n; i++)
	{
		mult = 1.0;
		for (j = 1; j <= n; j++)
			if (i != j)
				mult = mult * (point_x - x[j]) / (x[i] - x[j]);
		result += mult *y[i];
	}
	return result;
}
