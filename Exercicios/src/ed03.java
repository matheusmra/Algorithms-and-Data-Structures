import java.util.Scanner;
public class ed03 {
    public static void showUpperLetters(String nome){
        for(int i = 0; i < nome.length(); i++) {
            char c = nome.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                System.out.println(c);
            }
        }
    }
    public static void ex0311(Scanner ler){
        String nome;
        ler.nextLine();
        System.out.println("Palavra = ");
        nome = ler.nextLine();
        showUpperLetters(nome);
    }

    public static int countUpper(String nome){
        int count = 0;
        for(int i = 0; i < nome.length(); i++){
            char c = nome.charAt(i);
            if(c >= 'A' && c <= 'Z'){
                count++;
            }
        }
        return count;
    }

    public static void ex0312(Scanner ler){
        ler.nextLine();
        System.out.println("Palavra = ");
        String nome = ler.nextLine();
        int t = countUpper(nome);
        System.out.println("Total de letras em Uppercase = " + t);
        showUpperLetters(nome);
    }
    public static int countLower(String n){
        int count = 0;
        for(int i = 0; i < n.length(); i++){
            char c = n.charAt(i);
            if(c >= 'a' && c <= 'z'){
                count++;
            }
        }
        return count;
    }

    public static void showLower(String n){
        for(int i = 0; i < n.length(); i++){
            char c = n.charAt(i);
            if(c >= 'a' && c <= 'z'){
                System.out.println(c);
            }
        }
    }

    public static void ex0313(Scanner ler){
        ler.nextLine();
        System.out.println("Palavra = ");
        String n = ler.nextLine();
        System.out.println("Total de letras em lowerCase = " + countLower(n));
        showLower(n);
    }

    public static int countLetters(String n){
        int count = 0;
        for(int i = 0; i < n.length(); i++){
            char c = n.charAt(i);
            if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
                count++;
            }
        }
        return count;
    }

    public static void showLetters(String n){
        System.out.println("Exibindo somente as letras: ");
        for(int i = 0; i < n.length(); i++){
            char c = n.charAt(i);
            if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
                System.out.print(c);
            }
        }
    }

    public static void ex0314(Scanner ler){
        ler.nextLine();
        System.out.println("Palavra = ");
        String n = ler.nextLine();
        System.out.println("Total de letras: " + countLetters(n) + " | Total de letras em lowerCase = " + countLower(n) + " | Total de letras em UpperCase = " + countUpper(n));
        showLetters(n);
    }

    public static int countNums(String n){
        int count = 0;
        for(int i = 0; i < n.length(); i++){
            char c = n.charAt(i);
            if(c >= '0' && c <= '9'){
                count++;
            }
        }
        return count;
    }

    public static void showInvNum(String n) {
        for (int i = n.length() - 1; i >= 0; i--) {
            char c = n.charAt(i);
            if (c >= '0' && c <= '9') {
                System.out.println("Número: " + c + " na posição: " + (i + 1));
            }
        }
    }

    public static void ex0315(Scanner ler){
        ler.nextLine();
        System.out.println("Palavra = ");
        String n = ler.nextLine();
        System.out.println("Total de números: " + countNums(n));
        System.out.println("Numeros começando do final para o começo da string");
        showInvNum(n);

    }
    public static boolean isDigit(char c){
        return c >= '0' && c <= '9';
    }
    public static boolean isLetter(char c){
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    public static int countNonWD(String n){
        int total = 0;
        for(int i = 0; i < n.length(); i++){
            char c = n.charAt(i);
            if(!isDigit(c) && !isLetter(c) ){
                total++;
            }
        }
        return total;
    }
    public static void showNonWD(String n){
        for(int i = 0; i < n.length(); i++) {
            char c = n.charAt(i);
            if (!isDigit(c) && !isLetter(c)) {
                System.out.println(c);
            }
        }
    }

    public static void ex0316(Scanner ler){
        ler.nextLine();
        System.out.println("Palavra = ");
        String n = ler.nextLine();
        System.out.println("Total de palavras que não são letras e numeros: " + countNonWD(n));
        showNonWD(n);
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
                    ex0311(ler);
                    break;
                case 2:
                    ex0312(ler);
                    break;
                case 3:
                    ex0313(ler);
                    break;
                case 4:
                    ex0314(ler);
                    break;
                case 5:
                    ex0315(ler);
                    break;
                case 6:
                    ex0316(ler);
                    break;
                default:
                    System.out.print("\nERRO: OPCAO INVALIDA\n\n");
                    break;
            } // fim switch

        } while (opcao != 0);

        System.out.print("\nAperte ENTER para terminar!\n");

    }
}
