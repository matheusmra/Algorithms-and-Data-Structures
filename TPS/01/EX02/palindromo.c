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
    bool isPalindromo(char str[]){
        bool resp = true;
        for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) { // Percorre a string de forma que i seja o primeiro caractere e j o ultimo
            if (str[i] != str[j]) { // Se os caracteres forem diferentes não é palindromo
                resp = false;
                i = strlen(str); // Para o loop
            }
        }
        return resp;
    }//fim ispalindromo

    int main(){
        char str[TAM_MAX];
        scanf("%[^\n]", str);
        while (strcmp(str, "FIM") != 0) { // Enquanto a string for diferente de "FIM"
            if (isPalindromo(str)) { // Se for verdadeiro
                printf("SIM\n");
            } else { // Se for falso
                printf("NAO\n");
            }
            scanf(" %[^\n]", str);
        }
    }
