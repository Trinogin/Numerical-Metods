#ifndef IMPL_C_INCLUDED

#define IMPL_C_INCLUDED

#pragma once

#define UNUSED_PARAMETER(a) (void)a

double GaussIntegral(const int n, const double a, const double b,
	const double * const legandre, const double * const weights);

#endif // !IMPL_C_INCLUDED
