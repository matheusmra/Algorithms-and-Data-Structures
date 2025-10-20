#include <stdio.h>

void funcao_a(double peso){
    double npeso = 0.0;
    npeso =  peso * 1.15;
    printf("\nPeso apos engordar 15 porcento: %.2f", npeso);
}

void funcao_b(double peso){
    double npeso2 = 0.0;
    npeso2 = peso * 0.80;
    printf("\nPeso apos perder 20 porcento: %.2f", npeso2);
}

int main(){
    double peso = 0.0;
    scanf("%lf", &peso);
    printf("Peso atual: %.2f", peso);
    funcao_a(peso);
    funcao_b(peso);
}
