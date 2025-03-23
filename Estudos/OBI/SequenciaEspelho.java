import java.util.Scanner;

public class SequenciaEspelho {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inicio = sc.nextInt();
        int fim = sc.nextInt();
        String sequencia = "";
        for (int i = inicio; i <= fim; i++) {
            sequencia += i;
        }
        String inverso = "";
        for (int i = fim; i >= inicio; i--) {
            String numStr = Integer.toString(i);
            for (int j = numStr.length() - 1; j >= 0; j--) {
                inverso += numStr.charAt(j);
            }
        }
        System.out.println(sequencia + inverso);
    }
}
