import java.io.*;
import java.util.*;

class Game {
    private int id;
    private String name;
    private String releaseDate;
    private int estimatedOwners;
    private float price;
    private String[] supportedLanguages;
    private int metacriticScore;
    private float userScore;
    private int achievements;
    private String[] publishers;
    private String[] developers;
    private String[] categories;
    private String[] genres;
    private String[] tags;

    /**
     * Construtor padrão da classe Game
     * Inicializa todos os atributos com valores padrão
     */
    Game() {
        this.id = 0;
        this.name = "";
        this.releaseDate = "";
        this.estimatedOwners = 0;
        this.price = 0.0f;
        this.supportedLanguages = new String[0];
        this.metacriticScore = -1;
        this.userScore = -1.0f;
        this.achievements = 0;
        this.publishers = new String[0];
        this.developers = new String[0];
        this.categories = new String[0];
        this.genres = new String[0];
        this.tags = new String[0];
    }

    /**
     * Construtor parametrizado da classe Game
     * 
     * @param id                 - Identificador único do jogo
     * @param name               - Nome do jogo
     * @param releaseDate        - Data de lançamento do jogo
     * @param estimatedOwners    - Número estimado de jogadores
     * @param price              - Preço do jogo
     * @param supportedLanguages - Array de idiomas suportados
     * @param metacriticScore    - Nota da crítica especializada
     * @param userScore          - Nota dos usuários
     * @param achievements       - Quantidade de conquistas
     * @param publishers         - Array de publicadoras
     * @param developers         - Array de desenvolvedoras
     * @param categories         - Array de categorias do jogo
     * @param genres             - Array de gêneros do jogo
     * @param tags               - Array de tags do jogo
     */
    Game(int id, String name, String releaseDate, int estimatedOwners, float price, String[] supportedLanguages,
            int metacriticScore, float userScore, int achievements, String[] publishers, String[] developers,
            String[] categories, String[] genres, String[] tags) {
        this.id = id;
        this.name = name;
        this.releaseDate = releaseDate;
        this.estimatedOwners = estimatedOwners;
        this.price = price;
        this.supportedLanguages = supportedLanguages.clone();
        this.metacriticScore = metacriticScore;
        this.userScore = userScore;
        this.achievements = achievements;
        this.publishers = publishers.clone();
        this.developers = developers.clone();
        this.categories = categories.clone();
        this.genres = genres.clone();
        this.tags = tags.clone();
    }

    /**
     * Método para clonar um objeto Game
     * 
     * @return Clone do objeto Game atual
     */
    public Game clone() {
        Game resp = new Game();
        resp.id = this.id;
        resp.name = this.name;
        resp.releaseDate = this.releaseDate;
        resp.estimatedOwners = this.estimatedOwners;
        resp.price = this.price;
        resp.supportedLanguages = this.supportedLanguages.clone();
        resp.metacriticScore = this.metacriticScore;
        resp.userScore = this.userScore;
        resp.achievements = this.achievements;
        resp.publishers = this.publishers.clone();
        resp.developers = this.developers.clone();
        resp.categories = this.categories.clone();
        resp.genres = this.genres.clone();
        resp.tags = this.tags.clone();
        return resp;
    }

    /**
     * Getter para o ID do jogo
     * 
     * @return ID do jogo
     */
    public int getGameId() {
        return id;
    }

    /**
     * Setter para o ID do jogo
     * 
     * @param id - Novo ID do jogo
     */
    public void setGameId(int id) {
        this.id = id;
    }

    /**
     * Getter para o nome do jogo
     * 
     * @return Nome do jogo
     */
    public String getGameName() {
        return name;
    }

    /**
     * Setter para o nome do jogo
     * 
     * @param name - Novo nome do jogo
     */
    public void setGameName(String name) {
        this.name = name;
    }

    /**
     * Getter para a data de lançamento do jogo
     * 
     * @return Data de lançamento do jogo
     */
    public String getGameReleaseDate() {
        return releaseDate;
    }

    /**
     * Setter para a data de lançamento do jogo
     * 
     * @param releaseDate - Nova data de lançamento
     */
    public void setGameReleaseDate(String releaseDate) {
        this.releaseDate = releaseDate;
    }

    /**
     * Getter para o número estimado de jogadores
     * 
     * @return Número estimado de jogadores
     */
    public int getGameEstimatedOwners() {
        return estimatedOwners;
    }

    /**
     * Setter para o número estimado de jogadores
     * 
     * @param estimatedOwners - Novo número estimado de jogadores
     */
    public void setGameEstimatedOwners(int estimatedOwners) {
        this.estimatedOwners = estimatedOwners;
    }

    /**
     * Getter para o preço do jogo
     * 
     * @return Preço do jogo
     */
    public float getGamePrice() {
        return price;
    }

    /**
     * Setter para o preço do jogo
     * 
     * @param price - Novo preço do jogo
     */
    public void setGamePrice(float price) {
        this.price = price;
    }

    /**
     * Getter para os idiomas suportados
     * 
     * @return Array de idiomas suportados
     */
    public String[] getGameSupportedLanguages() {
        return supportedLanguages;
    }

    /**
     * Setter para os idiomas suportados
     * 
     * @param supportedLanguages - Novo array de idiomas suportados
     */
    public void setGameSupportedLanguages(String[] supportedLanguages) {
        this.supportedLanguages = supportedLanguages;
    }

    /**
     * Getter para a nota da crítica especializada
     * 
     * @return Nota da crítica especializada
     */
    public int getGameMetacriticScore() {
        return metacriticScore;
    }

    /**
     * Setter para a nota da crítica especializada
     * 
     * @param metacriticScore - Nova nota da crítica especializada
     */
    public void setGameMetacriticScore(int metacriticScore) {
        this.metacriticScore = metacriticScore;
    }

    /**
     * Getter para a nota dos usuários
     * 
     * @return Nota dos usuários
     */
    public float getGameUserScore() {
        return userScore;
    }

    /**
     * Setter para a nota dos usuários
     * 
     * @param userScore - Nova nota dos usuários
     */
    public void setGameUserScore(float userScore) {
        this.userScore = userScore;
    }

    /**
     * Getter para a quantidade de conquistas
     * 
     * @return Quantidade de conquistas
     */
    public int getGameAchievements() {
        return achievements;
    }

    /**
     * Setter para a quantidade de conquistas
     * 
     * @param achievements - Nova quantidade de conquistas
     */
    public void setGameAchievements(int achievements) {
        this.achievements = achievements;
    }

    /**
     * Getter para as publicadoras do jogo
     * 
     * @return Array de publicadoras
     */
    public String[] getGamePublishers() {
        return publishers;
    }

    /**
     * Setter para as publicadoras do jogo
     * 
     * @param publishers - Novo array de publicadoras
     */
    public void setGamePublishers(String[] publishers) {
        this.publishers = publishers;
    }

    /**
     * Getter para as desenvolvedoras do jogo
     * 
     * @return Array de desenvolvedoras
     */
    public String[] getGameDevelopers() {
        return developers;
    }

    /**
     * Setter para as desenvolvedoras do jogo
     * 
     * @param developers - Novo array de desenvolvedoras
     */
    public void setGameDevelopers(String[] developers) {
        this.developers = developers;
    }

    /**
     * Getter para as categorias do jogo
     * 
     * @return Array de categorias
     */
    public String[] getGameCategories() {
        return categories;
    }

    /**
     * Setter para as categorias do jogo
     * 
     * @param categories - Novo array de categorias
     */
    public void setGameCategories(String[] categories) {
        this.categories = categories;
    }

    /**
     * Getter para os gêneros do jogo
     * 
     * @return Array de gêneros
     */
    public String[] getGameGenres() {
        return genres;
    }

    /**
     * Setter para os gêneros do jogo
     * 
     * @param genres - Novo array de gêneros
     */
    public void setGameGenres(String[] genres) {
        this.genres = genres;
    }

    /**
     * Getter para as tags do jogo
     * 
     * @return Array de tags
     */
    public String[] getGameTags() {
        return tags;
    }

    /**
     * Setter para as tags do jogo
     * 
     * @param tags - Novo array de tags
     */
    public void setGameTags(String[] tags) {
        this.tags = tags;
    }

    /**
     * Método auxiliar para fazer parse de uma linha CSV
     * Trata campos entre aspas e vírgulas corretamente
     * 
     * @param linha - Linha do arquivo CSV a ser processada
     * @return Array de strings com os campos separados
     */
    private String[] parseCSVLine(String linha) {
        List<String> campos = new ArrayList<>();
        boolean dentroAspas = false;
        StringBuilder campo = new StringBuilder();

        for (int i = 0; i < linha.length(); i++) {
            char c = linha.charAt(i);

            if (c == '"') {
                dentroAspas = !dentroAspas;
            } else if (c == ',' && !dentroAspas) {
                campos.add(campo.toString());
                campo = new StringBuilder();
            } else {
                campo.append(c);
            }
        }
        campos.add(campo.toString());

        // Garantir que temos pelo menos 14 campos
        while (campos.size() < 14) {
            campos.add("");
        }

        return campos.toArray(new String[0]);
    }

    /**
     * Método auxiliar para extrair arrays de strings entre colchetes
     * Processa campos que contêm listas no formato ['item1', 'item2', ...]
     * 
     * @param campo - String contendo o array a ser extraído
     * @return Array de strings com os elementos extraídos
     */
    private String[] extrairArray(String campo) {
        if (campo == null || campo.isEmpty()) {
            return new String[0];
        }

        campo = campo.trim();

        if (campo.startsWith("[") && campo.endsWith("]")) {
            String conteudo = campo.substring(1, campo.length() - 1).trim();
            if (conteudo.isEmpty()) {
                return new String[0];
            }

            // Split por vírgula, mas mantém aspas simples
            List<String> itens = new ArrayList<>();
            boolean dentroAspas = false;
            StringBuilder item = new StringBuilder();

            for (int i = 0; i < conteudo.length(); i++) {
                char c = conteudo.charAt(i);

                if (c == '\'' && (i == 0 || conteudo.charAt(i - 1) != '\\')) {
                    dentroAspas = !dentroAspas;
                } else if (c == ',' && !dentroAspas) {
                    String itemStr = item.toString().trim();
                    if (itemStr.startsWith("'") && itemStr.endsWith("'")) {
                        itemStr = itemStr.substring(1, itemStr.length() - 1);
                    }
                    if (!itemStr.isEmpty()) {
                        itens.add(itemStr);
                    }
                    item = new StringBuilder();
                } else {
                    item.append(c);
                }
            }

            // Adicionar o último item
            String itemStr = item.toString().trim();
            if (itemStr.startsWith("'") && itemStr.endsWith("'")) {
                itemStr = itemStr.substring(1, itemStr.length() - 1);
            }
            if (!itemStr.isEmpty()) {
                itens.add(itemStr);
            }

            return itens.toArray(new String[0]);
        }

        // Se não está entre colchetes, tenta dividir por vírgula
        if (campo.contains(",")) {
            String[] partes = campo.split(",");
            for (int i = 0; i < partes.length; i++) {
                partes[i] = partes[i].trim().replaceAll("^'|'$", "");
            }
            return partes;
        }

        return new String[] { campo.trim().replaceAll("^'|'$", "") };
    }

    /**
     * Método para ler e processar dados de uma linha CSV
     * Popula todos os atributos do objeto Game com base nos dados da linha
     * 
     * @param linha - Linha do arquivo CSV contendo os dados do jogo
     */
    public void ler(String linha) {
        String[] campos = parseCSVLine(linha);

        try {
            this.id = Integer.parseInt(campos[0].trim());
            this.name = campos[1].trim();
            // Chamando a funcao de normalizacao de data
            this.releaseDate = normalizarData(campos[2].trim());
            // Estimated owners - remover caracteres não numéricos
            String owners = campos[3].trim().replaceAll("[^0-9]", "");
            this.estimatedOwners = owners.isEmpty() ? 0 : Integer.parseInt(owners);
            // Tratar preço - "Free to Play" vira 0.0
            String priceStr = campos[4].trim();
            if (priceStr.equals("Free to Play") || priceStr.isEmpty()) {
                this.price = 0.0f;
            } else {
                this.price = Float.parseFloat(priceStr);
            }
            // Extraindo array
            this.supportedLanguages = extrairArray(campos[5]);
            // tratando vazio
            String metaStr = campos[6].trim();
            if (metaStr.isEmpty()) {
                this.metacriticScore = -1;
            } else {
                this.metacriticScore = Integer.parseInt(metaStr);
            }

            // tratando vazio e "tbd"
            String userStr = campos[7].trim();
            if (userStr.isEmpty() || userStr.equals("tbd")) {
                this.userScore = -1.0f;
            } else {
                this.userScore = Float.parseFloat(userStr);
            }

            // tratando vazio
            String achStr = campos[8].trim();
            if (achStr.isEmpty()) {
                this.achievements = 0;
            } else {
                this.achievements = Integer.parseInt(achStr);
            }

            // Separando por vírgulas (se não estiver entre colchetes)
            String pubStr = campos[9].trim();
            if (pubStr.startsWith("[") && pubStr.endsWith("]")) {
                this.publishers = extrairArray(pubStr);
            } else {
                this.publishers = pubStr.split(",");
                for (int i = 0; i < publishers.length; i++) {
                    publishers[i] = publishers[i].trim();
                }
            }
            // Separando por vírgulas (se não estiver entre colchetes)
            String devStr = campos[10].trim();
            if (devStr.startsWith("[") && devStr.endsWith("]")) {
                this.developers = extrairArray(devStr);
            } else {
                this.developers = devStr.split(",");
                for (int i = 0; i < developers.length; i++) {
                    developers[i] = developers[i].trim();
                }
            }
            // Extrair arrays para categories, genres e tags
            this.categories = extrairArray(campos[11]);
            this.genres = extrairArray(campos[12]);
            this.tags = extrairArray(campos[13]);

        } catch (Exception e) {
            System.err.println("Erro ao processar linha: " + linha);
            e.printStackTrace();
        }
    }

    /**
     * Método auxiliar para normalizar formato de data
     * Converte datas do formato "MMM dd, yyyy" para "dd/mm/yyyy"
     * 
     * @param data - String contendo a data a ser normalizada
     * @return String com a data normalizada no formato dd/mm/yyyy
     */
    private String normalizarData(String data) {
        if (data == null || data.trim().isEmpty()) {
            return "";
        }

        data = data.trim();
        String[] meses = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

        String[] partes = data.split(" ");
        // Caso 1:Data completa
        if (partes.length == 3) {
            String mes = partes[0];
            String dia = partes[1].replace(",", "");
            String ano = partes[2];

            int numMes = 1;
            for (int i = 0; i < meses.length; i++) {
                if (meses[i].equals(mes)) {
                    numMes = i + 1;
                    break;
                }
            }

            return String.format("%02d/%02d/%s", Integer.parseInt(dia), numMes, ano);
            // Caso 2: Data sem dia
        } else if (partes.length == 2) {
            String mes = partes[0];
            String ano = partes[1];
            int numMes = 1;
            for (int i = 0; i < meses.length; i++) {
                if (meses[i].equals(mes)) {
                    numMes = i + 1;
                    break;
                }
            }
            return String.format("01/%02d/%s", numMes, ano);
            // Caso 3: Data só com ano
        } else if (partes.length == 1) {
            String ano = partes[0];
            return String.format("01/01/%s", ano);
        }

        // Se não conseguir processar, retorna a string original
        return data;
    }

    /**
     * Método auxiliar para converter array em string formatada
     * Converte um array de strings em uma string separada por vírgulas
     * 
     * @param array - Array de strings a ser convertido
     * @return String com elementos separados por vírgulas
     */
    private String arrayToString(String[] array) {
        if (array.length == 0)
            return "";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1)
                sb.append(", ");
        }
        return sb.toString();
    }

    /**
     * Método toString para exibir o jogo no formato especificado
     * Retorna uma representação formatada do objeto Game
     * 
     * @return String formatada com todos os dados do jogo
     */
    @Override
    public String toString() {
        return String.format(
                "=> %d ## %s ## %s ## %d ## %.2f ## [%s] ## %d ## %.1f ## %d ## [%s] ## [%s] ## [%s] ## [%s] ## [%s] ##",
                id, name, releaseDate, estimatedOwners, price,
                arrayToString(supportedLanguages), metacriticScore, userScore,
                achievements, arrayToString(publishers), arrayToString(developers),
                arrayToString(categories), arrayToString(genres), arrayToString(tags));
    }
}

/**
 * Pilha dinamica
 * 
 * @author Max do Val Machado
 * @version 2 01/2015
 */
class Pilha {
    private Celula topo;

    /**
     * Construtor da classe que cria uma fila sem elementos.
     */
    public Pilha() {
        topo = null;
    }

    /**
     * Insere elemento na pilha (politica FILO).
     * 
     * @param x Game elemento a inserir.
     */
    public void inserir(Game x) {
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }

    /**
     * Remove elemento da pilha (politica FILO).
     * 
     * @return Elemento removido.
     * @trhows Exception Se a sequencia nao contiver elementos.
     */
    public Game remover() throws Exception {
        if (topo == null) {
            throw new Exception("Erro ao remover!");
        }
        Game resp = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return resp;
    }

    /**
     * Mostra os elementos separados por espacos, comecando do topo.
     */
    public void mostrar() {
        System.out.print("[ ");
        for (Celula i = topo; i != null; i = i.prox) {
            System.out.print(i.elemento + " ");
        }
        System.out.println("] ");
    }

    public Game buscarPorId(int id) {
        for (Celula i = topo; i != null; i = i.prox) {
            if (i.elemento.getGameId() == id) {
                return i.elemento;
            }
        }
        return null;
    }
    
}

class Celula {
    public Game elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    /**
     * Construtor da classe.
     * 
     * @param elemento int inserido na celula.
     */
    public Celula(Game elemento) {
        this.elemento = elemento;
        this.prox = null;
    }
}

public class Q01 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pilha games = new Pilha();

        // Carregar todos os jogos do CSV com codificação UTF-8
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(
                    new FileInputStream("C:\\Users\\1516537\\Desktop\\AEDS2\\TP04\\games.csv"),
                    "UTF-8"));
            String linha = br.readLine(); // Pular cabeçalho
            while ((linha = br.readLine()) != null) {
                Game game = new Game();
                game.ler(linha);
                games.inserir(game);
            }
            br.close();
        } catch (IOException e) {
            System.err.println("Erro ao ler arquivo: " + e.getMessage());
        }

        // Ler IDs do usuário até digitar "FIM"
        String entrada;
        while (!(entrada = scanner.nextLine()).equals("FIM")) {
            try {
                int idProcurado = Integer.parseInt(entrada);
                Game gameEncontrado = games.buscarPorId(idProcurado);
                if (gameEncontrado != null) {
                    System.out.println(gameEncontrado);
                }
            } catch (NumberFormatException e) {
                return;
            }
        }

        scanner.close();
    }
}
