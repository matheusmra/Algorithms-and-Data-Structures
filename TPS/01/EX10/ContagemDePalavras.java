import java.util.Scanner;

/**
 * Disciplina: Algoritmos e Estrutura de Dados II
 * Professor: Max do Val Machado
 * Aluno: Matheus de Almeida Moreira
 * Matricula: 848813
 */
public class ContagemDePalavras {

    /**
     * Função para contar o número de palavras em uma string 
     * @return count - int = número de palavras
     * @param str - String a ser contada
     */
    public static int contarPalavras(String str) {
        int count = 0;
        boolean palavra = false;
        for (int i = 0; i < str.length(); i++){
            char caractere = str.charAt(i);
            if (caractere != ' ' && !palavra){
                palavra = true;
                count++;  
            }
            // Se o caractere for espaço, significa que a palavra acabou
            if (caractere == ' ') {
                palavra = false;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while(!(str = sc.nextLine()).equals("FIM")){
        int total = contarPalavras(str);
        System.out.println(total);
        }
        sc.close();
    }
}
