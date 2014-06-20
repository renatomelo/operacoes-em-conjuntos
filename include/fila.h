#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// Uma estrutura para representar a fila
typedef struct filaa {
    int frente, calda, tamanho;
    unsigned capacidade;
    int *vetor;
} Fila;

Fila *criarFila(unsigned capacidade);

//Retorna se a fila está cheia ou não
int estaCheia(Fila* fila);

//Retorna se a fila está vazia ou não
int estaVazia(Fila* fila);

//Insere um elemento no final da fila, sem prioridade. 
void enfileirar(Fila* fila, int item);

//Encontra o lugar mais adequado para o elemento dado
void check(Fila *fila, int item);

//Função que insere um elemento com prioridade
void inserirComPrioridade(Fila *fila, int item);

//Remove o elemeto na frente da fila
int desenfileirar(Fila* fila);
 
// Função que devolve o elemento que está na frente da fila
int frente(Fila* fila);

// Função que devolve a calda da fila
int calda(Fila* fila);



