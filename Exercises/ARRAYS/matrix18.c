#include <stdio.h>

void ler_matriz(double matriz[5][5]){
    for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                printf("Elemento [%d] [%d] =", i,j);
                scanf("%lf", &matriz[i][j]);
            }
        }

}

void printar_matriz(double matriz[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf(" %.2f", matriz[i][j]);
        }
        printf("\n");
    }



}

void printar_matriz_secundaria(double matriz[5][5]) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(j == 5 - 1 - i)
                printf("%.2f ", matriz[i][j]);
            else
                printf("     ");
        }
        printf("\n");
    }
}

double soma_diagonal_secundaria(double matriz[5][5]){
    int soma = 0;
    for(int i = 0; i < 5; i++){
        soma += matriz[i][5-1-i];
    }
    return soma;
}

int main(){
    int matriz[5][5];
    ler_matriz(matriz);
    printf("\nMATRIZ ORIGINAL:\n");
    printar_matriz(matriz);
    printf("\nDIAGONAL SECUNDARIA:\n");
    printar_matriz_secundaria(matriz);
    double soma = soma_diagonal_secundaria(matriz);
    printf("\nSOMA DA DIAGONAL SECUNDARIA: %.2f", soma);

}
