/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: WALISSON FERREIRA DE CARVALHO
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;
public class palindromo{
        /**
     *  Funcao para verificar se uma string é um palindromo.
     *  @return true se palindromo, false caso contrario.
     *  @param str - String
    */
    public static boolean isPalindromo(String str){
        boolean resp = true;
        for (int i = 0, j = str.length() - 1; i < j; i++, j--) { // Percorre a string de forma que i seja o primeiro caractere e j o ultimo
            if (str.charAt(i) != str.charAt(j)) { // Se os caracteres forem diferentes, não é palindromo
                resp = false;
                i = str.length(); // Para o loop
            }
        }
        return resp;
    }//fim ispalindromo

    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str;
    while (!(str = sc.nextLine()).equals("FIM")) {
        System.out.println(isPalindromo(str) ? "SIM" : "NAO");
    }
    sc.close();
    }
}