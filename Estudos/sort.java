public class sort {

    public static void swap(int[] arr, int a, int b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    public static void selection(int[] arr){
        int n = arr.length;
        for(int i = 0; i < n; i++){
            int menor = i;
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[menor]){
                    menor = j;
                }
            }
            swap(arr,i,menor);
        }
    }

    public static void mostrar(int[] arr){
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void bubble(int[] arr){
        int n = arr.length;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j+1] < arr[j]){
                    swap(arr,j+1,j);
                }
            }
        }
    }

    public static void main(String[] args){
        int arr1[] = {9,5,6,2,3,7,0,1,4,8};
        System.out.println("Antes:");
        mostrar(arr1);
        System.out.println("Depois:");
        selection(arr1);
        mostrar(arr1);
    }
}
