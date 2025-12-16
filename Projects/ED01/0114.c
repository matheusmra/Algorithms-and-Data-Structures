/*
 0114 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0114 0114.c
 Windows: gcc -o 0114 0114.c
 Para executar em terminal (janela de comandos):
 Linux : ./0114
 Windows: 0114
*/
#include<stdio.h>

int main(){
    int lr, lr2, area, perimetro; // LR == Lado retangulo
    printf("Digite o valor do primeiro lado:");
    scanf("%d", &lr); // Armazena o valor digita no endereco de memoria da variavel lr
    printf("Digite o valor do segundo lado:");
    scanf("%d", &lr2); // Armazena o valor digita no endereco de memoria da variavel lr2
    if(lr && lr2 > 0){
    lr = lr/6; // Calcula um sexto do lado
    lr2 = lr2/6; // Calcula um sexto do lado;
    area = lr * lr2; // Calcula a area
    perimetro = (lr *2)+(lr2 *2); // Calcula o perimetro
    printf("A area do retangulo eh: %d", area);
    printf("\nO perimetro do retangulo eh: %d", perimetro);
    }else{
    printf("O valor deve ser maior que zero");
    }

    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
