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
    No *novo = (No *)malloc(sizeof(No));    //aloca novo n�
    if(novo == NULL){   //se malloc retornar NULL a memoria nao foi alocada com sucesso
        printf("\nMEMORIA INSUFICIENTE!\n");
        return false;
    }else{  //caso contrario o n� foi alocado e um novo n� pode ser ent�o inserido
        novo->info = dado;      //insere o dado no campo info do n� alocado
        novo->prox = lista_LSE;  //o prox do novo n� � atualizado e passa a apontar para o antigo inicioo da lista
        lista_LSE = novo;  //o ponteiro da lista passa a apontar para o novo n� inserido
        return true;
    }
}

bool inserirFim_LSE(char dado){

    No *novo = (No *)malloc(sizeof(No));    //aloca novo n�

    if(novo == NULL){   //verifica falha na aloca��o
        printf("\nMEMORIA INSUFICIENTE!\n");
        return false;
    }else{
        novo->info = dado;  //insere o dado no campo info
        novo->prox = NULL;  //o prox do n� ddeve apontar para NULL indicando o fim da lista
        if(lista_LSE == NULL){  //se a lista estiver vazia
            lista_LSE = novo;  //atualiza ponteiro da lista para o novo n� inserido
        }else{  //se a lista n�o estiver vazia
            No *p;
            p = lista_LSE;   //ponteiro para percorrer a lista recebe o ponteiro da lista
            //percorre at� o n� que est� final da lista
            while(p->prox != NULL){ //enquanto o prox do n� atual for diferente de NULL
                p = p->prox;    //p recebe seu proximo
            }

            //o proximo do ultimo n� da lista passa a apontar para o novo n� inserido
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
        N++;    //a cada n� visitado incrementa N
        aux = aux->prox;    //o ponteiro recebe seu pr�ximo
    }
    return N;
}

bool inserirPosicao_LSE(int k, char dado){
    int i, N = numeroDeElementos_LSE();
    if(k < 1 || k > (N + 1)){   //testa se a posi��o � invalida
        printf("\nPOSICAO INVALIDA!NAO E POSSIVEL INSERIR.\n");
        return false;
    }else{  //se nao for invalida
        if(k == 1){  //se a posi��o for 1 (a 1� posi��o da lista) a inser��o � no inicio e o algoritmo e o mesmo j� apresentado
            inserirInicio_LSE(dado);
            return true;
        }else{  //sen�o, a inser��o � no meio ou no fim da lista
            No* novo = (No*)malloc(sizeof(No));     //aloca n�
            No *ant;    //ponteiro que guardar� o no anterior na itera��o na lista
            if(novo == NULL){   //verifica se houve falha na requisi��o de memoria
                printf("\nMEMORIA INSUFICIENTE!\n");
                return false;
            }
            ant = lista_LSE; //o ponteiro para o n� anterior � inicializado apontando pro inicio da lista
            for(i = 1; i < k - 1; i++)   //encontra elemento que anteceder� o novo elemento
                ant = ant->prox;
            novo->info = dado;  //insere o dado
            novo->prox = ant->prox; //o proximo do novo n� recebe o pr�ximo do n� encontrado
            ant->prox = novo;   //o prox do elemento encontrado aponta para o novo n�
            return true;
        }
    }
}



bool excluirInicio_LSE(){
    if(lista_LSE == NULL){  //testa se a lista est� vazia
        printf("\nLISTA VAZIA!REMOCAO INVALIDA.\n");
        return false;
    }else{  //se n�o estiver vazia...
        No *p;
        p = lista_LSE;   //p recebe o n� que est� no inicio da lista
        lista_LSE = p->prox; //o ponteiro da lista � atualizado e passa a apontar para o n� seguinte
        free(p);    //desaloca o n� que estava no inicio da lista da mem�ria
        return true;
    }
}

bool excluirPosicao_LSE(int k){
    int N = numeroDeElementos_LSE();
    if(lista_LSE == NULL){  //testa se a lista est� vazia
        printf("LISTA VAZIA!NAO E POSSIVEL EXCLUIR\n!\n");
        return false;
    }
    if(k > N || k < 1){ //testa se a posicao � invalida
        printf("\nPOSICAO INVALIDA!\n");
        return false;
    }
    if(k == 1){ //se a exclus�o for na 1� posi��o,� usado o algoritmo excluir no inicio
        return excluirInicio_LSE();
    }else{  //sen�o, a exclus�o � no meio ou no fim
        int i;
        No *p, *ant;
        p = lista_LSE;   //ponteiro usado para percorrer a lista
        ant = NULL; //ponteiro que ao final da itera��o  apontar� para o n� que anteceder� o novo n�
        for(i = 1; i < k; i++){ //encontra n� que aponta para o n� que ser� removido
            ant = p;    //anterior recebe atual
            p = p->prox;    //atual recebe seu pr�ximo
        }
        ant->prox = p->prox;    // o pr�ximo do n� encontrado aponta para o proximo do n� que ser� excluido
        free(p);    //desaloca o n�
        return true;
    }
}

bool excluirFim_LSE(){
    int N = numeroDeElementos_LSE();
    if(lista_LSE != NULL){  //se a lista n�o estiver vazia
        if(N == 1){ //se a lista possui apenas um elemento, o algoritmo excluir no inicio � usado
            return excluirInicio_LSE(lista_LSE);
        }else{  //sen�o possuir apenas um elemento...
            No *p, *q;
            p = lista_LSE;
            while(p->prox->prox != NULL)    //percorre a lista em busca do antecessor do ultimo n� na lista
                p = p->prox;
            q = p->prox;    //q recebe o ultimo n� da lista
            p->prox = NULL; //o proximo do penultimo n� da lista recebe NULL
            free(q);    //libera o ultimo n� da lista
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


//algoritmo para impress�o simples(sem interface).
void imprimir_LSE(){
    printf("\n\n");
    if(lista_LSE == NULL){  //testa se a lista est� vazia
        printf("\nLista vazia!\n");
    }else{  //se a lista n�o estiver vazia
        No *aux;
        aux = lista_LSE;    //ponteiro aux usado para percorrer a lista � inicializado apontando para o inicio da lista
        while(aux != NULL){ //enquanto o ponteiro for diferente de NULL, imprime e passa para o pr�ximo n�
            printf("info = %c\n\n", aux->info); //imprime
            aux = aux->prox;    //faz o n� apontar para seu pr�ximo
        }
    }
    system("pause");
}
