#include <stdio.h>
#include <stdbool.h>
     bool PesquisaBinaria(int vetor[], int x){
        bool resp = false;
        int dir = 9, esq = 0, meio;
        while(esq <= dir){
            meio = (esq + dir)/2;
            if(vetor[meio] == x){
                resp = true;
                esq = 9;
            }else if(vetor[meio] < x){
                esq = meio + 1;
            }else{
                dir = meio - 1;
            }
        }
        return resp;
    }
    int main(){
        int vetor [10] = {1,2,3,4,5,6,7,8,9,10};
        int x = 5;
        if(PesquisaBinaria(vetor, x)){
            printf("Valor encontrado");
        }
    }

