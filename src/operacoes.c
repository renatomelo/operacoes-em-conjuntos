#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "op_vetor.h"

#define true 1 // para usar como tipo booleano
#define false 0

int nConjuntos = 0;

typedef int bool; //Definição do tipo booleano

Arvore *raiz = NULL; //Arvore binária de buca

// É válido se não existe valor maior que k no conjunto
bool ehValido(int k, int n, int vet[]){
	if (buscaBinaria(k,n,vet)) 
		return false;
	return true;	
}

//+
void add(int max, int n, int *vet){
	//Validação	
	if(ehValido(max,n,vet)){
		//incapsula o vetor e o tamanho em um nó  	
		No *conjunto = criaNovoNo(n,vet);
		//Se o conj. já existe na arvore não insere
		if (existe(raiz, conjunto))
		printf("E\n0\n");
		else{
			//caso contrario o conjunto é inseridos
			raiz = insere_rec(raiz, conjunto);
			nConjuntos++;
			printf("0\n");
		}
	}else//Se existe no conj elemento maior q max dá erro		
		printf("E\n0\n");
}
//-
void del(int n, int *vet){
	//Incapsula os dados em um nó
	No *conjunto = criaNovoNo(n,vet);
	//Verifica se existe esse nó na arvore
	//Se sim, é removido. Se não, dá erro
	if (existe(raiz, conjunto)){
		raiz = remover_rec(raiz,conjunto);
		nConjuntos--;
		printf("0\n");
	}else{
		printf("E\n0\n");
	}
}
//=
void igualdade(int n, int *vet){
	//Verifica se o conjunto ja existe no superconjunto
	No *conjunto = criaNovoNo(n,vet);
	if (existe(raiz, conjunto))
		printf("0\n");
	else
		printf("E\n0\n");
}

//'*'
void exibir(){
	emOrdem(raiz);
	printf("0\n");
}

/* operação '<'
Esta operação deve listar todos os conjuntos da coleção que são
subconjuntos próprios do conjunto envolvido na operação
*/
void imprimeSubConj(int n, int* vet){
	No *atual, *pilha[nConjuntos];
	int topo = 0;
	char saida[] = "E\n0\n";
	
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];

			if (n > atual->tam){
				if (contemSubConj(vet,n,atual->elem,atual->tam)){
					imprimeVetor(atual->elem,atual->tam);
					strcpy(saida, "0\n");
				}
			}
			
			atual = atual->dir;
		}
	}
	printf("%s",saida);
}

// operação '>'
/*
Esta operação deve listar todos os conjuntos da coleção que são superconjuntos próprios do conjunto envolvido na operação.
*/      
void imprimeSuperConj(int n, int* vet){
	No *atual, *pilha[nConjuntos];
	int topo = 0;
	char saida[] = "E\n0\n";
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];

			if (n < atual->tam){
				if (contemSubConj(atual->elem,atual->tam,vet,n)){
					imprimeVetor(atual->elem,atual->tam);
					strcpy(saida, "0\n");
				}
			}
			
			atual = atual->dir;
		}
	}
	printf("%s",saida);
}

// operação '/'
/*Esta operação deve remover da coleção todos os conjuntos que 
são superconjuntos próprios do conjunto envolvido na operação. */
void removeSuperConj(int n, int* vet){
	No *atual, *pilha[nConjuntos];
	int topo = 0;
	char saida[] = "E\n0\n";
	
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];

/*			if (n == atual->tam){*/
/*				if(saoIguais(vet,atual->elem,n)){*/
/*					raiz = remover_rec(raiz,atual);*/
/*					(*nConjuntos)--;*/
/*					strcpy(saida, "0\n");*/
/*				}*/
/*			}*/
			if (n < atual->tam){
				if (contemSubConj(atual->elem,atual->tam,vet,n)){
					raiz = remover_rec(raiz,atual);
					(nConjuntos)--;
					strcpy(saida, "0\n");
				}
			}
			
			atual = atual->dir;
		}
	}
	printf("%s",saida);
}
