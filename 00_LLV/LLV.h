#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 20

int IL, FL, IA, FA;

void inicializar(char vetor[], bool vet[]);
void mostrar(char vetor[], bool vet[]);
bool remover(char vetor[], int local, int pos, bool vet[]);
bool inserir(char vetor[], int local, int pos, char elemento, bool vet[]);
void principal();

void inicializar(char vetor[], bool vet[]) {
    int i;
    IA = 0;
    FA = 4;
    IL = -1;
    FL = -1;
    for(i = 0; i < 5 ; i++) {
        vetor[i] = 32;
        vet[i] = true;
    }
}

void mostrar(char vetor[], bool vet[]) {
    printf("|  -------------------                                  |\n");
    printf("| |");
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
        printf("[FL]|");
    } else {
        printf(" FL |");
    }
    printf("                                 |\n");
    printf("|  -------------------                                  |\n");
    printf("| | %2d | %2d | %2d | %2d |                                 |\n", IA, FA, IL, FL);
    printf("|  -------------------                                  |\n");
    printf("|                                                       | \n");
    printf("|          ARRANJO:                                     |\n");
    printf("|  ------------------------                             |\n");
    printf("| |  0 |  1 |  2 |  3 |  4 |                            |\n");
    printf("|  ------------------------                             |\n");
    printf("| |  %c |  %c |  %c |  %c |  %c |                            |\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4]);
    printf("|  ------------------------                             |\n");
    printf("|                                                       |");
}

bool remover(char vetor[], int local, int pos, bool vet[]) {
    int i;
    if(local == 1) {
        if(IL == -1)
            return false;
        else {
            IL = IL + 1;
            vet[2] = true;
            if(IL > FL) {
                IL = FL = -1;
                vet[3] = true;
            }
        }
    } else if(local == 2) {
        if(IL == -1)
            return false;
        else {
            FL = FL - 1;
            vet[3] = true;
            if(FL < IL) {
                IL = FL = -1;
                vet[2] = true;
            }
        }
    } else {
        if((pos <= 0) || (pos > (FL - IL + 1)))
            return false;
        else {
            for(i = IL + pos - 1; i <= FL - 1; i++)
                vetor[i] = vetor[i + 1];
            FL = FL - 1;
            vet[3] = true;
            if(FL == IL - 1) {
                FL = IL = -1;
                vet[2] = true;
            }
            return true;
        }
    }
    return false;
}


bool inserir(char vetor[], int local, int pos, char elemento, bool vet[]) {
    int i;
    if(local == 1) {
        if(IA == IL && FA == FL)
            return false;
        else {
            if(IL == -1) {
                IL = FL = IA;
                vet[2] = true;
                vet[3] = true;
            } else {
                if(IL > IA) {
                    IL = IL - 1;
                    vet[2] = true;
                } else {
                    for(i = FL; i >= IL; i--)
                        vetor[i + 1] = vetor[i];
                    FL = FL + 1;
                    vet[3] = true;
                }
            }
            vetor[IL] = elemento;
            return true;
        }
    } else if(local == 2) {
        if(IA == IL && FA == FL)
            return false;
        else {
            if(IL == -1) {
                IL = FL = IA;
                vet[2] = true;
                vet[3] = true;
            } else {
                if(FL < FA) {
                    FL = FL + 1;
                    vet[3] = true;
                } else {
                    for(i = IL; i <= FL; i++)
                        vetor[i - 1] = vetor[i];
                    IL = IL - 1;
                    vet[2] = true;
                }
            }
            vetor[FL] = elemento;
            return true;
        }
    } else {
        if((IA == IL && FA == FL) ||
                (pos > (FL - IL) + 2) || (pos < IA) ||
                (IL == -1 && pos != 1))
            return false;
        else {
            if(IL == -1) {
                IL = FL = IA;
                vet[2] = true;
                vet[3] = true;
            } else {
                if(FL != FA) {
                    for(i = FL; i >= (IL) + pos - 1; i--)
                        vetor[i + 1] = vetor[i];
                    FL = FL + 1;
                    vet[3] = true;
                } else {
                    for(i = IL; i <= IL + pos - 2; i++)
                        vetor[i - 1] = vetor[i];
                    IL = IL - 1;
                    vet[2] = true;
                }
            }
            vetor[IL + pos - 1] = elemento;
            return true;
        }
    }
    return false;
}

void ini(bool vet[]) {
    int i;
    for(i = 0; i < 4; i++)
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
    char vetor[MAX];
    bool vet[MAX];
    arq = fopen("LLV.txt", "r");
    texto(arq);
    scanf("%*c");
    system("cls");
    texto(arq);
    scanf("%*c");
    inicializar( vetor, vet);
    system("cls");
    texto(arq);
    mostrar( vetor, vet);
    scanf("%*c");
    ini(vet);
    inserir( vetor, 1, 0, 'A', vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( vetor, 2, 0, 'B', vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( vetor, 2, 0, 'C', vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( vetor, 2, 0, 'D', vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    inserir( vetor, 3, 3, 'X', vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    system("cls");
    ini(vet);
    remover( vetor, 1, 0, vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    remover( vetor, 2, 0, vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    ini(vet);
    remover( vetor, 3, 2, vet);
    texto(arq);
    mostrar( vetor, vet);
    texto(arq);
    scanf("%*c");
    fclose(arq);
}