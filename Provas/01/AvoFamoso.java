import java.util.*;
public class AvoFamoso {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int primeiro = 0;
            int segundo = 0;
            if(N == 0 && M == 0){
                break;
            }
            int[] pontos = new int[10001];
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    int jogador = sc.nextInt();
                    pontos[jogador]++;
                }
            }
            for(int i = 1; i <= 10000; i++){
                if(pontos[i] > primeiro) {
                    segundo = primeiro;
                    primeiro = pontos[i];
                }else if(pontos[i] > segundo && pontos[i] < primeiro){
                    segundo = pontos[i];
                }
            }
            List<Integer> segundos = new ArrayList<>();
            for(int i = 1; i <= 10000; i++){
                if(pontos[i] == segundo){
                    segundos.add(i);
                }
            }
            for(int jogador : segundos){
                System.out.print(jogador + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
