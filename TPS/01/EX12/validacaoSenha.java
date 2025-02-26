/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;
public class validacaoSenha {
    /**
     *  Funcao para verificar se a string possui alguma letra maiuscula
     *  @return true/false
     *  @param str - String a ser percorrida
    */
    public static boolean hasUpper(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z'){
                return true;
            }
        }
        return false;
    }

    /**
     *  Funcao para verificar se a string possui alguma letra minuscula
     *  @return true/false
     *  @param str - String a ser percorrida
    */
    public static boolean hasLower(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= 'a' && str.charAt(i) <= 'z'){
                return true;
            }
        }
        return false;
    }

    /**
     *  Funcao para verificar se a string possui algum digito
     *  @return true/false
     *  @param str - String a ser percorrida
    */
    public static boolean hasDigit(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9'){
                return true;
            }
        }
        return false;
    }

    /**
     *  Funcao para verificar se a string possui algum caractere especial
     *  @return true/false
     *  @param str - String a ser percorrida
    */
    public static boolean hasEspecial(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if((str.charAt(i) >= '!' && str.charAt(i) <= '/') || 
               (str.charAt(i) >= ':' && str.charAt(i) <= '@') ||
               (str.charAt(i) >= '[' && str.charAt(i) <= '`') ||
               (str.charAt(i) >= '{' && str.charAt(i) <= '~')){
                return true;
            }
        }
        return false;
    }

        /**
     *  Funcao para verificar se a string é uma senha 
     *  @return true/false
     *  @param str - String a ser percorrida
    */
    public static boolean isGood(String str){
        int size = str.length();
        if(size >= 8){
            if(hasDigit(str) && hasEspecial(str) && hasLower(str) && hasUpper(str)){ // Verifica se possui letra maiuscula, minuscula, digito e especial
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.next()).equals("FIM")){
        System.out.println(isGood(str) ? "SIM" : "NÃO");
        }
        sc.close();

    }
    
}
