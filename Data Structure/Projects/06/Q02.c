#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 256
#define MAX_ARRAY 50
#define MAX_LINE 4096
#define MAX_GAMES 2000
#define bool short
#define true 1
#define false 0

typedef struct
{
    int appID;
    char name[MAX_STR];
    char releaseDate[20];
    int estimatedOwners;
    double price;
    char *supportedLanguages[MAX_ARRAY];
    int metacriticScore;
    double userScore;
    int achievements;
    char *publishers[MAX_ARRAY];
    char *developers[MAX_ARRAY];
    char *categories[MAX_ARRAY];
    char *genres[MAX_ARRAY];
    char *tags[MAX_ARRAY];
} Game;

typedef struct CelulaDupla
{
    Game elemento;            // Elemento inserido na celula.
    struct CelulaDupla *prox; // Aponta a celula prox.
    struct CelulaDupla *ant;  // Aponta a celula anterior.
} CelulaDupla;

CelulaDupla *novaCelulaDupla(Game elemento)
{
    CelulaDupla *nova = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    nova->elemento = elemento;
    nova->ant = nova->prox = NULL;
    return nova;
}

// LISTA PROPRIAMENTE DITA =======================================================
CelulaDupla *primeiro;
CelulaDupla *ultimo;

/**
 * Cria uma lista dupla sem elementos (somente no cabeca).
 */
void start()
{
    // criar sentinela vazia (appID = -1)
    Game sentinela;
    memset(&sentinela, 0, sizeof(Game));
    sentinela.appID = -1;
    primeiro = novaCelulaDupla(sentinela);
    ultimo = primeiro;
}

/**
 * Insere um elemento na primeira posicao da lista.
 * @param x int elemento a ser inserido.
 */
void inserirInicio(Game x)
{
    CelulaDupla *tmp = novaCelulaDupla(x);

    tmp->ant = primeiro;
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if (primeiro == ultimo)
    {
        ultimo = tmp;
    }
    else
    {
        tmp->prox->ant = tmp;
    }
    tmp = NULL;
}

/**
 * Insere um elemento na ultima posicao da lista.
 * @param x int elemento a ser inserido.
 */
void inserirFim(Game x)
{
    ultimo->prox = novaCelulaDupla(x);
    ultimo->prox->ant = ultimo;
    ultimo = ultimo->prox;
}

/**
 * Remove um elemento da primeira posicao da lista.
 * @return resp int elemento a ser removido.
 */
Game removerInicio()
{
    if (primeiro == ultimo)
    {
        fprintf(stderr, "Erro ao remover (vazia)!\n");
        exit(1);
    }

    CelulaDupla *tmp = primeiro;
    primeiro = primeiro->prox;
    Game resp = primeiro->elemento;
    tmp->prox = primeiro->ant = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

/**
 * Remove um elemento da ultima posicao da lista.
 * @return resp int elemento a ser removido.
 */
Game removerFim()
{
    if (primeiro == ultimo)
    {
        fprintf(stderr, "Erro ao remover (vazia)!\n");
        exit(1);
    }
    Game resp = ultimo->elemento;
    ultimo = ultimo->ant;
    ultimo->prox->ant = NULL;
    free(ultimo->prox);
    ultimo->prox = NULL;
    return resp;
}

/**
 *  Calcula e retorna o tamanho, em numero de elementos, da lista.
 *  @return resp int tamanho
 */
int tamanho()
{
    int tamanho = 0;
    CelulaDupla *i;
    for (i = primeiro; i != ultimo; i = i->prox, tamanho++)
        ;
    return tamanho;
}

/**
 * Insere um elemento em uma posicao especifica considerando que o
 * primeiro elemento valido esta na posicao 0.
 * @param x int elemento a ser inserido.
 * @param pos int posicao da insercao.
 * @throws Exception Se <code>posicao</code> invalida.
 */
void inserir(Game x, int pos)
{

    int tam = tamanho();

    if (pos < 0 || pos > tam)
    {
        fprintf(stderr, "Erro ao inserir (posicao %d/%d invalida)!\n", pos, tam);
        exit(1);
    }
    else if (pos == 0)
    {
        inserirInicio(x);
    }
    else if (pos == tam)
    {
        inserirFim(x);
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        CelulaDupla *i = primeiro;
        int j;
        for (j = 0; j < pos; j++, i = i->prox)
            ;

        CelulaDupla *tmp = novaCelulaDupla(x);
        tmp->ant = i;
        tmp->prox = i->prox;
        tmp->ant->prox = tmp->prox->ant = tmp;
        tmp = i = NULL;
    }
}

/**
 * Remove um elemento de uma posicao especifica da lista
 * considerando que o primeiro elemento valido esta na posicao 0.
 * @param posicao Meio da remocao.
 * @return resp int elemento a ser removido.
 * @throws Exception Se <code>posicao</code> invalida.
 */
Game remover(int pos)
{
    Game resp;
    int tam = tamanho();

    if (primeiro == ultimo)
    {
        fprintf(stderr, "Erro ao remover (vazia)!\n");
        exit(1);
    }
    else if (pos < 0 || pos >= tam)
    {
        fprintf(stderr, "Erro ao remover (posicao %d/%d invalida)!\n", pos, tam);
        exit(1);
    }
    else if (pos == 0)
    {
        resp = removerInicio();
    }
    else if (pos == tam - 1)
    {
        resp = removerFim();
    }
    else
    {
        // Caminhar ate a posicao anterior a insercao
        CelulaDupla *i = primeiro->prox;
        int j;
        for (j = 0; j < pos; j++, i = i->prox)
            ;

        i->ant->prox = i->prox;
        i->prox->ant = i->ant;
        resp = i->elemento;
        i->prox = i->ant = NULL;
        free(i);
        i = NULL;
    }

    return resp;
}

/**
 * Mostra os elementos da lista separados por espacos.
 */
void mostrar()
{
    CelulaDupla *i;
    printf("[ ");
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
        printf("%d ", i->elemento.appID);
    }
    printf("] \n");
}

/**
 * Mostra os elementos da lista de forma invertida
 * e separados por espacos.
 */
void mostrarInverso()
{
    printf("[ ");
    CelulaDupla *i;
    for (i = ultimo; i != primeiro; i = i->ant)
    {
        printf("%d ", i->elemento.appID);
    }
    printf("] \n"); // Termina de mostrar.
}

/**
 * Procura um elemento e retorna se ele existe.
 * @param x Elemento a pesquisar.
 * @return <code>true</code> se o elemento existir,
 * <code>false</code> em caso contrario.
 */
bool pesquisar(Game x)
{
    bool resp = false;
    CelulaDupla *i;

    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
        if (i->elemento.appID == x.appID)
        {
            resp = true;
            break;
        }
    }
    return resp;
}

/**
 * Remove espaços em branco do início e fim de uma string.
 *
 * @param str Ponteiro para a string a ser trimada.
 */
void trim_inplace(char *str)
{
    int i = 0;
    while (isspace((unsigned char)str[i]))
        i++;
    if (i > 0)
        memmove(str, str + i, strlen(str + i) + 1);

    int len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1]))
        str[--len] = '\0';
}

/**
 * Converte uma string numérica para int.
 *
 * @param s Ponteiro para a string contendo o número.
 * @return Valor inteiro convertido.
 */
int stringParaInt(const char *s)
{
    if (!s)
        return 0;
    int sign = 1, i = 0;
    if (s[0] == '-')
    {
        sign = -1;
        i = 1;
    }
    long val = 0;
    for (; s[i] != '\0'; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            break;
        val = val * 10 + (s[i] - '0');
    }
    return (int)(val * sign);
}

/**
 * Converte uma string numérica para double.
 *
 * @param s Ponteiro para a string contendo o número.
 * @return Valor double convertido..
 */
double stringParaDouble(const char *s)
{
    if (!s)
        return 0.0;
    double inteiro = 0.0, frac = 0.0;
    int i = 0, neg = 0;
    if (s[0] == '-')
    {
        neg = 1;
        i = 1;
    }
    while (s[i] && s[i] != '.')
    {
        if (s[i] >= '0' && s[i] <= '9')
            inteiro = inteiro * 10 + (s[i] - '0');
        else
            break;
        i++;
    }
    if (s[i] == '.')
    {
        i++;
        double base = 1;
        while (s[i])
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                frac = frac * 10 + (s[i] - '0');
                base *= 10;
            }
            else
                break;
            i++;
        }
        frac = frac / base;
    }
    double total = inteiro + frac;
    return neg ? -total : total;
}

/**
 * Converte abreviação de mês.
 *
 * @param mes Abreviação do mês .
 * @return Ponteiro para string.
 */
const char *mesParaNumero(const char *mes)
{
    if (strcmp(mes, "Jan") == 0)
        return "01";
    if (strcmp(mes, "Feb") == 0)
        return "02";
    if (strcmp(mes, "Mar") == 0)
        return "03";
    if (strcmp(mes, "Apr") == 0)
        return "04";
    if (strcmp(mes, "May") == 0)
        return "05";
    if (strcmp(mes, "Jun") == 0)
        return "06";
    if (strcmp(mes, "Jul") == 0)
        return "07";
    if (strcmp(mes, "Aug") == 0)
        return "08";
    if (strcmp(mes, "Sep") == 0)
        return "09";
    if (strcmp(mes, "Oct") == 0)
        return "10";
    if (strcmp(mes, "Nov") == 0)
        return "11";
    if (strcmp(mes, "Dec") == 0)
        return "12";
    return "01";
}

/**
 * Normaliza datas em vários formatos para o formato DD/MM/YYYY.
 *
 * @param entrada String de entrada com a data.
 * @param saida Buffer onde será escrita a data normalizada.
 * @param saida_size Tamanho do buffer de saída.
 */
void converterData(const char *entrada, char *saida, size_t saida_size)
{
    if (!entrada || entrada[0] == '\0')
    {
        strncpy(saida, "01/01/1900", saida_size);
        saida[saida_size - 1] = '\0';
        return;
    }
    char temp[64];
    strncpy(temp, entrada, sizeof(temp) - 1);
    temp[sizeof(temp) - 1] = '\0';
    char mes[16] = "", dia[8] = "01", ano[16] = "1900";
    int parts = sscanf(temp, "%15s %7s %15s", mes, dia, ano);
    if (parts == 3)
    {
        char *p = strchr(dia, ',');
        if (p)
            *p = '\0';
    }
    else if (parts == 2)
    {
        strcpy(ano, dia);
        strcpy(dia, "01");
    }
    else if (parts == 1)
    {
        strcpy(ano, mes);
        strcpy(mes, "Jan");
    }
    int di = stringParaInt(dia);
    const char *mm = mesParaNumero(mes);
    snprintf(saida, saida_size, "%02d/%s/%s", di, mm, ano);
}

/**
 * Método auxiliar para extrair arrays de strings entre colchetes.
 *
 * @param campo String contendo o array a ser extraído.
 * @param saida Array de char* onde serão armazenadas strings alocadas.
 * @param max_saida Capacidade máxima do array saida.
 * @return Número de elementos extraídos.
 */
int quebrarArray(const char *campo, char *saida[], int max_saida)
{
    if (!campo)
        return 0;
    char buf[MAX_STR];
    int j = 0, count = 0;
    for (int i = 0; campo[i] != '\0'; i++)
    {
        char c = campo[i];
        if (c == '[' || c == ']' || c == '\'')
            continue;
        if (c == ',')
        {
            buf[j] = '\0';
            trim_inplace(buf);
            if (j > 0 && count < max_saida)
            {
                saida[count] = malloc(strlen(buf) + 1);
                strcpy(saida[count], buf);
                count++;
            }
            j = 0;
        }
        else
        {
            if (j < (int)sizeof(buf) - 1)
                buf[j++] = c;
            else
            {
                // se exceder, truncamos o token para evitar overflow
                buf[j] = '\0';
            }
        }
    }
    buf[j] = '\0';
    trim_inplace(buf);
    if (j > 0 && count < max_saida)
    {
        saida[count] = malloc(strlen(buf) + 1);
        strcpy(saida[count++], buf);
    }
    // marca sentinel NULL para indicar fim do array
    if (count < max_saida)
        saida[count] = NULL;
    else
        saida[max_saida - 1] = NULL;
    return count;
}

/**
 * Divide uma linha CSV em campos.
 * Aloca cada campo com malloc.
 *
 * @param linha Linha CSV a ser dividida.
 * @param campos Vetor de char* onde serão colocados ponteiros para strings alocadas.
 * @param maxCampos Capacidade máxima do vetor campos.
 * @return Número de campos encontrados.
 */
int dividirCSV(const char *linha, char *campos[], int maxCampos)
{
    char campoAtual[MAX_LINE];
    int j = 0, dentroAspas = 0, count = 0;
    for (int i = 0;; i++)
    {
        char c = linha[i];
        if (c == '"')
        {
            // trata aspas duplas escapadas ""
            if (linha[i + 1] == '"')
            {
                if (j < (int)sizeof(campoAtual) - 1)
                    campoAtual[j++] = '"';
                i++; // pula a segunda aspa
            }
            else
            {
                dentroAspas = !dentroAspas;
            }
        }
        else if ((c == ',' && !dentroAspas) || c == '\0' || c == '\n' || c == '\r')
        {
            campoAtual[j] = '\0';
            if (count < maxCampos)
            {
                campos[count] = malloc(strlen(campoAtual) + 1);
                strcpy(campos[count], campoAtual);
                trim_inplace(campos[count]);
                // remover aspas externas se existirem
                size_t len = strlen(campos[count]);
                if (len >= 2 && campos[count][0] == '"' && campos[count][len - 1] == '"')
                {
                    // move para esquerda e remove ultima
                    memmove(campos[count], campos[count] + 1, len - 2);
                    campos[count][len - 2] = '\0';
                    // desfaz escape de aspas duplas
                    char *src = campos[count], *dst = campos[count];
                    while (*src)
                    {
                        if (src[0] == '"' && src[1] == '"')
                        {
                            *dst++ = '"';
                            src += 2;
                        }
                        else
                            *dst++ = *src++;
                    }
                    *dst = '\0';
                    trim_inplace(campos[count]);
                }
            }
            count++;
            j = 0;
            if (c == '\0' || c == '\n')
                break;
        }
        else
        {
            if (j < (int)sizeof(campoAtual) - 1)
                campoAtual[j++] = c;
            else
            {
                // truncar para evitar overflow
            }
        }
    }
    return count < maxCampos ? count : maxCampos;
}

/**
 * Formata e imprime o preço seguindo as regras do enunciado:

 * @param price Valor do preço a ser impresso.
 */
static void printPrice(double price)
{
    // se for zero (Free to Play), mostrar 0.0
    if (price == 0.0)
    {
        printf("0.0");
        return;
    }
    char buf[64];
    snprintf(buf, sizeof(buf), "%.2f", price);
    size_t len = strlen(buf);
    // 2.00 -> 2.0 ; 7.50 -> 7.5 ; 2.99 -> 2.99
    if (len >= 4 && buf[len - 3] == '.' && buf[len - 2] == '0' && buf[len - 1] == '0')
    {
        buf[len - 2] = '0';
        buf[len - 1] = '\0';
    }
    else if (len >= 2 && buf[len - 1] == '0')
    {
        buf[len - 1] = '\0';
    }
    printf("%s", buf);
}

/**
 * Imprime um Game no formato usado na listagem final: "[idx] => appID ## name ## ..."
 */
void imprimirJogoLinha(const Game *g, int idx)
{
    printf("[%d] => %d ## %s ## %s ## %d ## ", idx, g->appID, g->name, g->releaseDate, g->estimatedOwners);
    printPrice(g->price);
    printf(" ## [");

    for (int i = 0; g->supportedLanguages[i] != NULL; i++)
    {
        printf("%s", g->supportedLanguages[i]);
        if (g->supportedLanguages[i + 1] != NULL)
            printf(", ");
    }

    printf("] ## %d ## ", g->metacriticScore);
    printf("%.1f", g->userScore);
    printf(" ## %d ## [", g->achievements);

    for (int i = 0; g->publishers[i] != NULL; i++)
    {
        printf("%s", g->publishers[i]);
        if (g->publishers[i + 1] != NULL)
            printf(", ");
    }

    printf("] ## [");
    for (int i = 0; g->developers[i] != NULL; i++)
    {
        printf("%s", g->developers[i]);
        if (g->developers[i + 1] != NULL)
            printf(", ");
    }

    printf("] ## [");
    for (int i = 0; g->categories[i] != NULL; i++)
    {
        printf("%s", g->categories[i]);
        if (g->categories[i + 1] != NULL)
            printf(", ");
    }

    printf("] ## [");
    for (int i = 0; g->genres[i] != NULL; i++)
    {
        printf("%s", g->genres[i]);
        if (g->genres[i + 1] != NULL)
            printf(", ");
    }

    printf("] ## [");
    for (int i = 0; g->tags[i] != NULL; i++)
    {
        printf("%s", g->tags[i]);
        if (g->tags[i + 1] != NULL)
            printf(", ");
    }

    printf("] ##\n");
}

/**
 * Lê o arquivo CSV de jogos, cria structs Game preenchidos e os armazena no array 'jogos'.
 *
 * @param jogos Ponteiro para array previamente alocado de Game com capacidade maxJogos.
 * @param maxJogos Capacidade máxima do array jogos.
 * @param caminho Caminho do arquivo CSV a ser aberto.
 * @return Número de registros lidos com sucesso.
 */
int loadCSV(Game *jogos, int maxJogos, const char *caminho)
{
    FILE *f = fopen(caminho, "r");
    if (!f)
    {
        perror("Erro ao abrir arquivo");
        return 0;
    }

    char linha[MAX_LINE];
    int qtd = 0;

    if (!fgets(linha, sizeof(linha), f))
    {
        fclose(f);
        return 0;
    } // pula cabeçalho

    while (fgets(linha, sizeof(linha), f) != NULL && qtd < maxJogos)
    {
        char *campos[14] = {0};
        int ncampos = dividirCSV(linha, campos, 14);

        Game g;
        memset(&g, 0, sizeof(Game));
        /* arrays serão terminadas por NULL por quebrarArray */

        g.appID = (ncampos > 0) ? stringParaInt(campos[0]) : 0;
        if (ncampos > 1)
        {
            strncpy(g.name, campos[1], MAX_STR - 1);
            g.name[MAX_STR - 1] = '\0';
            trim_inplace(g.name);
        }
        if (ncampos > 2)
            converterData(campos[2], g.releaseDate, sizeof(g.releaseDate));
        if (ncampos > 3)
            g.estimatedOwners = stringParaInt(campos[3]);
        if (ncampos > 4)
            g.price = stringParaDouble(campos[4]);
        if (ncampos > 5)
            quebrarArray(campos[5], g.supportedLanguages, MAX_ARRAY);
        if (ncampos > 6)
            g.metacriticScore = stringParaInt(campos[6]);
        if (ncampos > 7)
            g.userScore = stringParaDouble(campos[7]);
        if (ncampos > 8)
            g.achievements = stringParaInt(campos[8]);
        if (ncampos > 9)
            quebrarArray(campos[9], g.publishers, MAX_ARRAY);
        if (ncampos > 10)
            quebrarArray(campos[10], g.developers, MAX_ARRAY);
        if (ncampos > 11)
            quebrarArray(campos[11], g.categories, MAX_ARRAY);
        if (ncampos > 12)
            quebrarArray(campos[12], g.genres, MAX_ARRAY);
        if (ncampos > 13)
            quebrarArray(campos[13], g.tags, MAX_ARRAY);

        jogos[qtd++] = g;

        /* libera campos lidos */
        int tofree = (ncampos < 14) ? ncampos : 14;
        for (int i = 0; i < tofree; i++)
            if (campos[i])
                free(campos[i]);
    }

    fclose(f);
    return qtd;
}

/**
 * Libera toda a memória alocada dinamicamente nas listas internas de cada Game.
 *
 * @param jogos Ponteiro para o array de Game previamente preenchido.
 * @param qtd Número de elementos válidos no array jogos.
 */
void liberarRecursos(Game *jogos, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        for (int j = 0; jogos[i].supportedLanguages[j] != NULL; j++)
            free(jogos[i].supportedLanguages[j]);
        for (int j = 0; jogos[i].publishers[j] != NULL; j++)
            free(jogos[i].publishers[j]);
        for (int j = 0; jogos[i].developers[j] != NULL; j++)
            free(jogos[i].developers[j]);
        for (int j = 0; jogos[i].categories[j] != NULL; j++)
            free(jogos[i].categories[j]);
        for (int j = 0; jogos[i].genres[j] != NULL; j++)
            free(jogos[i].genres[j]);
        for (int j = 0; jogos[i].tags[j] != NULL; j++)
            free(jogos[i].tags[j]);
    }
}

int main()
{
    /* Aloca dinamicamente no heap */
    Game *jogos = malloc(sizeof(Game) * MAX_GAMES);
    if (!jogos)
    {
        fprintf(stderr, "Memória insuficiente\n");
        return 1;
    }
    /* FIX: Estava com problema ao tentar abrir o arquivo */
    const char *csvPath = "/tmp/games.csv";

    if (fopen("games.csv", "r"))
    {
        csvPath = "games.csv";
    }

    int qtd = loadCSV(jogos, MAX_GAMES, csvPath);

    start(); // inicializa lista dupla

    char entrada[256];
    while (1)
    {
        if (!fgets(entrada, sizeof(entrada), stdin))
            break;
        trim_inplace(entrada);
        if (strcmp(entrada, "FIM") == 0)
            break;
        int id = stringParaInt(entrada);
        for (int i = 0; i < qtd; i++)
        {
            if (jogos[i].appID == id)
            {
                inserirFim(jogos[i]);
                break;
            }
        }
    }

    /* Lê o número de operações a serem realizadas */
    int numOperations = 0;
    if (fgets(entrada, sizeof(entrada), stdin))
    {
        trim_inplace(entrada);
        numOperations = stringParaInt(entrada);
    }

    /* Processar comandos */
    int removedCount = 1;
    for (int op = 0; op < numOperations; op++)
    {
        if (!fgets(entrada, sizeof(entrada), stdin))
            break;
        trim_inplace(entrada);
        if (entrada[0] == '\0')
        {
            op--;
            continue;
        }

        if (strncmp(entrada, "II", 2) == 0)
        {
            int id = 0;
            sscanf(entrada + 2, "%d", &id);
            for (int i = 0; i < qtd; i++)
                if (jogos[i].appID == id)
                {
                    inserirInicio(jogos[i]);
                    break;
                }
        }
        else if (strncmp(entrada, "IF", 2) == 0)
        {
            int id = 0;
            sscanf(entrada + 2, "%d", &id);
            for (int i = 0; i < qtd; i++)
                if (jogos[i].appID == id)
                {
                    inserirFim(jogos[i]);
                    break;
                }
        }
        else if (strncmp(entrada, "I*", 2) == 0)
        {
            int pos = 0, id = 0;
            sscanf(entrada + 2, "%d %d", &pos, &id);
            for (int i = 0; i < qtd; i++)
                if (jogos[i].appID == id)
                {
                    inserir(jogos[i], pos);
                    break;
                }
        }
        else if (strcmp(entrada, "RI") == 0)
        {
            Game r = removerInicio();
            printf("%d (R) %s\n", removedCount++, r.name);
        }
        else if (strcmp(entrada, "RF") == 0)
        {
            Game r = removerFim();
            printf("%d (R) %s\n", removedCount++, r.name);
        }
        else if (strncmp(entrada, "R*", 2) == 0)
        {
            int pos = 0;
            sscanf(entrada + 2, "%d", &pos);
            Game r = remover(pos);
            printf("%d (R) %s\n", removedCount++, r.name);
        }
    }
    int n = 0;
    for (CelulaDupla *i = primeiro->prox; i != NULL; i = i->prox) {
        imprimirJogoLinha(&i->elemento, n++);
    }

    liberarRecursos(jogos, qtd);
    free(jogos);
    return 0;
}
