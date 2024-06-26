/****************************************************************** 
 * Nome: Pilha com apontadores                                    *
 * Descricao: Implementacao de pilha com apontadores              *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar lista,                                        *
 *            push,                                               *
 *            pop.                                                *
 *            ver topo,                                           *
 *            ehvazia,                                            *
 *            excluir pilha,                                      *
 * Autores:                                                       *
 * Jessica Maria de Souza Neves                                   *
 * Pedro Henrique de Araujo Santos                                *
 * Ultima alteracao: 19/05/2024                                   *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5


typedef struct pilhaNo{
    char titulo[50];
    char genero[30];
    char classificacao[8];
    int duracao;
    double valor_aluguel;
    int disponibilidade;
    struct pilhaNo *prox;
}PilhaNo;

typedef struct pilha{
    PilhaNo *topo;
}Pilha;


Pilha* criarPilha(){
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    
    nova->topo = NULL;
    return nova;
} //check

int push(Pilha *pilha, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade) {
    
    PilhaNo *nova = (PilhaNo*) malloc(sizeof(PilhaNo));
    
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
    nova->prox = pilha->topo;
    pilha->topo = nova;

    printf("Itens inseridos com sucesso!\n\n");
    return 1;
} //check

Pilha* excluirPilha(Pilha *pilha) {
    PilhaNo *aux;
    
    while(pilha->topo != NULL){
        aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
    }
    
    free(pilha);
    printf("Pilha excluida!\n");
    return NULL;
} //Chech

int verTopo(Pilha *pilha){
    PilhaNo *aux;
    
    if(pilha == NULL){
        printf("A pilha nao foi criada\n");
        return -1;
    }
    
    if(pilha->topo == NULL){
        printf("A pilha esta vazia\n");
        return -1;
    }
    
    printf("Detalhes do topo da pilha:\n\n");
        printf("Titulo: %s\n", pilha->topo->titulo);
        printf("Genero: %s\n", pilha->topo->genero);
        printf("Classificacao: %s\n", pilha->topo->classificacao);
        printf("Duracao: %d minutos\n", pilha->topo->duracao);
        printf("Valor do aluguel: R$%.2lf\n", pilha->topo->valor_aluguel);
        printf("Disponibilidade: %s\n", pilha->topo->disponibilidade ? "Disponivel" : "Indisponivel");
        
    return 0;
} //Check

PilhaNo* pop(Pilha *pilha){
    PilhaNo *p, *aux;

    if(pilha == NULL){
        printf("A pilha nao foi criada\n");
        return 0;
    }
    
    if(pilha->topo == NULL){
        printf("A pilha esta vazia\n");
        return 0;
    }

    aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    return aux;
} //Check

int ehVazia(Pilha* pilha){
    if(pilha == NULL){
        printf("A pilha não foi criada\n");
        return 1;
    }
    if(pilha->topo == NULL){
        printf("A pilha está vazia\n");
        return 1;
    }
    return 0;
}

int main() {
    char titulo[50];
    char genero[30];
    char classificacao[8];
    int duracao, disponibilidade, menu;
    double valor_aluguel;
    Pilha *pilha = NULL;
    PilhaNo *aux;

    while(1) {
        printf("O que voce quer fazer? \n");
        printf("1. Criar Pilha\n");
        printf("2. Adicionar filme\n");
        printf("3. Ver topo da pilha\n");
        printf("4. Remover topo da pilha\n");
        printf("5. Verificar se a pilha está vazia\n");
        printf("6. Excluir pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &menu);
        printf("\n");

        switch(menu) {
            case 1:
                pilha = criarPilha();
                printf("Pilha criada com sucesso\n\n");
                break;
            case 2:
                if (pilha == NULL) {
                    printf("A pilha não foi criada.\n");
                } else {
                    printf("Digite o titulo do filme: ");
                    scanf(" %[^\n]%*c", titulo);
                    printf("Digite o genero do filme: ");
                    scanf(" %[^\n]%*c", genero);
                    printf("Digite a classificacao do filme: ");
                    scanf(" %[^\n]%*c", classificacao);
                    printf("Digite a duracao do filme (em minutos): ");
                    scanf("%d", &duracao);
                    printf("Digite o valor do aluguel: ");
                    scanf("%lf", &valor_aluguel);
                    printf("Digite a disponibilidade (1 para disponivel, 0 para indisponivel): ");
                    scanf("%d", &disponibilidade);
                    push(pilha, titulo, genero, classificacao, duracao, valor_aluguel, disponibilidade);
                }
                break;
            case 3:
                verTopo(pilha);
                break;
            case 4:
                aux = pop(pilha);
                if (aux != NULL) {
                    printf("Filme removido:\n");
                    printf("Titulo: %s\n", aux->titulo);
                    printf("Genero: %s\n", aux->genero);
                    printf("Classificacao: %s\n", aux->classificacao);
                    printf("Duracao: %d minutos\n", aux->duracao);
                    printf("Valor do aluguel: R$%.2lf\n", aux->valor_aluguel);
                    printf("Disponibilidade: %s\n", aux->disponibilidade ? "Disponivel" : "Indisponivel");
                    free(aux);
                }
                break;
            case 5:
                ehVazia(pilha);
                break;
            case 6:
                pilha = excluirPilha(pilha);
                printf("Pilha excluída com sucesso\n");
                break;
            case 0:
                if (pilha != NULL) {
                    pilha = excluirPilha(pilha);
                }
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
