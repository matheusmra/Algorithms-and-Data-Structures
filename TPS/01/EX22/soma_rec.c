#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM_MAX 100
    /**
     * Função recursiva para obter a soma dos digitos
     * @return soma dos digitos
     * @param n - Numero que terá seus digitos somados
     */

int soma_digitos(int n)
{
    if(n == 0) // Caso para encerrar a recursão
    {
        return 0;
    }
    else
    {
        return n % 10 + soma_digitos(n/10); 
    }

}

int main()
{
    int n = 0;
    char string[TAM_MAX];
    while (scanf("%s", string) == 1 && strcmp(string, "FIM") != 0) {
        int n = atoi(string); 
        printf("%d\n", soma_digitos(n));
    }





}
