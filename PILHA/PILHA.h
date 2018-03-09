#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char info;
} No;

typedef struct {
    No vetor[MAX];
    int topo;
} Pilha;


void inicializar(Pilha * P) {
    P->topo = 0; //Topo é inicializado com 0, significa Pilha vazia
    int i;
    for(i = 0; i < MAX; i++)
        P->vetor[i].info = ' ';
}

void push(Pilha * P, char info) {
    P->vetor[P->topo++].info = info; //Elemento é inserido no topo e então é incrementado
}

void pop(Pilha * P) {
    P->topo--; //Para remoção basta decrementar o topo
    P->vetor[P->topo].info = ' ';
}

void texto(FILE * arq) {
    char str[1000];
    while(fgets(str, 100, arq)) {
        if(str[0] == '.')break;
        printf("%s", str);
    }
}

void mostrar(Pilha * P) {
    int i;
    printf("|                                                                       |\n");
    printf("|              ----------                                               |\n");
    for(i = 5; i >= 0; i--) {
        if(i == P->topo - 1) {
            printf("|             |     %c    |  <- TOPO                                     |\n", P->vetor[P->topo - 1].info);
            printf("|              ----------                                               |\n");
        } else {
            printf("|             |     %c    |                                              |\n", P->vetor[i].info);
            printf("|              ----------                                               |\n");
        }
    }
}


void principal() {
    Pilha P;
    FILE * arq;
    arq = fopen("PILHA.txt", "r");
    texto(arq);
    scanf("%*c");
    system("cls");
    inicializar( & P);
    texto(arq);
    mostrar( & P);
    scanf("%*c");
    push(&P, 'A');
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    push(&P, 'B');
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    push(&P, 'C');
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    push(&P, 'D');
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    push(&P, 'X');
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    system("cls");
    pop(&P);
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    pop(&P);
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    pop(&P);
    texto(arq);
    mostrar( & P);
    texto(arq);
    scanf("%*c");
    fclose(arq);
}
