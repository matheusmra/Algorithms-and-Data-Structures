package Estudos.QUIZ03;

public class pbrecursiva {
    public static int PesquisaBinaria(int [] vetor, int x, int esq, int dir){
        if(esq > dir){
            return -1;
        }
        else{
        int meio = (esq + dir)/2;
        if(x == vetor[meio]){
            return meio;
        }else if(vetor[meio] < x){
            return PesquisaBinaria(vetor, x, meio + 1, dir);
        }else{
            return PesquisaBinaria(vetor, x, esq, meio - 1);
        }
    }
}
    public static void main(String[] args) {
        int[] vetor = {1,2,3,4,5,6,7,8,9,10};
        int x = 50;
        int pos = PesquisaBinaria(vetor, x, 0, vetor.length - 1);
        if(pos != -1){
            System.out.println("Valor encontrado na posição");
        }else{
            System.out.println("Valor não encontrado!");
        }
    }
}
