/****************************************************************** 
 * Nome: Lista com vetores                                        *
 * Descricao: Implementacao de lista com uso de vetores (array).  *
 *            Esse codigo possui as principais operacoes da       *
 *            lista, como:                                        *
 *            criar lista,                                        *
 *            inserir elemento,                                   *
 *            remover elemento,                                   *
 *            buscar elemento,                                    *
 *            mostrar elementos,                                  *
 *            atualizar elementos,                                *
 *            excluir lista.                                      *
 * Autores:                                                       *
 * Jessica Maria de Souza Neves                                   *
 * Pedro Henrique de Araujo Santos                                *
 * Ultima alteracao: 07/05/2024                                   *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM 5

typedef struct {
        char titulo[50]; // Titulo do filme
        char genero[30]; // Genero do filme
        char classificacao[7]; // Classificacao indicativa
        int duracao; // Duracao em minutos
        double valor_aluguel; // Valor do aluguel
        int disponibilidade; // 1 para disponivel, 0 para nao disponivel
}Filme; // Array de filmes
    
typedef struct {
    int id;
    Filme *filmes;
} Lista;


Lista* criarLista(){
    Lista *nova = (Lista*)malloc(sizeof(Lista));

    if(nova == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    nova->id = 0; 
    nova->filmes = (Filme*)malloc(TAM * sizeof(Filme));
    if(nova->filmes == NULL){
        printf("Nao tem espaco\n");
        return NULL;
    }
    return nova;
}

int inserirElemento(Lista* lista, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){

    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    if (lista->id < TAM) {
        strcpy(lista->filmes[lista->id].titulo, titulo);
        strcpy(lista->filmes[lista->id].genero, genero);
        strcpy(lista->filmes[lista->id].classificacao, classificacao);
        lista->filmes[lista->id].duracao = duracao;
        lista->filmes[lista->id].valor_aluguel = valor_aluguel;
        lista->filmes[lista->id].disponibilidade = disponibilidade;
        ++(lista->id);
    } else {
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}

int inserirElementoInicio(Lista* lista, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    if(lista->id < TAM){
        for(i = lista->id; i > 0; --i){
            lista->filmes[i] = lista->filmes[i-1];
        }
        strcpy(lista->filmes[0].titulo, titulo);
        strcpy(lista->filmes[0].genero, genero);
        strcpy(lista->filmes[0].classificacao, classificacao);
        lista->filmes[0].duracao = duracao;
        lista->filmes[0].valor_aluguel = valor_aluguel;
        lista->filmes[0].disponibilidade = disponibilidade;
        ++(lista->id);
        
    }else{
        printf("Espaco esgotado\n");
        return 0;
    }

    return 1;
}

int inserirElementoId(Lista *lista, char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade, int posicao) {
    int i;
    
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }
    if (lista->id < TAM) {
   
        if (posicao < lista->id) {

            for (i = lista->id; i > posicao; --i) {
                lista->filmes[i] = lista->filmes[i-1];
            }
            strcpy(lista->filmes[posicao].titulo, titulo);
            strcpy(lista->filmes[posicao].genero, genero);
            strcpy(lista->filmes[posicao].classificacao, classificacao);
            lista->filmes[posicao].duracao = duracao;
            lista->filmes[posicao].valor_aluguel = valor_aluguel;
            lista->filmes[posicao].disponibilidade = disponibilidade;
            ++(lista->id);
        } else {
            printf("Posicao fora do intervalo permitido\n");
        }
    } else {
        printf("Espaco esgotado\n");
        return 0;
    }
    return 1;
}

void imprimirElementos(Lista* lista) {
    int i;

    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return;
    }

    if (lista->id == 0) {
        printf("Lista vazia\n");
        return;
    }

    printf("Detalhes dos filmes na lista:\n");
    for (i = 0; i < lista->id; ++i) {
        printf("Filme %d:\n", i + 1);
        printf("Titulo: %s\n", lista->filmes[i].titulo);
        printf("Genero: %s\n", lista->filmes[i].genero);
        printf("Classificacao: %s\n", lista->filmes[i].classificacao);
        printf("Duracao: %d minutos\n", lista->filmes[i].duracao);
        printf("Valor do aluguel: R$%.2lf\n", lista->filmes[i].valor_aluguel);
        printf("Disponibilidade: %s\n", lista->filmes[i].disponibilidade ? "Disponivel" : "Indisponivel");
        printf("\n");
    }
}

int buscarElemento(Lista *lista, char inserir[]){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    for(i = 0; i < lista->id; ++i){
        if(strcmp(lista->filmes[i].titulo, inserir) == 0){
            printf("Esse filme está na posicao %d\n",i);
            return i;
        }
    }
    return -1;
}

int atualizarElemento(Lista *lista, char busca[], char titulo[], char genero[], char classificacao[], int duracao, double valor_aluguel, int disponibilidade){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }
    for(i = 0; i < lista->id; ++i){
        
        if(strcmp(lista->filmes[i].titulo, busca) == 0){
            
        strcpy(lista->filmes[i].titulo, titulo);
        strcpy(lista->filmes[i].genero, genero);
        strcpy(lista->filmes[i].classificacao, classificacao);
        lista->filmes[i].duracao = duracao;
        lista->filmes[i].valor_aluguel = valor_aluguel;
        lista->filmes[i].disponibilidade = disponibilidade;
            printf("Valor atualizado\n");
            return i;
        }
    }
    return 0;
}

int removerElemento(Lista *lista, char remover[]){
    int i;
    if(lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    for(i = 0; i < lista->id; ++i){
        if(strcmp(lista->filmes[i].titulo, remover) == 0){
            //Deslocando os elementos apos posicao do elemento que sera removido da lista
            for(i; i < lista->id-1; ++i){
                lista->filmes[i] = lista->filmes[i+1];
            }
            --(lista->id);
            printf("Filme removido!\n\n");
            return 1;
        }
    }
    printf("valor nao foi encontrado\n");
    return 0;
}

Lista* excluirLista(Lista *lista) {
    if (lista != NULL) {
        if (lista->filmes != NULL) {
            free(lista->filmes);
        }
        free(lista);
    }
    printf("Lista excluida!\n");
    return NULL;
}

// Online C compiler to run C program online
#include <stdio.h>


int main() {
    
    char titulo[50];
    char genero[30];
    char classificacao[7];
    char nomeTitulo[50];
    int duracao,disponibilidade, menu;
    double valor_aluguel;
    int local,posicao;
    char resposta;
    
    Lista *lista;
    lista = criarLista();
    
    while(1){
    printf("O que voce quer fazer? \n1.Inserir filme \n2.Remover filme \n3.Buscar filme \n4.Mostrar filmes \n5.Atualizar filme \n6.Excluir lista\n");
    scanf("%d",&menu);
    
    switch(menu){
        case 1:
            printf("Onde ira adicionar? \n1.No inicio da lista \n2.No final da lista \n3.Em uma posicao especifica \n");
            scanf("%d",&local);
            
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
             switch(local){
                case 1:
                    inserirElementoInicio(lista,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade);
                    printf("Adicionado!\n\n");
                break;
                case 2:
                    inserirElemento(lista,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade);
                    printf("Adicionado!\n\n");
                break;
                case 3:
                    
                    printf("Qual posicao sera inserido? ");
                    scanf("%d",&posicao);
                    inserirElementoId(lista,titulo,genero,classificacao,duracao,valor_aluguel, disponibilidade,posicao);
                    printf("Adicionado!\n\n");
                break;
                default:
                    printf("Essa opcao nao existe!\n");
                    break;
             }
        break;
        case 2:
            if (lista->id != 0) {
                printf("Digite o nome do filme que será removido:\n");
                scanf(" %s",titulo);
                removerElemento(lista,titulo);
            }else{
                printf("Lista vazia\n");
            }
        break;
        case 3:
            if (lista->id != 0) {
                printf("Digite o nome do filme para buscar:\n");
                scanf(" %s",titulo);
                int busca = buscarElemento(lista,titulo);
                if(busca != -1){
                    printf("Encontrado!\n\n");
                }else{
                    printf("Elemento nao encontrado\n");
                }
            }else{
                printf("Lista vazia\n");
            }
        break;
        case 4:
             imprimirElementos(lista);
        break;
        case 5:
            if (lista->id != 0) {
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

