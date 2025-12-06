/*
 0118 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0118 0118.c
 Windows: gcc -o 0118 0118.c
 Para executar em terminal (janela de comandos):
 Linux : ./0118
 Windows: 0118
*/
#include<stdio.h>

int main(){
    double comprimento, largura, altura, volume;
    printf("Digite o valor do comprimento:");
    scanf("%lf", &comprimento);
    printf("\nDigigte o valor da largura:");
    scanf("%lf", &largura);
    printf("\nDigite o valor da altura");
    scanf("%lf", &altura);
    if(comprimento && largura && altura > 0){
    comprimento = comprimento/9;
    largura = largura/9;
    altura = altura/9;
    volume = comprimento * altura * largura;
    printf("\nO volume eh: %.2lf\n", volume);

}
else{
    printf("Numero invalido");
}
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
