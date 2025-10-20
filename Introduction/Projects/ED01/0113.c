/*
 0113 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0113 0113.c
 Windows: gcc -o 0113 0113.c
 Para executar em terminal (janela de comandos):
 Linux : ./0113
 Windows: 0113
*/
#include<stdio.h>

int main(){
    int lr, lr2, area; // LR == Lado retangulo
    printf("Digite o valor do primeiro lado:");
    scanf("%d", &lr); // Armazena o valor digita no endereco de memoria da variavel lr
    printf("Digite o valor do segundo lado:");
    scanf("%d", &lr2); // Armazena o valor digita no endereco de memoria da variavel lr2
    if(lr && lr2 > 0){
    lr = lr*3; // Aumenta o tamanho do lado 3x
    lr2 = lr2*3; // Aumenta o tamanho do lado 3x;
    area = lr * lr2; // Calcula a area
    printf("A area do retangulo eh: %d", area);
}else{
    printf("Numero invalido");
    }
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
