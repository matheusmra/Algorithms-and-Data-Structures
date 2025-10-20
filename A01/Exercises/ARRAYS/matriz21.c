#include <stdio.h>

void imprimir_matriz(int matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }

}

void transposta(int matriz[3][3]){
    int transposta[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            transposta[i][j] = matriz[j][i];
        }
    }
    imprimir_matriz(transposta);
}


void preencher_matriz(int matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("\nElemento [%d][%d] =", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }


}

int main(){
    int matriz[3][3];
    preencher_matriz(matriz);
    printf("\nMATRIZ ORIGINAL:\n");
    imprimir_matriz(matriz);
    printf("\nMATRIZ TRANSPOSTA:\n");
    transposta(matriz);

}
