#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5


typedef struct listaNo{
    char titulo[50];
    char genero[30];
    char classificacao[7];
    int duracao;
    double valor_aluguel;
    int disponibilidade;
    struct listaNo *prox;
    struct listaNo *ant;
}ListaNo;

typedef struct lista{
    ListaNo *prim;
    ListaNo *ult;
}Lista;


Lista* criarLista(){
    Lista *nova = (Lista*)malloc(sizeof(Lista));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    nova->prim = NULL;
    nova->ult = NULL;
    
    return nova;
}

int inserirElemento(Lista *lista, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade) {
    
    ListaNo *p; 
    ListaNo *nova = (ListaNo*) malloc(sizeof(ListaNo));
    
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }
    
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
    nova->ant = NULL;

    if(lista->prim == NULL){
        lista->prim = nova;
        lista->ult = nova;
        printf("Itens inseridos com sucesso!\n\n");
        return 1;
    }
    
    lista->ult->prox = nova;
    nova->ant = lista->ult;
    lista->ult = nova;

    printf("Itens inseridos com sucesso!\n\n");
    return 1;
}

Lista* excluirLista(Lista *lista) {
    ListaNo *aux;
    
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return NULL;
    }
    
    while(lista->prim != NULL){
        aux = lista->prim;
        lista->prim = lista->prim->prox;
        free(aux);
    }
    
    free(lista);
    printf("Lista excluida!\n");
    return NULL;
}

void imprimirElementos(Lista *lista){
    ListaNo *p;
    
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return ;
    }
    
    if(lista->prim == NULL){
        printf("A lista esta vazia\n");
        return ;
    }
    int i =1;
     printf("Detalhes dos filmes na lista:\n\n");
    for(p = lista->prim; p != NULL; p = p->prox){
        printf("Filme %d:\n", i);
        printf("Titulo: %s\n", p->titulo);
        printf("Genero: %s\n", p->genero);
        printf("Classificacao: %s\n", p->classificacao);
        printf("Duracao: %d minutos\n", p->duracao);
        printf("Valor do aluguel: R$%.2lf\n", p->valor_aluguel);
        printf("Disponibilidade: %s\n", p->disponibilidade ? "Disponivel" : "Indisponivel");
        printf("\n");
        i++;
    }
}

void imprimirElementosOrdemInversa(Lista *lista){
    ListaNo *p;
    
    if(lista == NULL){
        printf("A lista não existe");
        return ;
    }
    
    if(lista->prim == NULL){
        printf("A lista esta vazia");
        return ;
    }
    int i =1;
    printf("Detalhes dos filmes na lista:\n\n");
    for(p = lista->ult; p != NULL; p = p->ant){
        printf("Filme %d:\n", i);
        printf("Titulo: %s\n", p->titulo);
        printf("Genero: %s\n", p->genero);
        printf("Classificacao: %s\n", p->classificacao);
        printf("Duracao: %d minutos\n", p->duracao);
        printf("Valor do aluguel: R$%.2lf\n", p->valor_aluguel);
        printf("Disponibilidade: %s\n", p->disponibilidade ? "Disponivel" : "Indisponivel");
        printf("\n");
        i++;
    }
}

ListaNo* buscarElemento(Lista *lista, char titulo[]){
    ListaNo *p;
    
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    
    if(lista->prim == NULL){
        printf("A lista esta vazia\n");
        return NULL;
    }
    
    int posicao = 0;
   for(p = lista->prim; p != NULL; p = p->prox){
        if (strcmp(p->titulo, titulo) == 0) {
            printf("Film encontrado, %s está na posicao %d\n", p->titulo, posicao);
            return p;
        }
    }
    return NULL;
}

int atualizarElemento(Lista *lista, char busca[], char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){
    ListaNo *p;
    int i;
    
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    if(lista->prim == NULL){
        printf("A lista esta vazia\n");
        return 0;
    }
    
    for(p = lista->prim; p != NULL; p = p->prox){
        
        if(strcmp(p->titulo, busca) == 0){
            
            strcpy(p->titulo, titulo);
            strcpy(p->genero, genero);
            strcpy(p->classificacao, classificacao);
            p->duracao = duracao;
            p->valor_aluguel = valor_aluguel;
            p->disponibilidade = disponibilidade;
            printf("Valor atualizado\n");
            return 1;
        }
    }
    return 0;
}

int removerElemento(Lista *lista, char remover[]){
    ListaNo *p, *aux;
    int i;
    
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    
    if(lista->prim == NULL){
        printf("A lista esta vazia\n");
        return 0;
    }

    if( strcmp(lista->prim->titulo, remover) == 0){
        aux = lista->prim;
        lista->prim->prox->ant = NULL;
        lista->prim = lista->prim->prox;
        free(aux);
        return 1;
    }

    for(p = lista->prim; p->prox->prox != NULL; p = p->prox){
        /*Verificando se e o elemento que sera removido da lista*/
        if(strcmp(p->prox->titulo, remover) == 0){
            aux = p->prox;
            p->prox = p->prox->prox;
            p->prox->ant = p;
            free(aux);
            return 1;
        }
    }
    
    if(strcmp(p->prox->titulo, remover) == 0){
        aux = p->prox;
        p->prox = NULL;
        free(aux);
        return 1;
    }
    
    printf("valor nao foi encontrado\n");
    return 0;
}


int main() {
    
    char titulo[50];
    char genero[30];
    char classificacao[7];
    char nomeTitulo[50];
    int duracao,disponibilidade, menu;
    double valor_aluguel;
    int ordem,posicao;
    char resposta;
    ListaNo *busca;
    
    Lista *lista;
    ListaNo *pesquisa;
    
    lista = criarLista();
    
    while(1){
    printf("O que voce quer fazer? \n1.Inserir filme \n2.Remover filme \n3.Buscar filme \n4.Mostrar filmes \n5.Atualizar filme \n6.Excluir lista\n");
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
            inserirElemento(lista,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade);
        break;
        case 2:
            if (lista->prim != NULL) {
                printf("Digite o nome do filme que será removido:\n");
                scanf(" %s",titulo);
                removerElemento(lista,titulo);
            }else{
                printf("Lista vazia\n");
            }
        break;
        case 3:
            if (lista->prim != NULL) {
                printf("Digite o nome do filme para buscar:\n");
                scanf("%s",titulo);
                busca = buscarElemento(lista,titulo);
                if(busca != NULL){
                    printf("Encontrado!\n\n");
                }else{
                    printf("Elemento nao encontrado\n");
                }
            }else{
                printf("Lista vazia\n");
            }
        break;
        case 4:
            printf("Sera exibido em que ordem? \n1.Normal \n2.Inversa\n");
            scanf("%d",&ordem);
            switch(ordem){
                case 1:
                imprimirElementos(lista);
                break;
                case 2:
                imprimirElementosOrdemInversa(lista);
                break;
                default:
                printf("Essa opcao nao existe!\n");
                break;
            }
        break;
        case 5:
            if (lista->prim != NULL) {
                printf("Digite o nome do filme que os dados serao atualizados:\n");
                scanf("%s",nomeTitulo);
                printf("Agora preencha com os novos dados:\n");
                printf("Nome do filme: ");
                scanf("%s",titulo);
                printf("Genero: ");
                scanf("%s",genero);
                printf("Classificacao: ");
                scanf(" %s",classificacao);
                printf("Duracao em minutos: ");
                scanf("%d",&duracao);
                printf("Valor do aluguel por dia: ");
                scanf("%lf",&valor_aluguel);
                printf("disponivel? (0/1): ");
                scanf("%d",&disponibilidade);
                atualizarElemento(lista,nomeTitulo,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade);
                printf("Atualizado!\n\n");
            }else{
                printf("Lista vazia\n");
            }
        break;
        case 6:
            printf("Deseja mesmo excluir a lista? (s/n)\n");
            scanf(" %c",&resposta);
            switch(resposta){
                case 's':
                case 'S':
                excluirLista(lista);
                exit(0);
                break;
                case 'n':
                case 'N':
                break;
                default:
                printf("Essa opcao nao existe!\n");
                break;
            }
        break;
        default:
        printf("Essa opcao nao existe!\n");
        break;
    }
}

    return 0;
}
