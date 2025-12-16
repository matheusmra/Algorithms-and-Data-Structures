/*
 0120 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0120 0120.c
 Windows: gcc -o 0120 0120.c
 Para executar em terminal (janela de comandos):
 Linux : ./0120
 Windows: 0120
*/
#include <stdio.h>
#include <math.h>

int main() {
    double raio, volume;
    printf("Digite o valor do raio: ");
    scanf("%lf", &raio);
    if(raio > 0){



    // Calcula o raio menor
    raio = raio / 5.0;
    raio = raio * 3.0;

    // Calcula o volume da esfera
    volume = (4.0 / 3.0) * M_PI * raio * raio * raio;

    printf("O valor do volume eh: %.2lf\n", volume);

    return 0;
}else{
    printf("Numero invalido");
    }
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}

