package L05;
import java.util.Random;

public class TesteQuick {
    public static void main(String[] args) {
        int[] tamanhos = {100, 1000, 10000};
        String[] cenarios = {"Ordenado", "Quase Ordenado", "Aleatorio"};

        for (int n : tamanhos) {
            System.out.println("Tamanho do array: " + n);
            for (String cenario : cenarios) {
                int[] base = gerarArray(n, cenario);
                System.out.println("Cenário: " + cenario);

                // Primeiro pivô
                int[] arr1 = base.clone();
                Quicksort qs1 = new Quicksort(n);
                System.arraycopy(arr1, 0, qs1.array, 0, n);
                long ini = System.nanoTime();
                qs1.quicksortFirstPivot(0, n-1);
                long fim = System.nanoTime();
                System.out.printf("FirstPivot: %.3f ms\n", (fim-ini)/1e6);

                // Último pivô
                int[] arr2 = base.clone();
                Quicksort qs2 = new Quicksort(n);
                System.arraycopy(arr2, 0, qs2.array, 0, n);
                ini = System.nanoTime();
                qs2.quicksortLastPivot(0, n-1);
                fim = System.nanoTime();
                System.out.printf("LastPivot: %.3f ms\n", (fim-ini)/1e6);

                // Aleatório
                int[] arr3 = base.clone();
                Quicksort qs3 = new Quicksort(n);
                System.arraycopy(arr3, 0, qs3.array, 0, n);
                ini = System.nanoTime();
                qs3.quicksortRandomPivot(0, n-1);
                fim = System.nanoTime();
                System.out.printf("RandomPivot: %.3f ms\n", (fim-ini)/1e6);

                // Mediana de três
                int[] arr4 = base.clone();
                Quicksort qs4 = new Quicksort(n);
                System.arraycopy(arr4, 0, qs4.array, 0, n);
                ini = System.nanoTime();
                qs4.quicksortMedianOfThree(0, n-1);
                fim = System.nanoTime();
                System.out.printf("MedianOfThree: %.3f ms\n", (fim-ini)/1e6);

                // QuickSort com Insertion Sort para subarrays pequenos
                int[] arr5 = base.clone();
                Quicksort qs5 = new Quicksort(n);
                System.arraycopy(arr5, 0, qs5.array, 0, n);
                ini = System.nanoTime();
                qs5.quicksortWithInsertion(0, n-1);
                fim = System.nanoTime();
                System.out.printf("QuickWithInsertion: %.3f ms\n", (fim-ini)/1e6);

                System.out.println();
            }
            System.out.println("--------------------------------------------------");
        }
    }

    // Gera array conforme o cenário
    private static int[] gerarArray(int n, String cenario) {
        int[] arr = new int[n];
        Random rand = new Random();
        if (cenario.equals("Ordenado")) {
            for (int i = 0; i < n; i++) arr[i] = i;
        } else if (cenario.equals("Quase Ordenado")) {
            for (int i = 0; i < n; i++) arr[i] = i;
            // Troca 10% dos elementos aleatoriamente
            for (int i = 0; i < n/10; i++) {
                int a = rand.nextInt(n);
                int b = rand.nextInt(n);
                int tmp = arr[a];
                arr[a] = arr[b];
                arr[b] = tmp;
            }
        } else { // Aleatorio
            for (int i = 0; i < n; i++) arr[i] = rand.nextInt(n*10);
        }
        return arr;
    }
}