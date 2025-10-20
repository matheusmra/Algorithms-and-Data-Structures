#include <stdio.h>

int soma(int n){
    int total = 0;
    for(int i = 1; i <=n; i++){
        total += i;
    }
    return total;
}

int main(){
    int n = 0;
    scanf("%d", &n);
    printf("SOMA DE 1 ATE %d = %d", n, soma(n));

}
