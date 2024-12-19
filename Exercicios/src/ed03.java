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
        nome = ler.nextLine();
        showUpperLetters(nome);
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
                default:
                    System.out.print("\nERRO: OPCAO INVALIDA\n\n");
                    break;
            } // fim switch

        } while (opcao != 0);

        System.out.print("\nAperte ENTER para terminar!\n");

    }
}
