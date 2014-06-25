/*
Arquivo de cabeçalho da árvore, uma interface para arvore.c
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int tam; //Tamanho n do conjunto
	int *elem; //Vetor de elementos
	struct no *esq;
	struct no *dir;
}No;

typedef No Arvore;

No *criaNovoNo(int chave, int *elementos);

Arvore *inserir(Arvore *raiz, No *novo);

No *insere_rec(No *r, No * x);

void emOrdem(Arvore *raiz);

No *minimo(Arvore *raiz);

No *maximo(Arvore *raiz);

void remover(Arvore *raiz, int x);

Arvore *remover_rec(Arvore *raiz, No *x);

No *busca(Arvore *raiz, int x);

int existe(Arvore *raiz, No *x);

