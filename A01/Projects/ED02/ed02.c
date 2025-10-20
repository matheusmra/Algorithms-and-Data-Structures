/*
 Estudo Dirigido 02 - v0.0. - 21 / 08 / 2023
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed02 ed02.c
 Windows: gcc -o ed02 ed02.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed02
 Windows: ed02
*/

// dependencias
#include <stdio.h>

// Fun��o para mostrar o menu de op��es
void menuOpcoes() {
    printf("\nEscolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0211\n");
    printf("  2 - Exercicio 0212\n");
    printf("  3 - Exercicio 0213\n");
    printf("  4 - Exercicio 0214\n");
    printf("  5 - Exercicio 0215\n");
    printf("  6 - Exercicio 0216\n");
    printf("  7 - Exercicio 0217\n");
    printf("  8 - Exercicio 0218\n");
    printf("  9 - Exercicio 0219\n");
    printf(" 10 - Exercicio 0220\n");
    printf(" 11 - Exercicio 02E1\n");
    printf(" 12 - Exercicio 02E2\n");
} // fim menuOpcoes()

// Fun��o para o exerc�cio 0211
//- Ler um valor inteiro do teclado e
//- Dizer se � par ou �mpar
void ex0211(void) {
    int numero = 0;
    //Identifica��o
    printf("\nExercicio 0211:\n\n");
    // Inicio do programa
    printf("Digite um numero: ");
    scanf("%d", &numero);
    getchar(); // Limpar o buffer de entrada
    if (numero % 2 == 0) { // Testa se o resultado da divis�o por dois � 0 (Par)
        printf("\n%d eh um numero par.\n", numero);
    } else { //Caso n�o seja, significa que o n�mero � impar
        printf("\n%d eh um numero impar.\n", numero);
    }
    printf("Aperte ENTER para continuar!\n"); //Encerrar a execu��o da fun��o
    getchar();
} // Fim da fun��o ex0211

// Fun��o para o exerc�cio 0212
// - Ler um valor inteiro do teclado e
// - Dizer se � �mpar e menor que -15, ou par e maior que 15.
void ex0212(void) {
    int numero = 0;
    //Identifica��o
    printf("\nExercicio 0212:\n\n");
    //Inicio do programa
    printf("Digite o numero: ");
    scanf("%d", &numero);
    getchar(); // Limpar o buffer de entrada

    if (numero % 2 == 0) { // Numero par
        if (numero > 15) {
            printf("O numero %d eh par e maior que 15.\n", numero);
        } else {
            printf("O numero %d eh par e menor que 15.\n", numero);
        }
    } else { // N�mero �mpar
        if (numero < -15) {
            printf("O numero %d eh impar e menor que -15.\n", numero);
        } else {
            printf("O numero %d eh impar e maior que -15.\n", numero);
        }
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0212

// Fun��o para o exerc�cio 0213
// - Ler um valor inteiro do teclado e
// - Dizer se pertence ao intervalo aberto entre (25:45).
void ex0213(void) {
    int numero = 0;
    //Identifica��o
    printf("\nExercicio 0213:\n\n");
    //Inicio do programa
    printf("Digite um numero: ");
    scanf("%d", &numero);
    getchar(); // Limpar o buffer de entrada
    if (numero > 25 && numero < 45) {
        printf("%d faz parte do intervalo de 25 e 45.\n", numero);
    } else {
        printf("%d nao faz parte do intervalo.\n", numero);
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0213

// Fun��o para o exerc�cio 0214
// - Ler um valor inteiro do teclado e
// - Dizer se pertence ao intervalo fechado entre [20:60].
void ex0214(void) {
    int numero = 0;
    //Identifica��o
    printf("\nExercicio 0214:\n\n");
    //Inicio do programa
    printf("Digite o numero: ");
    scanf("%d", &numero);
    getchar(); // Limpar o buffer de entrada
    if (numero >= 20 && numero <= 60) {
        printf("%d faz parte do intervalo de 20 e 60.\n", numero);
    } else {
        printf("%d n�o faz parte do intervalo.\n", numero);
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0214

// Fun��o para o exerc�cio 0215
// - ler um valor inteiro do teclado e
// - dados os intervalos [10:25] e (15:50),
// - dizer se pertence � interse��o ou a apenas a um deles.
void ex0215(void) {
    int numero = 0;
    //Identifica��o
    printf("\nExercicio 0215:\n\n");
    //Inicio do Programa
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    getchar(); // Limpar o buffer de entrada

    if ((numero >= 10 && numero <= 25) && (numero > 15 && numero < 50)) {
        printf("%d faz parte da interse��o.\n", numero);
    } else if (numero >= 10 && numero <= 25) {
        printf("%d faz parte do intervalo de 10 e 25.\n", numero);
    } else if (numero > 15 && numero < 50) {
        printf("%d faz parte do intervalo de 15 e 50.\n", numero);
    }else if(numero < 10 || numero > 50){
        printf("%d nao faz parte do intervalo.\n", numero);
        }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0215

// Fun��o para o exerc�cio 0216
// - ler dois valores inteiros do teclado e
// - dizer se o primeiro � par e o segundo � �mpar.
void ex0216(void) {
    int numero1 = 0, numero2 = 0;
    //Identifica��o
    printf("\nExercicio 0216:\n\n");
    //Inicio do Programa
    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);
    getchar(); // Limpar o buffer de entrada

    if (numero1 % 2 == 0 && numero2 % 2 != 0) {
        printf("O primeiro numero: %d eh par e o segundo numero: %d eh impar.\n", numero1, numero2);
    } else if (numero1 % 2 != 0 && numero2 % 2 != 0) {
        printf("Os dois numeros sao impares.\n");
    } else if (numero1 % 2 != 0 && numero2 % 2 == 0) {
        printf("O primeiro numero eh impar e o segundo eh par.\n");
    } else if (numero1 % 2 == 0 && numero2 % 2 == 0) {
        printf("Os dois numero sao pares.\n");
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0216

// Fun��o para o exerc�cio 0217
// - ler dois valores inteiros do teclado e
// - dizer se o primeiro � �mpar e negativo, e se o segundo � par e positivo.
void ex0217(void) {
    int numero1 = 0, numero2 = 0;
    printf("\nExercicio 0217:\n\n");
    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);
    getchar(); // Limpar o buffer de entrada

    if (numero1 % 2 != 0 && numero1 < 0 && numero2 % 2 == 0 && numero2 > 0) {
        printf("O primeiro numero: %d eh impar e negativo e o segundo numero: %d eh par e positivo.\n", numero1, numero2);
    } else if (numero1 % 2 != 0 && numero1 < 0 && numero2 % 2 != 0 && numero2 < 0) {
        printf("Ambos s�o impares e negativos.\n");
    } else if (numero1 % 2 == 0 && numero1 < 0 && numero2 % 2 != 0 && numero2 > 0) {
        printf("O primeiro numero eh par e negativo. O segundo eh impar e positivo.\n");
    } else if (numero1 % 2 == 0 && numero1 > 0 && numero2 % 2 == 0 && numero2 > 0) {
        printf("Ambos s�o pares e positivos.\n");
    } else if (numero1 % 2 != 0 && numero1 < 0 && numero2 % 2 == 0 && numero2 < 0) {
        printf("O primeiro numero � negativo e impar. O segundo eh par e negativo.\n");
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0217
// Fun��o para o exerc�cio 0218
// - ler dois valores reais do teclado e
// - dizer se o primeiro � menor, igual ou maior que a metade do segundo.
void ex0218(void) {
    double numero1 = 0.0, numero2 = 0.0;
    printf("\nExercicio 0218:\n\n");
    printf("Digite o primeiro numero: ");
    scanf("%lf", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%lf", &numero2);
    getchar(); // Limpar o buffer de entrada

    if (numero1 < (numero2 / 2)) {
        printf("O numero %.2lf eh menor que a metade de %.2lf.\n", numero1, numero2);
    } else if (numero1 == (numero2 / 2)) {
        printf("O numero %.2lf eh a metade de %.2lf", numero1, numero2);
    } else if (numero1 > (numero2 / 2)) {
        printf("O numero %.2lf eh maior que a metade de %.2lf.\n", numero1, numero2);
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0218

// Fun��o para o exerc�cio 0219
// - ler tr�s valores reais do teclado e
// - dizer se o segundo est� entre o primeiro e o �ltimo,
// - quando esses dois forem diferentes entre si.
// - OBS.: Notar a ordem dos testes.

void ex0219(void) {
    double numero1 = 0.0, numero2 = 0.0, numero3 = 0.0;
    printf("\nExercicio 0219:\n\n");
    printf("Digite o primeiro numero: ");
    scanf("%lf", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%lf", &numero2);
    printf("Digite o terceiro numero: ");
    scanf("%lf", &numero3);
    getchar(); // Limpar o buffer de entrada

    if (numero1 != numero3) {
        if (numero2 > numero1 && numero2 < numero3) {
            printf("O numero %.2lf esta entre os numeros: %.2lf e %.2lf.\n", numero2, numero1, numero3);
        } else {
            printf("O numero %.2lf nao esta entre os numeros.\n", numero2);
        }
    } else {
        printf("ERRO: O Primeiro numero deve ser diferente do Terceiro numero.\n");
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0219

// Fun��o para o exerc�cio 0220
// - ler tr�s valores reais do teclado e
// - dizer se o segundo n�o est� entre o primeiro e o �ltimo,
// - quando todos forem diferentes entre si.
void ex0220(void) {
    double numero1 = 1.0, numero2 = 1.0, numero3 = 1.0;
    printf("\nExercicio 0220:\n\n");
    printf("Digite o primeiro numero: ");
    scanf("%lf", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%lf", &numero2);
    printf("Digite o terceiro numero: ");
    scanf("%lf", &numero3);
    getchar(); // Limpar o buffer de entrada

    if (numero1 != numero2 && numero1 != numero3 && numero2 != numero3) {
        if (numero2 < numero1 || numero2 > numero3) {
            printf("O numero %.2lf nao esta entre os numeros: %.2lf e %.2lf.\n", numero2, numero1, numero3);
        } else {
            printf("O numero %.2lf esta entre os numeros: %.2lf e %.2lf.\n", numero2, numero1, numero3);
        }
    } else {
        printf("ERRO: Os tres numeros devem ser diferentes!\n");
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex0220

// Fun��o para o exerc�cio 02E1
// - ler tr�s valores literais (caracteres) do teclado e
// - dizer se o primeiro valor lido est� entre os outros dois, ou se � igual a um deles.

void ex02E1(void) {
    char a = 'a', b = 'b', c = 'c';
    printf("\nExercicio 02E1:\n\n");
    printf("Digite o primeiro caractere: ");
    scanf(" %c", &a);
    printf("Digite o segundo caractere: ");
    scanf(" %c", &b);
    printf("Digite o terceiro caractere: ");
    scanf(" %c", &c);
    getchar(); // Limpar o buffer de entrada

    if (a == b || a == c) {
        printf("%c eh igual a pelo menos um dos outros valores.\n", a);
    } else if ((a > b && a < c) || (a < b && a > c)) {
        printf("%c esta entre %c e %c.\n", a, b, c);
    } else {
        printf("%c nao esta entre %c e %c.\n", a, b, c);
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex02E1

// Fun��o para o exerc�cio 02E2
// - ler tr�s valores literais (caracteres) do teclado e
// - dizer se o primeiro valor lido est� fora do intervalo definido pelos outros dois,
// - se esses forem diferentes entre si.
// - OBS.: Notar que n�o haver� garantias de ser o segundo menor que o terceiro.
void ex02E2(void) {
    char a = 'a', b = 'b', c = 'c';
    printf("\nExercicio 02E2:\n\n");
    printf("Digite o primeiro caractere: ");
    scanf(" %c", &a);
    printf("Digite o segundo caractere: ");
    scanf(" %c", &b);
    printf("Digite o terceiro caractere: ");
    scanf(" %c", &c);
    getchar(); // Limpar o buffer de entrada

    if (b != c) {
        if (!(((b < a) && (a < c)) || ((b > a) && (a > c)))) {
            printf("O caractere (%c) esta fora do intervalo (%c : %c).\n", a, b, c);
        } else {
            printf("O caractere (%c) esta dentro do intervalo (%c : %c).\n", a, b, c);
        }
    } else {
        printf("Tem dois caracteres iguais.\n");
    }
    printf("Aperte ENTER para continuar!\n");
    getchar();
}// Fim da fun��o ex02E2

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
            case 1: ex0211(); break;
            case 2: ex0212(); break;
            case 3: ex0213(); break;
            case 4: ex0214(); break;
            case 5: ex0215(); break;
            case 6: ex0216(); break;
            case 7: ex0217(); break;
            case 8: ex0218(); break;
            case 9: ex0219(); break;
            case 10: ex0220(); break;
            case 11: ex02E1(); break;
            case 12: ex02E2(); break;
            default:
                printf("\nERRO: OPCAO INVALIDA\n\n");
                break;
        } // fim switch

    } while (opcao != 0);

    printf("\nAperte ENTER para terminar!\n");
    getchar();

    return 0;
} // Fim da fun��o principal
