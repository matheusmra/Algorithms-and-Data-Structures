/*
 Estudo Dirigido 05 - v0.0. - 12 / 09 / 2024
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed05 ed05.c
 Windows: gcc -o ed05 ed05.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed05
 Windows: ed05
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// Fun��o para mostrar o menu de op��es
void menuOpcoes() {
    printf("\nEscolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0511\n");
    printf("  2 - Exercicio 0512\n");
    printf("  3 - Exercicio 0513\n");
    printf("  4 - Exercicio 0514\n");
    printf("  5 - Exercicio 0515\n");
    printf("  6 - Exercicio 0516\n");
    printf("  7 - Exercicio 0517\n");
    printf("  8 - Exercicio 0518\n");
    printf("  9 - Exercicio 0519\n");
    printf(" 10 - Exercicio 0520\n");
    printf(" 11 - Exercicio 05E1\n");
    printf(" 12 - Exercicio 05E2\n");
} // fim menuOpcoes()



// Incluir função e método (0511) para:
// para ler uma quantidade inteira (n) do teclado e, mediante um procedimento,
// testar a função para gerar valores múltiplos de 4 em ordem crescente.
void fun0511(int v1){
    int controle = 0;
    for (int i = 0; i < v1; i++) {
        controle = controle + 4;
        printf("\nO numero: (%d) eh multiplo de quatro.", controle);
    }
    printf("\n");


}
void ex0511()
{
    // identificacao
     printf("\nExercicio 0511:\n\n");
    //programa
    int n = 0;
    printf("\nDigite o numero de termos:");
    scanf("%d", &n);
    fun0511(n);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0511

// Fun��o para o exerc�cio 0512
// Incluir função e método (0512) para:
// para ler uma quantidade inteira do teclado e, mediante um procedimento,
// testar a função para gerar valores múltiplos de 3 e 4 em ordem crescente.
void fun0512(int v1){
    int controle = 0;
    for (int i = 0; i < v1; i++) {
        controle = controle + 12;
        printf("\nO numero: (%d) eh multiplo de tres e quatro.", controle);
    }
    printf("\n");


}
void ex0512() {
    // identificacao
    printf( "\nExercicio 0512:\n\n" );
    // programa
    int n = 0;
    printf("\nDigite o numero de termos:");
    scanf("%d", &n);
    fun0512(n);
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
    return 0;
}// Fim da fun��o ex0512

// Fun��o para o exerc�cio 0513
//  Incluir função e método (0513) para:
//  para ler uma quantidade inteira do teclado e, mediante um procedimento,
//  testar a função para gerar potências de 3 em ordem decrescente.
void fun0513(int v1){
    int p   = v1, num = 0;

    for(int i = p; i > 0; i = i - 1 )
    {
        num = pow(3, p);
        printf("\nO numero (%d) eh uma potencia de tres.", num);
        p = p - 1;
    }
    printf("\n");
}
void ex0513() {
// identificacao
    printf( "\nExercicio 0513:\n\n" );
    // encerrar
    int n = 0;
    printf("Digite o numero de termos:");
    scanf("%d", &n);
    fun0513(n);
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
    return 0;

}// Fim da fun��o ex0413

// Fun��o para o exerc�cio 0514
// Incluir função e método (0514) para:
// para ler uma quantidade inteira do teclado e, mediante um procedimento,
// testar a função para gerar valores crescentes nos denominadores
// (sequência dos inversos) múltiplos de 4.
void fun0514(int v1) {
int controle = 0, n = 1;
    for (int i = 0; i < v1; i++) {
        controle = controle + 4;
        printf("\nO numero: (%d/%d) eh multiplo de quatro.",n,controle);
    }
    printf("\n");



}
void ex0514() {
// identificacao
    printf( "\nExercicio 0514:\n\n" );
    int n = 0;
    printf("Digite o numero de termos:");
    scanf("%d",&n);
    fun0514(n);
    getchar();
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();

}// Fim da fun��o ex0414

// Fun��o para o exerc�cio 0415
// Incluir função e método (0515) para:
// para ler um valor real real (x) do teclado;
// para ler uma quantidade inteira do teclado e, mediante um procedimento,
// testar a função para gerar valores ímpares crescentes nos denominadores
// da sequência: 1 1/x1 1/x3 1/x5 ...
// DICA: Usar da biblioteca <math.h> a função pow ( x, y ) para calcular a potência

void ex0515() {
// identificacao
    printf( "\nExercicio 0515:\n\n" );

    printf( "\nAperte ENTER para continuar!\n" );
    getchar();

}// Fim da fun��o ex0415

// Fun��o para o exerc�cio 0416
// Incluir função e método (0516) para
// calcular a soma dos primeiros valores positivos começando no valor 4,
// múltiplos de 4 e não múltiplos de 5.
// Testar essa função para quantidades diferentes e mostrar os resultados em outro método.
// Exemplo: n = 5 => 4 + 8 + 12 + 16 + 24

int fun0516(int v1) {
    int soma = 0, x = 4;

    while (v1 >= 1) {
        if ((x % 4 == 0) && (x % 5 != 0)) {
            soma = soma+x;
            v1--;
        }
        x = x + 1;
    }
    return(soma);
}

void ex0516() {
    printf("\nExercicio 0516:\n\n");
    int n = 0;
    printf("Digite o numero de termos: ");
    scanf("%d", &n);
    printf("\nA soma dos multiplos de 4 que nao sao multiplos de 5: %d\n", fun0516(n));
    getchar();
    printf("\nAperte ENTER para continuar!\n");
    getchar(); // Para esperar o usuário pressionar ENTER
}
// Fim da fun��o ex0416

// Fun��o para o exerc�cio 0417
// Incluir função e método (0517) para
// calcular a soma dos inversos (1/x) dos primeiros valores positivos,
// começando no valor 3, múltiplos de 3 e não múltiplos de 5.
// Testar essa função para quantidades diferentes e
// mostrar os resultados em outro método.
// Exemplo: n = 5 => 1/3 + 1/6 + 1/9 + 1/12 + 1/18
double met0517(int v1)
{
    double soma = 0;
    int    x    = 3;

    while (1 <= v1)
    {
        if( (x % 3 == 0) && (x % 5 != 0) )
        {
            soma = soma + (1.0/x);
            v1 = v1- 1;
        }
        x = x + 1;
    }
    return ( soma );
}

void ex0517()
{
    // identificacao
    printf("\nExercicio 0517:\n\n");

    // programa
    int n = 0;
    printf( "\nDigite uma quantidade: " );
    scanf("%d", &n);

    printf( "\n%s%lf\n", "Soma = ", met0517(n) );

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
} // fim exercicio0517// Fim da fun��o ex0417
// Fun��o para o exerc�cio 0518
// Incluir função e método (0518) para
// calcular a soma da adição dos primeiros números naturais começando no valor 4.
// Testar essa função para quantidades diferentes de valores e
// mostrar os resultados em outro método.
// Exemplo: n = 5 => 4 + 5 + 7 + 10 + 14
int met0518(int v1)
{
    int soma = 0, num = 4, x = 1;

    while( v1 > 0 )
    {

        soma = soma + num;
        num = num + x;
        x = x + 1;
        v1 = v1 - 1;
    }
    return ( soma );
}
void ex0518() {
// identificacao
    printf( "\nExercicio 0518:\n\n" );
    int n = 0;
    printf("\nDigite um numero:");
    scanf("%d", &n);
    printf("\nA soma eh igual a: %d", met0518(n));
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da fun��o ex0418

// Fun��o para o exerc�cio 0519
// Incluir função e método (0519) para
// calcular a soma dos quadrados da adição dos números naturais começando no valor 4.
// Testar essa função para quantidades diferentes de valores e
// e mostrar os resultados em outro método.
// Exemplo: n = 5 => 16 + 25 + 36 + 49 + 64
int met0519(int v1)
{
    int soma = 0, num = 4, x = 1;
    while( v1 > 0 )
    {

        soma = soma + pow(num, 2);
        num = num + x;
        x = x + 1;
        v1 = v1 - 1;
    }
    return ( soma );
}
void ex0519() {
    // identificacao
    printf( "\nExercicio 0519:\n\n" );
    int n = 0;
    printf("\nDigite um numero:");
    scanf("%d", &n);
    printf("\nA soma eh igual a: %d", met0519(n));
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();

}// Fim da fun��o ex0419

// Fun��o para o exerc�cio 0420
// Incluir função e método (Exemplo0520) para
// calcular a soma dos inversos (1/x) das adições de números naturais terminando no valor 4.
// Testar essa função para quantidades diferentes de valores
// e mostrar os resultados em outro método.
// Exemplo: n = 5 => 1/14 + 1/10 + 1/7 + 1/5 + 1/4
double fun0520(int v1) {
    double soma = 0.0, num = 4.0, x = 1;
    for(int i = 1; i <= v1; i = i + 1)
    {
        soma = soma + (1.0/num);
        num = num + x;
        x = x + 1;
    }

    return ( soma );
}

void ex0520() {
// identificacao
    printf( "\nExercicio 0520:\n\n" );
    int n = 0;
    printf("Digite o numero de termos:");
    scanf("%d",&n);
    printf("\nSoma igual a: %d", fun0520(n));
    getchar();
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da fun��o ex0420

// Fun��o para o exerc�cio 04E1
// Incluir função e método (Exemplo05E1) para
// ler um número inteiro do teclado (n) e,
// mediante o uso da função, calcular e mostrar o fatorial desse valor em outro método:
// n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1 se n>0
int fun05E1(int v1){
    if( v1 < 0 )
        return 0;
    else if( v1 == 0 || v1 == 1)
        return 1;
    else
        return v1 * fun05E1(v1-1);
}

void ex05E1()
{
    // identificacao
    printf( "\nExercicio 04E1:\n\n" );
    // programa
    int n = 0;
    printf("Digite o numero a ser fatorado:");
    scanf("%d", &n);
    fun05E1(n);
    printf("Fatorial = %d", fun05E1(n));
    getchar();
    printf("\nAperte ENTER para continuar!\n");
    getchar();
} // fim exercicio04E1
// Fun��o para o exerc�cio 04E2
// Incluir função e método (Exemplo05E2) para
// ler uma quantidade inteira do teclado (n) e,
// mediante o uso da função, calcular e mostrar o resultado em outro método de
// f ( n ) = (1+3/2!) * (1+5/4!) * (1+7/8!) *
void ex05E2()
{
    // identificacao
    printf( "\nExercicio 04E2:\n\n" );

    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim fun��o 04E2

// Fun��o principal
int main(void) {
    int opcao;

    do {
        menuOpcoes(); // Chama a fun��o que exibe as op��es

        printf("\nOpcao = ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        // Executar a op��o escolhida
        switch (opcao) {
            case 0: break;
            case 1: ex0511(); break;
            case 2: ex0512(); break;
            case 3: ex0513(); break;
            case 4: ex0514(); break;
            case 5: ex0515(); break;
            case 6: ex0516(); break;
            case 7: ex0517(); break;
            case 8: ex0518(); break;
            case 9: ex0519(); break;
            case 10: ex0520(); break;
            case 11: ex05E1(); break;
            case 12: ex05E2(); break;
            default:
                printf("\nERRO: OPCAO INVALIDA\n\n");
                break;
        } // fim switch

    } while (opcao != 0);

    printf("\nAperte ENTER para terminar!\n");
    getchar();

    return 0;
} // Fim da fun��o principal
