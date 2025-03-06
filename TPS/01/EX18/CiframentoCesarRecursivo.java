/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;

public class CiframentoCesarRecursivo {
    /**
     * Função recursiva para criptografar uma string
     * @return String criptografada
     * @param str - String inicial
     * @param chave - número de casas a serem deslocadas
     * @param i - índice atual na string
     */
    public static String criptografarRecursivo(String str, int chave, int i) {
        // Condição base = se o índice for maior ou igual ao tamanho da string, retorna uma string vazia
        if (i >= str.length()) {
            return "";
        }
        // Pega o caractere atual da string
        char caractere = str.charAt(i);
        int asc = (int) caractere;
        // Se o caractere for um caractere pertecente a tabela ASCII
        if (asc >= 32 && asc <= 126) {
            asc = (asc - 32 + chave) % 95 + 32;
            return (char) asc + criptografarRecursivo(str, chave, i + 1);
        } else {
            // Se o caractere não for um imprimível, apenas adiciona a string
            return caractere + criptografarRecursivo(str, chave, i + 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int chave = 3;
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            // Chama a função recursiva passando o índice inicial como 0
            String strCripto = criptografarRecursivo(str, chave, 0);
            System.out.println(strCripto);
        }

        sc.close();
    }
}

