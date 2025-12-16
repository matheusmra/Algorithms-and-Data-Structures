/*
 01E2 - v0.0. - 17 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 01E2 01E2.c
 Windows: gcc -o 01E2 01E2.c
 Para executar em terminal (janela de comandos):
 Linux : ./01E2
 Windows: 01E2
*/
#include <stdio.h>
#include <math.h>

int main() {
    double volume, raio, area;
    printf("Digite o valor do volume: ");
    scanf("%lf", &volume);
    if(volume > 0){
    volume = volume/7;
    volume = volume*3;
    // Calcula o raio
    raio = sqrt(volume / M_PI);
    area = 4 * M_PI * (raio*raio);
    printf("\nO valor do raio eh: %.2lf\n", raio);
    printf("\nO valor da area eh: %.2lf\n", area);

    return 0;
}else{
    printf("Numero invalido");
}
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}

