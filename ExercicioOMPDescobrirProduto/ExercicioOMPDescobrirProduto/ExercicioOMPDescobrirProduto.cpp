/*
* Descobrir o produto entre todos os valores dentro de um array de inteiros com valores 1 e 2
* Solução paralela
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define TAM 50

int main()
{
	srand(time(NULL));
	int arr[TAM];
	
	#pragma omp parallel for
	for (int i = 0; i < TAM; i++)
	{
		arr[i] = (rand()%2)+1;
	}

	long prod = 1;
	#pragma omp parallel for reduction(*:prod)
	for (int i = 0; i < TAM; i++)
	{
		prod *= arr[i];
	}

	printf("Prod: %d\n", prod);

	system("pause");
}

/*
* Solução serial
int main()
{
	srand(time(NULL));
	int arr[TAM];

	for (int i = 0; i < TAM; i++)
	{
		arr[i] = (rand()%2)+1;
	}

	long prod = 1;
	for (int i = 0; i < TAM; i++)
	{
		prod *= arr[i];
	}

	printf("Prod: %d\n", prod);

	system("pause");
}
*/