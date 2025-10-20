/*
 0119 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0119 0119.c
 Windows: gcc -o 0119 0119.c
 Para executar em terminal (janela de comandos):
 Linux : ./0119
 Windows: 0119
*/
#include<stdio.h>
#include<math.h>

int main(){
    double raio, area;
    printf("Digite o valor do raio:");
    scanf("%lf", &raio);
    if(raio > 0){
    raio = raio/4;
    area = (M_PI * raio * raio)/2;
    printf("O valor da area eh: %.2lf", area);
}else{
    printf("Numero invalido");
}
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
