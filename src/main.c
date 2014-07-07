#include <stdio.h>
#include <stdlib.h>
#include "operacoes_rb.h"

/*
 Utilizei entrada e saida padrão (scanf e printf);
Isso obedece a regra da especificação, pode ser redirecionado 
de um arquivo e para um arquivo como pede no trabalho;
*/

/**
Leitura das entradas, a primeira linha é um valor max,  que é o
 maior elemento que pode existir nos conjuntos. Uma operação
 (+,-,=,*), um valor n, que será o tamanho dos conjuntos
e os elementos do conjunto. 
*/
int main (void)
{
	iniciar_colecao();
	//Variavel para receber o retorno do scanf
    int unused;
    
	char fimdalinha;
	char op='1'; // Inicia com um falor qualquer
	int i, k, n=0;
	int *vet;
	
	unused = scanf("%d",&k); //Lê o primeiro argumento da entrada
		

	//Lê o enter e vai para a proxima linha
	unused = scanf("%c",&fimdalinha);
		
	while (scanf("%c",&op)){
		//Lê a operação		
		
		//Sai do laço se chegar ao fim do arquivo
		if (op == '0')
			break;
			
		//Se a operação não é * lê o restante dos argumentos
		//caso contrario despresa o restante da linha
		if (op != '*'){
			//unused = scanf("%d",&n);
			
			//Lê os elementos do conjunto e insere em um vetor
			if(scanf("%d",&n)){
			vet = (int*) malloc(n * sizeof(int));
				for(i=0;i < n;i++)
					if(!scanf("%d",&vet[i]))
						printf("E\n0\n");
			}
			//Lê o enter e vai para a proxima linha
			unused = scanf("%c",&fimdalinha);		
		}else			
			unused = scanf("%c",&fimdalinha);

		switch(op){
			case '+'://Operação de inserção	
				add(n,vet);
				break; 
			case '-'://Operação de remoção de um conjunto
				del(n,vet);
				break;
			case '=':
				igualdade(n,vet);
				break;
			case '*':
				//Mostra todos os subconjuntos em ordem crescente
				exibir();
				break;
			case '>':
				//Imprime todos os conj que são superconjuntos
				//do conj envolvido
				imprimeSuperConj(n,vet);
				break;
			case '<':
				//Imprime todos os conj que são subconjuntos
				//do conj envolvido
				imprimeSubConj(n,vet);
				break;
			case '/':
				//Remove todos os conj que são subconjuntos
				//do conj envolvido
				removeSuperConj(n,vet);
				break;
			default: 
				printf("\t\t\tOperação invalida.\n");
				break;
		}
	}	
	return 0;
} 
