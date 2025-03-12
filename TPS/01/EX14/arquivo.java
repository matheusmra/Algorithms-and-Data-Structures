
import java.io.*;
 import java.util.Scanner;

 class arquivo {
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt();
         try (RandomAccessFile arquivo = new RandomAccessFile("arquivo.txt", "rw")) {
             for (int i = 0; i < n; i++) {
                 double valor = sc.nextDouble();
                 arquivo.writeDouble(valor); 
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
 
         try (RandomAccessFile arquivo = new RandomAccessFile("arquivo.txt", "r")) {
             long tamanhoArquivo = arquivo.length(); 
             long posicao = tamanhoArquivo - 8;  
             while (posicao >= 0) {
                 arquivo.seek(posicao); 
                 double valor = arquivo.readDouble(); 
                 System.out.println(valor);
                 posicao -= 8; 
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
 }
 