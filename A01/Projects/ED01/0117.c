/*
 0117 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0117 0117.c
 Windows: gcc -o 0117 0117.c
 Para executar em terminal (janela de comandos):
 Linux : ./0117
 Windows: 0117
*/
#include<stdio.h>

int main(){
    double lado, volume;
    printf("Digite o valor do lado:");
    scanf("%lf", &lado); // Armazena o valor digita no endereco de memoria da variavel base
    if(lado > 0){
    lado = lado*7;
    volume = lado*lado*lado;
    printf("O volume do cubo eh: %.2lf", volume);
}else{
    printf("Numero invalido");
}
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
