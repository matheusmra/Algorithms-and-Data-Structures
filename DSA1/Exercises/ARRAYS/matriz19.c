#include <stdio.h>

void preencher_matriz(int matriz[8][6]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 6; j++){
            printf("\nElemento [%d][%d] =", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

}

void imprimir_matriz(int matriz[8][6]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 6; j++){
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }
}

double media_matriz(int matriz[8][6]){
    double soma = 0;
    int total = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 6; j++){
            if(i%2 == 0){
                soma += matriz[i][j];
                total++;
            }
        }
    }
    return soma/total;

}

int main(){
    int matriz[8][6];
    preencher_matriz(matriz);
    printf("\nMATRIZ:\n");
    imprimir_matriz(matriz);
    double media = media_matriz(matriz);
    printf("\nMEDIA DOS ELEMENTOS DAS LINHAS PARES = %.2f", media);

}
