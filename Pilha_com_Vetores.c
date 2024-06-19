/****************************************************************** 
 * Nome: Pilha com vetores                                        *
 * Descricao: Implementacao de Pilha com uso de vetores (array).  *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar pilha,                                        *
 *            pop,                                                *
 *            push,                                               *
 *            excluir pilha.                                      *
 * Autores:                                                       *
 * Jessica Maria de Souza Neves                                   *
 * Pedro Henrique de Araujo Santos                                *
 * Ultima alteracao: 17/04/2024                                   *
 ******************************************************************/

/*Include das bibliotecas*/ 
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

typedef struct{
    int topo;
    Filme *filmes;
} Pilha;






Pilha* criarPilha(){
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }

    /*Preparando os dados iniciais da lista*/
    nova->topo = 0; 
    nova->filmes = (Filme*)malloc(TAM*sizeof(Filme));
    
    /*Verificando se o espaco foi resevado*/
    if(nova->filmes == NULL){
        printf("Nao tem espaco\n");
        free(nova); //liberando o espaco de lista
        return NULL;
    }

    /*Retonando o espaco resevado*/
    return nova;
}


Pilha* excluirPilha(Pilha *pilha){
    /*Liberando o espaco que foi reservado para o vetor elementos*/
    free(pilha->filmes);
    /*Liberando o espaco que foi reservado para a lista*/
    free(pilha);
    return NULL;
}


int push(Pilha *pilha, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){
    
    if(pilha == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    
    if(pilha->topo < TAM){
        strcpy(pilha->filmes[pilha->topo].titulo, titulo);
        strcpy(pilha->filmes[pilha->topo].genero, genero);
        strcpy(pilha->filmes[pilha->topo].classificacao, classificacao);
        pilha->filmes[pilha->topo].duracao = duracao;
        pilha->filmes[pilha->topo].valor_aluguel = valor_aluguel;
        pilha->filmes[pilha->topo].disponibilidade = disponibilidade;
        ++(pilha->topo);
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}


int pop(Pilha *pilha){
    
    if(pilha == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    
    if(pilha->topo == 0){
        printf("A pilha esta vazia\n");
        return 0;
    }
    pilha->topo = pilha->topo - 1;
    return 1;
}

int main() {
    
    char titulo[50];
    char genero[30];
    char classificacao[7];
    char nomeTitulo[50];
    int duracao,disponibilidade, menu;
    double valor_aluguel;
    
    Filme elemento;

    Pilha *pilha = criarPilha();
    
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
             push(pilha,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade);
        break;
        case 2:
           pop(pilha);
        break;
        
        default:
        printf("Essa opcao nao existe!\n");
        break;
    }
}
    

    return 0;
}
