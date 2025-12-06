/*
 0115 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0115 0115.c
 Windows: gcc -o 0115 0115.c
 Para executar em terminal (janela de comandos):
 Linux : ./0115
 Windows: 0115
*/
#include<stdio.h>

int main(){
    int base, altura, area;
    printf("Digite o valor da base:");
    scanf("%d", &base); // Armazena o valor digita no endereco de memoria da variavel base
    printf("Digite o valor da altura:");
    scanf("%d", &altura); // Armazena o valor digita no endereco de memoria da variavel altura
    if(base && altura > 0){
    area = (base * altura)/2; // Calcula a area
    area = area/2;
    printf("A area do retangulo eh: %d", area);

}else{
    printf("Numero invalido");
    }
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
