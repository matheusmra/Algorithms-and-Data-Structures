package Estudos.AV01;

public class insectionsort {
    public static void Insercao (int[] vetor, int n){
        for (int i = 1; i < n; i++) {
		    int tmp = vetor[i];
            int j = i - 1;

            while ((j >= 0) && (vetor[j] > tmp)) {
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = tmp;
        }
    }

    public static void show(int[] arr){
        for(int i = 0; i < arr.length; i++){
        System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        int[] vet = {50,40,30,20};
        show(vet);
        Insercao(vet, 4);
        show(vet);

    }
}
