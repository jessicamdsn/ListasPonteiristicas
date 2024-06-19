/****************************************************************** 
 * Nome: Fila com apontadores                                     *
 * Descricao: Implementacao de fila com uso de apontadores.       *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar lista,                                        *
 *            enqueue,                                            *
 *            dequeue,                                            *
 *            excluir fila.                                       *
 * Autores:                                                       *
 * Jessica Maria de Souza Neves                                   *
 * Pedro Henrique de Araujo Santos                                *
 * Ultima alteracao: 19/05/2024                                   *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct filme{
    char titulo[50];
    char genero[30];
    char classificacao[8];
    int duracao;
    double valor_aluguel;
    int disponibilidade;
    struct filme *prox;
}Filme;

typedef struct fila{
    Filme *inicio;
    Filme *fim;
}Fila;

Fila* criarFila(){
    Fila *nova = (Fila*)malloc(sizeof(Fila));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    
    nova->inicio = NULL;
    nova->fim = NULL;
    
    return nova;
}

int enqueue(Fila *fila, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){
    
    Filme *nova = (Filme*) malloc(sizeof(Filme));
    if(nova == NULL){
        printf("Sem espaco\n");
        return 0;
    }
    
    strcpy(nova->titulo, titulo);
    strcpy(nova->genero, genero);
    strcpy(nova->classificacao, classificacao);
    nova->duracao = duracao;
    nova->valor_aluguel = valor_aluguel;
    nova->disponibilidade = disponibilidade;
    nova->prox = NULL;
    
    if(fila->inicio == NULL){
        fila->inicio = nova;
        fila->fim = nova;
        return 1;
    }
    fila->fim->prox = nova;
    fila->fim = nova;
    return 1;
}

Filme* dequeue(Fila *fila){
    Filme *aux;
    
    if(fila == NULL){
        printf("A fila nao foi criada\n");
        return NULL;
    }
    
    if(fila->inicio == NULL){
        printf("A fila esta vazia\n");
        return NULL;
    }
    
    if(fila->inicio == fila->fim){
        aux = fila->inicio;
        fila->inicio = NULL;
        fila->fim = NULL;
        return aux;
    }
    
    aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    return aux;
}

Fila* excluirFila(Fila* fila){
    Filme *aux;
    
    while(fila->inicio != NULL){
        aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(aux);
    }
    free(fila);
    return NULL;
}

int main() {
    
    char titulo[50];
    char genero[30];
    char classificacao[7];
    char nomeTitulo[50];
    int duracao,disponibilidade, menu;
    double valor_aluguel;
    
    Filme elemento;

    Fila *fila = criarFila();
    
 while(1){
    printf("O que voce quer fazer? \n1.Inserir filme na fila. \n2.Remover filme da fila. \n3.Excluir fila.\n");
    scanf("%d",&menu);
    
    switch(menu){
        case 1:
        printf("Digite os seguintes dados sobre o filme que sera adicionado:\n");
            printf("Nome do filme: ");
            scanf("%s",titulo);
            printf("Genero: ");
            scanf("%s",genero);
            printf("Classificacao: ");
            scanf("%s",classificacao);
            printf("Duracao em minutos: ");
            scanf("%d",&duracao);
            printf("Valor do aluguel por dia: ");
            scanf("%lf",&valor_aluguel);
            printf("disponivel? (0/1): ");
            scanf("%d",&disponibilidade);
             enqueue(fila,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade);
            printf("\n");
        break;
        case 2:
            dequeue(fila);
        break;
        
        case 3:
            excluirFila(fila);
            exit(0);
        break;
        
        default:
        printf("Essa opcao nao existe!\n");
        break;
    }
}
    

    return 0;
}
