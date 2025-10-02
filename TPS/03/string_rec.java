import java.util.Scanner;
public class string_rec {

    

    // Método recursivo privado usando índice
    private static String inverter(String str, int i) {
        // Caso base: chegou no último caractere
        if (i == str.length() - 1) {
            return "" + str.charAt(i);
        }
        // Chamada recursiva: inverte o restante e adiciona o caractere atual no final
        return inverter(str, i + 1) + str.charAt(i);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.println(inverter(str, 0));
        }
    }
}
