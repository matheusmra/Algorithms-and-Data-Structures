#include <stdio.h>

void preencher_matriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int soma_linha(int matriz[5][5]) {
    int soma = 0;
    for (int j = 0; j < 5; j++) {
        soma += matriz[4][j];
    }
    return soma;
}

int soma_coluna(int matriz[5][5]) {
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += matriz[i][2];
    }
    return soma;
}

int soma_elementos(int matriz[5][5]) {
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

int soma_diagonal_principal(int matriz[5][5]) {
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += matriz[i][i];
    }
    return soma;
}

void imprimir_matriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimir_diagonal_principal(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j)
                printf("%d ", matriz[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}

void imprimir_diagonal_secundaria(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 5 - 1 - i)
                printf("%d ", matriz[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
}

int soma_diagonal_secundaria(int matriz[5][5]) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += matriz[i][5 - 1 - i];
    }
    return total;
}

int main() {
    int matriz[5][5];
    preencher_matriz(matriz);

    printf("\nMATRIZ PRINCIPAL:\n");
    imprimir_matriz(matriz);

    int total = soma_elementos(matriz);
    printf("\nSoma de todos os elementos da matriz = %d", total);

    int soma4 = soma_linha(matriz);
    int soma2 = soma_coluna(matriz);
    printf("\nSoma dos elementos da linha 4 = %d", soma4);
    printf("\nSoma dos elementos da coluna 2 = %d", soma2);

    int somaprincipal = soma_diagonal_principal(matriz);
    printf("\nDIAGONAL PRINCIPAL:\n");
    imprimir_diagonal_principal(matriz);
    printf("\nSoma da diagonal principal = %d", somaprincipal);

    printf("\nDIAGONAL SECUNDARIA:\n");
    imprimir_diagonal_secundaria(matriz);
    int somasecundaria = soma_diagonal_secundaria(matriz);
    printf("\nSoma da diagonal secundaria = %d", somasecundaria);

    return 0;
}

