/*
 01E1 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 01E1 01E1.c
 Windows: gcc -o 01E1 01E1.c
 Para executar em terminal (janela de comandos):
 Linux : ./01E1
 Windows: 01E1
*/
#include <stdio.h>
#include <math.h>

int main() {
    double area, raio;
    printf("Digite o valor da area: ");
    scanf("%lf", &area);
    if(area > 0){

    // Calcula o raio
    raio = sqrt(area / M_PI);
    raio = raio/9;

    printf("\nO valor do raio eh: %.2lf\n", raio);

    return 0;
}else{
    printf("Numero invalido");
}
        printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
