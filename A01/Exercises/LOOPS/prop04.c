#include <stdio.h>


int tabuada(int n){
    int resultado = 0;
    for(int i = 0; i < 11; i++){
        resultado = n * i;
        printf("\n %d X %d = %d", n, i, resultado);
    }


}

int main(){
    int n = 0;
    printf("Digite um numero:");
    scanf("%d", &n);
    tabuada(n);

}
