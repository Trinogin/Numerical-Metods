#include"Interface.h"

// Reading and printing is from 1 to n element. Without 0 in start. 
void ReadVector(FILE* stream, int n, double* const vector)
{
	int i;

	for (i = 1; i <= n; i++)
		fscanf(stream, "%lf", &vector[i]);
}

void PrintVector(FILE* stream, int n, double const* const vector)
{
	int i;

	for (i = 1; i <= n; i++)
		fprintf(stream, "%.3lf ", vector[i]);
	fprintf(stream, "\n");
}

void MemFree(double* p_1, double* p_2, double* p_3, double* p_4, double* p_5, double* p_6,
	double* p_7, double* p_8, double* p_9, double* p_10)
{
	if (p_1 != NULL)
		free(p_1);
	if (p_2 != NULL)
		free(p_2);
	if (p_3 != NULL)
		free(p_3);
	if (p_4 != NULL)
		free(p_4);
	if (p_5 != NULL)
		free(p_5);
	if (p_6 != NULL)
		free(p_6);
	if (p_7 != NULL)
		free(p_7);
	if (p_8 != NULL)
		free(p_8);
	if (p_9 != NULL)
		free(p_9);
	if (p_10 != NULL)
		free(p_10);
}

void StreamInClose(FILE* s_1, FILE* s_2, FILE* s_3, FILE* s_4, FILE* s_5)
{
	if (s_1 != NULL)
		fclose(s_1);
	if (s_2 != NULL)
		fclose(s_2);
	if (s_3 != NULL)
		fclose(s_3);
	if (s_4 != NULL)
		fclose(s_4);
	if (s_5 != NULL)
		fclose(s_5);
}
