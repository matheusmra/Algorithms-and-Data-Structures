import java.util.Scanner;
public class camisas{
    static class pessoa{
        String nome;
        String cor;
        char tamanho;

        pessoa(){
            this.nome = "";
            this.cor = "";
            this.tamanho = ' ';
        }

        pessoa(String nome, String cor, char tamanho){
            this.nome = nome;
            this.cor = cor;
            this.tamanho = tamanho;
        }
        String getName(){
            return nome;
        }
        String getCor(){
            return cor;
        }
        char getTam(){
            return tamanho;
        }


    }

    public static void main(String[] args){
        int n = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        pessoa arr[] = new pessoa[n];
        for(int i = 0; i < n; i++){
            String nome = sc.nextLine();
            String cor = sc.nextLine();
            char tamanho = sc.nextLine().charAt(0);
            arr[i] = new pessoa(nome,cor,tamanho);
        }
        for(int i = 0; i < n; i++){
            int resultado = 0;
            arr[i].getName().compareTo(arr[i].get)
        }

    }
}