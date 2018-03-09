#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    char info;
} No;

typedef struct {
    No vetor[MAX];
} Fila;

int IF, FF, IA, FA;
bool vet[4];


void inicializar(Fila * F) {
    IF = FF = -1;
    IA = 0;
    FA = 4;
    int i;
    for(i = 0; i < MAX; i++)
        F->vetor[i].info = ' ';
}

void inserir(Fila * F, char info) {
    if(IF != IA || FF != FA) { //Possui espaço
        if(IF == -1) { //Não possui elementos na Fila
            IF = FF = 0;
            F->vetor[FF].info = info;
            vet[2] = true;
            vet[3] = true;
        } else {
            if(FF != FA) { //Possui espaço a direita
                FF++;
                F->vetor[FF].info = info;
                vet[3] = true;
            } else {
                int i;
                for(i = IF; i < FF; i++)
                    F->vetor[i - 1].info = F->vetor[i].info;
                F->vetor[FF].info = info;
                IF--;
                vet[2] = true;
            }
        }
    }
}

void remover(Fila * F) {
    F->vetor[IF].info = ' ';
    IF++;
    vet[2] = true;
    if(IF == FF + 1) { //Fila ficou vazia
        IF = FF = -1;
        vet[2] = true;
    }
}

void ini() {
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

void mostrar(Fila * F) {
    printf("|  -------------------                                                  |\n");
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
    printf("                                                 |\n");
    printf("|  -------------------                                                  |\n");
    printf("| | %2d | %2d | %2d | %2d |                                                 |\n", IA, FA, IF, FF);
    printf("|  -------------------                                                  |\n");
    printf("|                                                                       | \n");
    printf("|          ARRANJO:                                                     |\n");
    printf("|  ------------------------                                             |\n");
    printf("| |  0 |  1 |  2 |  3 |  4 |                                            |\n");
    printf("|  ------------------------                                             |\n");
    printf("| |  %c |  %c |  %c |  %c |  %c |                                            |\n", F->vetor[0].info, F->vetor[1].info, F->vetor[2].info, F->vetor[3].info, F->vetor[4].info);
    printf("|  ------------------------                                             |\n");
    printf("|                                                                       |");
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
