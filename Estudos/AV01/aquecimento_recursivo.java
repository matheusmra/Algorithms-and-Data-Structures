import java.util.Scanner;
public class aquecimento_recursivo {
    public static int contar_recursivo(String str, int pos){
        if(pos >= str.length()){
            return 0;
        }
        int total = 0;
        if(str.charAt(pos) >= 'A' && str.charAt(pos) <= 'Z'){
            total++;
        }
        return total += contar_recursivo(str,pos+1);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str;
        while(!(str = sc.nextLine()).equals("FIM")){
            System.out.println(contar_recursivo(str,0));
        }
    }
}
