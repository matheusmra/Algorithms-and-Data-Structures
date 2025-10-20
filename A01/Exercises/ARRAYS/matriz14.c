#include <stdio.h>

void preencher_matriz(int matriz[2][3]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int total(int matriz[2][3]){
    int total = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] >= 5 && matriz[i][j] <= 12){
                total++;
            }
        }
    }
    return total;
}

int main(){
    int matriz[2][3];
    preencher_matriz(matriz);
    int n = total(matriz);
    printf("\nO total de elementos entre 5 e 12 na matriz eh: %d", n);

}
