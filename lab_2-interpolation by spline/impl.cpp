#include"impl.h"

int computing(const int size, double* x, double* y, double*h, double* l, double* delta, double* lambda,
	double* c, double* b, double* d)
{
	int k;

	for (k = 1; k <= size; k++)
	{
		h[k] = x[k] - x[k - 1];
		// h == 0 - critical error (divide by zero)
		if (h[k] == 0.0)
			return k;

		l[k] = (y[k] - y[k - 1]) / h[k];
	}


	delta[1] = -h[2] / (2.0 * (h[1] + h[2]));
	lambda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2]);
	for (k = 3; k <= size; k++)
	{
		delta[k - 1] = -h[k] / (2.0 * h[k - 1] + 2.0 * h[k] + h[k - 1] * delta[k - 2]);
		lambda[k - 1] = (3.0 * l[k] - 3.0 * l[k - 1] - h[k - 1] * lambda[k - 2]) /
			(2.0 * h[k - 1] + 2.0 * h[k] + h[k - 1] * delta[k - 2]);
	}
	c[0] = 0.0;
	c[size] = 0.0;

	for (k = size; k >= 2; k--)
		c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];

	for (k = 1; k <= size; k++)
	{
		d[k] = (c[k] - c[k - 1]) / (3.0 * h[k]);
		b[k] = l[k] + (2.0 * c[k] * h[k] + h[k] * c[k - 1]) / 3.0;
	}
	return 0;
}