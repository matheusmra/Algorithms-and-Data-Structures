#include <stdio.h>
#include <stdbool.h>

bool PesquisaSequencial(int matriz[], int n){
    for(int i = 0; i < 10; i++){
        if(matriz[i] == n){
            i = n;
            return true;
        }
    }
    return false;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int matriz[10] = {50,10,20,30,40,1,3,4,0,76};
    if(PesquisaSequencial(matriz, n)){
        printf("O numero %d foi encontrado", n);
    }else{
        printf("O numero digitado nao existe no array");
    }
}
