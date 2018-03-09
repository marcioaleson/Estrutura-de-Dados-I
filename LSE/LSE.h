#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<conio.h>

typedef struct No{
    char info;
    struct No *prox;
}No;

No *lista_LSE;

No* crialista_LSE(){    //retorna NULL para indicar que a lista nao possui nenhum elemento
    return NULL;
}

bool inserirInicio_LSE(char dado){
    No *novo = (No *)malloc(sizeof(No));    //aloca novo nó
    if(novo == NULL){   //se malloc retornar NULL a memoria nao foi alocada com sucesso
        printf("\nMEMORIA INSUFICIENTE!\n");
        return false;
    }else{  //caso contrario o nó foi alocado e um novo nó pode ser então inserido
        novo->info = dado;      //insere o dado no campo info do nó alocado
        novo->prox = lista_LSE;  //o prox do novo nó é atualizado e passa a apontar para o antigo inicioo da lista
        lista_LSE = novo;  //o ponteiro da lista passa a apontar para o novo nó inserido
        return true;
    }
}

bool inserirFim_LSE(char dado){

    No *novo = (No *)malloc(sizeof(No));    //aloca novo nó

    if(novo == NULL){   //verifica falha na alocação
        printf("\nMEMORIA INSUFICIENTE!\n");
        return false;
    }else{
        novo->info = dado;  //insere o dado no campo info
        novo->prox = NULL;  //o prox do nó ddeve apontar para NULL indicando o fim da lista
        if(lista_LSE == NULL){  //se a lista estiver vazia
            lista_LSE = novo;  //atualiza ponteiro da lista para o novo nó inserido
        }else{  //se a lista não estiver vazia
            No *p;
            p = lista_LSE;   //ponteiro para percorrer a lista recebe o ponteiro da lista
            //percorre até o nó que está final da lista
            while(p->prox != NULL){ //enquanto o prox do nó atual for diferente de NULL
                p = p->prox;    //p recebe seu proximo
            }

            //o proximo do ultimo nó da lista passa a apontar para o novo nó inserido
            p->prox = novo;
        }
        return true;
    }
}

//retorna numero de elementos da lista
int numeroDeElementos_LSE(){
    int N = 0;
    No *aux = lista_LSE;
    while(aux != NULL){       //enquanto o ponteiro for diferente de NULL percorre a lista
        N++;    //a cada nó visitado incrementa N
        aux = aux->prox;    //o ponteiro recebe seu próximo
    }
    return N;
}

bool inserirPosicao_LSE(int k, char dado){
    int i, N = numeroDeElementos_LSE();
    if(k < 1 || k > (N + 1)){   //testa se a posição é invalida
        printf("\nPOSICAO INVALIDA!NAO E POSSIVEL INSERIR.\n");
        return false;
    }else{  //se nao for invalida
        if(k == 1){  //se a posição for 1 (a 1ª posição da lista) a inserção é no inicio e o algoritmo e o mesmo já apresentado
            inserirInicio_LSE(dado);
            return true;
        }else{  //senão, a inserção é no meio ou no fim da lista
            No* novo = (No*)malloc(sizeof(No));     //aloca nó
            No *ant;    //ponteiro que guardará o no anterior na iteração na lista
            if(novo == NULL){   //verifica se houve falha na requisição de memoria
                printf("\nMEMORIA INSUFICIENTE!\n");
                return false;
            }
            ant = lista_LSE; //o ponteiro para o nó anterior é inicializado apontando pro inicio da lista
            for(i = 1; i < k - 1; i++)   //encontra elemento que antecederá o novo elemento
                ant = ant->prox;
            novo->info = dado;  //insere o dado
            novo->prox = ant->prox; //o proximo do novo nó recebe o próximo do nó encontrado
            ant->prox = novo;   //o prox do elemento encontrado aponta para o novo nó
            return true;
        }
    }
}



bool excluirInicio_LSE(){
    if(lista_LSE == NULL){  //testa se a lista está vazia
        printf("\nLISTA VAZIA!REMOCAO INVALIDA.\n");
        return false;
    }else{  //se não estiver vazia...
        No *p;
        p = lista_LSE;   //p recebe o nó que está no inicio da lista
        lista_LSE = p->prox; //o ponteiro da lista é atualizado e passa a apontar para o nó seguinte
        free(p);    //desaloca o nó que estava no inicio da lista da memória
        return true;
    }
}

bool excluirPosicao_LSE(int k){
    int N = numeroDeElementos_LSE();
    if(lista_LSE == NULL){  //testa se a lista está vazia
        printf("LISTA VAZIA!NAO E POSSIVEL EXCLUIR\n!\n");
        return false;
    }
    if(k > N || k < 1){ //testa se a posicao é invalida
        printf("\nPOSICAO INVALIDA!\n");
        return false;
    }
    if(k == 1){ //se a exclusão for na 1ª posição,é usado o algoritmo excluir no inicio
        return excluirInicio_LSE();
    }else{  //senão, a exclusão é no meio ou no fim
        int i;
        No *p, *ant;
        p = lista_LSE;   //ponteiro usado para percorrer a lista
        ant = NULL; //ponteiro que ao final da iteração  apontará para o nó que antecederá o novo nó
        for(i = 1; i < k; i++){ //encontra nó que aponta para o nó que será removido
            ant = p;    //anterior recebe atual
            p = p->prox;    //atual recebe seu próximo
        }
        ant->prox = p->prox;    // o próximo do nó encontrado aponta para o proximo do nó que será excluido
        free(p);    //desaloca o nó
        return true;
    }
}

bool excluirFim_LSE(){
    int N = numeroDeElementos_LSE();
    if(lista_LSE != NULL){  //se a lista não estiver vazia
        if(N == 1){ //se a lista possui apenas um elemento, o algoritmo excluir no inicio é usado
            return excluirInicio_LSE(lista_LSE);
        }else{  //senão possuir apenas um elemento...
            No *p, *q;
            p = lista_LSE;
            while(p->prox->prox != NULL)    //percorre a lista em busca do antecessor do ultimo nó na lista
                p = p->prox;
            q = p->prox;    //q recebe o ultimo nó da lista
            p->prox = NULL; //o proximo do penultimo nó da lista recebe NULL
            free(q);    //libera o ultimo nó da lista
            return true;
        }
    }else{  //lista vazia
        printf("\nLista Vazia!\n");
        return false;
    }
}

No* pesquisar_por_posicao(int pos){
    if(lista_LSE == NULL){
        printf("\nLista vazia!");
        return NULL;
    }else if(pos < 1 || pos > numeroDeElementos_LSE()){
        printf("Posicao invalida!");
        return NULL;
    }else{
        int i = 1;
        No *item = lista_LSE;
        for(;i < pos; i++)
            item = item->prox;
        return item;
    }
}

No* pesquisar_por_elemento(char dado){
    if(lista_LSE == NULL){
        printf("\nLista vazia!");
        return NULL;
    }else{
        No *aux = lista_LSE;
        while(aux != NULL)
        {
            if(aux->info == dado)
                return aux;
            aux = aux->prox;
        }
        return NULL;

    }
}


//algoritmo para impressão simples(sem interface).
void imprimir_LSE(){
    printf("\n\n");
    if(lista_LSE == NULL){  //testa se a lista está vazia
        printf("\nLista vazia!\n");
    }else{  //se a lista não estiver vazia
        No *aux;
        aux = lista_LSE;    //ponteiro aux usado para percorrer a lista é inicializado apontando para o inicio da lista
        while(aux != NULL){ //enquanto o ponteiro for diferente de NULL, imprime e passa para o próximo nó
            printf("info = %c\n\n", aux->info); //imprime
            aux = aux->prox;    //faz o nó apontar para seu próximo
        }
    }
    system("pause");
}
