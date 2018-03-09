#include<stdio.h>
#include<stdlib.h>


typedef struct elemento_pilha{
    char info;
    struct elemento_pilha *prox;
}elemento_pilha;

elemento_pilha *topo;

elemento_pilha* cria_pl(void){
    return NULL;
}

void push(char dado){
    elemento_pilha *novo;
    novo = (elemento_pilha *)malloc(sizeof(elemento_pilha));
    if(novo == NULL){
        printf("\nMemoria insuficiente!\n");
        return;
    }
    novo->info = dado;
    novo->prox = topo;
    topo = novo;
}

char pop()
{
    elemento_pilha *aux;
    char x;
    if(topo == NULL){
        printf("\npilha vazia!Remocao invalida!\n");
        exit(1);
    }else{
        x = topo->info;
        aux = topo;
        topo = topo->prox;
        free(aux);
        return (x);
    }
}

char showtop(){
    if(topo == NULL){
        printf("\nPilha vazia!\n");
        exit(1);
    }else
        return (topo->info);
}

void imprimepilha_din(){
    elemento_pilha *q;
    int i = 1;
    q = topo;
    if(topo == NULL){
        printf("\ttopo %c%c%c NULL",196 , 196, 16);
    }else{
        while(q != NULL){
            if(q == topo){
                printf("\n\t\t%c%c%c%c%c%c%c\n",218,196, 196, 196, 194, 196, 191);
                if(q->prox != NULL){
                    printf("\ttopo %c%c%c%c %c %c %c%c%c\n",196 , 196, 16 ,179 ,q->info ,179 ,179, 196, 191);
                    printf("\t\t%c%c%c%c%c%c%c %c\n", 192, 196, 196, 196, 193, 196, 217, 179);
                    printf("\t\t    %c%c%c%c%c\n",218 , 196, 196, 196, 217);
                    printf("\t\t    %c",31);
                }else{
                    printf("\ttopo %c%c%c%c %c %c %c%c%c%c NULL\n",196 , 196, 16 ,179 ,q->info ,179 ,179, 196, 196, 16);
                    printf("\t\t%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 217);
                }
            }else{
                printf("\n\t\t%c%c%c%c%c%c%c\n",218,196, 196, 196, 194, 196, 191);
                if(q->prox != NULL){
                    printf("\t\t%c %c %c %c%c%c\n",179 ,q->info ,179 ,179, 196, 191);
                    printf("\t\t%c%c%c%c%c%c%c %c\n", 192, 196, 196, 196, 193, 196, 217, 179);
                    printf("\t\t    %c%c%c%c%c\n",218 , 196, 196, 196, 217);
                    printf("\t\t    %c",31);
                }else{
                    printf("\t\t%c %c %c %c%c%c%c NULL\n",179 ,q->info ,179 ,179, 196, 196, 16);
                    printf("\t\t%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 217);
                }
            }
            q = q->prox;
        }
    }
}
