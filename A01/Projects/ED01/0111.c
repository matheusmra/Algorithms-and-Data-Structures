/*
 0111 - v0.0. - 16 / 08 / 2023
 Author: Matheus de Almeida Moreira - 848813

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o 0111 0111.c
 Windows: gcc -o 0111 0111.c
 Para executar em terminal (janela de comandos):
 Linux : ./0111
 Windows: 0111
*/
#include<stdio.h>

int main(){
    int lq, lq2; // LQ == Lado quadrado
    printf("Digite o valor do lado:");
    scanf("%d", &lq); // Armazena o valor digita no endereco de memoria da variavel lq
    if(lq > 0){
    lq2 = lq*2; // O valor do lado do segundo quadrado é o dobro do primeiro;
    lq2 = lq2*lq2; // Multiplica o valor do segundo lado por ele mesmo
    printf("A area do segundo quadrado eh: %d", lq2);
}else{
    printf("Numero invalido");
    }
    printf("\n\n--------- | FIM DO PROGRAMA | ---------\n\n");
}
