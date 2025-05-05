import java.io.*;
import java.util.*;
import java.text.SimpleDateFormat;
import java.text.ParseException;

class Show { 
    public static int comp = 0;
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
    public void Ler(String in) throws Exception {

        // Definir dados
        String simplify = "";
        boolean flag = true;
        int len = in.length();

        // Varrer String para verificar se está entre aspas
        for (int i = 0; i < len; i++) {

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
        setCast(CastAux);

        setCountry(ShowStr[5]);
        setDateAdded(ShowStr[6]);

        // Ajuste de variaveis
        setReleaseYear(StrToInt(ShowStr[7]));
        setRating(ShowStr[8]);
        setDuration(ShowStr[9]);

        // Ajuste na formatação
        String[] ListedInAux = ShowStr[10].split(",\\s*");
        setListedIn(ListedInAux);

    }

    /**
     * Função para criar Show pela String de entrada
     * 
     * @param in String de entrada
     * @return Show criado
     */
    public static Show Create(String in) throws Exception {

        // Definir dados
        Show created = new Show();

        // Leitura
        created.Ler(in);
        return created;
    }

    /**
     * Função para transformar id como String
     * 
     * @param data
     * @return
     */
    public static String IdString(String data) {

        // Definir dados
        String result = "";
        int i = 0;

        while (data.charAt(i) != ',') {

            result += data.charAt(i);
            i++;
        }

        return result;
    }

    /**
     * Leitura do arquivo CSV
     * 
     * @param caminho Caminho do CSV
     * @param id      String de entrada
     */
    public static Show AddVetor(String caminho, String id) throws Exception {

        // Definir dados
        Show show = null;
        File file = new File(caminho);

        if (!file.exists()) {

            throw new FileNotFoundException("Arquivo não encontrado: " + caminho);
        }

        try (Scanner sc = new Scanner(file)) {

            // Definir dados
            String data;

            // Verificar linhas
            while (sc.hasNext()) {

                // Criar show caso seja igual ao id
                data = sc.nextLine();
                if (IdString(data).equals(id)) {

                    show = Create(data);
                    quickSort(0, show.getCast().length - 1, show.getCast());
                }

            }
        }

        return show;
    }

    public void Imprimir() {

        System.out.print("=> ");
        System.out.print(showId + " ## ");
        System.out.print(title + " ## ");
        System.out.print(type + " ## ");
        System.out.print(director + " ## ");

        System.out.print("[");

        // Elenco
        for (int i = 0; i < cast.length; i++) {

            if (i == cast.length - 1)
                System.out.print(cast[i]);
            else
                System.out.print(cast[i] + ", ");
        }

        System.out.print("]");

        System.out.print(" ## ");

        System.out.print(country + " ## ");
        System.out.print(dateAdded + " ## ");
        System.out.print(releaseYear + " ## ");
        System.out.print(rating + " ## ");
        System.out.print(duration + " ## ");

        System.out.print("[");

        // Categorias
        for (int i = 0; i < listedIn.length; i++) {

            if (i == listedIn.length - 1)
                System.out.print(listedIn[i]);
            else
                System.out.print(listedIn[i] + ", ");
        }

        System.out.print("] ##");
    }

    /**
     * Realiza a troca de posição de alguns elementos
     * 
     * @param i     Índice do primeiro elemento
     * @param j     Índice do segundo elemento
     * @param array Array de Strings a ser ordenado
     */
    public static void swap(int i, int j, String[] array) {

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

        // Define índices e pivô no meio
        int i = esq, j = dir;
        String pivo = array[(esq + dir) / 2];

        // Varredura
        while (i <= j) {

            // Define posição das Strings menores e maiores que o pivô
            while (array[i].compareTo(pivo) < 0)
                i++;
            while (array[j].compareTo(pivo) > 0)
                j--;

            // Troca elementos para que menores fiquem antes do pivô
            // Troca elementos para que maiores fiquem depois do pivô
            if (i <= j) {
                swap(i, j, array);
                i++;
                j--;
            }
        }

        // Chamada recursiva para parte da esquerda e da direita
        if (esq < j)
            quickSort(esq, j, array);
        if (i < dir)
            quickSort(i, dir, array);
    }

    private Date getParsedDate() {

        if (dateAdded == null || dateAdded.isEmpty()) {
            return new Date(0);
        }
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("MMMM d, yyyy", Locale.US);
            return sdf.parse(dateAdded);
        } catch (ParseException e) {
            System.err.println("Erro ao parsear data: " + dateAdded);
            return new Date(0);
        }
    }

    // Método para comparar este show com outro
    public int compareTo(Show other) {

        // Compara as datas primeiro
        int dateComparison = this.getParsedDate().compareTo(other.getParsedDate());
        if (dateComparison != 0) {
            return dateComparison;
        }
        // Se as datas forem iguais, compara os títulos
        return this.title.compareTo(other.title);
    }

    // Método auxiliar para trocar dois elementos no array
    private static void swap(Show[] array, int i, int j) {
        Show temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Quicksort adaptado para Show[]
    public static void QuickSortShow(Show[] array, int esq, int dir) {
        int i = esq, j = dir;
        Show pivo = array[(dir + esq) / 2];

        while (i <= j) {
            while (array[i].compareTo(pivo) < 0)
                i++;
            while (array[j].compareTo(pivo) > 0)
                j--;

            if (i <= j) {
                swap(array, i, j);
                i++;
                j--;
            }
        }

        // Chamadas recursivas
        if (esq < j)
            QuickSortShow(array, esq, j);
        if (i < dir)
            QuickSortShow(array, i, dir);
    }
}

public class Q18 {

    public static void main(String[] args) throws Exception {
        // Definir dados
        long inicio = System.nanoTime();
        Show[] shows = new Show[300];
        String entrada1;
        int i = 0;
        // Leitura dos dados
        entrada1 = MyIO.readLine();
        while (!entrada1.equals("FIM")) {
            shows[i] = Show.AddVetor("/tmp/disneyplus.csv", entrada1);
            i++;
            entrada1 = MyIO.readLine();
        }

        // Ordenação
        Show.QuickSortShow(shows, 0, 299);
        for (int j = 0; j < 10; j++) {
            shows[j].Imprimir();
            System.out.println();
        }
        long fim = System.nanoTime();
        double tempoMs = (fim - inicio) / 1_000_000.0;
        try (PrintWriter writer = new PrintWriter(new FileWriter("848813_quicksort.txt"))) {
            writer.printf("848813\t%d\t%.2f\n", Show.comp, tempoMs);
        }
    }
}