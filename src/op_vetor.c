#include <stdio.h>
#define true 1 // para usar como tipo booleano
#define false 0

typedef int bool; //Definição do tipo booleano

// Busca binária modificada para validação
// A função abaixo recebe um número k e um vetor
// crescente v[0..n-1]. Ela devolve verdadeiro 
// se v[meio] >= k ou devolve falso se não existe 
// um valor maior ou igual a k
bool buscaBinaria( int k, int n, int v[]) {
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
//Devolve o menor entre dois vetores do mesmo tamanho
//o vetor que conter o menor elemento na posição i é o menor
int *menorVetor(int *vet1, int *vet2, int n){
	int i,j;
	for (i = 0; i < n; i++){
		if (vet1[i] > vet2[i]){
			return  vet2;
		}
	}
	return vet1;
}

//Devolve o maior entre dois vetores do mesmo tamanho
//o vetor que conter o maior elemento na posição i é o menor
int *maiorVetor(int *vet1, int *vet2, int n){
	int i,j;
	for (i = 0; i < n; i++){
		if (vet1[i] < vet2[i]){
			return  vet2;
		}
	}
	return vet1;
}

//Devolve verdade se vet1[0..n] é menor que vet2[0..n]
bool ehMenor(int vet1[], int vet2[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (vet1[i] > vet2[i])
			return  false;			
		if (vet1[i] < vet2[i])
			return true;
	}
}

//Devolve verdadeiro se os vetores são iguais
bool saoIguais(int vet1[], int vet2[], int n){
	int i;
	for (i = 0; i < n; i++){
		if (vet1[i] != vet2[i])
			return  false;
	}
	return true;
}

//Exibe os elementos um vetor de tamanho n
int imprimeVetor(int vet[], int n){
	int i;
	for (i = 0; i < n; i += 1)
		printf("%d ",vet[i]);
	printf("\n");
}

//Função de teste das funções acima
/* 
int main (int argc, char *argv[])
{
	int vet1[] = {1,4,6,8,9};
	int vet2[] = {11,4,6,8,9};
//	int result = buscaBinaria(7,5,vet);
//	printf("%d \n",result);

	printf("%d\n",saoIguais(vet1,vet2,5));
	return 0;
}
*/
