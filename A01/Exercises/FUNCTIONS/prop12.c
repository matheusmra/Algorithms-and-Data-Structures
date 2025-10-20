#include <stdio.h>


int pot(int x, int z){
    if(z == 0){
        return 1;
    }else{
        return x = x *pot(x, z-1);
    }

}

int main(){
    int x = 0, z = 0;
    scanf("%d %d", &x, &z);
    printf("%d elevado a %d = %d", x, z, pot(x,z));

}
