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

    public static boolean isIntersection(int numero){
        if(numero >= 15 && numero <= 25){
            return true;
        }else{
            return false;
        }
    }
    public static void ex0215(Scanner ler){
        System.out.println("Valor =");
        int x = ler.nextInt();
        if(isIntersection(x)){
            System.out.println("O valor esta na interseção dos intervalos");
        }
    }

    public static void ex0216(Scanner ler){
        System.out.println("Valor 1 = ");
        int x1 = ler.nextInt();
        System.out.println("Valor 2 = ");
        int x2 = ler.nextInt();
        if(isPar(x1) && !(isPar(x2))){
            System.out.println("O primeiro numero é par e o segundo é impar");
        }
    }

    public static void ex0217(Scanner ler){
        System.out.println("Valor 1 = ");
        int x1 = ler.nextInt();
        System.out.println("Valor 2 = ");
        int x2 = ler.nextInt();
        if(!(isPar(x1)) && x1 < 0 && isPar(x2) && x2 > 0){
            System.out.println("O primeiro numero é impar e menor que 0 e o segundo numero é positivo e maior que 0");
        }
    }

    public static int isHalf(double n1, double n2){
        if(n1 < n2){
            return 1;
        }else if (n1 == n2){
            return 2;
        }else if (n1 > (n2/2)){
            return 3;
        }
        return 0;
    }

    public static void ex0218(Scanner ler){
            System.out.println("Valor 1 = ");
            double x1 = ler.nextDouble();
            System.out.println("Valor 2 = ");
            double x2 = ler.nextDouble();
            int resposta = isHalf(x1,x2);
            if(resposta == 1){
                System.out.println("O numero: " + x1 + " é menor que " + x2 + " ");
            }else if (resposta == 2){
                System.out.println("Os numeros são iguais");
            }else if (resposta == 3){
                System.out.println("O numero: " + x1 + " é maior que a metade de " + x2 + " ");
            }
    }

    public static boolean isBetw(double n1, double n2, double n3){
        if(n2 > n1 && n2 < n3){
            return true;
        }
        return false;
    }

    public static void ex0219(Scanner ler){
        System.out.println("Valor 1 = ");
        double x1 = ler.nextDouble();
        System.out.println("Valor 2 = ");
        double x2 = ler.nextDouble();
        System.out.println("Valor 3 = ");
        double x3 = ler.nextDouble();
        if(isBetw(x1,x2,x3)){
            System.out.println("O valor: " + x2 + " esta entre os numeros: " + x1 + " e " + x3);
        }
    }

    public static void ex0220(Scanner ler){
        System.out.println("Valor 1 = ");
        double x1 = ler.nextDouble();
        System.out.println("Valor 2 = ");
        double x2 = ler.nextDouble();
        System.out.println("Valor 3 = ");
        double x3 = ler.nextDouble();
        if(!(isBetw(x1,x2,x3))){
            System.out.println("O segundo não está entre o primeiro e o último");
        }
    }

    public static boolean charBtw(char c1, char c2, char c3){
        if(c1 > c2 && c1 < c3){
            return true;
        }else if(c1 == c2 || c1 == c3){
            return true;
        }
        return false;
    }
    public static void ex02E1(Scanner ler){
        ler.nextLine();
        System.out.println("Primeira letra = ");
        char c1 = ler.nextLine().charAt(0);
        System.out.println("Segunda Letra = ");
        char c2 = ler.nextLine().charAt(0);
        System.out.println("Terceira letra = ");
        char c3 = ler.nextLine().charAt(0);
        if(charBtw(c1,c2,c3)){
            System.out.println("O primeiro valor lido está entre os outros dois, ou é igual a um deles.");
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
                case 6:
                    ex0216(ler);
                    break;
                case 7:
                    ex0217(ler);
                    break;
                case 8:
                    ex0218(ler);
                    break;
                case 9:
                    ex0219(ler);
                    break;
                case 10:
                    ex0220(ler);
                    break;
                case 11:
                    ex02E1(ler);
                    break;
                default:
                    System.out.print("\nERRO: OPCAO INVALIDA\n\n");
                    break;
            } // fim switch

        } while (opcao != 0);

        System.out.print("\nAperte ENTER para terminar!\n");

    }
}

