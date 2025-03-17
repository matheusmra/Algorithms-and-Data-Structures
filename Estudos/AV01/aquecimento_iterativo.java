import java.util.Scanner;
public class aquecimento_iterativo {


    public static int count_Upper(String str){
        int size = str.length();
        int total = 0;
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z'){
                total++;
            }
        }
        return total;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str;
        while(!(str = sc.nextLine()).equals("FIM")){
            System.out.println(count_Upper(str));
        }
    }
}
