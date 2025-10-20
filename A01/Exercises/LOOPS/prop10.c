#include <stdio.h>


int par(int n){
    int soma = 0;
    if(n%2 == 0){
        soma++;
    }
    return soma;
}

int impar(int n){
    int somai = 0;
    if(n %2 != 0){
        somai++;
    }
    return somai;
}

int main(){
    int totalp = 0, totali = 0;
    int n = 10;
    int pessoas[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &pessoas[i]);
    }
    for(int i = 0; i < n; i++){
       totalp += par(pessoas[i]);
       totali += impar(pessoas[i]);

    }
    printf("Soma dos numeros pares = %d", totalp);
    printf("\nSoma dos numeros impares = %d", totali);

}

