/*
Calcule o valor de PI utilizando OpenMP
*/

// Solução paralela

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define RET 10000000 // Quantidade de retangulos

int main() {

	double largura = 1.0 / RET;
	double altura = 0, pi;
	double inicio = omp_get_wtime();
	#pragma omp parallel
	{
		double x; // cada thread terá sua variavel x
		#pragma omp for reduction(+:altura)
		for (int i = 0; i < RET; i++)
		{
			x = (i + 0.5) * largura;
			altura += 4.0 / (1 + x * x);
		}
	}

	pi = largura * altura;

	double tempoTotal = omp_get_wtime() - inicio;
	printf("TEMPO: %f\n", tempoTotal);
	printf("PI: %f\n", pi);

	system("pause");
}


/*
Calcule o valor de PI utilizando OpenMP
*/
/*
* 
* Solução serial
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define RET 100000 // Quantidade de retangulos

int main() {

	double largura = 1.0 / RET;
	double x, altura = 0, pi;

	for (int i = 0; i < RET; i++)
	{
		x = (i + 0.5) * largura;
		altura += 4.0 / (1 + x * x);
	}

	pi = largura * altura;
	printf("PI: %f\n", pi);

	system("pause");
}
*/