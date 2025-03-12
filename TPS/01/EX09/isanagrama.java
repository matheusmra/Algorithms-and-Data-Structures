/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;

public class isanagrama {
    /**
     * Função para identificar se duas palavras são anagramas.
     * @param str1 Primeira palavra
     * @param str2 Segunda palavra
     * @return "SIM" se forem anagramas, senão "NÃO"
     */
    public static boolean isanagrama(String str1, String str2) {
        if (str1.length() != str2.length()) {
            return false;
        } //Caso o tamanho das duas strings o programa retorna falso
        int[] freq = new int[128]; // Array de tamanho 128 para verificar todas as ocorrências possiveis de um caractere (ASCII)
        for (int i = 0; i < str1.length(); i++) {
            freq[str1.charAt(i)]++;
            freq[str2.charAt(i)]--;
        }
        // Loop para verificar se é um anagrama
        for (int i = 0; i < 128; i++) {
            if (freq[i] != 0) { // Caso o resultado no array seja diferente de 0, significa que não é um anagrama
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            String[] palavras = str.split(" - "); // Retira o (espaço)-(espaço), seprando as strings
            System.out.println(isanagrama(palavras[0].toLowerCase(), palavras[1].toLowerCase()) ? "SIM" : "NÃO");
            // A função toLowerCase foi utilizada para evitar com que o programa retornasse Não quando as strings fossem anagramas porém com diferentes letras em maiúsculo
        }
        sc.close();
    }
}
