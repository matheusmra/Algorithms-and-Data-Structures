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

    public int getGameId() {
        return id;
    }

    public void setGameId(int id) {
        this.id = id;
    }

    public String getGameName() {
        return name;
    }

    public void setGameName(String name) {
        this.name = name;
    }

    public String getGameReleaseDate() {
        return releaseDate;
    }

    public void setGameReleaseDate(String releaseDate) {
        this.releaseDate = releaseDate;
    }

    public int getGameEstimatedOwners() {
        return estimatedOwners;
    }

    public void setGameEstimatedOwners(int estimatedOwners) {
        this.estimatedOwners = estimatedOwners;
    }

    public float getGamePrice() {
        return price;
    }

    public void setGamePrice(float price) {
        this.price = price;
    }

    public String[] getGameSupportedLanguages() {
        return supportedLanguages;
    }

    public void setGameSupportedLanguages(String[] supportedLanguages) {
        this.supportedLanguages = supportedLanguages;
    }

    public int getGameMetacriticScore() {
        return metacriticScore;
    }

    public void setGameMetacriticScore(int metacriticScore) {
        this.metacriticScore = metacriticScore;
    }

    public float getGameUserScore() {
        return userScore;
    }

    public void setGameUserScore(float userScore) {
        this.userScore = userScore;
    }

    public int getGameAchievements() {
        return achievements;
    }

    public void setGameAchievements(int achievements) {
        this.achievements = achievements;
    }

    public String[] getGamePublishers() {
        return publishers;
    }

    public void setGamePublishers(String[] publishers) {
        this.publishers = publishers;
    }

    public String[] getGameDevelopers() {
        return developers;
    }

    public void setGameDevelopers(String[] developers) {
        this.developers = developers;
    }

    public String[] getGameCategories() {
        return categories;
    }

    public void setGameCategories(String[] categories) {
        this.categories = categories;
    }

    public String[] getGameGenres() {
        return genres;
    }

    public void setGameGenres(String[] genres) {
        this.genres = genres;
    }

    public String[] getGameTags() {
        return tags;
    }

    public void setGameTags(String[] tags) {
        this.tags = tags;
    }

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

        while (campos.size() < 14) {
            campos.add("");
        }

        return campos.toArray(new String[0]);
    }

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

            String itemStr = item.toString().trim();
            if (itemStr.startsWith("'") && itemStr.endsWith("'")) {
                itemStr = itemStr.substring(1, itemStr.length() - 1);
            }
            if (!itemStr.isEmpty()) {
                itens.add(itemStr);
            }

            return itens.toArray(new String[0]);
        }

        if (campo.contains(",")) {
            String[] partes = campo.split(",");
            for (int i = 0; i < partes.length; i++) {
                partes[i] = partes[i].trim().replaceAll("^'|'$", "");
            }
            return partes;
        }

        return new String[] { campo.trim().replaceAll("^'|'$", "") };
    }

    public void ler(String linha) {
        String[] campos = parseCSVLine(linha);

        try {
            this.id = Integer.parseInt(campos[0].trim());
            this.name = campos[1].trim();
            this.releaseDate = normalizarData(campos[2].trim());
            String owners = campos[3].trim().replaceAll("[^0-9]", "");
            this.estimatedOwners = owners.isEmpty() ? 0 : Integer.parseInt(owners);
            String priceStr = campos[4].trim();
            if (priceStr.equals("Free to Play") || priceStr.isEmpty()) {
                this.price = 0.0f;
            } else {
                this.price = Float.parseFloat(priceStr);
            }
            this.supportedLanguages = extrairArray(campos[5]);
            String metaStr = campos[6].trim();
            if (metaStr.isEmpty()) {
                this.metacriticScore = -1;
            } else {
                this.metacriticScore = Integer.parseInt(metaStr);
            }

            String userStr = campos[7].trim();
            if (userStr.isEmpty() || userStr.equals("tbd")) {
                this.userScore = -1.0f;
            } else {
                this.userScore = Float.parseFloat(userStr);
            }

            String achStr = campos[8].trim();
            if (achStr.isEmpty()) {
                this.achievements = 0;
            } else {
                this.achievements = Integer.parseInt(achStr);
            }

            String pubStr = campos[9].trim();
            if (pubStr.startsWith("[") && pubStr.endsWith("]")) {
                this.publishers = extrairArray(pubStr);
            } else {
                this.publishers = pubStr.split(",");
                for (int i = 0; i < publishers.length; i++) {
                    publishers[i] = publishers[i].trim();
                }
            }
            String devStr = campos[10].trim();
            if (devStr.startsWith("[") && devStr.endsWith("]")) {
                this.developers = extrairArray(devStr);
            } else {
                this.developers = devStr.split(",");
                for (int i = 0; i < developers.length; i++) {
                    developers[i] = developers[i].trim();
                }
            }
            this.categories = extrairArray(campos[11]);
            this.genres = extrairArray(campos[12]);
            this.tags = extrairArray(campos[13]);

        } catch (Exception e) {
            System.err.println("Erro ao processar linha: " + linha);
            e.printStackTrace();
        }
    }

    private String normalizarData(String data) {
        if (data == null || data.trim().isEmpty()) {
            return "";
        }

        data = data.trim();
        String[] meses = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

        String[] partes = data.split(" ");
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
        } else if (partes.length == 1) {
            String ano = partes[0];
            return String.format("01/01/%s", ano);
        }

        return data;
    }

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

    @Override
    public String toString() {
        String priceStr;
        if (price == (int) price) {
            priceStr = String.format("%.1f", price);
        } else {
            priceStr = String.format("%.2f", price);
            if (priceStr.endsWith("0") && !priceStr.endsWith(".0")) {
                priceStr = priceStr.substring(0, priceStr.length() - 1);
            }
        }

        return String.format(
                "=> %d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1f ## %d ## [%s] ## [%s] ## [%s] ## [%s] ## [%s] ##",
                id, name, releaseDate, estimatedOwners, priceStr,
                arrayToString(supportedLanguages), metacriticScore, userScore,
                achievements, arrayToString(publishers), arrayToString(developers),
                arrayToString(categories), arrayToString(genres), arrayToString(tags));
    }
}

/**
 * Tabela Hash Direta com Rehash
 * Tamanho da tabela: 21
 * Função hash 1: (soma ASCII do Name) mod tamTab
 * Função hash 2 (rehash): (soma ASCII do Name + 1) mod tamTab
 */
class HashRehash {
    private Game[] tabela;
    private int tamTab; // Tamanho da tabela (21)

    /**
     * Construtor da Tabela Hash com Rehash
     */
    public HashRehash() {
        this.tamTab = 21;
        this.tabela = new Game[tamTab];

        // Inicializa toda a tabela com null
        for (int i = 0; i < tabela.length; i++) {
            tabela[i] = null;
        }
    }

    /**
     * Calcula a soma dos valores ASCII dos caracteres do nome
     * 
     * @param nome - Nome do jogo
     * @return Soma dos valores ASCII
     */
    private int somaASCII(String nome) {
        int soma = 0;
        for (int i = 0; i < nome.length(); i++) {
            soma += (int) nome.charAt(i);
        }
        return soma;
    }

    /**
     * Função hash 1: (soma ASCII do Name) mod tamTab
     * 
     * @param nome - Nome do jogo
     * @return Posição na tabela hash
     */
    private int hash(String nome) {
        return somaASCII(nome) % tamTab;
    }

    /**
     * Função hash 2 (rehash): (soma ASCII do Name + 1) mod tamTab
     * 
     * @param nome - Nome do jogo
     * @return Posição alternativa na tabela hash
     */
    private int rehash(String nome) {
        return (somaASCII(nome) + 1) % tamTab;
    }

    /**
     * Insere um elemento na tabela hash
     * Se houver colisão, usa rehash
     * 
     * @param game - Jogo a ser inserido
     */
    public void inserir(Game game) {
        if (game == null || game.getGameName() == null) {
            return;
        }

        int pos = hash(game.getGameName());

        // Se a posição está vazia, insere diretamente
        if (tabela[pos] == null) {
            tabela[pos] = game;
        }
        // Senão, tenta com rehash
        else {
            pos = rehash(game.getGameName());
            if (tabela[pos] == null) {
                tabela[pos] = game;
            }
            // Se ainda houver colisão, continua tentando com incremento
            else {
                int tentativas = 0;
                while (tabela[pos] != null && tentativas < tamTab) {
                    pos = (pos + 1) % tamTab;
                    tentativas++;
                }
                if (tentativas < tamTab) {
                    tabela[pos] = game;
                }
            }
        }
    }

    /**
     * Retorna a posição hash calculada para um nome (primeira função)
     * 
     * @param nome - Nome do jogo
     * @return Posição hash calculada
     */
    public int getPosicaoHash(String nome) {
        return hash(nome);
    }

    /**
     * Pesquisa um elemento na tabela hash pelo nome
     * Retorna true se encontrado, false caso contrário
     * Também conta as comparações realizadas
     * 
     * @param nome        - Nome do jogo a ser procurado
     * @param comparacoes - Array para armazenar o número de comparações
     * @return true se encontrado, false caso contrário
     */
    public boolean pesquisar(String nome, int[] comparacoes) {
        comparacoes[0] = 0;

        // Primeiro, verifica na posição calculada pela função hash
        int pos = hash(nome);
        comparacoes[0]++;

        if (tabela[pos] != null && tabela[pos].getGameName().equals(nome)) {
            return true;
        }

        // Se não encontrou, tenta com rehash
        pos = rehash(nome);
        comparacoes[0]++;

        if (tabela[pos] != null && tabela[pos].getGameName().equals(nome)) {
            return true;
        }

        // Continua buscando com incremento linear
        int posInicial = pos;
        pos = (pos + 1) % tamTab;
        while (pos != posInicial) {
            comparacoes[0]++;
            if (tabela[pos] == null) {
                return false; // Posição vazia, elemento não está na tabela
            }
            if (tabela[pos].getGameName().equals(nome)) {
                return true;
            }
            pos = (pos + 1) % tamTab;
        }

        return false; // Não encontrado
    }
}

/**
 * Pilha dinâmica para armazenar todos os jogos do CSV
 */
class Pilha {
    private Celula topo;

    public Pilha() {
        topo = null;
    }

    public void inserir(Game x) {
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
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
    public Game elemento;
    public Celula prox;

    public Celula(Game elemento) {
        this.elemento = elemento;
        this.prox = null;
    }
}

public class Q02 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pilha todosJogos = new Pilha();
        HashRehash hashTable = new HashRehash();

        // Variáveis para o arquivo de log
        int totalComparacoes = 0;
        long tempoInicio = System.currentTimeMillis();

        // Carregar todos os jogos do CSV
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(
                    new FileInputStream("/tmp/games.csv"),
                    "UTF-8"));
            String linha = br.readLine(); // Pular cabeçalho
            while ((linha = br.readLine()) != null) {
                Game game = new Game();
                game.ler(linha);
                todosJogos.inserir(game);
            }
            br.close();
        } catch (IOException e) {
            System.err.println("Erro ao ler arquivo: " + e.getMessage());
        }

        // Primeira parte: ler IDs e inserir na tabela hash
        String entrada;
        while (!(entrada = scanner.nextLine()).equals("FIM")) {
            try {
                int idProcurado = Integer.parseInt(entrada);
                Game gameEncontrado = todosJogos.buscarPorId(idProcurado);
                if (gameEncontrado != null) {
                    hashTable.inserir(gameEncontrado);
                }
            } catch (NumberFormatException e) {
                // Ignora entradas inválidas
            }
        }

        // Segunda parte: ler nomes e pesquisar na tabela hash
        while (!(entrada = scanner.nextLine()).equals("FIM")) {
            int[] comparacoes = new int[1];
            int posHash = hashTable.getPosicaoHash(entrada);
            boolean encontrado = hashTable.pesquisar(entrada, comparacoes);
            totalComparacoes += comparacoes[0];

            if (encontrado) {
                System.out.println(entrada + ":  (Posicao: " + posHash + ") SIM");
            } else {
                System.out.println(entrada + ":  (Posicao: " + posHash + ") NAO");
            }
        }

        long tempoFim = System.currentTimeMillis();

        // Gerar arquivo de log
        try {
            PrintWriter pw = new PrintWriter(new FileWriter("848813_hashRehash.txt"));
            pw.println("848813\t" + totalComparacoes + "\t" + (tempoFim - tempoInicio));
            pw.close();
        } catch (IOException e) {
            System.err.println("Erro ao escrever arquivo de log: " + e.getMessage());
        }

        scanner.close();
    }
}
