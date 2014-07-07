#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libtree.h"
#include "op_vetor.h"

typedef struct conjunto {
        int n;
        int *valores;
        struct rbtree_node node;
} Conjunto;

//Cria uma arvore rubro negra
struct rbtree tree;

Conjunto *criar_conjunto(int n, int *valores)
{
	int i;
	Conjunto* novo = (Conjunto*) malloc(sizeof (Conjunto));	
	novo->valores = valores;
	novo->n = n;
}

//Compara os conjuntos, retorna zero se for igual ou a difença do 
//nó a com b
int comparacao(const struct rbtree_node *a, const struct rbtree_node *b)
{
        Conjunto *p = rbtree_container_of(a, Conjunto, node);
        Conjunto *q = rbtree_container_of(b, Conjunto, node);                
        int result = p->n - q->n;
        if(result == 0){
        	int i;
        	for (i = 0; i < p->n; i += 1)
        	{
        		if(p->valores[i] != q->valores[i])
        			return p->valores[i] - q->valores[i];
        	}
        	result = 0;
        }
        return result;
}


//Inicializa a arvore vazia, passando como argumento 
//o endereço da arvore e a funcao de comparacao
void iniciar_colecao(){
	rbtree_init(&tree, comparacao, 0);
}

//Insere um conjunto na coleção
void add(int n, int *vet){

	Conjunto *conj = criar_conjunto(n,vet);
	if(!rbtree_insert((struct rbtree_node *) &conj->node, &tree))
		printf("0\n");
	else
		printf("E\n0\n");	
}

void del(int n, int *vet){
	Conjunto *conj = criar_conjunto(n,vet);
	  
	Conjunto *c;
	struct rbtree_node *nodo;
	nodo = rbtree_lookup ((struct rbtree_node *) &conj->node, &tree);
	if (nodo != NULL) {
		c = rbtree_container_of(nodo, Conjunto, node);
		rbtree_remove (&c->node, &tree);
		free (c);
		printf("0\n");
	}else
		printf("E\n0\n");		
}

//=
void igualdade(int n, int *vet){
	Conjunto *conj = criar_conjunto(n,vet);
	
	struct rbtree_node *result;
	result = rbtree_lookup ((struct rbtree_node *) &conj->node, &tree);
	if (result != NULL)
		printf("0\n");
	else
		printf("E\n0\n");
}

//'*'
void exibir(){
    struct rbtree_node *nodo;
    Conjunto *c;
    nodo = rbtree_first(&tree);
    while (nodo) {
        c = rbtree_container_of(nodo, Conjunto, node);
		imprimeVetor(c->valores,c->n);
        nodo = rbtree_next(nodo);
    }
    printf("0\n");
}

/* operação '<'
Esta operação deve listar todos os conjuntos da coleção que são
subconjuntos próprios do conjunto envolvido na operação
*/
void imprimeSubConj(int n, int* vet){
	char saida[] = "E\n0\n";
	struct rbtree_node *nodo;
    Conjunto *c;
    nodo = rbtree_first(&tree);
    while (nodo) {
        c = rbtree_container_of(nodo, Conjunto, node);
        
		if (n > c->n){
			
			if (contemSubConj(vet,n,c->valores,c->n)){
				imprimeVetor(c->valores,c->n);
				strcpy(saida, "0\n");
			}
		}
		
        nodo = rbtree_next(nodo);
    }
    printf("%s",saida);
}

/*void imprimeSubConj(int n, int* vet){*/
/*	Conjunto *c;*/
/*	struct rbtree_node *atual, *pilha[1000];*/
/*	int topo = 0;*/
/*	char saida[] = "E\n0\n";*/
/*	atual = tree.root;*/
/*	while(atual != NULL || topo > 0){		*/
/*		if (atual != NULL){*/
/*			pilha[topo++] = atual;*/

/*			atual = atual->left;*/
/*		}else{*/
/*			*/
/*			atual = pilha[--topo];*/
/*			*/
/*		    c = rbtree_container_of(atual, Conjunto, node);*/
/*		    */
/*			if (n > c->n){			*/
/*				if (contemSubConj(vet,n,c->valores,c->n)){*/
/*					imprimeVetor(c->valores,c->n);*/
/*					strcpy(saida, "0\n");*/
/*				}*/
/*			}*/
/*			atual = atual->right;*/
/*		}*/
/*	}*/
/*	printf("%s",saida);*/
/*}*/




// operação '>'
/*
Esta operação deve listar todos os conjuntos da coleção que são superconjuntos próprios do conjunto envolvido na operação.
*/      
void imprimeSuperConj(int n, int* vet){
	char saida[] = "E\n0\n";
	struct rbtree_node *nodo;
    Conjunto *c;
    nodo = rbtree_first(&tree);
    while (nodo) {
        c = rbtree_container_of(nodo, Conjunto, node);
		if (n < c->n){
			if (contemSubConj(c->valores,c->n,vet,n)){
				imprimeVetor(c->valores,c->n);
				strcpy(saida, "0\n");
			}
		}
        nodo = rbtree_next(nodo);
    }
    printf("%s",saida);
}


/*void imprimeSuperConj(int n, int* vet){*/
/*	Conjunto *c;*/
/*	struct rbtree_node *atual, *pilha[1000];*/
/*	int topo = 0;*/
/*	char saida[] = "E\n0\n";*/
/*	atual = tree.root;*/
/*	while(atual != NULL || topo > 0){		*/
/*		if (atual != NULL){*/
/*			pilha[topo++] = atual;*/

/*			atual = atual->left;*/
/*		}else{*/
/*			*/
/*			atual = pilha[--topo];*/
/*			*/
/*			c = rbtree_container_of(atual, Conjunto, node);*/
/*			if (n < c->n){*/
/*				if (contemSubConj(c->valores,c->n,vet,n)){*/
/*					imprimeVetor(c->valores,c->n);*/
/*					strcpy(saida, "0\n");*/
/*				}*/
/*			}*/
/*			*/
/*			atual = atual->right;*/
/*		}*/
/*	}*/
/*	printf("%s",saida);*/
/*}*/


// operação '/'
/*Esta operação deve remover da coleção todos os conjuntos que 
são superconjuntos próprios do conjunto envolvido na operação. */
void removeSuperConj(int n, int* vet){
	char saida[] = "E\n0\n";
	struct rbtree_node *nodo;
    Conjunto *c;
    nodo = rbtree_first(&tree);
    while (nodo) {
        c = rbtree_container_of(nodo, Conjunto, node);
		if (n > c->n){
			if (contemSubConj(c->valores,c->n,vet,n)){
				struct rbtree_node *no = nodo;
				nodo = rbtree_next (nodo);
				rbtree_remove (no, &tree);
				free (c);
				strcpy(saida, "0\n");
			}else
				nodo = rbtree_next(nodo);
		}else
        	nodo = rbtree_next(nodo);
    }
    printf("%s",saida);
}

/*void removeSuperConj(int n, int* vet){*/
/*	Conjunto *c;*/
/*	struct rbtree_node *atual, *pilha[1000];*/
/*	int topo = 0;*/
/*	char saida[] = "E\n0\n";*/
/*	atual = tree.root;*/
/*	while(atual != NULL || topo > 0){		*/
/*		if (atual != NULL){*/
/*			pilha[topo++] = atual;*/

/*			atual = atual->left;*/
/*		}else{			*/
/*			atual = pilha[--topo];*/
/*			*/
/*			c = rbtree_container_of(atual, Conjunto, node);*/
/*			if (n > c->n){*/
/*				if (contemSubConj(c->valores,c->n,vet,n)){*/
/*					rbtree_remove (atual, &tree);*/
/*					free (c);*/
/*					strcpy(saida, "0\n");*/
/*				}*/
/*			}*/
/*			*/
/*			atual = atual->right;*/
/*		}*/
/*	}*/
/*	printf("%s",saida);*/
/*}*/

