#include <stdio.h>


int total_pares(int matriz[3][4]){
    int total = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(matriz[i][j]%2 == 0){
                total++;
            }
        }
    }
    return total;
}


int total_impares(int matriz[3][4]){
    int total = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(matriz[i][j]%2 != 0){
                total++;
            }
        }
    }
    return total;
}

int media_elementos(int matriz[3][4]){
    int total = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            total+= matriz[i][j];
        }
    }
    return total/12;

}

void preencher_matriz(int matriz[3][4]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("\nElemento [%d][%d] =", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }

}

void imprimir_matriz(int matriz[3][4]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }

}

int main(){
    int matriz[3][4];
    preencher_matriz(matriz);
    printf("\nMATRIZ:\n");
    imprimir_matriz(matriz);
    int pares = total_pares(matriz);
    int impares = total_impares(matriz);
    int media = media_elementos(matriz);
    printf("\nTOTAL DE NUMEROS PARES: %d", pares);
    printf("\nTOTAL DE NUMEROS IMPARES: %d", impares);
    printf("\nMEDIA DOS ELEMENTOS: %d", media);

}
