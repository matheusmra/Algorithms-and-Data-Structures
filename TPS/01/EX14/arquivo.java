import java.io.*;
import java.util.Scanner;

public class arquivo {
    /**
     * Função para realizar a gravação de dados em um arquivo de texto.
     * @param nomeArquivo - Nome do arquivo no qual os dados serão gravados
     * @param n - Inteiro que representa a quantidade de números que serão gravados
     */
    public static void file_Add(String nomeArquivo, int n) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo))) {
            Scanner sc = new Scanner(System.in);
            for (int i = 0; i < n; i++) {
                double num = sc.nextDouble();
                writer.write(Double.toString(num));
                writer.newLine();
            }
            sc.close();
            writer.close(); // Fechando o arquivo após a escrita
        } catch (IOException e) {
            System.out.println("Erro ao abrir o arquivo para gravação.");
            System.exit(1);
        }
    }

    /**
     * Função para realizar a leitura e exibição de dados de um arquivo de texto,
     * lendo de trás para frente.
     * @param nomeArquivo - Nome do arquivo no qual os dados estão gravados
     * @param n - Inteiro que representa a quantidade de números que serão exibidos
     */
    public static void file_Read(String nomeArquivo, int n) {
        try (RandomAccessFile file = new RandomAccessFile(nomeArquivo, "r")) {
            long tamDouble = Double.BYTES;
            long tamArquivo = file.length();
            long posicao = tamArquivo - tamDouble;
            for (int i = 0; i < n && posicao >= 0; i++) {
                file.seek(posicao); // Move o ponteiro para a posição correta
                double num = file.readDouble();
                // Imprime o número de acordo com sua parte inteira ou decimal
                if (num == (int) num) {
                    System.out.println((int) num);
                } else {
                    System.out.println(num);
                }
                posicao -= tamDouble;
            }
        } catch (IOException e) {
            System.out.println("Erro ao abrir o arquivo para leitura.");
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Lê a quantidade de números
        // Passo 1: Grava os números no arquivo
        file_Add("arquivo.txt", n);
        // Passo 2: Lê os números de trás para frente
        file_Read("arquivo.txt", n);
        
        scanner.close();
    }
}
