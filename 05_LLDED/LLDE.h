#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20


typedef struct {
    char info;
    int prox;
    int ant;
} no;

typedef struct {
    int disp;
    char maior;
    char menor;
    int quant;
    no vet[MAX];
} LLDE;


void inicializar(LLDE * lista, bool vet[]) {
    int i;
    lista->disp = 1;
    for(i = 0; i < 5; i++) {
        lista->vet[i].prox = i + 1;
        lista->vet[i].ant = i - 1;
        lista->vet[i].info = ' ';
        vet[i] = true;
    }
    lista->vet[0].prox = -5;
    lista->vet[0].ant = -5;
    lista->vet[5].prox = -1;
    lista->vet[5].ant = -1;
    lista->vet[5].info = ' ';
    vet[5] = true;
}

int alocaNo(LLDE * lista) {
    int d;
    if(lista->disp == -1) {
        return 0;
    }
    d = lista->disp;
    lista->disp = lista->vet[lista->disp].prox;
    return d;
}

void inserir(LLDE * lista, int local, int pos, char info, bool vet[]) {
    int d = alocaNo(lista), r;
    lista->vet[d].info = info;
    if(d != 0) {
        if(local == 1) {
            r = lista->vet[0].prox;
            if(r != -5) {
                lista->vet[r].ant = d;
            }
            lista->vet[d].prox = r;
            lista->vet[d].ant = 0;
            lista->vet[0].prox = d;
            vet[0] = true;
            vet[d] = true;
        } else if(local == 2) {
            int i;
            i = lista->vet[0].prox;
            while(lista->vet[i].prox != -5) {
                i = lista->vet[i].prox;
            }
            r = lista->vet[i].prox;
            if(r != -5) {
                lista->vet[r].ant = d;
            }
            lista->vet[d].prox = r;
            lista->vet[d].ant = i;
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
            r = lista->vet[i].prox;
            if(r != -5) {
                lista->vet[r].ant = d;
            }
            lista->vet[d].prox = r;
            lista->vet[d].ant = i;
            lista->vet[i].prox = d;
            vet[i] = true;
            vet[d] = true;
        }
    }
}

void liberaNo(LLDE * lista, int ind) {
    lista->vet[ind].prox = lista->disp;
    lista->disp = ind;
}

void remover(LLDE * lista, int local, int pos, bool vet[]) {
    int q, r;
    if(local == 1) {
        int i = lista->vet[0].prox;
        q = lista->vet[i].ant;
        r = lista->vet[i].prox;
        if(r != -5){
            lista->vet[r].ant = q;
        }
        lista->vet[q].prox = r;
        liberaNo(lista, i);
    } else if(local == 2) {
        int i;
        i = lista->vet[0].prox;
        while(lista->vet[i].prox != -5) {
            i = lista->vet[i].prox;
        }
        q = lista->vet[i].ant;
        r = lista->vet[i].prox;
        if(r != -5){
            lista->vet[r].ant = q;
        }
        lista->vet[q].prox = r;
        liberaNo(lista, i);
    } else {
        int i;
        int cont;
        cont = 1;
        i = lista->vet[0].prox;
        while(cont < pos) {
            i = lista->vet[i].prox;
            cont++;
        }
        q = lista->vet[i].ant;
        r = lista->vet[i].prox;
        if(r != -5){
            lista->vet[r].ant = q;
        }
        lista->vet[q].prox = r;
        liberaNo(lista, i);
    }
}

void ini(bool vet[]) {
    int i;
    for(i = 0; i < 6; i++)
        vet[i] = false;
}
void atualiza(LLDE * lista) {
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

void mostrar(LLDE * lista, bool vet[]) {
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
    for(i = 0; i < 6; i++)
        printf("|     %c    ", lista->vet[i].info);
    printf("|   |\n| -------------------------------------------------------------------   |\n| ");
    for(i = 0; i < 6; i++) {
        if(vet[i] == true) {
            if(lista->vet[i].ant == -5) {
                printf("| [/]");
            } else if(lista->vet[i].ant == -1) {
                printf("| [!]");
            } else {
                printf("| [%d]", lista->vet[i].ant);
            }
            if(lista->vet[i].prox == -5) {
                printf("| [ /]");
            } else if(lista->vet[i].prox == -1) {
                printf("| [ !]");
            } else {
                printf("| [%2d]", lista->vet[i].prox);
            }
        } else {
            if(lista->vet[i].ant == -5) {
                printf("|  / ");
            } else if(lista->vet[i].ant == -1) {
                printf("|  ! ");
            } else {
                printf("|  %d ", lista->vet[i].ant);
            }
            if(lista->vet[i].prox == -5) {
                printf("|   / ");
            } else if(lista->vet[i].prox == -1) {
                printf("|   ! ");
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
    LLDE lista;
    bool vet[MAX];
    arq = fopen("LLDE.txt", "r");
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
