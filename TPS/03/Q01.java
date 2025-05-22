package TPS.03;

import java.io.*;
import java.util.*;

class Show { 

    private String showId;
    private String type;
    private String title;
    private String director;
    private String[] cast;
    private String country;
    private String dateAdded;
    private int releaseYear;
    private String rating;
    private String duration;
    private String[] listedIn;

    Show() {
        this.showId = null;
        this.type = null;
        this.title = null;
        this.director = null;
        this.cast = null;
        this.country = null;
        this.dateAdded = null;
        this.releaseYear = 0;
        this.rating = null;
        this.duration = null;
        this.listedIn = null;
    }

    Show(String showId, String type, String title, String director, String[] cast, String country,
            String dateAdded, int releaseYear, String rating, String duration, String[] listedIn){
        this.showId = showId;
        this.type = type;
        this.title = title;
        this.director = director;
        this.cast = new String[cast.length];
        this.country = country;
        this.dateAdded = dateAdded;
        this.releaseYear = releaseYear;
        this.rating = rating;
        this.duration = duration;
        this.listedIn = new String[listedIn.length];
    }

    public String getShowId(){

        return showId;
    }

    public void setShowId(String x){

        this.showId = (x.equals("")) ? "NaN" : x;
    }

    public String getType(){

        return type;
    }

    public void setType(String x){
        
        this.type = (x.equals("")) ? "NaN" : x;
    }

    public String getTitle(){
        
        return title;
    }

    public void setTitle(String x){
        this.title = (x.equals("")) ? "NaN" : x;
    }

    public String getDirector(){
        
        return director;
    }

    public void setDirector(String x){

        this.director = (x.equals("")) ? "NaN" : x;
    }

    public String[] getCast(){
        
        return cast;
    }

    public void setCast(String[] x){

        if(x.length == 1 && x[0].equals("")){

            this.cast = new String[] { "NaN" };
        } else {

            this.cast = x;
        }
    }

    public String getCountry(){

        return country;
    }

    
    public void setCountry(String x){

        this.country = (x.equals("")) ? "NaN" : x;
    }

    public String getDateAdded(){
        
        return dateAdded;
    }

    public void setDateAdded(String x){

        this.dateAdded = (x.equals("")) ? "NaN" : x;
    }

    public int getReleaseYear(){

        return releaseYear;
    }

    public void setReleaseYear(int x){

        this.releaseYear = x;
    }

    public String getRating(){
        
        return rating;
    }

    public void setRating(String x){

        this.rating = (x.equals("")) ? "NaN" : x;
    }

    public String getDuration(){

        return duration;
    }

    public void setDuration(String x){

        this.duration = (x.equals("")) ? "NaN" : x;
    }

    public String[] getListedIn(){
        
        return listedIn;
    }

    public void setListedIn(String[] listedIn){

        if(listedIn.length == 1 && listedIn[0].equals("")){

            this.listedIn = new String[] { "NaN" };
        } else {

            this.listedIn = listedIn;
        }
    }


    /**
     * Função para clonar um show.
     * 
     * @return novo objeto Show com os mesmos dados
     */
    public Show Clone(){
        return new Show(this.showId,this.type,this.title,this.director,this.cast,this.country,this.dateAdded,this.releaseYear,this.rating,this.duration,this.listedIn);
    }

    /**
     * Função para transformar String em inteiro
     * 
     * @param str String a ser transformada
     */
    public int StrToInt(String str){

        // Definir dados
        int len = str.length();
        int data = 0;

        for(int i = 0; i < len; i++){

            char c = str.charAt(i);
            data = (10 * data) + (c - '0');
        }

        return data;
    }

    /**
     * Leitura de dados da entrada e atribuições
     * 
     * @param in Entrada de dados
     */
    public void Ler(String in) throws Exception{

        // Definir dados
        String simplify = "";
        boolean flag = true;
        int len = in.length();

        // Varrer String para verificar se está entre aspas
        for(int i = 0; i < len; i++){

            char c = in.charAt(i);
            if (c == '"')
                flag = !flag;
            else if (c == ',' && flag)
                simplify += '|';
            else
                simplify += c;
        }

        // Array de Strings simplificado
        String[] ShowStr = simplify.split("\\|");
        // Settando valores
        setShowId(ShowStr[0]);
        setType(ShowStr[1]);
        setTitle(ShowStr[2]);
        setDirector(ShowStr[3]);

        // Ajuste na formatação
        String[] CastAux = ShowStr[4].split(",\\s*");
        int castl = CastAux.length;
        quickSort(0, castl - 1, CastAux);
        setCast(CastAux);
        setCountry(ShowStr[5]);
        setDateAdded(ShowStr[6]);

        // Ajuste de variaveis
        setReleaseYear(StrToInt(ShowStr[7]));
        setRating(ShowStr[8]);
        setDuration(ShowStr[9]);

        // Ajuste na formatação
        String[] ListedInAux = ShowStr[10].split(",\\s*");
        int ListedLen = ListedInAux.length;
        quickSort(0, ListedLen - 1, ListedInAux);
        setListedIn(ListedInAux);

    }

    /**
     * Função para criar Show pela String de entrada
     * 
     * @param in String de entrada
     * @return Show criado
     */
    public static Show Create(String in) throws Exception{
        Show created = new Show();
        created.Ler(in);
        return created;
    }

    /**
     * Leitura do arquivo CSV
     * 
     * @param caminho Caminho do CSV
     */
    public static Show[] csv(String caminho) throws Exception{
        Show[] shows = new Show[1369];
        File file = new File(caminho);
        if(!file.exists()){
            throw new FileNotFoundException("Arquivo não encontrado: " + caminho);
        }
        try(Scanner sc = new Scanner(file)){
            String data;
            int i = 0;
            while(sc.hasNext()){
                data = sc.nextLine();
                shows[i++] = Create(data);
            }
        }
        return shows;
    }

    /**
     * Função para trocar dois elementos do array
     * 
     * @param i     Índice do primeiro elemento
     * @param j     Índice do segundo elemento
     * @param array Array de Strings 
     */
    public static void swap(int i, int j, String[] array){

        String temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /**
     * Método QuickSort de ordenação para Strings
     * 
     * @param esq   Índice inicial
     * @param dir   Índice final
     * @param array Array de Strings a ser ordenado
     */
    public static void quickSort(int esq, int dir, String[] array) {
        if (array == null || array.length == 0 || esq >= dir)
            return;
        int i = esq, j = dir;
        String pivo = array[esq + (dir - esq) / 2]; 
        while (i <= j) {
            while (array[i].compareTo(pivo) < 0) i++;
            while (array[j].compareTo(pivo) > 0) j--;
            if (i <= j) {
                swap(i, j, array);
                i++;
                j--;
            }
        }
        // Chamada recursiva
        if (esq < j) quickSort(esq, j, array);
        if (i < dir) quickSort(i, dir, array);
    }
    

    public void Imprimir() {

        System.out.print("=> ");
        System.out.print(showId + " ## ");
        System.out.print(title + " ## ");
        System.out.print(type + " ## ");
        System.out.print(director + " ## ");
        System.out.print("[");
        if(cast != null && cast.length > 0)
            System.out.print(String.join(", ", cast));
        System.out.print("]");
        System.out.print(" ## ");
        System.out.print(country + " ## ");
        System.out.print(dateAdded + " ## ");
        System.out.print(releaseYear + " ## ");
        System.out.print(rating + " ## ");
        System.out.print(duration + " ## ");
        System.out.print("[");
        // Categorias
        if(listedIn != null && listedIn.length > 0)
            System.out.print(String.join(", ", listedIn));
        System.out.print("] ## ");
        System.out.println(); 
    }
}

import java.io.*;
import java.util.*;

class ListaShow {
    private Show[] array;
    private int n;

    public ListaShow(int tamanho){
        array = new Show[tamanho];
        n = 0;
    }

    public void inserirInicio(Show show) throws Exception {
        if(n >= array.length) throw new Exception("Erro ao inserir: lista cheia");
        // mover todos para direita
        for(int i = n; i > 0; i--){
            array[i] = array[i-1];
        }
        array[0] = show;
        n++;
    }

    public void inserir(Show show, int pos) throws Exception {
        if(n >= array.length || pos < 0 || pos > n) throw new Exception("Erro ao inserir");
        // mover todos da pos para direita
        for(int i = n; i > pos; i--){
            array[i] = array[i-1];
        }
        array[pos] = show;
        n++;
    }

    public void inserirFim(Show show) throws Exception {
        if(n >= array.length) throw new Exception("Erro ao inserir: lista cheia");
        array[n] = show;
        n++;
    }

    public Show removerInicio() throws Exception {
        if(n == 0) throw new Exception("Erro ao remover: lista vazia");
        Show resp = array[0];
        // mover todos para esquerda
        for(int i = 0; i < n-1; i++){
            array[i] = array[i+1];
        }
        array[n-1] = null;
        n--;
        return resp;
    }

    public Show remover(int pos) throws Exception {
        if(n == 0 || pos < 0 || pos >= n) throw new Exception("Erro ao remover");
        Show resp = array[pos];
        for(int i = pos; i < n-1; i++){
            array[i] = array[i+1];
        }
        array[n-1] = null;
        n--;
        return resp;
    }

    public Show removerFim() throws Exception {
        if(n == 0) throw new Exception("Erro ao remover: lista vazia");
        Show resp = array[n-1];
        array[n-1] = null;
        n--;
        return resp;
    }

    public void mostrar(){
        for(int i = 0; i < n; i++){
            array[i].Imprimir();
        }
    }
}


public class Q01 {
    public static void main(String[] args) throws Exception {
        MyIO.setCharset("ISO-8859-1");
        // Ler todos os shows do CSV
        Show[] shows = Show.csv("TPS/02/tmp/disneyplus.csv");

        ListaShow lista = new ListaShow(150);  // capacidade arbitrária

        // Parte 1: ler IDs para imprimir shows correspondentes (igual TP02)
        String linha = MyIO.readLine();
        while(!linha.equals("FIM")){
            for(int i = 0; i < shows.length; i++){
                if(shows[i].getShowId().equals(linha)){
                    shows[i].Imprimir();
                    break;
                }
            }
            linha = MyIO.readLine();
        }

        // Parte 2: comandos de inserção e remoção
        int n = Integer.parseInt(MyIO.readLine());
        for(int i = 0; i < n; i++){
            linha = MyIO.readLine();
            String[] cmd = linha.split(" ");

            switch(cmd[0]){
                case "II": // inserir no início
                    // cmd[1] = nome do arquivo com o show a inserir
                    Show sII = Show.Create("/tmp/" + cmd[1]);
                    lista.inserirInicio(sII);
                    break;

                case "IF": // inserir no fim
                    Show sIF = Show.Create("/tmp/" + cmd[1]);
                    lista.inserirFim(sIF);
                    break;

                case "I*": // inserir em posição
                    int posI = Integer.parseInt(cmd[1]);
                    Show sI = Show.Create("/tmp/" + cmd[2]);
                    lista.inserir(sI, posI);
                    break;

                case "RI": // remover início
                    Show rI = lista.removerInicio();
                    System.out.println("(R) " + rI.getTitle());
                    break;

                case "RF": // remover fim
                    Show rF = lista.removerFim();
                    System.out.println("(R) " + rF.getTitle());
                    break;

                case "R*": // remover posição
                    int posR = Integer.parseInt(cmd[1]);
                    Show r = lista.remover(posR);
                    System.out.println("(R) " + r.getTitle());
                    break;

                default:
                    throw new Exception("Comando inválido");
            }
        }

        // Mostrar lista no final
        lista.mostrar();
    }
}

