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

bool pesquisaBin( int k, int n, int v[]) {
	int inicio = 0;
	int meio;
	int fim = n-1;
	while (inicio <= fim) { 
		meio = (inicio + fim)/2;
		if (k == v[meio])
			return true;
		else if (v[meio] > k) 
			fim = meio -1;
		else
			inicio = meio + 1;
   }
   return false;
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
	printf("%d",n);
	for (i = 0; i < n; i += 1)
		printf(" %d",vet[i]);
	printf("\n");
}

//Recebe um conjunto, um subconjunto e seus respectivos tamanhos
//Devolve verdadeiro se o subconjunto está contido no cojunto
bool contemSubConj(int* conj,int tamConj,int* subConj,int tamSubConj){
    int i;
    for(i = 0; i < tamSubConj; i++){
		if(!pesquisaBin(subConj[i],tamConj,conj)){
			return false;
		}
    }
    return true;
}
