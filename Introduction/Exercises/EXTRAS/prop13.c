#include <stdio.h>

int tabuada(int n){
    int resultado;
    for(int i = 0; i < 11; i++){
        resultado = n*i;
        printf("\n 5 x %d = %d", i, resultado);
    }

}

int main(){
    int n = 0;
    scanf("%d", &n);
    tabuada(n);
}
