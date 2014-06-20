#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "op_vetor.h"

#define true 1 // para usar como tipo booleano
#define false 0
/*
 Programa que realiza as funcionalidades básicas do trabalho,tais como:
reconhecer cada operação, validação das entradas e armazenamento dos dados em vetor.
 Utilizei entrada e saida padrão (scanf e printf);
Isso obedece a regra da especificação, pode ser redirecionado 
de um arquivo e para um arquivo como pede no trabalho;
 Até o momento os printfs presentes no código são só para fim de log.
 Ainda não são as saídas processadas.
*/

typedef int bool; //Definição do tipo booleano

//Arvore binária de buca
Arvore *raiz = NULL;

// É válido se não existe valor maior que k no conjunto
bool ehValido(int k, int n, int vet[]){
	//Esta função está no arquivo op_vetor.c
	if (buscaBinaria(k,n,vet)) 
		return false;
	return true;	
}
	
bool existe(int n,int vet[]){
	No *conjunto = cria_novo_no(n,vet);
	if (buscaNo(raiz, conjunto))
		return true;
	else
		return false;
}

/*void exibirTodos(Arvore *raiz, int nConjuntos){*/
/*	//Fila *fila = atravassarEmOrdem(raiz,nConjuntos);*/
/*	No **vetorNodos = atravassarEmOrdem(raiz, nConjuntos);*/
/*	int i,j;*/
/*/*	while (!estaVazia(fila))*/
/*/*	{   printf("%d Desenfileirado\n", desenfileirar(fila));	}	*/
/*	for (i = 0; i < nConjuntos; i += 1)*/
/*	{		*/
/*		int n = vetorNodos[i]->tam;*/
/*		//int proximo = vetorNodos[i+1]->tam;*/
/*		printf("quem é o i: %d ", i );*/
/*		printf("%d: ", n );*/
/*/*		if(i < nConjuntos -1){	*/
/*/*			printf("IF quem é o i: %d \n", i );		*/
/*/*			if (n == proximo){*/
/*/*			printf("IF quem é o i: %d \n", i );*/
/*/*				int *conjAtual = vetorNodos[i]->elementos;*/
/*/*				int *proxConj = vetorNodos[i+1]->elementos;*/
/*/*				int *menor = menorVetor(conjAtual, proxConj, n);*/
/*/*				int *maior = menorVetor(conjAtual, proxConj, n);*/
/*/*				imprimeVetor(menor,n);*/
/*/*				imprimeVetor(maior,n);*/
/*/*				i++;			*/
/*/*			}else{*/
/*/*				printf("ELSE quem é o i: %d \n", i );*/
/*/*				imprimeVetor(vetorNodos[i]->elementos, n);*/
/*/*			}		*/
/*/*		}else{*/
/*/*			printf("ELSE quem é o i: %d \n", i );*/
/*/*		}*/
/*			imprimeVetor(vetorNodos[i]->elementos, n);*/
/*			printf("FOR quem é o i: %d \n", i );*/
/*	}*/
/*}*/

int main (int argc, char *argv[])
{
	char fimdalinha;
	char op='1'; // Inicia com um falor qualquer
	int i, max, n=0;
	int vet[n];
	int nConjuntos = 0;//numero de conj inseridos no superconjunto
	
	scanf("%d",&max);
	
	//Lê o enter e vai para a proxima linha
	scanf("%c",&fimdalinha);
		
	while (op){				
		scanf("%c",&op);
		//Sai do laço se chegar ao fim do arquivo
		if (op == '0'){
			printf("Fim do arquivo.\n");
			break;
		}
		if (op != '*'){
			scanf("%d",&n);
		
			printf("%c ", op);		
			printf("%d ", n);		

			for(i=0;i < n;i++)
				scanf("%d",&vet[i]);			
			
			//Lê o enter e vai para a proxima linha
			scanf("%c",&fimdalinha); 
		
			//Exibe o conteudo do vetor
			for (i = 0; i < n; i += 1)
				printf("%d ", vet[i]);
		}else			
			scanf("%c",&fimdalinha);
		
		switch(op){
			case '+':			
				if(ehValido(max,n,vet)){		
					No *conjunto = cria_novo_no(n,vet);
					if (buscaNo(raiz, conjunto))
						printf("\t\tErro.\n");
					else{
						raiz = insere_rec(raiz, conjunto);
						nConjuntos++;
						printf("\t\tOk!\n");
					}
				}else
					printf("\t\tConjunto inváldo.\n\n");
				break; 
			case '-':
				if(true){
					No *conjunto = cria_novo_no(n,vet);
					if (buscaNo(raiz, conjunto)){
						raiz = remover_rec(raiz,conjunto);
						nConjuntos--;
						printf("\t\tOk!\n");
					}else{
						printf("\t\tErro.\n");
					}
				}
				break;
			case '=': 
				if(existe(n,vet))
					printf("\t\tOk!.\n");
				else
					printf("\t\tErro.\n");
				break;
			case '*': 
				printf("Exibindo..\n");
				emOrdem(raiz);
				break;
			default: 
				printf("\t\t\tOperação invalida.\n");
				break;
		}
	}	
	return 0;
} 
