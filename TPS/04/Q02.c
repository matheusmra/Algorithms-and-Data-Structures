#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LENGTH 5000
#define MAX_FIELD_LENGTH 1000
#define MAX_ARRAY_SIZE 100
#define MAX_GAMES 1852

typedef struct {
    int id;
    char name[MAX_FIELD_LENGTH];
    char releaseDate[20];
    int estimatedOwners;
    float price;
    char supportedLanguages[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH];
    int supportedLanguagesCount;
    int metacriticScore;
    float userScore;
    int achievements;
    char publishers[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH];
    int publishersCount;
    char developers[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH];
    int developersCount;
    char categories[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH];
    int categoriesCount;
    char genres[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH];
    int genresCount;
    char tags[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH];
    int tagsCount;
} Game;

/**
 * Função para inicializar um Game com valores padrão
 * Define todos os campos da estrutura com valores iniciais apropriados
 * @param game - Ponteiro para a estrutura Game a ser inicializada
 */
void initGame(Game *game) {
    game->id = 0;
    strcpy(game->name, "");
    strcpy(game->releaseDate, "");
    game->estimatedOwners = 0;
    game->price = 0.0f;
    game->supportedLanguagesCount = 0;
    game->metacriticScore = -1;
    game->userScore = -1.0f;
    game->achievements = 0;
    game->publishersCount = 0;
    game->developersCount = 0;
    game->categoriesCount = 0;
    game->genresCount = 0;
    game->tagsCount = 0;
}

/**
 * Função para extrair apenas os números de uma string
 * Remove todos os caracteres não numéricos e retorna o valor inteiro
 * @param str - String contendo números e outros caracteres
 * @return Número inteiro extraído da string, ou 0 se não houver números
 */
int extractNumbers(char *str) {
    char numbers[MAX_FIELD_LENGTH] = "";
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            numbers[j++] = str[i];
        }
    }
    numbers[j] = '\0';

    return (strlen(numbers) > 0) ? atoi(numbers) : 0;
}

/**
 * Função para normalizar formato de data do CSV para padrão brasileiro
 * Converte datas do formato "MMM dd, yyyy" para "dd/mm/yyyy"
 * Trata casos com informações incompletas usando "01" como padrão
 * @param data - String contendo a data no formato original
 * @param result - String onde será armazenado o resultado formatado
 */
void normalizarData(char *data, char *result) {
    if (data == NULL || strlen(data) == 0) {
        strcpy(result, "");
        return;
    }

    char *meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                     "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    char dataCopy[MAX_FIELD_LENGTH];
    strcpy(dataCopy, data);

    char *token = strtok(dataCopy, " ");
    char mes[10] = "", dia[10] = "", ano[10] = "";
    int count = 0;

    while (token != NULL && count < 3) {
        if (count == 0) strcpy(mes, token);
        else if (count == 1) {
            strcpy(dia, token);
            dia[strcspn(dia, ",")] = '\0';
        }
        else if (count == 2) strcpy(ano, token);
        count++;
        token = strtok(NULL, " ");
    }

    if (count == 3) {
        int numMes = 1;
        for (int i = 0; i < 12; i++) {
            if (strcmp(meses[i], mes) == 0) {
                numMes = i + 1;
                break;
            }
        }
        sprintf(result, "%02d/%02d/%s", atoi(dia), numMes, ano);
    } else if (count == 2) {
        int numMes = 1;
        for (int i = 0; i < 12; i++) {
            if (strcmp(meses[i], mes) == 0) {
                numMes = i + 1;
                break;
            }
        }
        sprintf(result, "01/%02d/%s", numMes, ano);
    } else if (count == 1) {
        sprintf(result, "01/01/%s", mes);
    } else {
        strcpy(result, data);
    }
}

/**
 * Função para extrair elementos de um array formatado entre colchetes
 * Processa campos do CSV que contêm listas no formato ['item1', 'item2', ...]
 * Remove aspas simples e espaços desnecessários dos elementos
 * @param campo - String contendo o array a ser processado
 * @param array - Matriz bidimensional onde serão armazenados os elementos
 * @return Número de elementos extraídos e armazenados no array
 */
int extrairArray(char *campo, char array[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH]) {
    if (campo == NULL || strlen(campo) == 0) {
        return 0;
    }

    int count = 0;

    if (campo[0] == '[' && campo[strlen(campo)-1] == ']') {
        char conteudo[MAX_FIELD_LENGTH * 10];
        strncpy(conteudo, campo + 1, strlen(campo) - 2);
        conteudo[strlen(campo) - 2] = '\0';

        if (strlen(conteudo) == 0) return 0;

        int i = 0, j = 0;
        int dentroAspas = 0;
        char item[MAX_FIELD_LENGTH] = "";

        while (i < strlen(conteudo)) {
            char c = conteudo[i];

            if (c == '\'' && (i == 0 || conteudo[i-1] != '\\')) {
                dentroAspas = !dentroAspas;
            } else if (c == ',' && !dentroAspas) {
                if (item[0] == '\'' && item[strlen(item)-1] == '\'') {
                    item[strlen(item)-1] = '\0';
                    strcpy(array[count], item + 1);
                } else {
                    strcpy(array[count], item);
                }

                char *start = array[count];
                while (*start == ' ') start++;
                if (start != array[count]) {
                    memmove(array[count], start, strlen(start) + 1);
                }

                if (strlen(array[count]) > 0) count++;
                strcpy(item, "");
                j = 0;

                while (i + 1 < strlen(conteudo) && conteudo[i + 1] == ' ') i++;
            } else {
                item[j++] = c;
                item[j] = '\0';
            }
            i++;
        }

        if (strlen(item) > 0) {
            if (item[0] == '\'' && item[strlen(item)-1] == '\'') {
                item[strlen(item)-1] = '\0';
                strcpy(array[count], item + 1);
            } else {
                strcpy(array[count], item);
            }

            char *start = array[count];
            while (*start == ' ') start++;
            if (start != array[count]) {
                memmove(array[count], start, strlen(start) + 1);
            }

            if (strlen(array[count]) > 0) count++;
        }
    } else if (strchr(campo, ',') != NULL) {
        char *token = strtok(campo, ",");
        while (token != NULL && count < MAX_ARRAY_SIZE) {
            while (*token == ' ') token++;
            char *end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = '\0';

            strcpy(array[count], token);
            count++;
            token = strtok(NULL, ",");
        }
    } else {
        strcpy(array[0], campo);
        count = 1;
    }

    return count;
}

/**
 * Função para fazer parsing de uma linha CSV respeitando aspas e vírgulas
 * Separa os campos de uma linha CSV tratando corretamente campos entre aspas
 * que podem conter vírgulas internas
 * @param linha - String contendo a linha completa do arquivo CSV
 * @param campos - Matriz onde serão armazenados os campos separados
 * @return Número de campos extraídos da linha
 */
int parseCSVLine(char *linha, char campos[20][MAX_FIELD_LENGTH * 5]) {
    int count = 0;
    int i = 0;
    int dentroAspas = 0;
    char campo[MAX_FIELD_LENGTH * 5] = "";
    int j = 0;

    while (i < strlen(linha) && count < 20) {
        char c = linha[i];

        if (c == '"') {
            dentroAspas = !dentroAspas;
        } else if (c == ',' && !dentroAspas) {
            campo[j] = '\0';
            strcpy(campos[count], campo);
            count++;
            strcpy(campo, "");
            j = 0;
        } else {
            campo[j++] = c;
        }
        i++;
    }

    campo[j] = '\0';
    strcpy(campos[count], campo);
    count++;

    while (count < 14) {
        strcpy(campos[count], "");
        count++;
    }

    return count;
}

/**
 * Função para processar uma linha CSV e popular uma estrutura Game
 * Extrai todos os dados de uma linha do arquivo CSV e preenche os campos
 * correspondentes na estrutura Game com tratamento adequado de tipos
 * @param linha - String contendo a linha do CSV a ser processada
 * @param game - Ponteiro para a estrutura Game a ser preenchida
 */
void lerGame(char *linha, Game *game) {
    // Agora "campos" não fica mais na stack de cada chamada
    static char campos[20][MAX_FIELD_LENGTH * 5];
    parseCSVLine(linha, campos);

    game->id = atoi(campos[0]);
    strcpy(game->name, campos[1]);
    normalizarData(campos[2], game->releaseDate);
    game->estimatedOwners = extractNumbers(campos[3]);

    if (strcmp(campos[4], "Free to Play") == 0 || strlen(campos[4]) == 0) {
        game->price = 0.0f;
    } else {
        game->price = atof(campos[4]);
    }

    game->supportedLanguagesCount = extrairArray(campos[5], game->supportedLanguages);
    game->metacriticScore = (strlen(campos[6]) == 0) ? -1 : atoi(campos[6]);
    game->userScore = (strlen(campos[7]) == 0 || strcmp(campos[7], "tbd") == 0) ? -1.0f : atof(campos[7]);
    game->achievements = (strlen(campos[8]) == 0) ? 0 : atoi(campos[8]);

    game->publishersCount = extrairArray(campos[9], game->publishers);
    game->developersCount = extrairArray(campos[10], game->developers);
    game->categoriesCount = extrairArray(campos[11], game->categories);
    game->genresCount = extrairArray(campos[12], game->genres);
    game->tagsCount = extrairArray(campos[13], game->tags);
}

/**
 * Função para converter um array de strings em uma única string formatada
 * Concatena todos os elementos do array separados por vírgulas e espaços
 * Utilizada para formatar arrays de dados antes da impressão
 * @param array - Matriz bidimensional contendo as strings a serem concatenadas
 * @param count - Número de elementos válidos no array
 * @param result - String onde será armazenado o resultado concatenado
 */
void arrayToString(char array[MAX_ARRAY_SIZE][MAX_FIELD_LENGTH], int count, char *result) {
    strcpy(result, "");
    for (int i = 0; i < count; i++) {
        strcat(result, array[i]);
        if (i < count - 1) {
            strcat(result, ", ");
        }
    }
}

/**
 * Função para exibir um Game 
 * @param game - Ponteiro para a estrutura Game a ser impressa
 */
void printGame(Game *game) {
    char langStr[MAX_FIELD_LENGTH * 10] = "";
    char pubStr[MAX_FIELD_LENGTH * 10] = "";
    char devStr[MAX_FIELD_LENGTH * 10] = "";
    char catStr[MAX_FIELD_LENGTH * 10] = "";
    char genStr[MAX_FIELD_LENGTH * 10] = "";
    char tagStr[MAX_FIELD_LENGTH * 10] = "";

    arrayToString(game->supportedLanguages, game->supportedLanguagesCount, langStr);
    arrayToString(game->publishers, game->publishersCount, pubStr);
    arrayToString(game->developers, game->developersCount, devStr);
    arrayToString(game->categories, game->categoriesCount, catStr);
    arrayToString(game->genres, game->genresCount, genStr);
    arrayToString(game->tags, game->tagsCount, tagStr);

    // Formatação inteligente do preço dentro da função printGame
    if (game->price == (int)game->price) {
        // Número inteiro: formato com 1 casa decimal (ex: 2.0)
        printf("=> %d ## %s ## %s ## %d ## %.1f ## [%s] ## %d ## %.1f ## %d ## [%s] ## [%s] ## [%s] ## [%s] ## [%s] ##\n",
               game->id, game->name, game->releaseDate, game->estimatedOwners, game->price,
               langStr, game->metacriticScore, game->userScore, game->achievements,
               pubStr, devStr, catStr, genStr, tagStr);
    } else {
        // Tem decimais: verificar se termina em 0
        char tempPrice[20];
        sprintf(tempPrice, "%.2f", game->price);
        
        // Remove zero final desnecessário (ex: 2.90 vira 2.9)
        int len = strlen(tempPrice);
        if (len > 2 && tempPrice[len-1] == '0' && tempPrice[len-2] != '.') {
            tempPrice[len-1] = '\0';
        }
        
        printf("=> %d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %.1f ## %d ## [%s] ## [%s] ## [%s] ## [%s] ## [%s] ##\n",
               game->id, game->name, game->releaseDate, game->estimatedOwners, tempPrice,
               langStr, game->metacriticScore, game->userScore, game->achievements,
               pubStr, devStr, catStr, genStr, tagStr);
    }
}


/**
 * Função principal do programa
 * Carrega os dados dos jogos do arquivo CSV, processa entradas do usuário
 * e exibe as informações dos jogos solicitados até receber "FIM"
 * @return Código de saída do programa (0 para sucesso, 1 para erro)
 */
int main() {
    setlocale(LC_ALL, "");

    Game *games = malloc(sizeof(Game) * MAX_GAMES);
    if (games == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    int gameCount = 0;
    FILE *file = fopen("/tmp/games.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo\n");
        free(games);
        return 1;
    }

    char linha[MAX_LINE_LENGTH];

    if (fgets(linha, sizeof(linha), file) == NULL) {
        fclose(file);
        free(games);
        return 1;
    }

    while (fgets(linha, sizeof(linha), file) != NULL && gameCount < MAX_GAMES) {
        linha[strcspn(linha, "\n")] = '\0';
        initGame(&games[gameCount]);
        lerGame(linha, &games[gameCount]);
        gameCount++;
    }

    fclose(file);

    char entrada[100];
    while (scanf("%s", entrada) && strcmp(entrada, "FIM") != 0) {
        int idProcurado = atoi(entrada);

        for (int i = 0; i < gameCount; i++) {
            if (games[i].id == idProcurado) {
                printGame(&games[i]);
                break;
            }
        }
    }

    free(games);
    return 0;
}
