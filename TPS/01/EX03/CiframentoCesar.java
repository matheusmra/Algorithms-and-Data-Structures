
/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;
public class CiframentoCesar {
            /**
     *  Funcao para criptografar uma string
     *  @return str2 - String criptografada
     *  @param str - String inicial
     *  @param chave - int = numero de casas a serem deslocadas
    */
    public static String criptografar(String str, int chave) {
        String str2 = "";
        int size = str.length();
        for (int i = 0; i < size; i++) {
            char caractere = str.charAt(i); 
            int asc = (int) caractere; 
            if (asc >= 32 && asc <= 126) { // Se o caractere for um caractere pertecente a tabela ASCII
                asc = (asc - 32 + chave) % 95 + 32;
                str2 += (char) asc;
            } else {
                str2 += caractere;
            }
        }
        return str2;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int chave = 3;
        String str;
        while(!(str = sc.nextLine()).equals("FIM")){ // Enquanto a string não for igual a "FIM"
                String strCripto = criptografar(str, chave);
                System.out.println(strCripto);
        }
        sc.close();
    }     
}
