#include <stdio.h>
 
int main() {
 
    int n = 0;
    while(scanf("%d", &n) >= 1 && n <= 10000){
        if(n == 0){
            break;
        }
        int arr[n];
        int countm = 0;
        int countj = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(arr[i] == 0){
                countm++;
            }else if(arr[i] == 1){
                countj++;
            }
        }
        printf("Mary won %d times and John won %d times\n", countm, countj);
    }
 
    return 0;
}