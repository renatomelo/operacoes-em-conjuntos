#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

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

// É válido se não existe valor maior que k no conjunto
bool ehValido(int k, int n, int vet[]){
	if (buscaBinaria(k,n,vet)) //Esta função está no arquivo op_vetor.c
		return false;
	if (igualdade(n,vet))
		return false;
	return true;	
}
			
//Arvore binária de buca
arvore *raiz = NULL;
	
bool igualdade(int n,int vet[]){
	no *result = busca(raiz, n);
	if (result != NULL)
	{
		int i;
		for (i = 0; i < n; i += 1)
		{
			//printf("%d ",result)
			if (vet[i] != result->elementos[i])
				return false;
		}
		return true;
	}
	return false;
}

/*void exibirTodos(arvore *raiz){*/
/*		int i, nodos[];*/
/*		for (i = 0; i < raiz->chave; i += 1)*/
/*		{*/
/*			nodos[i]	*/
/*		}*/
/*		printf("\n");	*/
/*}*/

int main (int argc, char *argv[])
{
	char fimdalinha;
	char op='1'; // Inicia com um falor qualquer
	int i, max, n=0;
	int vet[n];
	
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
				if(ehValido(max, n, vet)){
					no *conjunto = cria_novo_no(n,vet);
					raiz = inserir(raiz, conjunto);
					printf("\t\t\t\tInserido\n");
				}else
					printf("\t\t\t\tConjunto inváldo.\n\n");
				break; 
			case '-': 				
				if(igualdade(n,vet)){
					raiz = remover_rec(raiz,n);
					printf("\t\t\t\tRemovido\n");
				}else
					printf("\t\t\t\tEste conj. não existe.\n");				
				break;
			case '=': 
				//printf("\t\tIgualdade\n");
				if(igualdade(n,vet))
					printf("\t\tEste conj. existe no superconjunto.\n");
				else
					printf("\t\t\t\tEste conj. não existe.\n");
				break;
			case '*': 
				printf("Exibindo..\n");
				atravassarEmOrdem(raiz);
				break;
			default: 
				printf("\t\t\t\tOperação invalida.\n");
				break;
		}
	}	
	return 0;
} 
