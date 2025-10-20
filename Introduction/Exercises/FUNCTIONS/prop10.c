#include <stdio.h>


double somatorio(int n){
    int controle = 2;
    if(n > 0){
        printf("(1)");
        printf("\n+");
        for(int i = 2; i <=n; i++){
        printf("\n(1/%d)", controle);
        printf("\n +");
        controle++;
        }

    }


}


int main(){
    int n = 0;
    scanf("%d", &n);
    somatorio(n);


}
