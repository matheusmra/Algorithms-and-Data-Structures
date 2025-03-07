/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define TAM_MAX 1000
        /**
     *  Funcao para verificar se uma string é um palindromo.
     *  @return true se palindromo, false caso contrario.
     *  @param str - String
    */
    bool isPalindromoRecursivo(char str[], int i, int j){
        if (i >= j) {
            return true;
        }
        // Se o primeiro e o ultimo caracteres forem diferentes não é um palindromo
        if (str[i] != str[j]) {
            return false;
        }

        // Chama recursivamente passando para o proximo caractere (i) e caractere antes do ultimo (j)
        return isPalindromoRecursivo(str,(i+1),(j-1));
    }//fim ispalindromo

    int main(){
        char str[TAM_MAX];
        scanf("%[^\n]", str);
        while (strcmp(str, "FIM") != 0) { // Enquanto a string for diferente de "FIM"
            if (isPalindromoRecursivo(str,0,(strlen(str) - 1))) { // Se for verdadeiro
                printf("SIM\n");
            } else { // Se for falso
                printf("NAO\n");
            }
            scanf(" %[^\n]", str);
        }
    }
