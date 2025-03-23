#include <stdio.h>
int main(){

    char resp[6];
    int tv = 0;
    for(int i = 0; i < 6; i++){
        scanf("%c", &resp[i]);
        getchar();
        if(resp[i] == 'V'){
            tv++;
        }
        if(resp[i] != 'V' && resp[i] != 'P'){
           return 0;
        }
    }
    if(tv >= 1 && tv <= 2){
        printf("3");
    }else if(tv >= 3 && tv <= 4){
        printf("2");
    }else if(tv >= 5 && tv <= 6){
        printf("1");
    }else{
        printf("-1");
    }
}
