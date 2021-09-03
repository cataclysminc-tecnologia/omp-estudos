/*
Cálculo de histograma paralelo
Conte as ocorrênciasa de cada número para um conjunto de dados
Números aleatórios entre 0 e 11
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define TAM 10000

int main()
{
	srand(time(NULL));
	int arr[TAM];

	for (int i = 0; i < TAM; i++)
	{
		arr[i] = rand() % 12;
	}

	int hist[12];
	omp_lock_t chave[12];
	for (int i = 0; i < 12; i++)
	{
		hist[i] = 0;
		omp_init_lock(&chave[i]);
	}

	#pragma omp parallel for
	for (int i = 0; i < TAM; i++)
	{
		omp_set_lock(&chave[arr[i]]);
		hist[arr[i]]++;
		omp_unset_lock(&chave[arr[i]]);
	}

	for (int i = 0; i < 12; i++)
	{
		printf("Pos %d: %d\n", i, hist[i]);
	}

	system("pause");
}