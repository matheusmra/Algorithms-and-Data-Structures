package Teste.src;
import java.util.Scanner;

public class fatorial {
    public static int fatorial(int numero) {
        if(numero == 0){
            return 1;
        }else{
            return numero*fatorial(numero-1);
        }
    }
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        System.out.print("Digite o valor: ");
        int x = ler.nextInt();
        System.out.println(fatorial(x));
    }
}
