#include <stdio.h>
#define true 1
#define false 0

typedef int bool;


// Busca binária modificada para validação
// A função abaixo recebe um número k e um vetor
// crescente v[0..n-1]. Ela devolve verdadeiro 
// se v[meio] >= k ou devolve falso se não existe 
// um valor maior ou igual a k

bool
buscaBinaria( int k, int n, int v[]) {
	int inicio = 0;
	int meio;
	int fim = n-1;
	while (inicio <= fim) { 
		meio = (inicio + fim)/2; 
		if (v[meio] > k) 
			return true;
		else
			inicio = meio + 1;
   }
   return false;
}

/**
int
main (int argc, char *argv[])
{
	int vet[] = {1,2,3,4,6};
	int result = buscaBinaria(7,5,vet);
	printf("%d \n",result);
	return 0;
}
*/
