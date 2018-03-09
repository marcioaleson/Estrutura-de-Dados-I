#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20
#define Local int
typedef struct {
    char info;
    int prox;
} no;

typedef struct {
    int disp;
    char maior;
    char menor;
    int quant;
    no vet[MAX];
} LLSE;

void inicializar(LLSE * lista, bool vet[]) {
    int i;
    lista->disp = 1;
    for(i = 0; i < 5; i++) {
        lista->vet[i].prox = i + 1;
        lista->vet[i].info = ' ';
        vet[i] = true;
    }
    lista->vet[0].prox = -5;
    lista->vet[5].prox = -1;
    lista->vet[5].info = ' ';
    lista->maior = ' ';
    lista->menor = ' ';
    lista->quant = 0;
    vet[5] = true;
}

int alocaNo(LLSE * lista) {
    int d;
    if(lista->disp == -1) {
        return 0;
    }
    d = lista->disp;
    lista->disp = lista->vet[lista->disp].prox;
    return d;
}

void inserir(LLSE * lista, Local local, int pos, char info, bool vet[]) {
    int d = alocaNo(lista);
    lista->vet[d].info = info;
    if(d != 0) {
        if(local == 1) {
            lista->vet[d].prox = lista->vet[0].prox;
            lista->vet[0].prox = d;
            vet[0] = true;
            vet[d] = true;
        } else if(local == 2) {
            int i;
            i = lista->vet[0].prox;
            while(lista->vet[i].prox != -5) {
                i = lista->vet[i].prox;
            }
            lista->vet[d].prox = lista->vet[i].prox;
            lista->vet[i].prox = d;
            vet[i] = true;
            vet[d] = true;
        } else {
            int i;
            int cont;
            i = lista->vet[0].prox;
            cont =  1;
            while(cont < pos) {
                i = lista->vet[i].prox;
                cont++;
            }
            lista->vet[d].prox = lista->vet[i].prox;
            lista->vet[i].prox = d;
            vet[i] = true;
            vet[d] = true;
        }
        lista->quant++;
    }
}

void liberaNo(LLSE * lista, int ind) {
    lista->vet[ind].prox = lista->disp;
    lista->disp = ind;
}

void remover(LLSE * lista, Local local, int pos, bool vet[]) {
    int atual;
    if(local == 1) {
        atual = lista->vet[0].prox;
        lista->vet[0].prox = lista->vet[atual].prox;
        liberaNo(lista, atual);
    } else if(local == 2) {
        int i;
        i = lista->vet[0].prox;
        while(lista->vet[lista->vet[i].prox].prox != -5) {
            i = lista->vet[i].prox;
        }
        atual = lista->vet[i].prox;
        lista->vet[i].prox = lista->vet[atual].prox;
        liberaNo(lista, atual);
    } else {
        int i;
        int cont;
        cont = 1;
        i = lista->vet[0].prox;
        while(cont < pos) {
            i = lista->vet[i].prox;
            cont++;
        }
        atual = lista->vet[i].prox;
        lista->vet[i].prox = lista->vet[atual].prox;
        liberaNo(lista, atual);
    }
    lista->quant--;
}

void ini(bool vet[]) {
    int i;
    for(i = 0; i < 6; i++)
        vet[i] = false;
}
void atualiza(LLSE * lista) {
    int i;
    if(lista->quant > 0) {
        lista->menor = 99;
        for(i = lista->vet[0].prox; i != -5; i = lista->vet[i].prox) {
            if(lista->maior < lista->vet[i].info)
                lista->maior = lista->vet[i].info;
            if(lista->vet[i].info < lista->menor)
                lista->menor = lista->vet[i].info;
        }
    }
}

void mostrar(LLSE * lista, bool vet[]) {
    int i;
    atualiza(lista);
    printf("| --------------------------------                                      |\n");
    printf("| |[DISP]| MAIOR | MENOR | QUANT |                                      |\n");
    printf("| --------------------------------                                      |\n");
    printf("| |  %2d  |   %c   |   %c   |   %d   |                                      |\n", lista->disp, lista->maior, lista->menor, lista->quant);
    printf("| --------------------------------                                      |\n");
    printf("|                                                                       |\n");
    printf("|                             ARRANJO:                                  |\n");
    printf("| -------------------------------------------------------------------   |\n");
    printf("| |     0    |     1    |     2    |     3    |     4    |     5    |   |\n");
    printf("| -------------------------------------------------------------------   |\n| ");
    for(i = 0; i < 6; i++) {
        printf("|  %c ", lista->vet[i].info);
        if(vet[i] == true) {
            if(lista->vet[i].prox == -5) {
                printf("| [ /]");
            } else {
                printf("| [%2d]", lista->vet[i].prox);
            }
        } else {
            if(lista->vet[i].prox == -5) {
                printf("|   / ");
            } else {
                printf("|  %2d ", lista->vet[i].prox);
            }
        }
    }
    printf("|   |\n");
    printf("| -------------------------------------------------------------------   |\n");
    printf("|                                                                       |");
}

void texto(FILE * arq) {
    char str[1000];
    while(fgets(str, 100, arq)) {
        if(str[0] == '.')break;
        printf("%s", str);
    }
}

void principal() {
    FILE * arq;
    LLSE lista;
    bool vet[MAX];
    arq = fopen("LLSE.txt", "r");
    texto(arq);
    scanf("%*c");
    system("cls");
    texto(arq);
    scanf("%*c");
    inicializar( & lista, vet);
    system("cls");
    texto(arq);
    mostrar( & lista, vet);
    scanf("%*c");
    ini(vet);
    inserir( & lista, 1, 0, 'A', vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( & lista, 2, 0, 'B', vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( & lista, 2, 0, 'C', vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( & lista, 2, 0, 'D', vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( & lista, 3, 2, 'X', vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    system("cls");
    ini(vet);
    remover( & lista, 1, 0, vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    remover( & lista, 2, 0, vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    remover( & lista, 3, 2, vet);
    texto(arq);
    mostrar( & lista, vet);
    texto(arq);
    scanf("%*c");
    fclose(arq);
}
