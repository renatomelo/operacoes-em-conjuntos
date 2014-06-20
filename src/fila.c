#include "fila.h"
 
Fila* criarFila(unsigned capacidade)
{
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->frente = fila->tamanho = 0;
    fila->calda = capacidade - 1;  
    fila->vetor = (int*) malloc(fila->capacidade * sizeof(int));
    return fila;
}
//Retorna se a fila está cheia ou não
int estaCheia(Fila* fila)
{  return (fila->tamanho == fila->capacidade);  }

//Retorna se a fila está vazia ou não
int estaVazia(Fila* fila)
{  return (fila->tamanho == 0); }

//Insere um elemento no final da fila, sem prioridade. 
void enfileirar(Fila* fila, int item)
{
    if (estaCheia(fila))
        return;
    fila->calda = (fila->calda + 1) % fila->capacidade;
    fila->vetor[fila->calda] = item;
    fila->tamanho = fila->tamanho + 1;
    printf("%d Emfileirado\n", item);
}

//Encontra o lugar mais adequado para o elemento dado pela chave
void check(Fila *fila, int item){
	int i,j,n;
	n = fila->tamanho;
	for (i = 0; i < n; i++){
		if (item <= fila->vetor[i]){
			for (j = n + 1; j > i; j--){
				fila->vetor[j] = fila->vetor[j - 1];
			}
            fila->vetor[i] = item;
            return;
		}
	}
	fila->vetor[i] = item;
}

//Função que insere um elemento com prioridade
void inserirComPrioridade(Fila *fila, int item){
	if (estaCheia(fila))
        return;
	check(fila, item);
	printf("%d Emfileirado\n", item);
	fila->tamanho = fila->tamanho + 1;	
}

//Remove o elemeto na frente da fila
int desenfileirar(Fila* fila)
{
    if (estaVazia(fila)){
    	printf("Impossivel remover. fila vazia.\n");
    	return ;
    }        
    int item = fila->vetor[fila->frente];
    fila->frente = (fila->frente + 1) % fila->capacidade;
    fila->tamanho = fila->tamanho - 1;
    return item;
}
 
// Função que devolve o elemento que está na frente da fila
int frente(Fila* fila)
{
    if (estaVazia(fila)){
    	printf("Fila Vazia. Não tem frente.");
    	return -1;
    }        
    return fila->vetor[fila->frente];
}
 
// Função que devolve a calda da fila
int calda(Fila* fila)
{
    if (estaVazia(fila)){
    	printf("Fila Vazia. Não tem calda.");
    	return -1;
    }
    return fila->vetor[fila->calda];
}

//Teste das funções acima 
/*int main()*/
/*{*/
/*    Fila* fila = criarFila(1000);*/
/* */
/*/*    enfileirar(fila, 10);*/
/*/*    enfileirar(fila, 20);*/
/*/*    enfileirar(fila, 30);*/
/*/*    enfileirar(fila, 40);*/
/*/*    enfileirar(fila, 90);*/
/*/*    enfileirar(fila, 70);*/
/*/*    enfileirar(fila, 50);*/
/*    inserirComPrioridade(fila, 10);*/
/*    inserirComPrioridade(fila, 20);*/
/*    inserirComPrioridade(fila, 30);*/
/*    inserirComPrioridade(fila, 40);*/
/*    inserirComPrioridade(fila, 80);*/
/*    inserirComPrioridade(fila, 70);*/
/*    inserirComPrioridade(fila, 50);*/
/*	*/
/*	while (!estaVazia(fila))*/
/*	{   printf("%d Desenfileirado\n", desenfileirar(fila));	}*/

/* */
/*    printf("O item da frente é: %d\n", frente(fila));*/
/*    printf("O item da calda é: %d\n", calda(fila));*/
/* */
/*    return 0;*/
/*}*/
