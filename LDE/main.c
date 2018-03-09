#include"LDE.h"

void mostrar(No *l);

void texto(FILE *);

int main(){
        char op;
        FILE *ft;
        ft = fopen("LDE.txt", "r");
        if(ft == NULL){
            printf("\nO ARQUIVO NAO PODE SER ABERTO!\n");
            exit(1);
        }
        texto(ft);
        scanf("%*c");
        system("cls");
        No *l = crialista_LDE();
        texto(ft);
        mostrar(l);
        texto(ft);
        scanf("%*c");
        inserirPosicao_LDE(l, 1, 'A');
        texto(ft);
        mostrar(l);
        texto(ft);
        scanf("%*c");
        texto(ft);
        inserirPosicao_LDE(l, 2, 'B');
        mostrar(l);
        texto(ft);
        scanf("%*c");
        texto(ft);
        inserirPosicao_LDE(l, 3, 'C');
        mostrar(l);
        texto(ft);
        scanf("%*c");
        texto(ft);
        inserirPosicao_LDE(l, 4, 'D');
        mostrar(l);
        texto(ft);
        scanf("%*c");
        texto(ft);
        inserirPosicao_LDE(l, 3, 'X');
        mostrar(l);
        texto(ft);
        scanf("%*c");
        system("cls");
        texto(ft);
        excluirPosicao_LDE(l, 1);
        mostrar(l);
        texto(ft);
        scanf("%*c");
        texto(ft);
        excluirPosicao_LDE(l, 4);
        mostrar(l);
        texto(ft);
        scanf("%*c");
        texto(ft);
        excluirPosicao_LDE(l, 2);
        mostrar(l);
        texto(ft);
        system("pause");
        printf("\n\n Fim do programa!");
        fclose(ft);
        fflush(stdin);
        op = getch();
    return 0;
}

void mostrar(No *l){
    if(l->prox == NULL){
        printf("�������Ŀ\n");
        printf("�/�   �/�\n");
        printf("���������\n");
    }else{
        int j;
        No *aux;
        aux = l;
        printf(" ");
        while(aux != NULL)
        {
            if(aux->prox != NULL){
                printf("�������Ŀ��%c", 16);
            }else{
                printf("�������Ŀ    ");
            }
            aux = aux->prox;
        }
        printf("\n ");
        aux = l;
        while(aux != NULL){
            if(aux->ant != NULL){
                if(aux->prox != NULL){
                    printf("%c�ĳ � %c � �", 17, aux->info);
                }else{
                    printf("%c�ĳ � %c �/�", 17, aux->info);
                }
            }else{
                printf("�/� %c � �", aux->info);
            }
            aux = aux->prox;
        }
        printf("\n ");
        aux = l;
        while(aux != NULL){
            printf("���������   ");
            aux = aux->prox;
        }
        printf("\n");
    }
}

void texto(FILE * arq){
    char str[1000];
    while(fgets(str, 100, arq)) {
        if(str[0] == '+')break;
        printf("%s", str);
    }
}
