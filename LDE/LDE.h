#include<stdio.h>
#include<stdlib.h>


typedef struct No{
    char info;
    struct No *ant;
    struct No *prox;
}No;

No* crialista_LDE(void){
    No *l;
    l = (No *)malloc(sizeof(No));
    //printf("aloca");
    if(l == NULL){
        printf("ERRO NA SOLICITACAO DE MEMORIA!\n");
        exit(1);
    }
    //o primeiro nó e um nó de cabeçalho, que foi usado para evitar o uso
    //de ponteiro duplo, o que tornaria o algoritmo um pouco mais dificil
    //de entender. O nó alocado não corresponde a um elemento da lista
    //propriamente, mais guarda informações sobre a lista, funcionando como
    //um descritor e facilitador de operações.
    l->ant = NULL;
    l->info = ' ';
    l->prox = NULL;
    return l;
}

No* alocano_LDE(){
    No *novo;
    novo = (No *)malloc(sizeof(No));
    if(novo == NULL){
        printf("\nMEMORIA INSUFICIENTE!\n");
        exit(1);
    }
    return novo;
}

void inserirdepois_LDE(No *l, No *depoisde, char info){
    No *novo, *aux;
    novo = alocano_LDE();
    novo->info = info;
    aux = depoisde->prox;
    if(aux != NULL)
        aux->ant = novo;
    novo->prox = aux;
    depoisde->prox = novo;
    novo->ant = depoisde;
}

void inserirPosicao_LDE(No *l, int k, char info){
    if(k < 1){
        printf("Posicao invalida!");
        return;
    }else{
        int i = 1;
        No *aux = l->prox;
        No *ant = l;
        while(i < k && aux != NULL){
            ant = aux;
            aux = aux->prox;
            i++;
        }
        if(k > i + 1)
        {
            printf("posicao invalida!");
            return;
        }else{
            inserirdepois_LDE(l, ant, info);
        }
    }
}

void removerno_LDE(No *l, No *p){
    No *r, *q;
    if(p == NULL || l->prox == NULL){
        printf("\nERRO NA REMOCAO!\n");
        exit(1);
    }
    q = p->prox;
    r = p->ant;
    r->prox = p->prox;
    if(q != NULL)
        q->ant = p->ant;
    free(p);
}


void excluir_elemento_LDE(No *l, char info){
    No *aux = l->prox;
    while(aux != NULL){
        if(aux->info == info){
            removerno_LDE(l, aux);
            return;
        }
        aux = aux->prox;
    }
}


char excluirPosicao_LDE(No *l, int pos){
    if(l->prox == NULL){
        printf("\nERRO NA EXCLUSAO!\n");
        exit(1);
    }
    int i;
    char x;
    No* atual = l->prox;
    for(i = 1; i < pos; i++)
        atual = atual->prox;
    x = atual->info;
    removerno_LDE(l, atual);
    return x;
}


No* buscaitem_LDE(No *l, char info, No *q)
{
    No *p;
    p = q;
    while(p !=  NULL){
        if(info == p->info)
            break;
        p = p->prox;
    }
    return p;
}

void liberarlista_LDE(No *l){
    No *aux;
    aux = l->prox;
    while(aux != NULL){
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(l);
}
