/*
 Estudo Dirigido 03 - v0.0. - 23 / 08 / 2023
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed03 ed03.c
 Windows: gcc -o ed03 ed03.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed03
 Windows: ed03
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Tamanho max string
const int TAM_STR = 80;
// Função para mostrar o menu de opções
void menuOpcoes() {
    printf("\nEscolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0311\n");
    printf("  2 - Exercicio 0312\n");
    printf("  3 - Exercicio 0313\n");
    printf("  4 - Exercicio 0314\n");
    printf("  5 - Exercicio 0315\n");
    printf("  6 - Exercicio 0316\n");
    printf("  7 - Exercicio 0317\n");
    printf("  8 - Exercicio 0318\n");
    printf("  9 - Exercicio 0319\n");
    printf(" 10 - Exercicio 0320\n");
    printf(" 11 - Exercicio 03E1\n");
    printf(" 12 - Exercicio 03E2\n");
} // fim menuOpcoes()

// Função para o exercício 0311
// - ler uma palavra do teclado;
// - mostrar as letras maiúsculas.
// DICA: Definir um teste para determinar se um caractere é letra minúscula.

void ex0311()
{
    // identificacao
    printf( "\nExercicio 0311:\n\n" );

    // programa
    char palavra [TAM_STR];
    int tam = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for(int i = 0; i < tam; i++ )
    {
        if( ( 64 < palavra[i]) && (palavra[i] < 91) )
        {
            printf( "A letra: [%c] eh maiuscula\n" , palavra[i] );
        }
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
} // fim exercicio0311

// Função para o exercício 0212
// - ler uma palavra do teclado;
// - contar e mostrar apenas as letras minúsculas.
void ex0312() {
    // identificacao
    printf( "\nExercicio 0312:\n\n" );

    // programa
    char palavra [TAM_STR];
    int tam = 0, contagem = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for(int i = 0; i < tam; i++ )
    {
        if( !( ( 64 < palavra[i]) && (palavra[i] < 91) ))
        {
            contagem++;
            printf("A letra: [%c] eh minuscula\n", palavra[i]);
        }
    }
    printf("O total de letras minusculas eh: %d", contagem);

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0212

// Função para o exercício 0313
// ler uma palavra do teclado;
// - contar e mostrar as letras minúsculas percorrendo do fim para o início da palavra.
void ex0313() {
// identificacao
    printf( "\nExercicio 0313:\n\n" );

    // programa
    char palavra [TAM_STR];
    int tam = 0, contagem = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for(int i = tam - 1; i >= 0; i--)
    {
        if( !( ( 64 < palavra[i]) && (palavra[i] < 91) ))
        {
            contagem++;
            printf("A letra: [%c] eh minuscula\n", palavra[i]);
        }
    }
    printf("O total de letras minusculas eh: %d", contagem);

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0313

// Função para o exercício 0314
// - ler uma cadeia de caracteres do teclado;
// - contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas.
void ex0314() {
// identificacao
    printf( "\nExercicio 0314:\n\n" );

    // programa
    char palavra [TAM_STR];
    int tam = 0, contagem = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for(int i = 0; i < tam; i++ )
    {
        if( ( 64 < palavra[i]) && (palavra[i] < 91) || (96 < palavra[i] && (palavra[i]) < 123))
        {
            contagem++;
            printf("O caracter: [%c] eh uma letra\n", palavra[i]);
        }
    }
    printf("O total de caracteres que sao letras eh: %d", contagem);

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0314

// Função para o exercício 0315
// - ler uma cadeia de caracteres do teclado;
// - contar e mostrar todos os dígitos, percorrendo do fim para o início da cadeia de caracteres.
void ex0315() {
// identificacao
    printf( "\nExercicio 0315:\n\n" );

    // programa
    char palavra [TAM_STR];
    int tam = 0, contagem = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for(int i = tam - 1; i >= 0; i--)
    {
        if( ( 47 < palavra[i]) && (palavra[i] < 58))
        {
            contagem++;
            printf("O caracter: [%c] eh um digito\n", palavra[i]);
        }
    }
    printf("O total de caracteres que sao digitos eh: %d", contagem);

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0315

// Função para o exercício 0316
// - ler uma cadeia de caracteres do teclado;
// - contar e mostrar tudo o que não for dígito e também não for letra.

void ex0316() {
// identificacao
    printf( "\nExercicio 0316:\n\n" );

    // programa
    char palavra [TAM_STR];
    int tam = 0, contagem = 0;

    printf( "Digite uma palavra: " );
    scanf( "%s" , palavra);
    getchar();
    printf( "\n" );

    tam = strlen(palavra);

    for(int i = tam - 1; i >= 0; i--)
    {
        if( ( 32 < palavra[i]) && (palavra[i] < 48) || (57 < palavra[i] && (palavra[i]) < 65) || (90 < palavra[i]) && (palavra[i] < 97) || (122 < palavra[i]) && (palavra[i] < 127))
        {
            contagem++;
            printf("O caracter: [%c] nao eh uma letra ou digito\n", palavra[i]);
        }
    }
    printf("O total de caracteres que nao sao letras ou digitos eh: %d", contagem);

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0316

// Função para o exercício 0317
// - ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b];
// - ler uma quantidade (n) de valores inteiros a serem testados;
// - repetir a leitura de outros tantos valores, quantos os indicados pela quantidade, um (x) por vez;
// - contar e mostrar quantos dentre esses valores lidos (x) os que forem múltiplos de 5, e pertençam ao intervalo [a:b].
void ex0317(void) {
// identificacao
    printf( "\nExercicio 0317:\n\n" );
    int a = 0, b = 0, n = 0;
    int count = 0;
    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%d" , &a );
    getchar();
    printf( "Insira o valor final do intervalo: " );
    scanf( "%d" , &b );
    getchar();
    printf( "Insira a quantidade de valores: " );
    scanf( "%d" , &n );
    getchar();
    printf( "\n" );
    int x[n];
    for(int i = 0; i < n; i=i+1 )
    {
        printf( "Digite o valor: " );
        scanf( "%d" , &x[i] );
        getchar();
    }
    printf( "\n" );
    for(int i = 0; i < n; i++ )
    {
        if( (x[i] % 5 == 0) && (a <= x[i] && x[i] <= b) )
        {
            printf( "O numero %d eh multiplo de 5 e esta dentro do intervalo [ %d : %d ]\n" , x[i], a, b );
            count++;
        }
    }

    printf( "\n(%d) valores sao multiplos de 5 e pertecem ao intervalo\n", count );

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0317
// Função para o exercício 0318
// - ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b];
// - ler uma quantidade (n) de valores inteiros a serem testados;
// - ler outros tantos valores quantos os indicados pela quantidade, um (x) por vez;
// - contar e mostrar quantos dentre esses valores lidos (x)os que forem múltiplos de 3, que não forem também múltiplos de 5,e pertençam ao intervalo [a:b].
void ex0318() {
// identificacao
    printf( "\nExercicio 0318:\n\n" );
    int a = 0, b = 0, n = 0;
    int count = 0;
    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%d" , &a );
    getchar();
    printf( "Insira o valor final do intervalo: " );
    scanf( "%d" , &b );
    getchar();
    printf( "Insira a quantidade de valores: " );
    scanf( "%d" , &n );
    getchar();
    printf( "\n" );
    int x[n];
    for(int i = 0; i < n; i=i+1 )
    {
        printf( "Digite o valor: " );
        scanf( "%d" , &x[i] );
        getchar();
    }
    printf( "\n" );
    for(int i = 0; i < n; i++ )
    {
        if( (x[i] % 3 == 0) && (x[i] % 5 != 0) && (a <= x[i] && x[i] <= b) )
        {
            printf( "O numero %d eh multiplo de 3, nao eh multiplo de 5 e esta dentro do intervalo [ %d : %d ]\n" , x[i], a, b );
            count++;
        }
    }
    printf( "\n(%d) valores sao multiplos de 3, nao sao multiplos de 5 e pertecem ao intervalo\n", count );
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0318

// Função para o exercício 0319
// - ler dois valores reais (a e b), o primeiro (a) menor que o segundo (b), confirmadamente, para definirem um intervalo aberto (a:b);
// - ler a quantidade (n) de valores reais a serem testados, e ler outros tantos valores (x) quantos os indicados por essa quantidade;
// - contar e mostrar todos os valores lidos, pertencentes ao do intervalo,cujas partes inteiras forem ímpares.
// DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),antes de testar se é ímpar (ver 0110).


void ex0319() {
    // identificacao
    printf( "\nExercicio 0319:\n\n" );
    double a = 0.0, b = 0.0;
    int n = 0, count = 0;
    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%lf" , &a );
    getchar();
    printf( "Insira o valor final do intervalo: " );
    scanf( "%lf" , &b );
    getchar();
    if( a >= b )
    {
        printf( "\nERRO: A valores invalidos! Certifique-se de que a < b! \n" );
    }
    else
    {
        printf( "Insira a quantidade de valores: " );
        scanf( "%d" , &n );
        getchar();
        printf( "\n" );
        double x[n];
        for(int i = 0; i < n; i=i+1 )
        {
            printf( "Digite o valor: " );
            scanf( "%lf" , &x[i] );
            getchar();
        }
        printf( "\n" );
        for (int i = 0; i < n; i++)
        {
            if( a < x[i] && x[i] < b )
            {
                int inteiro = (int)x[i];
                if( inteiro % 2 == 1 )
                {
                    printf( "%.2lf eh impar e pertece ao intervalo\n" , x[i] );
                    count++;
                }

            }
        }

        printf( "\n%d valores com partes inteiras impares pertencem ao intervalo\n" , count );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0319

// Função para o exercício 0220
// - ler dois valores reais (a e b), maiores que 0 e menores que 1, confirmadamente, para definirem um intervalo aberto (a:b);
// - ler uma quantidade (n) de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade;
// - contar e mostrar todos os valores lidos que tenham suas partes fracionárias fora do intervalo ]a:b[.
// DICA: Usar conformação de tipo (type casting) para isolar a parte inteira (int),e obter a parte fracionária mediante a subtração da parte inteira, antes de testar.

void ex0320() {
// identificacao
    printf( "\nExercicio 0320:\n\n" );
    double a = 0.0, b = 0.0;
    int n = 0, count = 0;
    printf( "Insira o primeiro valor do intervalo: " );
    scanf( "%lf" , &a );
    getchar();
    printf( "Insira o valor final do intervalo: " );
    scanf( "%lf" , &b );
    getchar();
    if( a <= 0 || a >= 1 || b <= 0 || b >= 1 || a >= b ) //
    {
        printf( "\n%s\n" , "ERRO: O valor e inicial e final nao sao maiores que 0 e menores que 1" );
    }
    else
    {
        printf( "Insira a quantidade de valores: " );
        scanf( "%d" , &n );
        getchar();
        printf( "\n" );
        double x[n];
        for(int i = 0; i < n; i=i+1 )
        {
            printf( "Digite o valor: " );
            scanf( "%lf" , &x[i] );
            getchar();
        }
        printf( "\n" );
        for(int i = 0; i < n; i=i+1 )
        {
            x[i] = x[i] - (int)x[i];
        }
        for (int i = 0; i < n; i++)
        {
            if( x[i] < a || x[i] > b ) // nao pertence ao intervalo
            {
                printf( "(%.2lf) nao pertece ao intervalo\n" , x[i] );
                count++;
            }
        }
        printf( "\n%d valores tem partes fracionarias que nao pertencem ao intervalo\n" , count );
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0320

// Função para o exercício 02E1
// - ler uma linha do teclado;
// - separar em outra cadeia de caracteres e mostrar todos os símbolos não alfanuméricos (letras ou dígitos) na cadeia de caracteres.

void ex03E1()
{
    // identificacao
    printf( "\nExercicio 03E1:\n\n" );
    char palavra[TAM_STR];
    printf( "Digite uma linha:\n" );
    fgets(palavra, sizeof(palavra), stdin);
    for(int i = 0; palavra[i] != '\0'; i++ )
    {
        if( !(isalnum(palavra[i])) && !(isspace(palavra[i])) )
        {
            printf( "%c%s\n" , palavra[i], " nao eh alfanumerico." );
        }
    }
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
    getchar();
} // fim exercicio03E1
// Função para o exercício 03E2
//- ler uma cadeia de caracteres do teclado;
//- dizer se a sequência contém apenas símbolos que NÃO são letras
void ex03E2()
{
    // identificacao
    printf( "\nExercicio 03E2:\n\n" );
    char palavra[TAM_STR];
    int tam = 0, var = 0;
    printf( "Digite uma sequencia de caracteres:\n" );
    scanf( "%s" , palavra );
    tam = strlen(palavra);
    for(int i = 0; i < tam; i++ )
    {
        if( isalpha(palavra[i]) )
        {
            var = 0;
        }
        else
        {
            var = 1;
        }
    }

    if(var)
    {
        printf("\nA cadeia de caracteres \"%s\" so tem simbolos\n" , palavra);
    }
    else
    {
        printf("\nA cadeia de caracteres \"%s\" tem letra(s)\n" , palavra);
    }

    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
    getchar();
} // fim função 03E2

// Função principal
int main(void) {
    int opcao;

    do {
        menuOpcoes(); // Chama a função que exibe as opções

        printf("\nOpcao = ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        // Executar a opção escolhida
        switch (opcao) {
            case 0: break;
            case 1: ex0311(); break;
            case 2: ex0312(); break;
            case 3: ex0313(); break;
            case 4: ex0314(); break;
            case 5: ex0315(); break;
            case 6: ex0316(); break;
            case 7: ex0317(); break;
            case 8: ex0318(); break;
            case 9: ex0319(); break;
            case 10: ex0320(); break;
            case 11: ex03E1(); break;
            case 12: ex03E2(); break;
            default:
                printf("\nERRO: OPCAO INVALIDA\n\n");
                break;
        } // fim switch

    } while (opcao != 0);

    printf("\nAperte ENTER para terminar!\n");
    getchar();

    return 0;
} // Fim da função principal
