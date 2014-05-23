#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto {
  int tamanho;
  int valores[];
}conjunto;

typedef struct no {
  struct conjunto *conj;
  struct no *esq;
  struct no *dir;
}no;

typedef struct arvore {
  int tamanhoarvore;
  struct no *nodos[];
}arvore;

void insereConjunto(struct arvore *t, struct no *vertice) {

    //TODO - Incrementa a árvore
    int tamarv;
    t->tamanhoarvore++;
    tamarv = t->tamanhoarvore;
    t->nodos[tamarv-1] = vertice;
    printf("%d\n", t->tamanhoarvore);
}

void defineOperacao(char op, struct arvore *t, struct no *vertice) {
    if (op != '0') {
        switch (op){
            case '+':
                insereConjunto(t, vertice);
                break;
        }
    }
}

void leArquivo() {
    FILE *arquivo;
    arquivo = fopen("arq_com_as_operacoes.txt", "r");

    //armazena a operação, +, -, * etc
    char operacao = 'a';

    //tamanho do conjunto, vai ser obtido do arquivo
    int n = 0;

    //para controlar a saída do laço
    char c = 1;

    //para iterar no for
    int i;

    //vetor com os valores
    int chave[n];

    //inteiro k, que possui o primeiro inteiro do arquivo
    int k;

    //define um conjunto e aloca memória
    struct conjunto *cj;
    cj = (struct conjunto *) malloc(sizeof(struct conjunto));

    //define um nó de aloca memória
    struct no *nodo;
    nodo = (struct no *) malloc(sizeof(struct no));

    //define a árvore vazia do programa
    struct arvore *arv;
    arv = (struct arvore *) malloc(sizeof(struct arvore));
    arv->tamanhoarvore = 0;

    fscanf(arquivo, "%d\n", &k);

    //laço para ler o arquivo
    while (c != 0 ) {
        fscanf(arquivo, "%c %d\n", &operacao, &n);
        //printf("%c\n", operacao);
        for(i = 0; i < n; i++) {
            fscanf(arquivo, "%d\n", &chave[i]);
        }

        //Seta os valores do novo conjunto lido do arquivo
        cj->tamanho = n;
        for(i = 0; i < n; i++) {
            cj->valores[i] = chave[i];
        }

        //Seta os valores do novo nó
        nodo->conj = cj;
        nodo->esq = NULL;
        nodo->dir = NULL;

        //chama a função que irá realizar o switch
        defineOperacao(operacao, arv, nodo);

        if (operacao == '0') {
            break;
        }
        //printf("%d\n", n);
        //printf("Fim da Linha!\n");
    }
    /*printf("\nValores:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", chave[i]);
    }
    printf("%d", k);*/
    fclose(arquivo);
}

void escreveArquivo(){

}

int main()
{
    printf("Hello world!\n");
    leArquivo();
    return 0;
}
