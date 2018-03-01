#ifndef HEADER_LAGRANGE_INCLUDED
#define HEADER_LAGRANGE_INCLUDED

#define UNUSED_PARAMETER(name) (void)name

#include<math.h>

double InterpolLagrangePol(int n, double* x, double* y, double point_x);

#endif //HEADER_LAGRANGE_INCLUDED