#include <stdio.h>


int total(int matrix[3][5]){
    int total =0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(matrix[i][j] >= 15 && matrix[i][j] <= 20){
                total++;
            }
        }
    }
    return total;
}

int main(){
    int matrix[3][5];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    int media = total(matrix);
    printf("O total de elementos entre 15 e 20 eh: %d", media);
}

