import java.util.Random;
import java.util.Scanner;

public class AlteracaoAleatoria {    
    public static String swap_Letters(String input, Random gerador) {
        char letra1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char letra2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26)); 
        String resultado = "";
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == letra1) {
                resultado += letra2;
            } else {
                resultado += input.charAt(i);
            }
        }
        return resultado;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random gerador = new Random();
        String str = "";
        gerador.setSeed(4);
        while (!(str = sc.nextLine()).equals("FIM")) {;
            System.out.println(swap_Letters(str,gerador));
            }
            sc.close();
    }
}