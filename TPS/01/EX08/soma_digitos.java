
/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
import java .util.Scanner;
public class soma_digitos{
    /**
     *  Funcao para digitos de um numero
     *  @return soma dos digitos
     *  @param n - Numero que possui os digitos a serem somados
    */
    public static int somarDigitos(int n){
        if (n == 0){ // Fim da recursão
            return 0;
        } else {
            return n % 10 + somarDigitos(n / 10); 
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.next()).equals("FIM")) { // O Loop será sera encerrado quando digiat FIM
        int n = Integer.parseInt(str); // Converte a string para inteiro;
        int soma = somarDigitos(n);
        System.out.println(soma);
        }
        sc.close();
    }
}