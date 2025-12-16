#include <stdio.h>


void maior(int matrix[6][3]){
    int maior = 0;
    int imaior = 0;
    int jmaior = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] > maior){
                maior = matrix[i][j];
                imaior = i;
                jmaior = j;
            }
        }
    }
    printf("\nO maior elemento da matrix eh (%d) e ele se encontra na posicao: matrix[%d][%d]", maior, imaior,jmaior);
}


void menor(int matrix[6][3]){
    int menor = 100000000000;
    int imenor = 0;
    int jmenor = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            if(matrix[i][j] < menor){
                menor = matrix[i][j];
                imenor = i;
                jmenor = j;
            }
        }
    }
    printf("\nO menor elemento da matrix eh (%d) e ele se encontra na posicao: matrix[%d][%d]", menor, imenor,jmenor);


}

int main(){
    int matrix[6][3];
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    maior(matrix);
    menor(matrix);
}
