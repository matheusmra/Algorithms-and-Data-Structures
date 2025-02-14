package Estudos.QUIZ03;
public class pesquisabinaria {
    public static boolean PesquisaBinaria(int[] vetor, int x){
        boolean resp = false;
        int dir = vetor.length - 1, esq = 0, meio;
        while(esq <= dir){
            meio = (esq + dir)/2;
            if(vetor[meio] == x){
                resp = true;
                esq = vetor.length;
            }else if(vetor[meio] < x){
                esq = meio + 1;
            }else{
                dir = meio - 1;
            }
        }
        return resp;
    }
    public static void main(String[] args){
        int[] vetor = {1,2,3,4,5,6,7,8,9,10};
        int x = 5;
        if(PesquisaBinaria(vetor, x)){
            System.out.println("Valor encontrado!");
        }
    }
    
}
