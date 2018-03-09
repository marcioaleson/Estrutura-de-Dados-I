#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int IF, FF, IA, FA, quant;
    char maior, menor;
} Descritor;

typedef struct {
    char info;
} No;

typedef struct {
    No vetor[MAX];
    Descritor D;
} Fila;


bool vet[7];

void inicializar(Fila * F) {
    F->D.IF = F->D.FF = -1;
    F->D.quant = F->D.IA = 0;
    F->D.FA = 4;
    F->D.maior = F->D.menor = ' ';
    vet[6] = true;
    int i;
    for(i = 0; i < MAX; i++)
        F->vetor[i].info = ' ';
}

void inserir(Fila * F, char info) {
    if(F->D.IF != F->D.IA || F->D.FF != F->D.FA) { //Possui espaço
        if(F->D.IF == -1) { //Não possui elementos na Fila
            F->D.IF = F->D.FF = 0;
            F->vetor[F->D.FF].info = info;
            F->D.maior = F->D.menor = info;
            vet[2] = vet[3] = vet[4] = vet[5] = true;
        } else {
            if(F->D.FF != F->D.FA) { //Possui espaço a direita
                F->D.FF++;
                F->vetor[F->D.FF].info = info;
                vet[3] = true;
            } else {
                int i;
                for(i = F->D.IF; i < F->D.FF; i++)//Caso não tenha espaço, se movimenta os elementos para a esquerda
                    F->vetor[i - 1].info = F->vetor[i].info;
                F->vetor[F->D.FF].info = info;
                F->D.IF--;
                vet[2] = true;
            }
        }
        if(info > F->D.maior) {
            F->D.maior = info;
            vet[5] = true;
        } else if(info < F->D.menor) {
            F->D.menor  = info;
            vet[4] = true;
        }
        F->D.quant++;
    }
}

void remover(Fila * F) {
    int i;
    if(F->vetor[F->D.IF].info == F->D.maior) {
        F->D.maior = 0;
        for(i = F->D.IF + 1; i <= F->D.FF; i++)
            if(F->vetor[i].info > F->D.maior)
                F->D.maior = F->vetor[i].info;
        vet[5] = true;
    } else if(F->vetor[F->D.IF].info == F->D.menor) {
        F->D.menor = 'z'+1;
        for(i = F->D.IF + 1; i <= F->D.FF; i++)
            if(F->vetor[i].info < F->D.menor)
                F->D.menor = F->vetor[i].info;
        vet[4] = true;
    }
    F->vetor[F->D.IF].info = ' ';
    F->D.IF++;
    vet[2] = true;
    if(F->D.IF == F->D.FF + 1) { //Fila ficou vazia
        F->D.IF = F->D.FF = -1;
        vet[2] = true;
    }
    F->D.quant--;
}

void ini() {
    int i;
    for(i = 0; i < 6; i++)
        vet[i] = false;
}

void texto(FILE * arq) {
    char str[1000];
    while(fgets(str, 100, arq)) {
        if(str[0] == '.')break;
        printf("%s", str);
    }
}

void mostrar(Fila * F) {
    int i;
    printf("|  ---------------------     -------------------------                  |\n");
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
        printf("| Menor: [%c] |", F->D.menor);
    } else {
        printf("| Menor: %c  |", F->D.menor);
    }
    if(vet[5] == true) {
        printf(" Maior: [%c]", F->D.maior);
    } else {
        printf(" Maior: %c ", F->D.maior);
    }
    if(vet[4] != vet[5])
        printf(" |                  |\n");
    else if(vet[4] == true && vet[4] == vet[5])
        printf(" |                 |\n");
    else
        printf(" |                   |\n");
    printf("|  ---------------------     -------------------------                  |\n");
    printf("|  | %2d | %2d | %2d | %2d |    ", F->D.IA, F->D.FA, F->D.IF, F->D.FF);
    if(vet[6] == true) {
        printf("| Quant: [%d] |            |                 |\n", F->D.quant);
    } else {
        printf("| Quant: %d  |            |                 |\n", F->D.quant);
    }
    printf("|  ---------------------     -------------------------                  |\n");
    printf("|                                                                       |\n");
    printf("|           ARRANJO:                                                    |\n");
    printf("|  --------------------------                                           |\n");
    printf("|  |  0 |  1 |  2 |  3 |  4 |                                           |\n");
    printf("|  --------------------------                                           |\n|  ");
    for(i = 0; i < 5; i++)
        printf("|  %c ", F->vetor[i].info);
    printf("|                                           |\n");
    printf("|  --------------------------                                           |\n|                                                                       |");
}

void principal() {
    Fila F;
    FILE * arq;
    arq = fopen("FILA.txt", "r");
    texto(arq);
    scanf("%*c");
    system("cls");
    ini();
    inicializar( & F);
    texto(arq);
    mostrar( & F);
    scanf("%*c");
    ini();
    inserir( & F, 'A');
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    inserir( & F, 'B');
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    inserir( & F, 'C');
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    inserir( & F, 'D');
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    inserir( & F, 'X');
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    system("cls");
    remover( & F);
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    remover( & F);
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    ini();
    remover( & F);
    texto(arq);
    mostrar( & F);
    texto(arq);
    scanf("%*c");
    fclose(arq);
}
