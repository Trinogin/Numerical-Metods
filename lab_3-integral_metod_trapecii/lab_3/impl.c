#include"impl.h"

double Itergral_Trapezium(double const* const y, const double step, const int n)
{
	double result = 0.0;
	int i;

	for (i = 2; i < n; i++)
		result += y[i] ;
	
	result += ((y[1] + y[n]) / 2.0);
	
	result *= step;

	return result;
}