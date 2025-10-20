#include <stdio.h>

double area(double lado){
   double total = 0.0;
   total = lado*lado;
   return total;

}

int main() {
    double lado = 0.0;
    scanf("%lf", &lado);
    printf("Valor do lado = %.2f \nValor da area = %.2f", lado, area(lado));
}
