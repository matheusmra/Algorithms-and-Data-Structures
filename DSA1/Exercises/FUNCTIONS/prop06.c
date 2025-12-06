#include <stdio.h>


double pesoideal(double altura, char sexo) {
    double pesoh = 0.0;
    double pesom = 0.0;

    if (sexo == 'H') {
        pesoh = 72.7 * altura - 58;
        printf("Seu peso ideal eh %.2f\n", pesoh);
    } else if (sexo == 'M') {
        pesom = 62.1 * altura - 44.7;
        printf("Seu peso ideal eh %.2f\n", pesom);
    } else {
        printf("Opcao de genero invalida.\n");
    }
}

int main() {
    double altura = 0.0;
    char sexo;

    printf("Digite sua altura (em metros): ");
    scanf("%lf", &altura);
    printf("Digite seu genero (H para homem, M para mulher): ");
    scanf(" %c", &sexo);

    if (sexo == 'H' || sexo == 'M') {
        pesoideal(altura, sexo);
    } else {
        printf("Opcao de genero invalida.\n");
    }

    return 0;
}
