#include <stdio.h>

void inteiroounegativo(int n){
    if(n>0){
        printf("(%d) eh positivo", n);
    }else{
        printf("(%d) eh negativo", n);
    }

}

int main(){
    int n = 0;
    scanf("%d", &n);
    inteiroounegativo(n);

}
