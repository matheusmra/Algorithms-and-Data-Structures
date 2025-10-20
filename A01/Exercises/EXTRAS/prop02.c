#include <stdio.h>

int prop02(int v1, int v2, int v3){
    int resultado = 0;
    resultado = v1*v2*v3;
    return resultado;
}

int main(){
    int n1 = 0, n2 = 0, n3 = 0;
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("%d", prop02(n1,n2,n3));

}
