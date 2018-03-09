#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20
#define Local int

typedef struct {
    int IA;
    int FA;
    int IL;
    int FL;
    char maior;
    char menor;
    int quant;
    char vet[MAX];
} LLD;

void inicializar(LLD * lista, bool vet[]);
void mostrarLLV(LLD * lista, bool vet[]);
bool remover(LLD * lista, int local, int pos, bool vet[]);
bool inserir(LLD * lista, int local, int pos, char elemento, bool vet[]);
void principal();

void inicializar(LLD * lista, bool vet[]) {
    int i;
    lista->IA = 0;
    lista->FA = 4;
    lista->IL = -1;
    lista->FL = -1;
    for(i = 0; i < 7 ; i++) {
        lista->vet[i] = 32;
        vet[i] = true;
    }
    lista->quant  = 0;
    lista->maior = ' ';
    lista->menor = ' ';
}

void mostrar(LLD * lista, bool vet[]) {
    int i;
    printf("|  ---------------------     -------------------------  |\n");
    printf("|  |");
    if(vet[0] == true) {
        printf("[IA]|");
    } else {
        printf(" IA |");
    }
    if(vet[1] == true) {
        printf("[FA]|");
    } else {
        printf(" FA |");
    }
    if(vet[2] == true) {
        printf("[IL]|");
    } else {
        printf(" IL |");
    }
    if(vet[3] == true) {
        printf("[FL]|    ");
    } else {
        printf(" FL |    ");
    }
    if(vet[4] == true) {
        printf("| Menor: [%c] |", lista->menor);
    } else {
        printf("| Menor: %c  |", lista->menor);
    }
    if(vet[5] == true) {
        printf(" Maior: [%c]", lista->maior);
    } else {
        printf(" Maior: %c ", lista->maior);
    }/*
    if(vet[6] == true) {
        printf("Quant: [FL]");
    } else {
        printf("Quant: FL ");
    }*/
    if(vet[4] != vet[5])
        printf(" |  |\n");
    else if(vet[4] == true && vet[4] == vet[5])
        printf(" | |\n");
    else
        printf(" |   |\n");
    printf("|  ---------------------     -------------------------  |\n");
    printf("|  | %2d | %2d | %2d | %2d |    ", lista->IA, lista->FA, lista->IL, lista->FL);
    if(vet[6] == true) {
        printf("| Quant: [%d] |            | |\n", lista->quant);
    } else {
        printf("| Quant: %d  |            | |\n", lista->quant);
    }
    printf("|  ---------------------     -------------------------  |\n");
    printf("|                                                       |\n");
    printf("|           ARRANJO:                                    |\n");
    printf("|  --------------------------                           |\n");
    printf("|  |  0 |  1 |  2 |  3 |  4 |                           |\n");
    printf("|  --------------------------                           |\n|  ");
    for(i = 0; i < 5; i++)
        printf("|  %c ", lista->vet[i]);
    printf("|                           |\n");
    printf("|  --------------------------                           |\n|                                                       |");
}

bool remover(LLD * lista, Local local, int pos, bool vet[]) {
    int i;
    if(local == 1) {
        if(lista->IL == -1)
            return false;
        else {
            lista->IL = lista->IL + 1;
            vet[2] = true;
            if(lista->IL > lista->FL) {
                lista->IL = lista->FL = -1;
                lista->maior = ' ';
                lista->menor = ' ';
                vet[3] = true;
                vet[4] = true;
                vet[5] = true;
            }
            if(lista->vet[lista->IL - 1] == lista->maior) {
                lista->maior = ' ';
                for(i = lista->IL; i <= lista->FL; i++)
                    if(lista->vet[i] > lista->maior)
                        lista->maior = lista->vet[i];
                    vet[5] = true;
            } else if(lista->vet[lista->IL - 1] == lista->menor) {
                lista->menor = lista->vet[lista->IL];
                for(i = lista->IL + 1; i <= lista->FL; i++)
                    if(lista->vet[i] < lista->menor)
                        lista->menor = lista->vet[i];
                    vet[4] = true;
            }
            lista->quant--;
            vet[6] = true;
            return true;
        }
    } else if(local == 2) {
        if(lista->IL == -1)
            return false;
        else {
            lista->FL = lista->FL - 1;
            vet[3] = true;
            if(lista->FL < lista->IL) {
                lista->IL = lista->FL = -1;
                lista->maior = ' ';
                lista->menor = ' ';
                vet[2] = true;
                vet[4] = true;
                vet[5] = true;
            }
            if(lista->vet[lista->FL + 1] == lista->maior) {
                lista->maior = ' ';
                for(i = lista->IL; i <= lista->FL; i++)
                    if(lista->vet[i] > lista->maior)
                        lista->maior = lista->vet[i];
                    vet[5] = true;
            } else if(lista->vet[lista->FL + 1] == lista->menor) {
                lista->menor = lista->vet[lista->IL];
                for(i = lista->IL + 1; i <= lista->FL; i++)
                    if(lista->vet[i] < lista->menor)
                        lista->menor = lista->vet[i];
                    vet[4] = true;
            }
            lista->quant--;
            vet[6] = true;
            return true;
        }
    } else {
        if((pos <= 0) || (pos > (lista->FL - lista->IL + 1)))
            return false;
        else {
            if(lista->vet[lista->IL + pos - 1] == lista->maior) {
                lista->maior = ' ';
                for(i = lista->IL; i <= lista->FL; i++)
                    if(lista->vet[i] > lista->maior && lista->vet[i] != lista->vet[lista->IL + pos - 1])
                        lista->maior = lista->vet[i];
                    vet[5] = true;
            } else if(lista->vet[lista->IL + pos - 1] == lista->menor) {
                lista->menor = lista->vet[lista->IL];
                for(i = lista->IL + 1; i <= lista->FL; i++)
                    if(lista->vet[i] < lista->menor && lista->vet[i] != lista->vet[lista->IL + pos - 1])
                        lista->menor = lista->vet[i];
                    vet[4] = true;
            }
            for(i = lista->IL + pos - 1; i <= lista->FL - 1; i++)
                lista->vet[i] = lista->vet[i + 1];
            lista->FL = lista->FL - 1;
            vet[3] = true;
            if(lista->FL == lista->IL - 1) {
                lista->FL = lista->IL = -1;
                lista->maior = ' ';
                lista->menor = ' ';
                vet[2] = true;
                vet[4] = true;
                vet[5] = true;
            }
            lista->quant--;
            vet[6] = true;
            return true;
        }
    }
    return false;
}


bool inserir(LLD * lista, Local local, int pos, char elemento, bool vet[]) {
    int i;
    if(local == 1) {
        if(lista->IA == lista->IL && lista->FA == lista->FL)
            return false;
        else {
            if(lista->IL == -1) {
                lista->IL = lista->FL = lista->IA;
                lista->menor = elemento;
                vet[2] = true;
                vet[3] = true;
                vet[4] = true;
            } else {
                if(lista->IL > lista->IA) {
                    lista->IL = lista->IL - 1;
                    vet[2] = true;
                } else {
                    for(i = lista->FL; i >= lista->IL; i--)
                        lista->vet[i + 1] = lista->vet[i];
                    lista->FL = lista->FL + 1;
                    vet[3] = true;
                }
            }
            lista->vet[lista->IL] = elemento;
            lista->quant++;
            if(elemento > lista->maior) {
                lista->maior = elemento;
                vet[5] = true;
            } else if(elemento < lista->menor) {
                lista->menor = elemento;
                vet[4] = true;
            }
            vet[6] = true;
            return true;
        }
    } else if(local == 2) {
        if(lista->IA == lista->IL && lista->FA == lista->FL)
            return false;
        else {
            if(lista->IL == -1) {
                lista->IL = lista->FL = lista->IA;
                lista->menor = elemento;
                vet[2] = true;
                vet[3] = true;
            } else {
                if(lista->FL < lista->FA) {
                    lista->FL = lista->FL + 1;
                    vet[3] = true;
                } else {
                    for(i = lista->IL; i <= lista->IL; i++)
                        lista->vet[i - 1] = lista->vet[i];
                    lista->IL = lista->IL - 1;
                    vet[2] = true;
                }
            }
            lista->vet[lista->FL] = elemento;
            lista->quant++;
            if(elemento > lista->maior) {
                lista->maior = elemento;
                vet[5] = true;
            } else if(elemento < lista->menor) {
                lista->menor = elemento;
                vet[4] = true;
            }
            vet[6] = true;
            return true;
        }
    } else {
        if((lista->IA == lista->IL && lista->FA == lista->FL) ||
                (pos > (lista->FL - lista->IL) + 2) || (pos < lista->IA) ||
                (lista->IL == -1 && pos != 1))
            return false;
        else {
            if(lista->IL == -1) {
                lista->IL = lista->FL = lista->IA;
                lista->menor = elemento;
                vet[2] = true;
                vet[3] = true;
            } else {
                if(lista->FL != lista->FA) {
                    for(i = lista->FL; i >= (lista->IL) + pos - 1; i--)
                        lista->vet[i + 1] = lista->vet[i];
                    lista->FL = lista->FL + 1;
                    vet[3] = true;
                } else {
                    for(i = lista->IL; i <= lista->IL + pos - 2; i++)
                        lista->vet[i - 1] = lista->vet[i];
                    lista->IL = lista->IL - 1;
                    vet[2] = true;
                }
            }
            lista->vet[lista->IL + pos - 1] = elemento;
            lista->quant++;
            if(elemento > lista->maior) {
                lista->maior = elemento;
                vet[5] = true;
            } else if(elemento < lista->menor) {
                lista->menor = elemento;
                vet[4] = true;
            }
            vet[6] = true;
            return true;
        }
    }
    return false;
}

void ini(bool vet[]) {
    int i;
    for(i = 0; i < 7; i++)
        vet[i] = false;
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
    LLD lista;
    bool vet[MAX];
    arq = fopen("LLD.txt", "r");
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
    inserir( & lista, 3, 3, 'X', vet);
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
