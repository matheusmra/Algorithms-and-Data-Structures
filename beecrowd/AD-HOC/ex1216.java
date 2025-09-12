import java.util.Scanner;

public class ex1216 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double soma = 0.0;
        int count = 0;
        while (sc.hasNextLine()) {
            if (!sc.hasNextLine()) break;
            String nome = sc.nextLine(); 
            if (!sc.hasNextLine()) break;
            int distancia = Integer.parseInt(sc.nextLine());
            
            soma += distancia;
            count++;
        }
        if (count > 0) {
            double media = soma / count;
            System.out.printf("%.1f\n", media);
        }

        sc.close();
    }
}
