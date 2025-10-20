#include <stdio.h>

int pares(int vet[15]){
    int total = 0;
    for(int i = 0; i < 15; i++){
        if(vet[i]%2==0){
            printf("\n%d EH PAR", vet[i]);
            total++;
        }
    }
    printf("\nTotal de pares = %d", total);

}

int main(){
    int n = 15;
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    pares(vet);

}
