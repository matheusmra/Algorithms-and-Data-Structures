import java.util.Scanner;

public class leds {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        sc.nextLine(); // Consumir a quebra de linha após o nextInt()

        String[] num = new String[n];
        for (int i = 0; i < n; i++) {
            num[i] = sc.nextLine(); // Ler cada número como string
        }

        // Mapeamento de LEDs por dígito
        int[] ledsPorDigito = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // 0-9

        for (int i = 0; i < n; i++) {
            int total = 0;
            for (int j = 0; j < num[i].length(); j++) {
                char ch = num[i].charAt(j);
                total += ledsPorDigito[ch - '0']; // Converter char para índice do array
            }
            System.out.println(total + " leds");
        }

        sc.close();
    }
}
