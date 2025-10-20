#include <stdio.h>

void preencher_matriz(double matrix[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%lf", &matrix[i][j]);
        }
    }

}

void printar_matriz(double matrix[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%2.f", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplicar_matriz(double matrix[3][3], int n){
    double resultado[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            resultado[i][j] = matrix[i][j] * n;
        }
    }
    printf("\nMATRIZ ORIGINAL:\n");
    printar_matriz(matrix);
    printf("\nMATRIZ MULTIPLICADA POR %d:\n", n);
    printar_matriz(resultado);
}


int main(){
    int n = 0;
    printf("N =");
    scanf("%d", &n);
    double matrix[3][3];
    preencher_matriz(matrix);
    multiplicar_matriz(matrix,n);

}
