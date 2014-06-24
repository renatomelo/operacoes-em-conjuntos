#include <stdio.h>
#include <string.h>
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

//operação '<'
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
				if (pesquisaSubConj(vet,n,atual->elem,atual->tam))
					imprimeVetor(atual->elem,atual->tam);
			}
			
			atual = atual->dir;
		}
	}
}

// operação '>'
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
				if (pesquisaSubConj(atual->elem,atual->tam,vet,n))
					imprimeVetor(atual->elem,atual->tam);
			}
			
			atual = atual->dir;
		}
	}
}

// operação '/'
/*Esta operação deve remover da coleção todos os conjuntos que 
são superconjuntos próprios do conjunto envolvido na operação. */
void removeSuperConj(Arvore *raiz, int *nConjuntos, int n, int* vet){
	No *atual, *pilha[*nConjuntos];
	int topo = 0;
	char saida[] = "Erro.";
	
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];

			if (n == atual->tam){
				if(saoIguais(vet,atual->elem,n)){
					raiz = remover_rec(raiz,atual);
					(*nConjuntos)--;
					strcpy(saida, "Ok!");
				}
			}
			else if (n < atual->tam){
				if (pesquisaSubConj(atual->elem,atual->tam,vet,n)){
					raiz = remover_rec(raiz,atual);
					(*nConjuntos)--;
					strcpy(saida, "Ok!");
				}
			}
			
			atual = atual->dir;
		}
	}
	printf("\t\t%s\n",saida);
}
