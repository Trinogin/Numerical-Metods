#include"impl.h"
#include<cmath>

double F(const double x)
{
	return sin(x) * cos(x);
}

double GaussIntegral(const int n, const double a, const double b,
	const double * const legandre, const double * const weights)
{
	double result = 0.0;
	int i;

	for (i = 1; i <= n; i++)
		result +=  weights[i] *  F((a + b) / 2.0 + (b - a) / 2.0 * legandre[i]);

	result *= (b - a) / 2.0;

	return result;
}