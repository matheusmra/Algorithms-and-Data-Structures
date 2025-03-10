import java.util.Scanner;

public class substringmaislonga {
        /**
     *  Funcao para verificar se a string possui alguma letra maiuscula
     *  @return total - valor da maior substring
     *  @param str - String a ser percorrida
    */
    public static int maiorSubstringUnica(String str) {
        int total = 0;
        int inicio = 0;
        boolean[] visto = new boolean[128]; // Considerando caracteres ASCII
        for (int fim = 0; fim < str.length(); fim++) {
            while (visto[str.charAt(fim)]) {
                visto[str.charAt(inicio)] = false;
                inicio++;
            }
            visto[str.charAt(fim)] = true;
            total = Math.max(total, fim - inicio + 1);
        }
        return total;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.println(maiorSubstringUnica(str));
        }
        sc.close();
    }
}
