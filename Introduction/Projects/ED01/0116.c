/*
 0116 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0116 0116.c
 Windows: gcc -o 0116 0116.c
 Para executar em terminal (janela de comandos):
 Linux : ./0116
 Windows: 0116
*/
#include <stdio.h>
#include <math.h> // Para usar a função sqrt

int main() {
    double lado, altura, area, perimetro;
    printf("Digite o valor do lado do triangulo equilatero: ");
    scanf("%lf", &lado);
    if(lado > 0){
    lado = lado*4;
    // Calcula a altura
    altura = (lado*sqrt(3.0))/2;

    // Calcula a área
    area = ((lado*lado)*(sqrt(3)))/4;

    // Calcula o perímetro
    perimetro = 3.0 * lado;

    printf("Altura do triangulo: %.2lf\n", altura);
    printf("\nArea do triangulo: %.2lf\n", area);
    printf("\nPerimetro do triangulo: %.2lf\n", perimetro);

    return 0;
}else{
    printf("Numero invalido");
    }
        printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}



