
#include <stdio.h>

int main() {
    int n = 8;
    int pessoas[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pessoas[i]);
    }

    int f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0;
    for (int i = 0; i < 8; i++) {
        if (pessoas[i] <= 15) {
            f1++;
        } else if (pessoas[i] >= 16 && pessoas[i] <= 30) {
            f2++;
        } else if (pessoas[i] >= 31 && pessoas[i] <= 45) {
            f3++;
        } else if (pessoas[i] >= 46 && pessoas[i] <= 60) {
            f4++;
        } else {
            f5++;
        }
    }

    double por1 = (f1 / 8.0) * 100;
    double por2 = (f5 / 8.0) * 100;

    printf("Total de pessoas na faixa etária 1 = %d\n", f1);
    printf("Total de pessoas na faixa etária 2 = %d\n", f2);
    printf("Total de pessoas na faixa etária 3 = %d\n", f3);
    printf("Total de pessoas na faixa etária 4 = %d\n", f4);
    printf("Total de pessoas na faixa etária 5 = %d\n", f5);
    printf("\nPorcentagem de pessoas na primeira faixa etaria = %.2f%%\n", por1);
    printf("Porcentagem de pessoas na quinta faixa etaria = %.2f%%\n", por2);

    return 0;
}
