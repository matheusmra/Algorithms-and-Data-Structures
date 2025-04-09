import java.util.Scanner;
 class torneio {
    public static void main(String[] args){
        int total = 0;
        Scanner sc = new Scanner(System.in);
        char[] arr = new char[6];
        for(int i = 0; i < 6; i++){
            arr[i] = sc.nextLine().charAt(0);
            if(arr[i] != 'P' && arr[i] != 'V'){
                System.exit(0);
            }
        }
        for(int i = 0; i < 6; i++){
            if(arr[i] == 'V'){
                total++;
            }
        }
        if(total >= 1 && total <= 2){
            System.out.println("3");
        }else if(total >= 3 && total <= 4){
            System.out.println("2");
        }else if(total >= 5 && total <=6){
            System.out.println("1");
        }else{
            System.out.println("-1");
        }
    }
}
