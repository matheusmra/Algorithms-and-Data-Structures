#include <stdio.h>

double area(double b_maior, double b_menor, double altura){
    double area = 0.0;
    area = ((b_maior + b_menor)*altura)/2;
    return area;
}

int main(){
    double b_maior = 0.0, b_menor = 0.0, altura = 0.0;
    scanf("%lf %lf %lf", &b_maior, &b_menor, &altura);
    printf("Base maior = %.2f \nBase Menor = %.2f \nAltura = %.2f", b_maior, b_menor, altura);
    printf("\nArea do trapezio = %.2f", area(b_maior, b_menor, altura));

}
