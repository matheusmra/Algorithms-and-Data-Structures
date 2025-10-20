#include <stdio.h>

int prop01(int v1, int v2){
    int resultado = 0;
    resultado = v1 - v2;
    return resultado;
}
int main(){
    int n1 = 0, n2 = 0;
    printf("Digite o valor do primeiro numero:");
    scanf("%d", &n1);
    printf("\nDigite o valor do segundo numero:");
    scanf("%d", &n2);
    printf("\n O resultado eh: %d", prop01(n1,n2));

}
