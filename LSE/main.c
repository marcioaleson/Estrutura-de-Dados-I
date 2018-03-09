#include"LSE.h"

void mostrar();

void mostrarPasso(char, int);

void mostrarPasso2(int);

void texto(FILE *);

int main(){
        char op;
        FILE *ft;
        ft = fopen("texto2.txt", "r");
        if(ft == NULL){
            printf("\nO ARQUIVO NAO PODE SER ABERTO!\n");
            exit(1);
        }
        texto(ft);
        scanf("%*c");
        system("cls");
        texto(ft);
        scanf("%*c");
        system("cls");
        lista_LSE = crialista_LSE();
        system("cls");
        texto(ft);
        mostrar();
        texto(ft);
        scanf("%*c");
        system("cls");
        texto(ft);
        mostrarPasso('A', 1);
        inserirInicio_LSE('A');
        printf("\n");
        mostrar();
        texto(ft);
        scanf("%*c");
        texto(ft);
        mostrarPasso('B', (numeroDeElementos_LSE() + 1));
        inserirFim_LSE('B');
        mostrar();
        texto(ft);
        scanf("%*c");
        texto(ft);
        mostrarPasso('C', (numeroDeElementos_LSE() + 1));
        inserirFim_LSE('C');
        mostrar();
        texto(ft);
        scanf("%*c");
        texto(ft);
        mostrarPasso('D', (numeroDeElementos_LSE() + 1));
        inserirFim_LSE('D');
        mostrar();
        texto(ft);
        scanf("%*c");
        texto(ft);
        mostrarPasso('X', 3);
        inserirPosicao_LSE(3, 'X');
        mostrar();
        texto(ft);
        scanf("%*c");
        system("cls");
        texto(ft);
        mostrarPasso2(1);
        excluirInicio_LSE();
        mostrar();
        texto(ft);
        scanf("%*c");
        texto(ft);
        mostrarPasso2(numeroDeElementos_LSE());
        excluirFim_LSE();
        mostrar();
        texto(ft);
        scanf("%*c");
        texto(ft);
        mostrarPasso2(2);
        excluirPosicao_LSE(2);
        mostrar();
        texto(ft);
        system("pause");
        printf("\n\n Fim do programa!");
        fclose(ft);
        fflush(stdin);
        op = getch();
    return 0;
}

void mostrar(){
    int j, N = numeroDeElementos_LSE();
    No *aux;
    if(N == 0){
        printf("%c PRIM %c%c%c NULL", 179, 196, 196, 16, 179);
        for(j = 0; j <51; j++)
            printf(" ");
        printf("%c\n%c", 179, 179);
        for(j = 0; j <65; j++)
            printf(" ");
        printf("%c\n%c", 179, 179);
        for(j = 0; j <65; j++)
            printf(" ");
        printf("%c", 179);
    }else{
        printf("³");
        for(j = 2; j <= 10; j++)
            printf(" ");
        for(j = 1; j <= N;j++){
            printf("%c%c%c%c%c%c%c   ",218,196, 196, 196, 194, 196, 191);
        }
        for(j = 11+10*N; j < 67; j++)
            printf(" ");
        printf("³\n³");
        aux = lista_LSE;
        printf(" PRIM %c%c%c", 196, 196, 16);
        while(aux->prox != NULL){
            printf("%c %c %c %c%c%c%c",179 ,aux->info ,179 ,179, 196, 196, 16);
            aux = aux->prox;
        }
         printf("%c %c %c/%c",179 ,aux->info ,179 ,179);
        for(j = 10*N+8; j < 67; j++)
            printf(" ");
        printf("³\n³");
        for(j = 2; j <= 10; j++)
            printf(" ");
        for(j = 1; j <= N;j++){
            printf("%c%c%c%c%c%c%c   ", 192, 196, 196, 196, 193, 196, 217);
        }
        for(j = 10*(N+1)+1; j < 67; j++)
            printf(" ");
        printf("³\n");
    }
}

void mostrarPasso(char dado, int posicao){
    int i, N = numeroDeElementos_LSE();
    if(N + 1 != posicao || posicao == 1){
        printf("³");
        for(i = 1; i <= 10*posicao-1; i++)
            printf(" ");
        printf("%c%c%c%c%c%c%c", 218, 196, 196, 196, 194, 196, 191);
        for( i += 8 ;i < 67; i++)
            printf(" ");
        printf("³\n³");
        for(i = 1; i <= 10*posicao - 6; i++)
            printf(" ");
        printf("%c--->", 218);
        printf("%c %c %c %c%c", 179, dado, 179 , 179, 191);
        for(i += 14; i < 67; i++)
            printf(" ");
        printf("³\n³");
        for(i = 1; i <= (10*posicao - 6); i++)
            printf(" ");
        printf("|    ");
        printf("%c%c%c%c%c%c%c|", 192, 196, 196, 196, 193, 196, 217);
        for(i += 14; i < 67; i++)
            printf(" ");
        printf("³\n³");
        for(i = 1; i <= 10*posicao - 6; i++)
            printf(" ");
        printf("|     %c-----%c", 218, 217);
        for(i += 14;i < 67; i++)
            printf(" ");
        printf("³\n³");
        for(i = 1; i <= 10*posicao - 6; i++)
            printf(" ");
        printf("|     %c", 31);
        for(i += 8; i < 67; i++)
            printf(" ");
        printf("³\n");
        mostrar();
    }else{
        for(i = 1; i <= 10*posicao; i++)
            printf(" ");
        printf("%c%c%c%c%c%c%c   ", 218, 196, 196, 196, 194, 196, 191);
        printf("\n");
        for(i = 1; i <= 10*posicao - 5; i++)
            printf(" ");
        printf("%c--->", 218);
        printf("%c %c %c/%c", 179, dado, 179 , 179);
        for(i = 1; i <= 7*posicao + 1; i++)
            printf(" ");
        printf("\n");
        for(i = 1; i <= 10*posicao - 5; i++)
            printf(" ");
        printf("|    ");
        printf("%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 217);
        for(i = 1; i <= 10*posicao - 5; i++)
            printf(" ");
        printf("³\n");
        mostrar();
    }
}

void mostrarPasso2(int pos){
    int i, N = numeroDeElementos_LSE();
    if(pos == N){
        printf("³");
        for(i = 1; i <= pos*10 - 5; i++)
            printf(" ");
        printf("%c", 218);
        for(i = 1; i < 9; i++)
            printf("-");
        printf("%c", 191);
        for(i = (pos*10-5)+12; i < 67; i++)
            printf(" ");
        printf("³\n³");
        for(i = 1; i <= pos*10 - 5; i++)
            printf(" ");
        printf("|");
        for(i = 1; i < 9; i++)
            printf(" ");
        printf("%c", 31);
        for(i = (pos*10-5)+12; i < 67; i++)
            printf(" ");
        printf("³\n");

    }else{
        printf("³");
        for(i = 1; i <= pos*10 - 5; i++)
            printf(" ");
        printf("%c", 218);
        for(i = 1; i <= 15; i++)
            printf("-");
        printf("%c", 191);
        for(i = (pos*10 - 5) + 19; i < 67; i++)
            printf(" ");
        printf("³\n³");
        for(i = 1; i <= pos*10 - 5; i++)
            printf(" ");
        printf("|");
        for(i = 1; i <= 15; i++)
            printf(" ");
        printf("%c", 31);
        for(i = (pos*10 - 5) + 19; i < 67; i++)
            printf(" ");
        printf("³\n");
    }
    mostrar();
}

void texto(FILE * arq){
    char str[1000];
    while(fgets(str, 100, arq)) {
        if(str[0] == '+')break;
        printf("%s", str);
    }
}
