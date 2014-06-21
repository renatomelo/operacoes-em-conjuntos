#include <stdio.h>
#include "arvore.h"
#include "op_vetor.h"



//+
void add(int n, int *vet);
//-
void del(int n, int *vet);
//=
void igualdade(int n, int *vet);
//*
void exibir();

//<
/*
Esta operação deve listar todos os conjuntos da coleção que são
subconjuntos próprios do conjunto envolvido na operação
*/
void imprimeSubConj(Arvore *raiz, int nConjuntos, int n, int* vet){
	No *atual, *pilha[nConjuntos];
	int topo = 0;
	
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];

			if (n == atual->tam)
				if(saoIguais(vet,atual->elem,n))
					imprimeVetor(atual->elem,atual->tam);
			if (n > atual->tam){
				if (contemSubConj(vet,n,atual->elem,atual->tam))
					imprimeVetor(atual->elem,atual->tam);
			}
			
			atual = atual->dir;
		}
	}
}

//>
/*
Esta operação deve listar todos os conjuntos da coleção que são superconjuntos próprios do conjunto envolvido na operação.
*/      
void imprimeSuperConj(Arvore *raiz, int nConjuntos, int n, int* vet){
	No *atual, *pilha[nConjuntos];
	int topo = 0;
	
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];

			if (n == atual->tam)
				if(saoIguais(vet,atual->elem,n))
					imprimeVetor(atual->elem,atual->tam);
			if (n < atual->tam){
				if (contemSubConj(atual->elem,atual->tam,vet,n))
					imprimeVetor(atual->elem,atual->tam);
			}
			
			atual = atual->dir;
		}
	}
}
