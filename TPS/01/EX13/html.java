import java.io.*;
import java.util.Scanner;
import java.net.*;


public class html {

    public static String get_Html(String endereco) throws URISyntaxException {
        InputStream is = null;
        BufferedReader br;
        String resp = "", line;
        try {
           URI uri;
           URL url;
           uri = new URI(endereco);
           url = uri.toURL();
           is = url.openStream();  
           br = new BufferedReader(new InputStreamReader(is, "UTF-8"));
           while ((line = br.readLine()) != null) {
              resp += line + "\n";
           }
        } catch (MalformedURLException mue) {
           mue.printStackTrace();
        } catch (IOException ioe) {
           ioe.printStackTrace();
        } 
        return resp;
    }

    public static void show_count_html(String html, String nome){
        int x1 = 0,x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, x9 = 0, x10 = 0, x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, x17 = 0, x18 = 0, x19 = 0, x20 = 0, x21 = 0, x22 = 0, x23 = 0, x24 = 0, x25 = 0;
        // Percorre String
        for(int i = 0; i < html.length(); i++){
            char c = html.charAt(i);
            // Verifica se existem as tags desejadas
            if(c == '<'){
                // Verifica se possui a tag <br>
                if(html.charAt(i + 1) == 'b' && html.charAt(i + 2) == 'r' && html.charAt(i + 3) == '>'){
                    x23++;
                    i = i + 3;
                  // Verifica se possui a tag <table>  
                }else if(html.charAt(i + 1) == 't' && html.charAt(i + 2) == 'a' && html.charAt(i + 3) == 'b' && html.charAt(i + 4) == 'l' && html.charAt(i + 5) == 'e' && html.charAt(i + 6) == '>'){
                    x25++;
                    i = i + 6;
                }
            }else if(c >= 'a' && c <= 'z'){
                // Verifique se os caracteres são vogais
                if(c == 'a') x1++;
                else if(c == 'e') x2++;
                else if(c == 'i') x3++;
                else if(c == 'o') x4++;
                else if(c == 'u') x5++;
                else {
                    x23++;
                }
              // Testa se os caracteres possuem acento
            } else if(c == 225) x6++;
              else if(c == 233) x7++;
              else if(c == 237) x8++;
              else if(c == 243) x9++;
              else if(c == 250) x10++;
              else if(c == 224) x11++;
              else if(c == 232) x12++;
              else if(c == 236) x13++;
              else if(c == 242) x14++;
              else if(c == 249) x15++;
              else if(c == 227) x16++;
              else if(c == 245) x17++;
              else if(c == 226) x18++;
              else if(c == 234) x19++;
              else if(c == 238) x20++;
              else if(c == 244) x21++;
              else if(c == 251) x22++;
        }
        // Imprime
        System.out.println("a(" + x1 + ")" + " e(" + x2 + ")" + " i(" + x3 + ")" + " o(" + x4 + ")" + " u(" + x5 + ")" + " á(" + x6 + ")" + " é(" + x7 + ")" + " í(" + x8 + ")" + " ó(" + x9 + ")" + " ú(" + x10 + ")" + " à(" + x11 + ")" + " è(" + x12 + ")" + " ì(" + x13 + ")" + " ò(" + x14 + ")" + " ù(" + x15 + ")" + " ã(" + x16 + ")" + " õ(" + x17 + ")" + " â(" + x18 + ")" + " ê(" + x19 + ")" + " î(" + x20 + ")" + " ô(" + x21 + ")" + " û(" + x22 + ")" + " consoante(" + x23 + ")" + " <br>(" + x24 + ")" + " <table>(" + x25 + ") " + nome);
    }

   public static void main(String[] args) throws URISyntaxException {
      Scanner sc = new Scanner(System.in);
      String nome = "", endereco = "", html = "";
      nome = sc.nextLine();  
      while(!nome.equals("FIM")){
           endereco = sc.nextLine();
           html = get_Html(endereco);
           show_count_html(html, nome);
           nome = sc.nextLine();  
      }
      sc.close();
   }
}