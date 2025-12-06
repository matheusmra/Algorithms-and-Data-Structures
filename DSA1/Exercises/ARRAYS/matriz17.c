#include <stdio.h>


void preencher_matriz(int matriz[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

}

int media_diagonal_principal(int matriz[10][10]){
    int soma = 0;
    for(int i = 0; i < 10; i++){
            soma += matriz[i][i];
            }
    return soma/10;
}

int main(){
    int matriz[10][10];
    preencher_matriz(matriz);
    int media = media_diagonal_principal(matriz);
    printf("A media da diagonal principal eh: %d", media);

}
