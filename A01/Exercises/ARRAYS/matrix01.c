#include <stdio.h>

#define TAM_MAX 10

int maior(int mat[2][2]){
    int maior = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(mat[i][j] > maior){
                maior = mat[i][j];
            }
        }
    }
    return maior;


}

int main(){
    int matrix[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int maiora = maior(matrix);
    int resultante[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            resultante[i][j] = (matrix[i][j]*maiora);
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("\n%d", resultante[i][j]);
        }
    }



}
