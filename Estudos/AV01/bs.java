public class bs {

    public static void bubbleSort(int[] array){
        int n = array.length;
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(array[j] > array[j+1]){
                    int tmp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = tmp;
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
        int[] arr = {10,9,8,7,6,5,4,3,2,1};
        show_arr(arr);
        System.out.println("Após ordenação:");
        bubbleSort(arr);
        show_arr(arr);

    }
}
