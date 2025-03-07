import java.util.Scanner;
/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
public class palindromoRecursivo {

    /**
     * Função recursiva para verificar se uma string é um palíndromo.
     * @param str - String
     * @return true se for palíndromo, false caso contrário
     */
    public static boolean isPalindromoRecursivo(String str, int i, int j) {
        if (i >= j) {
            return true;
        }
        // Se o primeiro e o ultimo caracteres forem diferentes não é um palindromo
        if (str.charAt(i) != str.charAt(j)) {
            return false;
        }

        // Chama recursivamente passando para o proximo caractere (i) e caractere antes (j)
        return isPalindromoRecursivo(str,(i+1),(j-1));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.println(isPalindromoRecursivo(str,0,(str.length() - 1)) ? "SIM" : "NAO");
        }
        
        sc.close();
    }
}
