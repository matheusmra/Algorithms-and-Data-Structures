#include <stdio.h>


int fatorial(n){
    if(n == 1 || n ==0){
    return 1;
    }else{
    return n * fatorial(n-1);
    }

}

int main(){
    int n = 0;
    scanf("%d", &n);
    printf("Fatorial de %d = %d", n, fatorial(n));

}
