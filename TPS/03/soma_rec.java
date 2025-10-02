import java.util.Scanner;

public class soma_rec{

        /**
     * Função recursiva para obter a soma dos digitos
     * @return soma dos digitos
     * @param n - Numero que terá seus digitos somados
     */
public static int soma_digitos(int n)
{
    if(n == 0) // Caso para encerrar a recursão
    {
        return 0;
    }
    else
    {
        return n % 10 + soma_digitos(n/10); 
    }

}

public static void main(String[] args){
{
    int n = 0;
    Scanner sc = new Scanner(System.in);
    String str;
        while (!(str = sc.nextLine()).equals("FIM")) {
           n = Integer.parseInt(str);
           System.out.println(soma_digitos(n));
        }
}
}
}
