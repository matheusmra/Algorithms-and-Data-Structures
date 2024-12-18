import java.util.Scanner;
public class ed02 {
    public static boolean isPar(int numero){
        if(numero %2 == 0){
            return true;
        }
        return false;
    }
    public static void ex0211(Scanner ler) {
        System.out.print("Digite o valor do numero:");
        int x = ler.nextInt();
        if(x > 0) {
            if (isPar(x)) {
                System.out.print("O numero: " + x + " é par!");
            } else {
                System.out.print("O numero é impar");
            }
        }else{
            System.out.print("O numero digitado é negativo");
        }
    }
    public static void ex0212(Scanner ler) {
        System.out.print("Digite o valor do número: ");
        int x = ler.nextInt();

        if (!isPar(x) && x < -15) {
            System.out.println("O número é ímpar e menor que -15.");
        } else if (isPar(x) && x > 15) {
            System.out.println("O número é par e maior que 15.");
        } else if (!isPar(x)) {
            System.out.println("O número é ímpar, mas não é menor que -15.");
        } else {
            System.out.println("O número é par, mas não é maior que 15.");
        }
    }
    public static boolean isIntervalo(int numero){
        if(numero > 25 && numero < 45){
            return true;
        }else{
            return false;
        }
    }
    public static void ex0213(Scanner ler){
        System.out.println("Numero =");
        int x = ler.nextInt();
        if(isIntervalo(x)){
            System.out.println("O numero esta no intervalo entre 25 e 45");
        }else{
            System.out.println("O numero nao esta no intervalo");
        }
    }

    public static boolean isIntervalo2(int numero){
        if(numero >= 20 && numero <= 60){
            return true;
        }else{
            return false;
        }
    }

    public static void ex0214(Scanner ler){
        System.out.println("Valor =");
        int x = ler.nextInt();
        if(isIntervalo2(x)){
            System.out.println("O numero " + x + " pertence ao intervalo fechado entre 20 e 60");
        }else{
            System.out.println("O numero nao pertence ao intervalo");
        }
    }

    public static void main(String[] args) {
        int opcao;
        do {

            System.out.print("\nOpcao = ");
            Scanner ler = new Scanner(System.in);
            opcao = ler.nextInt();

            // Executar a opção escolhida
            switch (opcao) {
                case 0:
                    break;
                case 1:
                    ex0211(ler);
                    break;
                case 2:
                    ex0212(ler);
                    break;
                case 3:
                    ex0213(ler);
                    break;
                case 4:
                    ex0214(ler);
                    break;
                case 5:
                    ex0215(ler);
                    break;
                default:
                    System.out.print("\nERRO: OPCAO INVALIDA\n\n");
                    break;
            } // fim switch

        } while (opcao != 0);

        System.out.print("\nAperte ENTER para terminar!\n");

    }
}

