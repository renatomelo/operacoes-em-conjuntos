#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libtree.h"
#include "op_vetor.h"

typedef struct conjunto {
        int n;
        int *valores;
        struct splaytree_node node;
} Conjunto;

//Cria uma arvore rubro negra
struct splaytree tree;

Conjunto *criar_conjunto(int n, int *valores)
{
	int i;
	Conjunto* novo = (Conjunto*) malloc(sizeof (Conjunto));	
	novo->valores = (int*) malloc(n * sizeof(int));			
	for (i = 0; i < n; i++){
		novo->valores[i] = valores[i];
	}
	novo->n = n;	
}

//Compara os conjuntos, retorna zero se for igual ou a difença do 
//nó a com b
int comparacao(const struct splaytree_node *a, const struct splaytree_node *b)
{
        Conjunto *p = splaytree_container_of(a, Conjunto, node);
        Conjunto *q = splaytree_container_of(b, Conjunto, node);                
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
	splaytree_init(&tree, comparacao, 0);
}

//Insere um conjunto na coleção
void add(int n, int *vet){

	Conjunto *conj = criar_conjunto(n,vet);
	if(!splaytree_insert((struct splaytree_node *) &conj->node, &tree))
		printf("0\n");
	else
		printf("E\n0\n");	
}

void del(int n, int *vet){
	Conjunto *conj = criar_conjunto(n,vet);
	  
	Conjunto *c;
	struct splaytree_node *nodo;
	nodo = splaytree_lookup ((struct splaytree_node *) &conj->node, &tree);
	if (nodo != NULL) {
		c = splaytree_container_of(nodo, Conjunto, node);
		splaytree_remove (&c->node, &tree);
		free (c);
		printf("0\n");
	}else
		printf("E\n0\n");		
}

//=
void igualdade(int n, int *vet){
	Conjunto *conj = criar_conjunto(n,vet);
	
	struct splaytree_node *result;
	result = splaytree_lookup ((struct splaytree_node *) &conj->node, &tree);
	if (result != NULL)
		printf("0\n");
	else
		printf("E\n0\n");
}

//'*'
void exibir(){
    struct splaytree_node *nodo;
    Conjunto *c;
    nodo = splaytree_first(&tree);
    while (nodo) {
        c = splaytree_container_of(nodo, Conjunto, node);
		imprimeVetor(c->valores,c->n);
        nodo = splaytree_next(nodo);
    }
    printf("0\n");
}

/* operação '<'
Esta operação deve listar todos os conjuntos da coleção que são
subconjuntos próprios do conjunto envolvido na operação
*/
void imprimeSubConj(int n, int* vet){
	char saida[] = "E\n0\n";
	struct splaytree_node *nodo;
    Conjunto *c;
    nodo = splaytree_first(&tree);
    int cont=0;
    while (nodo) {
        c = splaytree_container_of(nodo, Conjunto, node);
        
		if (n > c->n){
			cont++;
			
			if (contemSubConj(vet,n,c->valores,c->n)){
				imprimeVetor(c->valores,c->n);
				strcpy(saida, "0\n");
			}
		}
		
        nodo = splaytree_next(nodo);
    }
    printf("%s",saida);
}

// operação '>'
/*
Esta operação deve listar todos os conjuntos da coleção que são superconjuntos próprios do conjunto envolvido na operação.
*/      
void imprimeSuperConj(int n, int* vet){
	char saida[] = "E\n0\n";
	struct splaytree_node *nodo;
    Conjunto *c;
    nodo = splaytree_first(&tree);
    while (nodo) {
        c = splaytree_container_of(nodo, Conjunto, node);
		if (n < c->n){
			if (contemSubConj(c->valores,c->n,vet,n)){
				imprimeVetor(c->valores,c->n);
				strcpy(saida, "0\n");
			}
		}
        nodo = splaytree_next(nodo);
    }
    printf("%s",saida);
}

// operação '/'
/*Esta operação deve remover da coleção todos os conjuntos que 
são superconjuntos próprios do conjunto envolvido na operação. */
void removeSuperConj(int n, int* vet){
	char saida[] = "E\n0\n";
	struct splaytree_node *nodo;
    Conjunto *c;
    nodo = splaytree_first(&tree);
    while (nodo) {
        c = splaytree_container_of(nodo, Conjunto, node);
		if (n > c->n){
			if (contemSubConj(c->valores,c->n,vet,n)){
				struct splaytree_node *no = nodo;
				nodo = splaytree_next (nodo);
				splaytree_remove (no, &tree);
				free (c);
				strcpy(saida, "0\n");
			}else
				nodo = splaytree_next(nodo);
		}else
        	nodo = splaytree_next(nodo);
    }
    printf("%s",saida);
}
