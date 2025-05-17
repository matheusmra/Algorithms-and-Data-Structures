#include <stdio.h>

#define MAXN 1000000

int produtoDigitosImpares(int n) {
    int produto = 1;
    int temImpar = 0;

    while (n > 0) {
        int d = n % 10;
        if (d % 2 == 1) {
            produto *= d;
            temImpar = 1;
        }
        n /= 10;
    }

    return temImpar ? produto : 1;
}

int main() {
    int N;
    long long K;
    scanf("%d %lld", &N, &K);

    int caixas[MAXN];
    for (int i = 0; i < N; i++) {
        scanf("%d", &caixas[i]);
    }

    long long turno = 1;

    while (turno <= K) {
        // Procurar a caixa com mais frutas
        int idx = -1;
        int max = -1;
        for (int i = 0; i < N; i++) {
            if (caixas[i] > max) {
                max = caixas[i];
                idx = i;
            }
        }

        // Se não há mais caixas com frutas, termina
        if (max <= 0) {
            printf("0\n");
            return 0;
        }

        int coleta = produtoDigitosImpares(caixas[idx]);

        if (turno == K) {
            printf("%d\n", coleta);
            return 0;
        }

        caixas[idx] -= coleta;
        if (caixas[idx] <= 0) {
            caixas[idx] = 0;
        }

        turno++;
    }

    return 0;
}
