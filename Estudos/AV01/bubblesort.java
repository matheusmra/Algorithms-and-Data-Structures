package Estudos.AV01;

public class bubblesort {

    public static void bubble(int[] arr){
        int size = arr.length;
        for(int i = 0; i < size - 1; i++){
            for(int j = 0; j < size - 1 - i; j++){
             if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            }
        }
    }

    public static void show_arr(int[] arr){
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
    public static void main(String[] args){
        int[] arr = {20,3,9,7,2,1,0};
        show_arr(arr);
        bubble(arr);
        System.out.println();
        System.out.println("Após ordenação:");
        show_arr(arr);
    }
}
