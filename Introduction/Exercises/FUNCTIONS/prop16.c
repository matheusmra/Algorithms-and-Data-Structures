#include <stdio.h>
int soma(int vet[20]){
    int total = 0;
    for(int i = 0; i < 20; i++){
            total = total + vet[i];
    }
    printf("\nSoma de todos os numeros = %d", total);

}

int main(){
    int n = 20;
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    soma(vet);

}
