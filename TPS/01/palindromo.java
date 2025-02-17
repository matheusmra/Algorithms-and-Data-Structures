import java.util.Scanner;

public class palindromo{
    public static boolean isPalindromo(String str){
        boolean resp = true;
        for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
            if (str.charAt(i) != str.charAt(j)) {
                resp = false;
            }
        }
        return resp;
    }
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String str;
    while (!(str = sc.nextLine()).equals("FIM")) {
        System.out.println(isPalindromo(str) ? "SIM" : "NAO");
    }
    sc.close();
    }
}