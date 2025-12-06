#include <stdio.h>


int media(int matrix[2][4]){
    int total = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            if(matrix[i][j] %2 == 0){
                total += matrix[i][j];
            }
        }
    }
    return total/8;

}


void total_pares_linhas(int matrix[2][4]){
    for(int i = 0; i < 2; i++){
        int total = 0;
        for(int j = 0; j < 4; j++){
            if(matrix[i][j] >= 12 && matrix[i][j] <= 20){
                total++;
            }
        }
         printf("\nTotal de elementos entre 12 e 20 na linha %d = %d", i, total);
    }

}

int main(){
    int matrix[2][4];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int mediapares = media(matrix);
    printf("\nA media de numeros pares na matriz eh %d", mediapares);
    total_pares_linhas(matrix);



}

