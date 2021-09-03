#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {

	// OMP_NUM_THREADS <- variável de ambiente que marca a quantidade de número de threads
	//#pragma omp parallel 
	int var1 = 10;

	omp_set_num_threads(6);

	#pragma omp parallel  num_threads(6)
	{
		int var2 = 10;
		var2++;
		var1++;
		//printf("VAR1: %d\n", var1);
		printf("VAR2: %d\n", var2);
	}

	printf("serial\n");
	/*
	#pragma omp parallel num_threads(8)
	{
		printf("MSG2\n");
	}*/

	system("pause");
}