#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_size 100
int soma_digitos(int n)
{
    if(n == 0)
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
    char string[max_size];
    while (scanf("%s", string) == 1 && strcmp(string, "FIM") != 0) {
        int n = atoi(string);
        printf("%d\n", soma_digitos(n));
    }





}
