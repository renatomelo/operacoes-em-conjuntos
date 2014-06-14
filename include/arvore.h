#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int chave; //Tamanho n do conjunto
	int *elementos; //Vetor de elementos
	struct no *esq;
	struct no *dir;
	struct no *raiz;
}no;

typedef no arvore;

no *cria_novo_no(int chave, int *elementos);

arvore *inserir(arvore *raiz, no *novo);

no *insere_rec(no *r, no * x);

void atravassarEmOrdem(arvore *raiz);

no *minimo(arvore *raiz);

no *maximo(arvore *raiz);

no *sucessor(arvore *raiz, no *x);

no *antecessor(arvore *raiz, no *x);

void remover(arvore *raiz, int x);

arvore *remover_rec(arvore *raiz, int x);

no *busca(arvore *raiz, int x);

