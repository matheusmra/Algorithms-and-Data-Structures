import java.util.Scanner;

public class FilaSimples {
    static final int CAPACIDADE = 5;
    static int[] fila = new int[CAPACIDADE];
    static int frente = 0, tras = 0, tamanho = 0;

    static void enfileirar(int valor) {
        if (tamanho == CAPACIDADE) {
            System.out.println("Fila cheia!");
            return;
        }
        fila[tras] = valor;
        tras = (tras + 1) % CAPACIDADE;
        tamanho++;
    }

    static int desenfileirar() {
        if (tamanho == 0) {
            System.out.println("Fila vazia!");
            return -1;
        }
        int valor = fila[frente];
        frente = (frente + 1) % CAPACIDADE;
        tamanho--;
        return valor;
    }

    static void imprimirFila() {
        if (tamanho == 0) {
            System.out.println("Fila vazia!");
            return;
        }
        System.out.print("Fila: ");
        for (int i = 0; i < tamanho; i++) {
            System.out.print(fila[(frente + i) % CAPACIDADE] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        enfileirar(10);
        imprimirFila();
        enfileirar(20);
        imprimirFila();
        enfileirar(30);
        imprimirFila();
        System.out.println("Removido: " + desenfileirar());
        imprimirFila();
        scanner.close();
    }
}
