#include <stdio.h>

int main() {

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int td1 = 0, td2 = 0;
    int x;
    // Conta bolinhos do prato de Natan
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) td1++;
    }
    // Conta bolinhos do prato de Samuel
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) td2++;
    }

    if (td1 == m) {
        printf("Tudo certo.");
    } else if (td2 == m) {
        printf("Pegou de Samuel.");
    } else {
        printf("Pegou de um estranho.");
    }

    return 0;
}
