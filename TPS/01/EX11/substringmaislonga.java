import java.util.Scanner;

public class substringmaislonga {
        /**
     *  Funcao para verificar se a string possui alguma letra maiuscula
     *  @return total - valor da maior substring
     *  @param str - String a ser percorrida
    */
    public static int maiorSubstring(String str) {
        int result = 0;
        int inicio = 0;
        boolean[] visto = new boolean[128]; // Considerando caracteres ASCII
        for (int fim = 0; fim < str.length(); fim++) {
            while (visto[str.charAt(fim)]) { // Serve para verificar se um caractere apareceu novamente 
                visto[str.charAt(inicio)] = false;
                inicio++;
            }
            visto[str.charAt(fim)] = true;
            result = Math.max(result, fim - inicio + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
            System.out.println(maiorSubstring(str));
        }
        sc.close();
    }
}
