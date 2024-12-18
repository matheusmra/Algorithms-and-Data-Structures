import java.util.Scanner;

public class matriz {

    public static void ler_matriz(int[][] matriz) {
        Scanner ler = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print("Valor do elemento da matriz [" + i + "][" + j + "] = ");
                matriz[i][j] = ler.nextInt();
            }
        }
        ler.close();
    }

    public static void imprimir_matriz(int[][] matriz) {
        System.out.println("Matriz:");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matriz = new int[3][3];
        ler_matriz(matriz);
        imprimir_matriz(matriz);
    }
}
