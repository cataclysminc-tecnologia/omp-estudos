/*
* Descobrir se um número digitado pelo usuário é primo
* Solução Paralela
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int num;
	bool primo = 1; // verdadeiro

	printf("Digite um valor: \n");
	scanf_s("%d", &num);

	#pragma omp parallel for
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			primo = 0;
		}
	}

	if (primo)
	{
		printf("primo\n");
	}
	else {
		printf("Nao primo\n");
	}

	system("pause");
}

/*
* Solução serial
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int num;
	bool primo = 1; // verdadeiro

	printf("Digite um valor: \n");
	scanf_s("%d", &num);

	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			primo = 0;
		}
	}

	if (primo)
	{
		printf("primo\n");
	}
	else {
		printf("Nao primo\n");
	}

	system("pause");
}
*/