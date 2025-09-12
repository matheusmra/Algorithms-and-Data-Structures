

import java.util.Random;
import java.util.Scanner;

public class AlteracaoAleatoria {
        /**
     * Função para alterar uma string aleatoriamente.
     * @param str String a ser alterada
     * @param caracter Letra sorteada para ser substituida
     * @param sub Letra sorteada para substituir a primeira
     * @return "SIM" se forem anagramas, senão "NÃO"
     */
    public static String swap_Letters(String str, char caracter, char sub){
        String result = " ";
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != caracter) {
                result = result + str.charAt(i); // Armazena o caractere na string
            }else{
                result = result + sub; // Realiza a substituição e armazena na string
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        char caracter = ' ';
        char sub = ' ';
        Random gerador = new Random();
        gerador.setSeed(4);
        Scanner sc = new Scanner(System.in);
        String str = "";
        String str2 = "";
        while (!(str = sc.nextLine()).equals("FIM")) {
            caracter  =  ( char ) ( 'a' + ( Math.abs( gerador.nextInt( ) ) % 26 ) );
            sub = ( char ) ( 'a' + ( Math.abs( gerador.nextInt( ) ) % 26 ) );
            str2 = swap_Letters(str, caracter, sub);
            System.out.println(str2);
        }
        sc.close();
    }
    
}