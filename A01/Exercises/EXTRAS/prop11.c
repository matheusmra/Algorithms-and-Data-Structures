#include <stdio.h>

double area_losango(double diagonal_maior, double diagonal_menor){
    double resultado = (diagonal_maior*diagonal_menor)/2;
    return resultado;
}

int main(){
    double maior = 0.0, menor = 0.0;
    scanf("%lf %lf", &maior, &menor);
    printf("Area do losango = %.2f", area_losango(maior, menor));
}
