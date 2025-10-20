/*
 0112 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0112 0112.c
 Windows: gcc -o 0112 0112.c
 Para executar em terminal (janela de comandos):
 Linux : ./0112
 Windows: 0112
*/
#include<stdio.h>

int main(){
    int lq, area, perimetro; // LQ == Lado quadrado
    printf("Digite o valor do lado:");
    scanf("%d", &lq); // Armazena o valor digita no endereco de memoria da variavel lq
    if(lq > 0){
    lq = lq/3; // Altera o valor do lado para um terço;
    area = lq*lq; // Calcula a area do quadrado
    perimetro = lq*4; // Calcula o perimetro de um terço do lado
    printf("A area do quadrado eh: %d", area);
    printf("\nO perimetro do quadrado eh: %d", perimetro);
}else{
    printf("Numero invalido");
    }
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
