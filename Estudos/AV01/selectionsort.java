package Estudos.AV01;

public class selectionsort {

    // Método de ordenação Selection Sort
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;  
                }
            }
            if (minIndex != i) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }

    public static void show(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();  
    }

    public static void main(String[] args) {
        int[] vet = {64, 25, 12, 22, 11};  
        System.out.print("Array original: ");
        show(vet);  

        selectionSort(vet); 
        System.out.print("Array ordenado: ");
        show(vet);  
    }
}

