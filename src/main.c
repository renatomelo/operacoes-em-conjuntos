#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "op_vetor.h"
#include "operacoes.h"


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

Arvore *raiz = NULL; //Arvore binária de buca

// É válido se não existe valor maior que k no conjunto
bool ehValido(int k, int n, int vet[]){
	//Esta função está no arquivo op_vetor.c
	if (buscaBinaria(k,n,vet)) 
		return false;
	return true;	
}

//Verifica se dado conjunto já foi inserido no superconjunto
//Recebe um valor n, e um vetor, incapsula em um nó e então
// faz uma busca na árvore, devolve verdadeiro se existe.
bool existe(int n,int vet[]){
	No *conjunto = cria_novo_no(n,vet);
	if (buscaNo(raiz, conjunto))
		return true;
	else
		return false;
}
/**
Aqui a acontece a leitura das entrada, a primeira linha é um 
valor max, que é o maior elemento que pode existir nos conjuntos.
Uma operação (+,-,=,*), um valor n, que será o tamanho dos conjuntos
e os elementos do conjunto. 
*/
int main (int argc, char *argv[])
{
	char fimdalinha;
	char op='1'; // Inicia com um falor qualquer
	int i, max, n=0;
	int nConjuntos = 0;
	
	scanf("%d",&max); //Lê o primeiro argumento da entrada
	int vet[max];
	
	//Lê o enter e vai para a proxima linha
	scanf("%c",&fimdalinha);
		
	while (op){
		//Lê a operação		
		scanf("%c",&op);
		//Sai do laço se chegar ao fim do arquivo
		if (op == '0'){
			printf("Fim do arquivo.\n");
			break;
		}
		//Se a operação não é * lê o restante dos argumentos
		//caso contrario desconsidera o restante da linha
		if (op != '*'){
			scanf("%d",&n);

		
			//Mostra os valores que foram lidos
			printf("%c ", op);		
			printf("%d ", n);
			
			//Lê os elementos do conjunto e insere em um vetor
			for(i=0;i < n;i++)
				scanf("%d",&vet[i]);			
			
			//Lê o enter e vai para a proxima linha
			scanf("%c",&fimdalinha); 
		
			//Exibe o conteudo do vetor
/*			for (i = 0; i < n; i += 1)*/
/*				printf("%d ", vet[i]);*/
		}else			
			scanf("%c",&fimdalinha);
		
		switch(op){
			case '+'://Operação de inserção	
				//Validação	
				if(ehValido(max,n,vet)){
					//incapsula o vetor e o tamanho em um nó  	
					No *conjunto = cria_novo_no(n,vet);
					//Se o conj. já existe na arvore não insere
					if (buscaNo(raiz, conjunto))
						printf("\t\tErro.\n");
					else{
						//caso contrario o conjunto é inseridos
						raiz = insere_rec(raiz, conjunto);
						nConjuntos++;
						printf("\t\tOk!\n");
					}
				}else
					//Se existe no conj elemento maior q max dá erro
					printf("\t\tErro.\n\n");
				break; 
			case '-'://Operação de remoção de um conjunto
				//Sem esse if está dando erro na criação do nó
				if(true){
					//Incapsula os dados em um nó
					No *conjunto = cria_novo_no(n,vet);
					//Verifica se existe esse nó na arvore
					//Se sim, é removido. Se não, dá erro
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
				//Verifica se o conjunto ja existe no superconjunto
				//Se sim, Ok, senão, dá erro.
				if(existe(n,vet))
					printf("\t\tOk!.\n");
				else
					printf("\t\tErro.\n");
				break;
			case '*':
				//Mostra todos os subconjuntos em ordem crescente
				printf("Exibindo todos..\n");
				emOrdem(raiz);
				break;
			case '>':
				//Imprime todos os conj que são superconjuntos
				//do conj envolvido
				printf("\nExibindo..\n");
				imprimeSuperConj(raiz,nConjuntos,n,vet);
				break;
			case '<':
				//Imprime todos os conj que são subconjuntos
				//do conj envolvido
				printf("\nExibindo..\n");
				imprimeSubConj(raiz,nConjuntos,n,vet);
				break;
			default: 
				printf("\t\t\tOperação invalida.\n");
				break;
		}
	}	
	return 0;
} 
