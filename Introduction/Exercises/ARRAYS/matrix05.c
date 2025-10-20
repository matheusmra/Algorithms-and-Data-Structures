#include <stdio.h>


void total_mes(int matrix[12][4]){
    for(int i = 0; i < 12; i++){
        int total = 0;
        for(int j = 0; j< 4; j++){
        total += matrix[i][j];
        }
        printf("\nTotal de vendas no mes (%d) = R$%d", i, total);
    }

}

void total_semana(int matrix[12][4]){
    for(int i = 0; i < 12; i++){
        for(int j = 0 ; j< 4; j++){
        int total = 0;
        total += matrix[i][j];
        printf("\nTotal de vendas na semana (%d) do mes (%d) = R$%d",j, i, total);
        }
    }

}

void total_ano(int matrix[12][4]){
    int total = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0 ; j< 4; j++){
        total += matrix[i][j];
        }
    }
    printf("\nTotal de vendas no ano = R$%d",total);

}

int main(){
    int matrix[12][4];
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 4; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    total_mes(matrix);
    total_semana(matrix);
    total_ano(matrix);


}
