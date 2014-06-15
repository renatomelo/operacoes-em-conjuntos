#include "arvore.h"

/*Adotando a politica de criar o novo nó fora da função de inserção*/
no *cria_novo_no(int chave, int *elementos){
	no *novo;
	novo = malloc(sizeof (no));
	novo->chave = chave;
	novo->elementos = elementos;
	novo->esq = novo->dir = NULL;
}

// A função recebe uma árvore de busca r e uma 
// folha nova que não pertence à árvore.
// A função insere o nó novo na árvore 
// de modo que a árvore continue sendo de busca
// e devolve o endereço da nova árvore.
arvore *inserir(arvore *raiz, no *novo){
	no *atual, *ultimo;
	atual = raiz;
	while (atual != NULL){
		ultimo = atual;
		if (atual->chave > novo->chave)
			atual = atual->esq;
		else
			atual = atual->dir;
	}
	if (raiz == NULL)
		raiz = novo;
	else if (ultimo->chave > novo->chave)
		ultimo->esq = novo;
	else
		ultimo->dir = novo;
	return raiz;
}

/*Inserir recursivamente*/
no *insere_rec(no *r, no * x){
	if (!r)
		return x;
	if(x->chave < r->chave)
		r->esq = insere_rec(r->esq, x);
	else
		r->dir = insere_rec(r->dir, x);
	return r;
}

/*Mostra todos os nodos da árvore em ordem crescente*/
/*void atravassarEmOrdem(arvore *raiz){*/
/*	if (raiz != NULL){		*/
/*		exibir_emordem(raiz->esq);	*/
/*		printf("%d ",raiz->chave);
/*		exibir_emordem(raiz->dir);*/
/*	}*/
/*}*/

Fila *atravassarEmOrdem(arvore *raiz, int nConjuntos){
	Fila *fila = criarFila(nConjuntos);
	no *atual, *pilha[nConjuntos];
	int topo = 0;
	atual = raiz;
	while(atual != NULL || topo > 0){
		if (atual != NULL){
			pilha[topo++] = atual;
			atual = atual->esq;
		}else{
			atual = pilha[--topo];
			//printf("%d\n", atual->chave);
			inserirComPrioridade(fila,atual->chave);
			atual = atual->dir;
		}
	}
	return fila;
}

/*Encontra o menor elemento da arvore*/
no *minimo(arvore *raiz){
	while(raiz->esq != NULL)
		raiz = raiz->esq;
	return raiz;
}

/*Encontra o maior elemento da arvore*/
no *maximo(arvore *raiz){
	while(raiz->dir != NULL)
		raiz = raiz->dir;
	return raiz;
}

//Recebe o endereço de um nó x. Devolve o endereço do nó seguinte na 
//ordem e-r-d. A função supõe que x != NULL.
no *sucessor(arvore *raiz, no *x){
	no *atual, *sucessor;
	if (x->dir != NULL)
		return minimo(x->dir);
	else{
		sucessor = NULL;
		atual = raiz;
		while (atual != x)
		{
			sucessor = atual;
			if (x->chave < atual->chave)
				atual = atual->esq;
			else
				atual = atual->dir;
		}
	}
	return sucessor;
}

no *antecessor(arvore *raiz, no *x){
	no *atual, *antecessor;
	if(x->esq != NULL)
		return maximo(x->esq);
	else{
		antecessor = NULL;
		atual = raiz;
		while (atual != x){
			antecessor = atual;
			if (x->chave < atual->chave)
				atual = atual->esq;
			else
				atual = atual->dir;
		}		
	}
	return antecessor;
}

void remover(arvore *raiz, int x){
	no *atual, *anterior;
	atual = raiz;
	anterior = NULL;
	if(raiz == NULL) printf("Arvore vazia.\n");
		//return NULL
	while (atual != NULL && atual->chave != x)
	{
		if(x < atual->chave){
			//Vai pra esquerda
			anterior = atual;
			atual = atual->esq;		
		}
		else if((x > atual->chave)){
			//vai pra direita
			anterior = atual;
			atual = atual->dir;
		}
	}
	if(atual == NULL)
		printf("\t Não encontrado.\n");
	if (atual->chave == x){
		//printf("Encontrou. LOL\n");
		if (atual->esq == NULL && atual->dir == NULL){
			printf("Não tem filhos. :)\n");
			free(atual);
		}			
		else if(atual->esq == NULL){
			printf("Tem o filho da direita :/\n");
			no *tmp = minimo(atual->dir);
			free(atual);
		}
			
		else if(atual->dir == NULL)
			printf("Tem o filho da esquerda :/\n");
		else
			printf("O fdp tem dois filhos. :(\n");
	}
		
}

arvore *remover_rec(arvore *raiz, int x){
/*	Caso base*/
	if(raiz == NULL) return raiz;
	if(x < raiz->chave)
		raiz->esq = remover_rec(raiz->esq, x);
	else if((x > raiz->chave))
		raiz->dir = remover_rec(raiz->dir, x);
	else{ //Encontrou o nó a ser removido*/
		//Se o nó é uma folha*/
/*		if (raiz->esq == NULL && raiz->dir == NULL){*/
/*			free(raiz);*/
/*			raiz = NULL;*/
/*		}*/
		//Tem apenas um filho direita*/
		if(raiz->esq == NULL){
			no *tmp = raiz->dir;
			free(raiz);
			return tmp;
		}
		//Tem apenas um filho a esquerda*/
		else if (raiz->dir == NULL){
			no *tmp = raiz->esq;
			free(raiz);
			return tmp;
		}
		//Nó tem os dois filhos*/		
		no *tmp = minimo(raiz->dir);
		//Copia o conteudo do sucessor neste nó
		raiz->chave = tmp->chave;
		raiz->elementos = tmp->elementos;
		//Deleta o sucessor
		raiz->dir = remover_rec(raiz->dir, tmp->chave);		
	}
	return raiz;
}

/*Recebe um inteiro x e uma arvore r. Devolve um nó cuja chave é x.*/
/*se tal nó não existe, devolve NULL*/
no *busca(arvore *raiz, int x){
	while(raiz != NULL && raiz->chave != x){
		if (raiz->chave > x)
			raiz = raiz->esq;
		else
			raiz = raiz->dir;
	}
	return raiz;
}


/*int main (int argc, char *argv[]){*/
/*	arvore *raiz = NULL;*/
/*	int v1[] = {1,2,3};*/
/*	int v2[] = {4,5,6,7};*/
/*	int v3[] = {6,7};*/
/*	int v4[] = {4,5,6,7,8};*/
/*	int v5[] = {7};*/

/*	*/
/*	raiz = inserir(raiz,cria_novo_no(3,v1));*/
/*	no *nodo = cria_novo_no(4,v2);*/
/*	raiz = inserir(raiz,nodo);*/
/*	raiz = inserir(raiz,cria_novo_no(1,v5));*/
/*	raiz = inserir(raiz,cria_novo_no(2,v3));*/
/*	//raiz = inserir(raiz,cria_novo_no(5,v4));*/
/*	//raiz = inserir(raiz,cria_novo_no(1,v5));*/
/*	raiz = inserir(raiz,cria_novo_no(5,v4));*/
/*	//raiz = inserir(raiz,cria_novo_no(3,v1));*/
/*	//raiz = inserir(raiz,cria_novo_no(1,v5));*/
/*	exibir_emordem(raiz);*/
/*	printf("\n");*/
/*	no *m = minimo(raiz);*/
/*	printf("Menor elemento da árvore: %d\n",m->chave);*/
/*	m = maximo(raiz);*/
/*	printf("Maior elemento da árvore: %d\n",m->chave);*/
/*	no *suc = sucessor(raiz,nodo);*/
/*	printf("Sucessor de %d: %d\n",nodo->chave,suc->chave);*/
/*	no *ant = antecessor(raiz,nodo);*/
/*	printf("Antecessor de %d: %d\n",nodo->chave,ant->chave);*/
/*	*/
/*	//raiz = remover_rec(raiz,3);*/
/*	//raiz = remover_rec(raiz,1);*/
/*	//raiz = remover_rec(raiz,5);*/
/*	//exibir_emordem(raiz);*/
/*	//printf("\n");*/
/*	no *resultadoBusca = busca(raiz, 4);*/
/*	int i;*/
/*	for (i = 0; i < 4; i += 1)*/
/*	{*/
/*		printf("%d ", resultadoBusca->elementos[i]);*/
/*	}	*/
/*	printf("\n");*/
/*	//remover(raiz,4);*/
/*	return 0;*/
/*}*/
