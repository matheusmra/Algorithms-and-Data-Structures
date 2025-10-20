#include <stdio.h>

double prop05(double v1){
    int desconto = 0.0;
    desconto = v1*0.90;
    return desconto;
}

int main(){
    double n = 0.0;
    scanf("%lf", &n);
    printf("Valor antes do desconto: %.2f", n);
    printf("\nValor com desconto: %.2f", prop05(n));
}
