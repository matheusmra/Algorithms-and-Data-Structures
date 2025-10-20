#include <stdio.h>

double convertor(double peso){
    double gramas = 0.0;
    gramas = peso * 1000;
    return gramas;
}

int main(){
    double peso = 0.0;
    scanf("%lf", &peso);
    printf("Peso em KG = %.2f", peso);
    printf("\nPeso em GRAMAS = %.2f", convertor(peso));
}
