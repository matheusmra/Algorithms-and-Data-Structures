#include <stdio.h>

int soma_matrizes(int mat1[3][8], int mat2[3][8]){
    int resultante[3][8];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            resultante[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            printf("\n%d", resultante[i][j]);
        }
        printf("\n");
    }

}

int subtracao_matrizes(int mat1[3][8], int mat2[3][8]){
    int resultante[3][8];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            resultante[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            printf("\n%d", resultante[i][j]);
        }
        printf("\n");
    }

}

void ler_matrix(int mat[3][8]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            scanf("%d", &mat[i][j]);
        }
    }

}

int main(){
    int mat1[3][8];
    int mat2[3][8];
    ler_matrix(mat1);
    ler_matrix(mat2);
    soma_matrizes(mat1,mat2);
    subtracao_matrizes(mat1,mat2);



}
