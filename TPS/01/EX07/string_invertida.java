import java.util.Scanner;
public class string_invertida {
    /**
     * Função para inverter uma string
     * @return str2 - String invertida
     * @param str - String a ser invertida
     */
    public static String inverter(String str) {
        String str2 = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            str2 += str.charAt(i);
        }
        return str2;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
        String strInvertida = inverter(str);
        System.out.println(strInvertida);
        }
        sc.close();
        }
    }
    

