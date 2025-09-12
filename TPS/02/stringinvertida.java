/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: WALISSON FERREIRA DE CARVALHO
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java.util.Scanner;
public class stringinvertida{

    /**
     *  Funcao para inverter uma string.
     *  @return string invertida
     *  @param str - String
    */
    public static String inverter(String str){
        int size = str.length(); // Tamanho da string recebida
        String result = ""; // Inicializa string invertida como vazia
        for(int i = size - 1; i >= 0; i--){ //Percorre a string recebida de trás para frente
            result += str.charAt(i); // Adiciona o caracter da posição i na string
        }
        return result; // Retorna
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.println(inverter(str));
    }
}
}