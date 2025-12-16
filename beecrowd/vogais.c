#include <stdio.h>
 
int main() {
 
    int n;
    while(scanf("%d", &n) != 0){
        if(n == 1) printf("B\n");
        if(n == 2) printf("BA\n");
        if(n == 3) printf("CB\n");
        if(n == 4) printf("BAA\n");
        if(n == 5) printf("BCB\n");
        if(n == 6) printf("CBA\n");
        if(n == 7) printf("DAB\n");
        if(n == 8) printf("BAAA\n");
        if(n == 0 || n > 8) return 0;
    }
 
    return 0;
}