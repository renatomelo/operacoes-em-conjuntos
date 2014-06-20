#include <stdio.h>
#include <stdlib.h>
//#include "fila.h"

typedef struct no {
	int tam; //Tamanho n do conjunto
	int *elem; //Vetor de elementos
	struct no *esq;
	struct no *dir;
}No;

typedef No Arvore;

No *cria_novo_no(int chave, int *elementos);

Arvore *inserir(Arvore *raiz, No *novo);

No *insere_rec(No *r, No * x);

void emOrdem(Arvore *raiz);

//Fila *atravassarEmOrdem(Arvore *raiz, int nConjuntos);
No **atravassarEmOrdem(Arvore *raiz, int nConjuntos);

No *minimo(Arvore *raiz);

No *maximo(Arvore *raiz);

No *sucessor(Arvore *raiz, No *x);

No *antecessor(Arvore *raiz, No *x);

void remover(Arvore *raiz, int x);

Arvore *remover_rec(Arvore *raiz, No *x);

No *busca(Arvore *raiz, int x);

int buscaNo(Arvore *raiz, No *x);

