/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;

public class isRecursivo {
 /**
     * Função recursiva para identificar se a string é composta somente por vogais
     * @return verdadeiro ou falso
     * @param str String
     * @param i Índice atual da string
     */
    public static boolean x1(String str, int i) {
        if (i >= str.length()) {
            return true; // Se percorremos toda a string e todas as letras eram vogais, retornamos verdadeiro
        }
        if (str.charAt(i) != 'a' && str.charAt(i) != 'e' && str.charAt(i) != 'i' && str.charAt(i) != 'o' && str.charAt(i) != 'u') {
            return false; // Se encontrar um caractere que não seja vogal, retorna falso
        }
        return x1(str, i + 1); // Chama prox caractere
    }

    /**
     * Função recursiva para identificar se a string é composta somente por consoantes
     * @return verdadeiro ou falso
     * @param str String
     * @param i Índice atual da string
     */
    public static boolean x2(String str, int i) {
        if (i >= str.length()) {
            return true; 
        }
        if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u' || str.charAt(i) == ',' || str.charAt(i) == '.') {
            return false; // Se encontrar um caractere que seja uma vogal ou pontuação retorna falso
        }
        return x2(str, i + 1); // Chama prox caractere
    }

    /**
     * Função recursiva para identificar se a string é composta somente por dígitos
     * @return verdadeiro ou falso
     * @param str String
     * @param i Índice atual da string
     */
    public static boolean x3(String str, int i) {
        if (i >= str.length()) {
            return true; 
        }
        if (str.charAt(i) < '0' || str.charAt(i) > '9') {
            return false; // Se encontrar um caractere que não seja dígito, retorna falso
        }
        return x3(str, i + 1); // Chama prox caractere
    }

    /**
     * Função recursiva para identificar se a string é um número real
     * @return verdadeiro ou falso
     * @param str String
     * @param i Índice atual da string
     * @param ponto Indicador se já encontramos um ponto ou vírgula
     */
    public static boolean x4(String str, int i, boolean ponto) {
        if (i >= str.length()) {
            return ponto; 
        }
        if (str.charAt(i) == '.' || str.charAt(i) == ',') {
            if (ponto) {
                return false; // Se já encontramos um ponto, retorna falso
            }
            ponto = true; // Encontrou um ponto ou virgula
        } else if (str.charAt(i) < '0' || str.charAt(i) > '9') {
            return false; // Se encontrar um caractere que não seja digito
        }
        return x4(str, i + 1, ponto); // Chama prox caractere
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.println(
                (x1(str.toLowerCase(), 0) ? "SIM " : "NAO ") +
                (x2(str.toLowerCase(), 0) ? "SIM " : "NAO ") +
                (x3(str.toLowerCase(), 0) ? "SIM " : "NAO ") +
                (x4(str.toLowerCase(), 0, false) ? "SIM" : "NAO")
            );
        }
        sc.close();
    }
}
