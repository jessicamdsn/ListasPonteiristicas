/****************************************************************** 
 * Nome: Lista com vetores                                        *
 * Descricao: Implementacao de fila com uso de vetores (array).  *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar lista,                                        *
 *            enqueue,                                            *
 *            dequeue.                                            *
 * Autores:                                                       *
 * Jessica Maria de Souza Neves                                   *
 * Pedro Henrique de Araujo Santos                                *
 * Ultima alteracao: 19/05/2024                                   *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

typedef struct{
    char titulo[50];
    char genero[30];
    char classificacao[8];
    int duracao;
    double valor_aluguel;
    int disponibilidade;
} Filme;

typedef struct{
    int inicio;
    int fim;
    Filme *filmes;
} Fila;

Fila* criarFila(){
    Fila *nova = (Fila*)malloc(sizeof(Fila));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    
    nova->inicio = 0;
    nova->fim = 0;
    nova->filmes = (Filme*)malloc(TAM * sizeof(Filme));
    
    if(nova->filmes == NULL){
        printf("Nao tem espaco\n");
        free(nova);
        return NULL;
    }
    return nova;
}

int enqueue(Fila *fila, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){
    if(fila == NULL){
        printf("A fila nao foi criada\n");
        return 0;
    }
    
    if((fila->fim + 1) % TAM != fila->inicio){
        strcpy(fila->filmes[fila->fim].titulo, titulo);
        strcpy(fila->filmes[fila->fim].genero, genero);
        strcpy(fila->filmes[fila->fim].classificacao, classificacao);
        fila->filmes[fila->fim].duracao = duracao;
        fila->filmes[fila->fim].valor_aluguel = valor_aluguel;
        fila->filmes[fila->fim].disponibilidade = disponibilidade;
        fila->fim = (fila->fim + 1) % TAM;
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }
}

Filme dequeue(Fila *fila){
    Filme valor;
    strcpy(valor.titulo,"erro");
    
    if(fila == NULL){
        printf("A fila nao foi criada\n");
        return valor;
    }
    
    if(((fila->inicio + 1) % TAM) == fila->fim){
        valor = fila->filmes[fila->inicio];
        fila->inicio = (fila->inicio + 1) % TAM;
        return valor;
    }
    
    if(((fila->inicio + 1) % TAM) != fila->fim){
        valor = fila->filmes[fila->inicio];
        fila->inicio = (fila->inicio + 1) % TAM;
        return valor;
    }
    return valor;
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
    printf("O que voce quer fazer? \n1.Inserir filme na fila \n2.Remover filme da fila\n");
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
        break;
        case 2:
           elemento=dequeue(fila);
           printf("titulo removido: %s\n",elemento.titulo);
        break;
        
        default:
        printf("Essa opcao nao existe!\n");
        break;
    }
}
    

    return 0;
}
