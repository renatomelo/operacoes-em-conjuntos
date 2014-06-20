#include "arvore.h" //alterar
#define true 1 // para usar como tipo booleano
#define false 0

typedef int bool; //Definição do tipo booleano

/*Adotando a politica de criar o novo nó fora da função de inserção*/
No *cria_novo_no(int tam, int elem[]){
	int i;
	No *novo;
	novo = malloc(sizeof (No));
	novo->tam = tam;
	novo->elem = (int*) malloc(tam * sizeof(int));
	for (i = 0; i < tam; i += 1)
		novo->elem[i] = elem[i];
	novo->esq = novo->dir = NULL;
}

// A função recebe uma árvore de busca r e uma 
// folha nova que não pertence à árvore.
// A função insere o nó novo na árvore 
// de modo que a árvore continue sendo de busca
// e devolve o endereço da nova árvore.
Arvore *inserir(Arvore *raiz, No *novo){	
	No *atual, *anterior;
	atual = raiz;
	while (atual != NULL){
		anterior = atual;
		if (atual->tam > novo->tam)
			atual = atual->esq;
		else 
			atual = atual->dir;
	}
	if (raiz == NULL)
		return novo;
	else if (anterior->tam > novo->tam)
		anterior->esq = novo;
	else
		anterior->dir = novo;
	return raiz;
}

/*Inserir recursivamente*/
No *insere_rec(No *r, No *x){
	if (!r)
		return x;
	if (r->tam > x->tam){
		r->esq = insere_rec(r->esq, x);
	}		
	else if(r->tam < x->tam){
		r->dir = insere_rec(r->dir, x);
	}else{
		if(ehMenor(x->elem,r->elem,x->tam))
			r->esq = insere_rec(r->esq, x);
		else
			r->dir = insere_rec(r->dir, x);
	}
	return r;
}

/*Mostra todos os nodos da árvore em ordem crescente*/
void emOrdem(Arvore *raiz){
	if (raiz != NULL){		
		emOrdem(raiz->esq);	
		printf("%d: ",raiz->tam);
		imprimeVetor(raiz->elem,raiz->tam);
		emOrdem(raiz->dir);
	}
}

/*No **atravassarEmOrdem(Arvore *raiz, int nConjuntos){*/
/*	//Fila *fila = criarFila(nConjuntos);*/
/*	No *vetorNodos[nConjuntos];*/
/*	No *atual, *pilha[nConjuntos];*/
/*	int nElem=0;*/
/*	int topo = 0;*/
/*	atual = raiz;*/
/*	while(atual != NULL || topo > 0){*/
/*		if (atual != NULL){*/
/*			pilha[topo++] = atual;*/
/*			atual = atual->esq;*/
/*		}else{*/
/*			atual = pilha[--topo];*/
/*			//inserirComPrioridade(fila,atual->elem);*/
/*			vetorNodos[nElementos++] = atual;*/
/*			atual = atual->dir;*/
/*		}*/
/*	}*/
/*	return vetorNodos;*/
/*}*/

/*Encontra o menor elemento da arvore*/
No *minimo(Arvore *raiz){
	while(raiz->esq != NULL)
		raiz = raiz->esq;
	return raiz;
}

/*Encontra o maior elemento da arvore*/
No *maximo(Arvore *raiz){
	while(raiz->dir != NULL)
		raiz = raiz->dir;
	return raiz;
}

//Recebe o endereço de um nó x. Devolve o endereço do nó seguinte na 
//ordem e-r-d. A função supõe que x != NULL.
No *sucessor(Arvore *raiz, No *x){
	No *atual, *sucessor;
	if (x->dir != NULL)
		return minimo(x->dir);
	else{
		sucessor = NULL;
		atual = raiz;
		while (atual != x)
		{
			sucessor = atual;
			if (x->tam < atual->tam)
				atual = atual->esq;
			else
				atual = atual->dir;
		}
	}
	return sucessor;
}

No *antecessor(Arvore *raiz, No *x){
	No *atual, *antecessor;
	if(x->esq != NULL)
		return maximo(x->esq);
	else{
		antecessor = NULL;
		atual = raiz;
		while (atual != x){
			antecessor = atual;
			if (x->tam < atual->tam)
				atual = atual->esq;
			else
				atual = atual->dir;
		}		
	}
	return antecessor;
}

void remover(Arvore *raiz, int x){
	No *atual, *anterior;
	atual = raiz;
	anterior = NULL;
	if(raiz == NULL) printf("Arvore vazia.\n");
		//return NULL
	while (atual != NULL && atual->tam != x)
	{
		if(x < atual->tam){
			//Vai pra esquerda
			anterior = atual;
			atual = atual->esq;		
		}
		else if((x > atual->tam)){
			//vai pra direita
			anterior = atual;
			atual = atual->dir;
		}
	}
	if(atual == NULL)
		printf("\t Não encontrado.\n");
	if (atual->tam == x){
		//printf("Encontrou. LOL\n");
		if (atual->esq == NULL && atual->dir == NULL){
			printf("Não tem filhos. :)\n");
			free(atual);
		}			
		else if(atual->esq == NULL){
			printf("Tem o filho da direita :/\n");
			No *tmp = minimo(atual->dir);
			free(atual);
		}
			
		else if(atual->dir == NULL)
			printf("Tem o filho da esquerda :/\n");
		else
			printf("O fdp tem dois filhos. :(\n");
	}
		
}

Arvore *remover_rec(Arvore *raiz, No *x){
	/*	Caso base*/
	if(raiz == NULL) return raiz;
	if(x->tam < raiz->tam)
		raiz->esq = remover_rec(raiz->esq, x);
	else if((x->tam > raiz->tam))
		raiz->dir = remover_rec(raiz->dir, x);
	else{ 
		//Encontrou o nó a ser removido*/
		if(saoIguais(raiz->elem,x->elem,x->tam)){
			//Tem apenas um filho direita*/
			if(raiz->esq == NULL){
				No *tmp = raiz->dir;
				free(raiz);
				return tmp;
			}
			//Tem apenas um filho a esquerda*/
			else if (raiz->dir == NULL){
				No *tmp = raiz->esq;
				free(raiz);
				return tmp;
			}
			//Nó tem os dois filhos*/		
			No *tmp = minimo(raiz->dir);
			//Copia o conteudo do sucessor neste nó
			raiz->tam = tmp->tam;
			int i;
			for (i = 0; i < tmp->tam; i += 1)
				raiz->elem[i] = tmp->elem[i];
			//Deleta o sucessor
			raiz->dir = remover_rec(raiz->dir, tmp);
		}else{
			if(ehMenor(x->elem,raiz->elem,x->tam)==1){
				raiz->esq = remover_rec(raiz->esq,x);				
			}else{
				raiz->dir = remover_rec(raiz->dir,x);
			}
		}		
	}
	return raiz;
}

/*Recebe um inteiro x e uma arvore r. Devolve um nó cujo tamanho é x.*/
/*se tal nó não existe, devolve NULL*/
No *busca(Arvore *raiz, int x){
	while(raiz != NULL && raiz->tam != x){
		if (raiz->tam > x)
			raiz = raiz->esq;
		else
			raiz = raiz->dir;
	}
	return raiz;
}

//Devolve verdade se o nó existe na arvore
bool buscaNo(Arvore *raiz, No *x){
	while(raiz != NULL){
		if (raiz->tam > x->tam)
			raiz = raiz->esq;
		else if (raiz->tam < x->tam)
			raiz = raiz->dir;
		else{
			if(saoIguais(raiz->elem,x->elem,x->tam))
				return true;
			else{
				if(ehMenor(x->elem,raiz->elem,x->tam)==1){
					raiz = raiz->esq;					
				}					
				else{
					raiz = raiz->dir;
				}
			}
		}			
	}
	return false;
}



/*int main (int argc, char *argv[]){*/
/*	Arvore *raiz = NULL;*/
/*	int v1[] = {1,2,3};*/
/*	int v2[] = {4,5,6,7};*/
/*	int v3[] = {6,7};*/
/*	int v4[] = {4,5,6,7,8};*/
/*	int v5[] = {7};*/

/*	*/
/*	raiz = insere_rec(raiz,cria_novo_no(3,v1));*/
/*	No *nodo = cria_novo_no(4,v2);*/
/*	raiz = insere_rec(raiz,nodo);*/
/*	raiz = insere_rec(raiz,cria_novo_no(1,v5));*/
/*	raiz = insere_rec(raiz,cria_novo_no(2,v3));*/
/*	//raiz = inserir(raiz,cria_novo_no(5,v4));*/
/*	//raiz = inserir(raiz,cria_novo_no(1,v5));*/
/*	raiz = insere_rec(raiz,cria_novo_no(5,v4));*/
/*	//raiz = inserir(raiz,cria_novo_no(3,v1));*/
/*	//raiz = inserir(raiz,cria_novo_no(1,v5));*/
/*	emOrdem(raiz);*/
/*	printf("\n");*/
/*/*	no *m = minimo(raiz);*/
/*/*	printf("Menor elemento da árvore: %d\n",m->chave);*/
/*/*	m = maximo(raiz);*/
/*/*	printf("Maior elemento da árvore: %d\n",m->chave);*/
/*/*	no *suc = sucessor(raiz,nodo);*/
/*/*	printf("Sucessor de %d: %d\n",nodo->chave,suc->chave);*/
/*/*	no *ant = antecessor(raiz,nodo);*/
/*/*	printf("Antecessor de %d: %d\n",nodo->chave,ant->chave);*/
/*	*/
/*	//raiz = remover_rec(raiz,3);*/
/*	//raiz = remover_rec(raiz,1);*/
/*	//raiz = remover_rec(raiz,5);*/
/*	//exibir_emordem(raiz);*/
/*	//printf("\n");*/
/*/*	no *resultadoBusca = busca(raiz, 4);*/
/*/*	int i;*/
/*/*	for (i = 0; i < 4; i += 1)*/
/*/*	{*/
/*/*		printf("%d ", resultadoBusca->elem[i]);*/
/*/*	}	*/
/*	printf("\n");*/
/*	//remover(raiz,4);*/
/*	return 0;*/
/*}*/
