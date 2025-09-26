package L03;

import java.util.Scanner;

public class sort {

    public static boolean ehImpar(int x) {
        return x % 2 != 0;

    }

    public static boolean precisaTrocar(int a, int b, int m) {
        int ma = a % m;
        int mb = b % m;
        if (ma != mb) {
            return ma > mb;
        }

        boolean aImpar = ehImpar(a);
        boolean bImpar = ehImpar(b);

        if (aImpar && !bImpar)
            return false;
        if (!aImpar && bImpar)
            return true;
        if (aImpar && bImpar)
            return a < b;
        if (!aImpar && !bImpar)
            return a > b;
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            System.out.print("" + n + " " + m);
            System.out.println();
            int[] vetor = new int[n];
            for (int x = 0; x < n; x++) {
                vetor[x] = sc.nextInt();
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (precisaTrocar(vetor[j], vetor[j + 1], m)) {
                        int tmp = vetor[j];
                        vetor[j] = vetor[j + 1];
                        vetor[j + 1] = tmp;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                System.out.println(vetor[i]);
            }
            if (n == 0 && m == 0)
                break;
        }
    }
}

