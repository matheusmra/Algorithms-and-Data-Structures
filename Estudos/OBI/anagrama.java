import java.util.Scanner;
public class anagrama{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        int[] arr = new int[128];
        if(str1.length() == str2.length()){
            for(int i = 0; i < str1.length(); i++){
                arr[str1.charAt(i)]++;
                arr[str2.charAt(i)]--;
            }
            for(int i = 0; i < str1.length(); i++){
                if(arr[i] != 0){
                    System.out.println("N");
                }else{
                    System.out.println("S");
                }
            }
        }
    }
}