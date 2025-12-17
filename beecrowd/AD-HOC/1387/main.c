#include <stdio.h>
int main() {
    int L, R;
    while(scanf("%d %d", &L, &R) == 2){
        if (L == 0 && R == 0) {
            break;   
        }
        if(L >= 1 && L <= 5 && R >= 1 && R <= 5){
            printf("%d\n", L + R);
        }
    }
    
}