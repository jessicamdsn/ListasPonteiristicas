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
}ListaNo;

typedef struct lista{
    ListaNo *prim;
}Lista;


Lista* criarLista(){
    Lista *nova = (Lista*)malloc(sizeof(Lista));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    nova->prim = NULL;
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

    if(lista->prim == NULL){
        lista->prim = nova;
        printf("Itens inseridos com sucesso bb!\n");
        return 1;
    }

    for(p = lista->prim; p->prox != NULL; p = p->prox);

    p->prox = nova;

    printf("Itens inseridos com sucesso bb!\n");
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
    
    for(p = lista->prim; p != NULL; p = p->prox){
        printf("Itens inseridos: %s, %s, %s, %d minutos, R$%.2lf, Disponibilidade: %d\n", p->titulo, p->genero, p->classificacao, p->duracao, p->valor_aluguel, p->disponibilidade);
    }
    printf("\n");
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
        posicao++;
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
        p = lista->prim;
        lista->prim = lista->prim->prox;
        free(p);
        return 1;
    }

    for(p = lista->prim; p->prox->prox != NULL; p = p->prox){
        /*Verificando se e o elemento que sera removido da lista*/
        if(strcmp(p->prox->titulo, remover) == 0){
            aux = p->prox;
            p->prox = p->prox->prox;
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
    
    Lista *lista;
    ListaNo *pesquisa;
    
    lista = criarLista();

    if (lista != NULL) {
        printf("lista criada\n");
    }
    
    inserirElemento(lista, "madagascar", "animacao", "livre", 120, 2, 1);
    
    imprimirElementos(lista);
    
    inserirElemento(lista, "jumanji", "acao", "10", 120, 3, 1);
    
    inserirElemento(lista, "vingadores", "acao", "livre", 130, 5, 1);
    
    pesquisa = buscarElemento(lista, "vingadores");
    pesquisa = buscarElemento(lista, "jumanji");
    
    atualizarElemento(lista, "vingadores", "007", "Acao", "16", 120, 10, 1);
    printf("\n");
    imprimirElementos(lista);
    
    removerElemento(lista, "jumanji");
    imprimirElementos(lista);
    
    

    return 0;
}
