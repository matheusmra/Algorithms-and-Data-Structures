#include <stdio.h>
#include <string.h>
#define TAM_MAX 100

    /**
     * Função para realizar a troca de dois caracteres
     * @param str String que terá os caracteres trocados
     * @param inicio primeira letra
     * @param fim segunda letra
     */

void swap(char str[], int inicio, int fim){
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
}
    /**
     * Função recursiva para inverter uma string
     * @return string invertida
     * @param str String a ser invertida
     * @param inicio posição da primeira letra
     * @param fim posição da segunda letra
     */
void inverter(char str[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    swap(str,inicio,fim);
    // Chama recursivamente os próximos caracteres
    inverter(str, inicio + 1, fim - 1);
}

int main() {
    char str[TAM_MAX];
    
    while (1) {
        // Lê a string
        scanf("%[^\n]", str);
        getchar(); //Buffer de entrada
        if (strcmp(str, "FIM") == 0) { //Condição de parada
            break;
        }
        inverter(str, 0, strlen(str) - 1); // Chamada da função
        printf("%s\n", str); //Exibe a string invertida
    }

    return 0;
}
