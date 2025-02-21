/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;

public class is {
        /**
     *  Funcao para identificar se a string é composta somente por vogais
     *  @return verdadeiro ou falso
     *  @param str String
    */
    public static boolean x1(String str){
        int size = str.length(); // Tamanho da string
        for(int i = 0; i < size; i++){
            if(str.charAt(i) != 'a' && str.charAt(i) != 'e' && str.charAt(i) != 'i' && str.charAt(i) != 'o' && str.charAt(i) != 'u'){
                return false;
            }
        }
        return true;
    }

            /**
     *  Funcao para identificar se a string é composta somente por consoantes
     *  @return verdadeiro ou falso
     *  @param str String
    */
    public static boolean x2(String str){
        int size = str.length(); // Tamanho da string
        for(int i = 0; i < size; i++){
            if(str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u'){
                return false;
            }else if(str.charAt(i) == ',' || str.charAt(i) == '.'){ // Retorna falso caso o caractere seja igual , ou . (Antes retornava true quando digitava um numero real)
                return false;
            }
        }
        return true;
    }

    /**
     *  Funcao para identificar se a string é composta somente por digitos
     *  @return verdadeiro ou falso
     *  @param str String
    */
    public static boolean x3(String str){
        int size = str.length(); // Tamanho da string
        for(int i = 0; i < size; i++){
            if(str.charAt(i) < 48 || str.charAt(i) > 57){ // Verifica se o caracter[i] é menor que 0 (ASCII) ou maior que 9(ASCII)
                return false;
            }
        }
        return true;
    }

        /**
     *  Funcao para identificar se a string é um numero real
     *  @return verdadeiro ou falso
     *  @param str String
    */
    public static boolean x4(String str) {
        boolean ponto = false;
        int size = str.length();
        for (int i = 0; i < size; i++) {
            if (str.charAt(i) == '.' || str.charAt(i) == ',') {
                if (ponto) {
                    return false;
                }
                ponto = true;
            } else if (x3(str)) {
                return false;
            }
        }
        return ponto;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println(x1(str.toLowerCase()));
        System.out.println(x2(str.toLowerCase()));
        System.out.println(x3(str.toLowerCase()));
        System.out.println(x4(str.toLowerCase()));
        sc.close();
    }
    
}
