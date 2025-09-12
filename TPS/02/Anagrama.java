
/**
 * Classe para realizar verificação de anagrama.
 */
public class Anagrama {

    /**
     * Método para obter uma Substring
     * @param inicio Índice inicial
     * @param fim Índice final
     * @param str String de entrada padrão
     * @return Substring obtida
     */
    public static String substr(int inicio, int fim, String str){

        // Definir dados
        String sbs = "";

        // Percorrer String
        for(int i = inicio; i < fim; i++){

            char c = str.charAt(i);
            sbs += c;
        }

        return sbs;
    }

    /**
     * Método para encontrar posição de caractere
     * @param c Caractere desejado
     * @param str String de entrada padrão
     * @return Posição encontrada
     */
    public static int FindChar(char c, String str){

        // Definir dados
        int len = str.length();
        int j = 0;

        // Percorrer String
        for(int i = 0; i < len; i++){

            // Verificação
            char cs = str.charAt(i);
            if(cs == c){

                j = i;
                i = len;
            }
        }

        return j;
    }

    /**
     * Método para obter caractere minúsculo
     * @param c Caractere
     * @return Caractere em minúsculo
     */
    public static char Minuscula(char c){

        if(c >= 'A' && c <= 'Z'){

            return (char) (c + ('a' - 'A')); 
        }
        
        return c;
    }

    /**
     * Método para ordenar String
     * @param str String de entrada padrão 
     * @return String ordenada
     */
    public static String Ordenar(String str){
       
        // Definir dados
        char[] arr = str.toCharArray();
        int len = arr.length;

        // Algoritmo de seleção
        for(int i = 0; i < len - 1; i++){
            
            int menor = i;
            for(int j = i + 1; j < len; j++){
               
                if(Minuscula(arr[j]) < Minuscula(arr[menor])){
                    
                    menor = j;
                }
            }

            // Minúsculo
            arr[i] = Minuscula(arr[i]);
            arr[menor] = Minuscula(arr[menor]);

            // Troca
            char temp = arr[i];
            arr[i] = arr[menor];
            arr[menor] = temp;
        }

        return new String(arr);
    }

    /**
     * Método para verificar se Strings são anagramas
     * @param str1 String 1
     * @param str2 String 2
     * @return Verificação
     */
    public static boolean anagrama(String str1, String str2){

        if(str1.length() != str2.length()){

            return false;
        }

        String cpy1 = Ordenar(str1);
        String cpy2 = Ordenar(str2);

        return cpy1.equals(cpy2);
    }

    /**
     * Método principal que lê strings e verifica propriedade anagrama.
     * O programa encerra quando a entrada for "FIM".
     * @param args Argumentos da linha de comando.
     */
    public static void main(String[] args) {
        
        MyIO.setCharset("ISO-8859-1");

        // Definir dados
        String str1, str2, str3;

        // Leitura de dados
        str1 = MyIO.readLine();
        
        // Looping
        while(!str1.equals("FIM")){

            // Manipulando entrada
            str2 = substr(0, FindChar(' ', str1), str1);
            str3 = substr(FindChar('-', str1) + 2, str1.length(), str1);
            
            // Verificação
            if(anagrama(str2, str3)){

                MyIO.println("SIM");
            } else {
                MyIO.println("NÃO");
            }

            str1 = MyIO.readLine();
        }
    }
}
