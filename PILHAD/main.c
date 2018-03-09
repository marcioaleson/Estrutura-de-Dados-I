#include"PILHAD.h"

void texto(FILE *);

int main(){
    FILE *ft;
    ft = fopen("PILHAD.txt", "r");
    if(ft == NULL){
        printf("\nO ARQUIVO NAO PODE SER ABERTO!\n");
        exit(1);
    }
    texto(ft);
    scanf("%*c");
    system("cls");
    topo = cria_pl();
    texto(ft);
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    push('A');
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    push('B');
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    push('C');
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    push('D');
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    push('X');
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    system("cls");
    texto(ft);
    pop();
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    pop();
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    texto(ft);
    pop();
    imprimepilha_din();
    texto(ft);
    scanf("%*c");
    return 0;
}

void texto(FILE * arq){
    char str[1000];
    while(fgets(str, 100, arq)) {
        if(str[0] == '+')break;
        printf("%s", str);
    }
}
