#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TAM 1000
#define NT 8

int main() {

	// Criar um array e tirar a média dos valores
	int arr[TAM];

	for (int i = 0; i < TAM; i++)
	{
		arr[i] = i;
	}


	int soma[NT];
	for (int i = 0; i < NT; i++)
	{
		soma[i] = 0;
	}
	int somaTotal = 0;
	#pragma omp parallel num_threads(NT)
	{
		int soma = 0;
		#pragma omp for
		for (int i = 0; i < TAM; i++)
		{
			soma += arr[i];
		}
		#pragma omp atomic
		{
			somaTotal += soma;
		}
		
	}

	printf("media: %f\n", (float)somaTotal / NT);

	system("pause");
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TAM 1000
#define NT 8

int main() {

	// Criar um array e tirar a média dos valores
	int arr[TAM];

	for (int i = 0; i < TAM; i++)
	{
		arr[i] = i;
	}


	int soma[NT];
	for (int i = 0; i < NT; i++)
	{
		soma[i] = 0;
	}
	int somaTotal = 0;
	#pragma omp parallel num_threads(NT)
	{
		int soma = 0;
		int id = omp_get_thread_num();
		#pragma omp for
		for (int i = 0; i < TAM; i++)
		{
			soma += arr[i];
		}
		#pragma omp critical
		{
			somaTotal += soma;
		}

	}

	for (int i = 0; i < NT; i++)
	{
		somaTotal += soma[i];
	}

	printf("media: %f\n", (float)somaTotal / NT);

	system("pause");
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TAM 1000
#define NT 8

int main() {

	// Criar um array e tirar a média dos valores
	int arr[TAM];

	for (int i = 0; i < TAM; i++)
	{
		arr[i] = i;
	}


	int soma[NT];
	for (int i = 0; i < NT; i++)
	{
		soma[i] = 0;
	}
	int somaTotal = 0;
	#pragma omp parallel num_threads(NT)
	{
		int id = omp_get_thread_num();
		#pragma omp for
		for (int i = 0; i < TAM; i++)
		{
			soma[id] += arr[i];
		}
	}

	for (int i = 0; i < NT; i++)
	{
		somaTotal += soma[i];
	}

	printf("media: %f\n", (float)somaTotal / NT);

	system("pause");
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TAM 1000
#define NT 8

int main() {

	// Criar um array e tirar a média dos valores
	int arr[TAM];

	for (int i = 0; i < TAM; i++)
	{
		arr[i] = i;
	}


	int soma[NT];
	for (int i = 0; i < NT; i++)
	{
		soma[i] = 0;
	}
	int somaTotal = 0;
	#pragma omp parallel num_threads(NT)
	{
		int id = omp_get_thread_num();
		// 0 8 16 24 primeira thread
		// 1 9 17 25 segunda thread
		// 2 10 18, 26 terceira thread
		for (int i = id; i < TAM; i+=NT)
		{
			soma[id] += arr[i];
		}
	}

	for (int i = 0; i < NT; i++)
	{
		somaTotal += soma[i];
	}

	printf("media: %f\n", (float)somaTotal / NT);

	system("pause");
}
*/