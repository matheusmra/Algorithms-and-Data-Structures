import java.util.Scanner;
public class validacaoSenha {
    public static boolean hasUpper(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= 'A' || str.charAt(i) <= 'Z'){
                i = size;
                return true;
            }
        }
        return false;
    }

    public static boolean hasLower(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= 'a' || str.charAt(i) <= 'z'){
                i = size;
                return true;
            }
        }
        return false;
    }

    public static boolean hasDigit(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= '0' || str.charAt(i) <= '9'){
                i = size;
                return true;
            }
        }
        return false;
    }

    public static boolean hasEspecial(String str){
        int size = str.length();
        for(int i = 0; i < size; i++){
            if(str.charAt(i) >= '!' || str.charAt(i) <= '/'){
                i = size;
                return true;
            }
        }
        return false;
    }

    public static boolean isGood(String str){
        int size = str.length();
        if(size >= 8){
            if(hasDigit(str) && hasEspecial(str) && hasLower(str) && hasUpper(str)){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        if(isGood(str)){
            System.out.println("SIM");
        }
            System.out.println("NAO");
        sc.close();

    }
    
}
