#include <stdio.h>
#include <stdlib.h>
//#include "op_vetor.h"

#define true 1 // para usar como tipo booleano
#define false 0
/*
	Programa que realiza as funcionalidades básicas do trabalho, tais como: reconhecer cada operação, validação das entradas e armazenamento dos dados em vetor.
	Utilizei entrada e saida padrão (scanf e printf);
	Isso obedece a regra da especificação, pode ser redirecionado de um arquivo e para um arquivo como pede no trabalho;
	Até o momento os printfs presentes no código são só para fim de log
	Ainda não são as saídas processadas.
*/
typedef int bool; //Definição do tipo booleano

// É válido se não existe valor maior que k no conjunto
bool ehValido(int k, int n, int vet[]){
	if (buscaBinaria(k,n,vet))
		return true;
	return false;	
}

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
			
		scanf("%d",&n);
		
		printf("%c ", op);
		printf("%d ", n);		

		for(i=0;i < n;i++)
			scanf("%d",&vet[i]);			
			
		//Lê o enter e vai para a proxima linha
		scanf("%c",&fimdalinha); 
		
		for (i = 0; i < n; i += 1)
			printf("%d ", vet[i]);
		
		switch(op){
			case '+':
				if(ehValido(max, n, vet))
					printf("\t\tInserir\n");
				else
					printf("\t\tConjunto inváldo.\n\n");
				break; 
			case '-': 
				printf("\t\tRemover\n");
				break;
			case '=': 
				printf("\t\tIgualdade\n");
				break;
			case '*': 
				printf("\t\tExibir\n");
				break;
			default: 
				printf("\t\tOperação invalida\n");
				break;
		}
	}	
	return 0;
} 
