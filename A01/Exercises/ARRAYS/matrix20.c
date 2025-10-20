#include <stdio.h>

int maior(int matriz[5][5]){
    int maior = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }
    return maior;
}

void preencher_matriz(int matriz[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("\nElemento [%d][%d] =", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void diagonal_principal(int matriz[5][5]){
    int n = maior(matriz);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == j){
                printf("%d", matriz[i][j] * n);
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }


}

int main(){
    int matriz[5][5];
    preencher_matriz(matriz);
    diagonal_principal(matriz);

}
