/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;

public class isanagrama {
    /**
     *  Funcao para identificar se duas strings são anagramas
     *  @return verdadeiro ou falso
     *  @param str1 String
     *  @param str2 String
    */
    public static boolean isanagram(String str1, String str2) {
        int[] soma = new int[256];
        if (str1.length() != str2.length()) { // Se o tamanho das duas strings for diferente o programa irá retornar falso
            return false;
        }
        for (int i = 0; i < str1.length(); i++) {
                soma[str1.charAt(i)]++; 
                soma[str2.charAt(i)]--;
            }
            for(int i = 0; i < 256; i++){
                if(soma[i] != 0){
                    return false;
                }
            }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        if (isanagram(str1, str2)) {
            System.out.println("SIM");
        } else {
            System.out.println("NAO");
        }
        sc.close();
    }
}
