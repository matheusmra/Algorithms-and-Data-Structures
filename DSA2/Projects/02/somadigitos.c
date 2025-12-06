#include <stdio.h>
#include <stdbool.h>
    /**
     *  Funcao para digitos de um numero
     *  @return soma dos digitos
     *  @param n - Numero que possui os digitos a serem somados
    */
int calcular(int n) {
    if(n == 0){ // Condição de parada
        return 0;
    } else {
        return n % 10 + calcular(n / 10);
    }
}

int main() {
    int n;
    while (true) {
        if (scanf("%d", &n) != 1) { // Se a entrada for diferente de um numero o programa encerra
            break;
        }
        printf("%d\n", calcular(n));
    }
    return 0;
}
