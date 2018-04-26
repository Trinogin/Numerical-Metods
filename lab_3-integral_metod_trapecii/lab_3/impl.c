#include"impl.h"

double Itergral_Trapezium(double const* const y, const double step, const int n)
{
	double result = 0.0;
	int i;

	result += y[1] * step;

	for (i = 2; i < n; i++)
		result += y[i] * step;

	result += y[n] * step;

	return result;
}