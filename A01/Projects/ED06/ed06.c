/*
 Estudo Dirigido 06 - v0.0. - 17 / 09 / 2024
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed06 ed06.c
 Windows: gcc -o ed06 ed06.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed06
 Windows: ed06
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define TAM_STRING 80
// Fun��o para mostrar o menu de op��es
void menuOpcoes() {
    printf("\nEscolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0611\n");
    printf("  2 - Exercicio 0612\n");
    printf("  3 - Exercicio 0613\n");
    printf("  4 - Exercicio 0614\n");
    printf("  5 - Exercicio 0615\n");
    printf("  6 - Exercicio 0616\n");
    printf("  7 - Exercicio 0617\n");
    printf("  8 - Exercicio 0618\n");
    printf("  9 - Exercicio 0619\n");
    printf(" 10 - Exercicio 0620\n");
    printf(" 11 - Exercicio 06E1\n");
    printf(" 12 - Exercicio 06E2\n");
} // fim menuOpcoes()



// Incluir função e método (0611) para:
// para ler uma quantidade inteira (n) do teclado e, mediante um procedimento,
// testar a função para gerar valores múltiplos de 4 em ordem crescente.
void fun0611(int v1, int v2) {
    if (v2 <= 0) {
        return;
    } else {
        printf("\n%d", v1);
        fun0611(v1 + 4, v2 - 1);
    }
}
void ex0611()
{
    // identificacao
     printf("\nExercicio 0611:\n\n");
    //programa
    int n = 0;
    printf("\nDigite o numero de vezes:");
    scanf("%d", &n);
    fun0611(4, n);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0611

// Fun��o para o exerc�cio 0612
// Incluir função e método (0612) para:
// ler um valor inteiro do teclado e chamar procedimento recursivo para
// mostrar essa quantidade em múltiplos de 4, em ordem decrescente, encerrando no valor 4.
void fun0612(int v1, int v2) {
    if (v1 >= 4){
        printf("\n%d", v1);
        fun0612(v1 - 4, v2 - 1);
    }else{
    return;
    }
}
void ex0612() {
    // identificacao
    printf( "\nExercicio 0612:\n\n" );
    // programa
    int n = 0;
    printf("\nDigite o numero de vezes:");
    scanf("%d", &n);
    fun0612(n * 4, n);
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
    return 0;
}// Fim da fun��o ex0612

// Fun��o para o exerc�cio 0613
//  Incluir função e método (0613) para:
// ler um valor inteiro do teclado e chamar procedimento recursivo para
// mostrar essa quantidade em valores da sequência de inversos dos múltiplos de 4, começando em 1.
// DICA: Separar o primeiro do restante.
// Exemplo: valor = 5 => { 1/1, 1/4, 1/8, 1/12, 1/16. }
void met0613(int v1, int v2) {
    if(v2 >= 1) {
        printf("\n1/%d ", v1);
        if(v1 == 1) {
            met0613( v1 + 3, v2 - 1 );
        }else{
            met0613( v1 + 4, v2 - 1 );
        }
    }
}

void ex0613() {
// identificacao
    printf( "\nExercicio 0613:\n\n" );
    // encerrar
    int n = 0;
    printf("Digite o numero de vezes:");
    scanf("%d", &n);
    met0613(1, n);
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
    return 0;

}// Fim da fun��o ex0613

// Fun��o para o exerc�cio 0614
// Incluir função e método (0614) para:
// ler um valor inteiro do teclado e chamar procedimento recursivo para
// mostrar essa quantidade em valores da sequência de inversos dos múltiplos de 4, terminando em 1.
// Exemplo: valor = 5 => { 1/16, 1/12, 1/8, 1/4, 1/1 }
void met0614(int v1, int v2) {
    if(v2 >= 1) {
        printf("\n1/%d ", v1);
        if(v1 == 4){
            met0614( v1 - 3, v2 - 1 );
        }else{
            met0614( v1 - 4, v2 - 1 );
        }
    }
}
void ex0614() {
// identificacao
    printf( "\nExercicio 0614:\n\n" );
    int n = 0, controle = 0;
    printf("Digite o numero de vezes:");
    scanf("%d", &n);
    // Obs: Na primeira versão, eu passava 16 como parametro, logo quando eu digitava um número maior que 5 ele realizava substrações negativas
    // para resolver esse problema, criei a variavel controle que vai ser passada como parametro.
    // Para que o valor esperado seja passado, multipliquei 4 pelo número de vezes menos 1. !(Foi necessário remover um do numero de vezes uma vez que já temos 1 quatro)
    controle = 4 * (n-1);
    met0614(controle, n);
    getchar();
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();

}// Fim da fun��o ex0614

// Fun��o para o exerc�cio 0615
// Incluir função e método (0615) para:
// calcular a soma de valores gerados pela adição dos primeiros valores pares positivos ao valor 4.
// Testar essa função para quantidades diferentes.
// Exemplo: valor = 5 => 4 + 6 + 10 + 16 + 24

int fun0615(int v1, int v2, int v3){
    int total = 0;
    if(v3 >= 1){
        total = v1 + fun0615(v1 + v2,v2 + 2,v3 - 1);
        //Caso queira conferir as somas: printf("\n Total: %d | V1: %d | V3: %d, total, v1, v2);
    }
    return (total);
}


void ex0615() {
// identificacao
    printf( "\nExercicio 0615:\n\n" );
    int n = 0, total = 0;
    printf("\nDigite o numero de vezes:");
    scanf("%d", &n);
    total = fun0615(4,2,n);
    printf("\nO total das adicoes eh: %d", total);
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();

}// Fim da fun��o ex0615

// Fun��o para o exerc�cio 0616
// Incluir função e método (0616) para
// calcular a soma dos inversos (1/x) dos primeiros valores pares positivos múltiplos do valor 4.
// Testar essa função para quantidades diferentes.
// Exemplo: valor = 5 => 1/4 + 1/6 + 1/10 + 1/16 + 1/24

// REVISAR ANTES DA PROVA (TIVE DIFICULDADE)
double fun0616(double v1, double v2, int v3){
    double soma = 0.0;
    if(v3 > 0){
        soma = v1/v2 + fun0616(v1, v2 + 4, v3 - 1);
    }
    return ( soma );
}

void ex0616() {
    printf("\nExercicio 0616:\n\n");
    int n = 0;
    double total = 0.0;
    printf("Digite o numero de vezes:");
    scanf("%d", &n);
    total = fun0616(1.0,4.0,n);
    printf("O total eh: %.2f", total);
    getchar();
    printf("\nAperte ENTER para continuar!\n");
    getchar(); // Para esperar o usuário pressionar ENTER
}
// Fim da fun��o ex0616

// Fun��o para o exerc�cio 0617
// Incluir função e método (0617) para
// ler uma cadeia de caracteres e chamar procedimento recursivo para
// mostrar cada símbolo separadamente, um por linha.
// Exemplo: sequência = "abcde"

void fun0617(char *v1, int v2){
    if(v1 && v2 >= 0){
        fun0617(v1,v2-1);
        printf("\n%c", v1[v2]);
    }
}

void ex0617(){
    // identificacao
    printf("\nExercicio 0617:\n\n");
    // programa
    char *cadeia[TAM_STRING];
    int tamanho = 0;
    // programa
    printf( "Digite uma palavra: " );
    scanf( "%s" , cadeia);
    getchar();
    tamanho = strlen(cadeia);
    fun0617(cadeia, tamanho);

    // encerrar
    printf("\n%s\n", "Aperte ENTER para continuar!");
    getchar();
} // fim exercicio0617

// Fun��o para o exerc�cio 0618
// Incluir função e método (0618) para
// contar os dígitos com valores ímpares em uma cadeia de caracteres.
// Testar essa função para cadeias de diferentes tamanhos.
// Exemplo: sequência = "P4LaVr@1"
int fun0618(char *v1, int v2) {
    int total = 0;
    if(v1 && v2 >= 0){
        total = fun0618(v1, v2 - 1);
        if(v1[v2] > 47 && v1[v2] < 58){
            if( v1[v2] % 2 != 0)
            {
                total = total + 1;
            }
        }
    }
    return (total);
}
void ex0618() {
// identificacao
    printf( "\nExercicio 0618:\n\n" );
    char *cadeia[TAM_STRING];
    int tamanho = 0, controle = 0;
    // programa
    printf( "Digite uma palavra: " );
    scanf( "%s" , cadeia);
    getchar();
    tamanho = strlen(cadeia);
    fun0618(cadeia, tamanho);
    controle = fun0618(cadeia,tamanho);
    if(controle > 0){
        printf("O total de digitos com valores impares eh: %d", controle);
    }else{
        printf("A cadeia nao possui digitos impares.");
        }
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da fun��o ex0618

// Fun��o para o exerc�cio 0619
// Incluir função e método (0619) para
// calcular a quantidade de maiúsculas maiores que 'M' em uma cadeia de caracteres.
// Testar essa função para cadeias de diferentes tamanhos.
// Exemplo: sequência = "P4LaVr@1"
int fun0619(char *v1, int v2) {
    int total = 0;
    if (v1 && v2 >= 0) {
        total = fun0619(v1, v2 - 1);
        if (v1[v2] > 77 && v1[v2] < 91) {
            total = total + 1;
        }
    }
    return total;
}
void ex0619() {
    //identificação
    printf( "\nExercicio 0619:\n\n" );
    char *cadeia[TAM_STRING];
    int tamanho = 0, controle = 0;
    // programa
    printf( "Digite uma palavra: " );
    scanf( "%s" , cadeia);
    getchar();
    tamanho = strlen(cadeia);
    fun0619(cadeia, tamanho);
    controle = fun0619(cadeia,tamanho);
    if(controle > 0){
        printf("O total de maiusculas maiores que 'M' eh : %d", controle);
    }else{
        printf("A cadeia nao possui caracteres maiores que 'M'.");
        }
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();

}// Fim da fun��o ex0619

// Fun��o para o exerc�cio 0620
// Incluir função e método (Exemplo0620) para
// calcular certo termo par da série de Fibonacci começando em 1.
// Testar essa função para quantidades diferentes.
// DICA: Separar o cálculo do termo e o teste para verificar se é par.
// Exemplo: valor = 3 => 2+8+34

int fibo(int v1) {
    int a = 1, b = 1, c;
    for (int i = 1; i <= v1; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fun0620(int v1) {
    int total = 0, termo = 0;
    for(int i = 1; i <= v1; i++){
        termo = fibo(i);
        if (termo % 2 == 0){
            total += termo;
        }
    }
    return total;
}

void ex0620() {
    printf("\nExercicio 0620:\n\n");
    int n = 0, total =0;
    printf("Digite o numero de vezes: ");
    scanf("%d", &n);
    // Solução temporária
    total = fun0620(n*n);
    printf("Total = %d\n", total);
    // Encerrar
    getchar();
    printf("Aperte ENTER para continuar!\n");
    getchar();
}
// Fim da fun��o ex0620

// Fun��o para o exerc�cio 06E1
// Incluir função e método (Exemplo06E1) para
// calcular o valor da função definida abaixo,
// lidos os valores de (x) e (n) do teclado:
// f ( x, n ) = 1 + x2 + x4 + x6 + x8 + ...

//PROBLEMA: O calculo correto só é realizado dessa maneira (Solução do COPILOT)
// Solução trocar o if, antes tinha feito para o código só ser executado se a variável v2 fosse maior que a v3.
double fun06E1(double v1, int v2, int v3){
    if(v3 > v2){
        return 0.0;
    }
        double total = pow(v1, 2*v3);
        return total + fun06E1(v1, v2, v3+1);

}

void ex06E1()
{
    // identificacao
    printf( "\nExercicio 06E1:\n\n" );
    // programa
    int n = 0;
    double x = 0.0, total = 0.0;
    printf("\nDigite o valor de x:");
    scanf("%lf", &x);
    printf("\nDigite o numero de vezes:");
    scanf("%d", &n);
    total = 1.0 + fun06E1(x, n, 1);
    printf("\nO total eh: %.2f", total);
    getchar();
    printf("\nAperte ENTER para continuar!\n");
    getchar();
} // fim exercicio06E1
// Fun��o para o exerc�cio 06E2
// Incluir função e método (Exemplo06E2) para
// para calcular o valor indicado abaixo,
// lido o número de termos (n) do teclado: e = 1 + 2/3! + 5/7! + 12/15! + 27/31! + ..
void ex06E2()
{
    // identificacao
    printf( "\nExercicio 06E2:\n\n" );

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
            case 1: ex0611(); break;
            case 2: ex0612(); break;
            case 3: ex0613(); break;
            case 4: ex0614(); break;
            case 5: ex0615(); break;
            case 6: ex0616(); break;
            case 7: ex0617(); break;
            case 8: ex0618(); break;
            case 9: ex0619(); break;
            case 10: ex0620(); break;
            case 11: ex06E1(); break;
            case 12: ex06E2(); break;
            default:
                printf("\nERRO: OPCAO INVALIDA\n\n");
                break;
        } // fim switch

    } while (opcao != 0);

    printf("\nAperte ENTER para terminar!\n");
    getchar();

    return 0;
} // Fim da fun��o principal
