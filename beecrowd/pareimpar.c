#include <stdio.h>

void b_cresc(int vet[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(vet[j] > vet[j+1]){
            int temp = vet[j];
            vet[j] = vet[j+1];
            vet[j+1] = temp;
        }
    }
    }
}

void b_decres(int vet[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(vet[j] < vet[j+1]){
            int temp = vet[j];
            vet[j] = vet[j+1];
            vet[j+1] = temp;
        }
    }
}
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int cp = 0;
    int ci = 0;
    if(n > 1 && n < 100000){
        int vetor[n];
        int p[n];
        int im[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &vetor[i]);
            if(vetor[i] %2 == 0){
                p[cp++] = vetor[i];
            }else{
                im[ci++] = vetor[i];
            }
        }
        b_cresc(p,cp);
        b_decres(im,ci);
        for(int i = 0; i < cp; i++){
            printf("%d\n", p[i]);
        }
        for(int i = 0; i < ci; i++){
            printf("%d\n", im[i]);
        }
    }
}