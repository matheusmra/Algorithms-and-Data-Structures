/*
 Estudo Dirigido 09 - v0.0. - 07 / 10 / 2024
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed09 ed09.c
 Windows: gcc -o ed09 ed09.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed09
 Windows: ed09
*/

// dependencias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
// Tamanho max string
const int TAM_STR = 80;
// Função para mostrar o menu de opções
void menuOpcoes() {
    printf("\nEscolha alguma das opcoes a seguir:\n\n");
    printf("  0 - Encerrar programa\n");
    printf("  1 - Exercicio 0911\n");
    printf("  2 - Exercicio 0912\n");
    printf("  3 - Exercicio 0913\n");
    printf("  4 - Exercicio 0914\n");
    printf("  5 - Exercicio 0915\n");
    printf("  6 - Exercicio 0916\n");
    printf("  7 - Exercicio 0917\n");
    printf("  8 - Exercicio 0918\n");
    printf("  9 - Exercicio 0919\n");
    printf(" 10 - Exercicio 0920\n");
    printf(" 11 - Exercicio 09E1\n");
    printf(" 12 - Exercicio 09E2\n");
} // fim menuOpcoes()

// Função para o exercício 0911
// ler as dimensões (quantidade de linhas e de colunas) de uma matriz real do teclado,
// bem como todos os seus elementos (apenas valores positivos ou zeros).
// Verificar se as dimensões não são nulas ou negativas.
// Para testar, ler dados e mostrá-los na tela por outro método.
//Exemplo: double positiveMatrix [10][10];
 //readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 //printDoubleMatrix ( 3, 3, positiveMatrix )


void readPositiveDoubleMatrix(int linha, int coluna, double positiveMatrix[linha][coluna]) {
    printf("Digite os elementos da matriz (%d x %d):\n", linha, coluna);
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            scanf("%lf", &positiveMatrix[i][j]);
        }
    }
}

void printDoubleMatrix(int linha, int coluna, double positiveMatrix[linha][coluna]) {
    printf("Matriz resultante:\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%.2lf\t", positiveMatrix[i][j]);
        }
        printf("\n");
    }
}

int ex0911() {
    int linha = 0, coluna = 0;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linha);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &coluna);
    if(linha <= 0 || coluna <= 0){
        printf("As dimensoes da matriz devem ser positivas.");
    }
    double positiveMatrix[linha][coluna];
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    printDoubleMatrix(linha, coluna, positiveMatrix);
    getchar();

    printf("\nAperte ENTER para continuar!\n");
    getchar();
}
// fim exercicio0911

// Função para o exercício 0912
// gravar uma matriz real em arquivo.
// A matriz e o nome do arquivo serão dados como parâmetros.
// Para testar, usar a leitura da matriz do problema anterior.
// Usar outro método para ler e recuperar a matriz do arquivo, antes de mostrá-la na tela.
// Exemplo: double positiveMatrix [10][10];
 //readPositiveMatrix DoubleMatrix ( 3, 3, positiveMatrix );
 //fprintDoubleMatrix ( "MATRIX_01.TXT", 3, 3, positiveMatrix )

void fprintDoubleMatrix(char *nomeArquivo, int linha, int coluna, double positiveMatrix[linha][coluna]) {
    FILE *file = fopen(nomeArquivo, "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo");
    }
    fprintf(file, "Matriz resultante:\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            fprintf(file, "%.2lf ", positiveMatrix[i][j]);
        }
        fprintf(file, "\n");
    }
    printf("\nResultado gravado com sucesso em MATRIX_01.TXT");
    fclose(file);
}

void readPositiveDoubleMatrixFromFile(char *nomeArquivo, int linha, int coluna, double positiveMatrix[linha][coluna]) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    printf("\nLendo a matriz do arquivo...\n");
    for(int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            fscanf(file, "%lf", &positiveMatrix[i][j]);
        }
    }

    fclose(file);
}

int ex0912() {
    int linha = 0, coluna = 0;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linha);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &coluna);
    if(linha <= 0 || coluna <= 0){
        printf("As dimensoes da matriz devem ser positivas.");
    }
    double positiveMatrix[linha][coluna];
    readPositiveDoubleMatrix(linha, coluna, positiveMatrix);
    fprintDoubleMatrix("MATRIX_01.TXT", linha, coluna, positiveMatrix);
    readPositiveDoubleMatrixFromFile("MATRIX_01.TXT", linha, coluna, positiveMatrix);
    printDoubleMatrix(linha, coluna, positiveMatrix);
    getchar();

    printf("\nAperte ENTER para continuar!\n");
    getchar();
}// Fim da função ex0912

// Função para o exercício 0913
// mostrar somente os valores na diagonal principal de uma matriz real, se for quadrada.
// Exemplo: double positiveMatrix [10][10];
 //readPositiveMatrix DoubleMatrix ( 3, 3, positiveMatrix );
 //printDiagonalDoubleMatrix ( 3, 3, positiveMatrix );

 void printDiagonalDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if(n <= 0){
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return;
    }
    printf("Valores na diagonal principal:\n");
    for(int i = 0; i < n; i++){
        printf("\n%.2lf ", positiveMatrix[i][i]);
    }
    printf("\n");
}

void ex0913() {
// identificacao
    printf( "\nExercicio 0913:\n\n" );
    // programa
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printDiagonalDoubleMatrix(n, positiveMatrix);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0913

// Função para o exercício 0914
// mostrar somente os valores na diagonal secundária de uma matriz real, se for quadrada.
// Exemplo: double positiveMatrix [10][10];
 //readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 //printSDiagonalDoubleMatrix ( 3, 3, positiveMatrix );

void printSDiagonalDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if(n <= 0){
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return;
    }
    printf("Valores na diagonal principal:\n");
    for(int i = 0; i < n; i++){
        printf("\n%.2lf ", positiveMatrix[i][n - 1 - i]);
    }
    printf("\n");
}

void ex0914() {
// identificacao
    printf( "\nExercicio 0914:\n\n" );
    // programa
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printSDiagonalDoubleMatrix(n, positiveMatrix);
    getchar();
    // encerrar
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0914

// Função para o exercício 0915
// mostrar somente os valores abaixo e na diagonal principal de uma matriz real, se for quadrada.
// Exemplo: double positiveMatrix [10][10];
 //readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 //printLDTriangleDoubleMatrix ( 3, 3, positiveMatrix );

void printLDTriangleDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if (n <= 0) {
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return;
    }
    printf("Valores abaixo e na diagonal principal:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("%.2lf ", positiveMatrix[i][j]);
        }
        printf("\n");
    }
}

void ex0915() {
// identificacao
    printf( "\nExercicio 0915:\n\n" );
    // programa
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printLDTriangleDoubleMatrix(n, positiveMatrix);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0915

// Função para o exercício 0916
// mostrar somente os valores acima e na diagonal principal de uma matriz real, se for quadrada.
// Exemplo: double positiveMatrix [10][10];
 // readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 // printLUTriangleDoubleMatrix ( 3, 3, positiveMatrix );

void printLUTriangleDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if (n <= 0) {
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return;
    }
    printf("Valores acima e na diagonal principal:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= i){
                printf("%.2lf ", positiveMatrix[i][j]);
            }else{
                printf("       ");
            }
        }
        printf("\n");
    }
}


void ex0916() {
// identificacao
    printf( "\nExercicio 0916:\n\n" );
    // programa
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printLUTriangleDoubleMatrix(n, positiveMatrix);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0916

// Função para o exercício 0917
// mostrar somente os valores abaixo e na diagonal secundária de uma matriz real, se for quadrada.
// Exemplo: double positiveMatrix [10][10];
 // readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 // printSLDTriangleDoubleMatrix ( 3, 3, positiveMatrix );

void printSLDTriangleDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if (n <= 0) {
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return;
    }
    printf("Valores abaixo e na diagonal secundaria:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= n - i - 1){
                printf("%.2lf ", positiveMatrix[i][j]);
            }else{
                printf("       ");
            }
        }
        printf("\n");
    }
}


void ex0917() {
// identificacao
    printf( "\nExercicio 0917:\n\n" );
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printSLDTriangleDoubleMatrix(n, positiveMatrix);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0917
// Função para o exercício 0918
//mostrar somente os valores acima e na diagonal secundária de uma matriz real, se for quadrada.
// Exemplo: double positiveMatrix [10][10];
 // readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 // printSLUTriangleDoubleMatrix ( 3, 3, positiveMatrix );

void printSLUTriangleDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if(n <= 0){
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return;
    }
    printf("Valores acima e na diagonal secundaria:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= n - i - 1){
                printf("%.2lf ", positiveMatrix[i][j]);
            }else{
                printf("       ");
            }
        }
        printf("\n");
    }
}


void ex0918() {
// identificacao
    printf( "\nExercicio 0918:\n\n" );
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printSLUTriangleDoubleMatrix(n, positiveMatrix);
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0918

// Função para o exercício 0919
// testar se não são todos zeros os valores abaixo da diagonal principal de uma matriz real quadrada.
// Exemplo: double positiveMatrix [10][10];
 // readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
//  bool result = allZerosLTriangleDoubleMatrix ( 3, 3, positiveMatrix );


bool allZerosLTriangleDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if(n <= 0){
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(positiveMatrix[i][j] != 0.0){
                return false;
            }
        }
    }
    return true;
}

void ex0919() {
    // identificacao
    printf( "\nExercicio 0919:\n\n" );
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printLDTriangleDoubleMatrix(n, positiveMatrix);
    bool result = allZerosLTriangleDoubleMatrix(n, positiveMatrix);
    if(result){
        printf("\nTodos os valores abaixo da diagonal principal sao igual a 0");
    }else{
        printf("\nExistem valores diferentes de zero");
    }
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0919

// Função para o exercício 0920
// testar se são zeros os valores acima da diagonal principal de uma matriz real quadrada.
//Exemplo: double positiveMatrix [10][10];
 // readPositiveDoubleMatrix ( 3, 3, positiveMatrix );
 // bool result = allZerosUTriangleDoubleMatrix ( 3, 3, positiveMatrix );

bool allZerosUTriangleDoubleMatrix(int n, double positiveMatrix[n][n]) {
    if(n <= 0){
        printf("A matriz deve ser quadrada (n x n) e n > 0.\n");
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > i && positiveMatrix[i][j] != 0.0){
                return false;
            }
        }
    }
    return true;
}


void ex0920() {
// identificacao
    printf( "\nExercicio 0920:\n\n" );
    int n = 0;
    scanf("%d", &n);
    if(n <= 0){
        printf("A matrix deve ser maior que 0");
    }
    double positiveMatrix[n][n];
    readPositiveDoubleMatrix(n, n, positiveMatrix);
    printLUTriangleDoubleMatrix(n, positiveMatrix);
    bool result = allZerosUTriangleDoubleMatrix(n, positiveMatrix);
    if(result){
        printf("\nTodos os valores acima da diagonal principal sao igual a 0.");
    }else{
        printf("\nExistem valores diferentes de zero");
    }
    // encerrar
    getchar();
    printf( "\nAperte ENTER para continuar!\n" );
    getchar();
}// Fim da função ex0320

// Função para o exercício 09E1
// ler do teclado as quantidades de linhas e colunas de uma matriz,
// e montar uma matriz com a característica abaixo,
// a qual deverá ser gravada em arquivo, após o retorno.
// Exemplos:
// 1 5 9 13
// 1 4 7 2 6 10 14
// 1 3 2 5 8 3 7 11 15
// 2 4 3 6 9 4 8 12 1


void preencherMatriz(int matriz[][TAM_STR], int n) {
    int valor = 1;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            matriz[i][j] = valor;
            valor++;
        }
    }
}

void salvarMatrizEmArquivo(int matriz[][TAM_STR], int n) {
    FILE* arquivo = fopen("extra01.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Matriz salva no arquivo \"extra01.txt\".\n");
}

void ex09E1() {
    int n;
    printf("Digite o tamanho da matriz (n): ");
    scanf("%d", &n);
    if(n <= 0 || n > TAM_STR){
        printf("Tamanho inválido. Use um valor entre 1 e %d.\n", TAM_STR);
    }
    int positiveMatrix[TAM_STR][TAM_STR];
    preencherMatriz(positiveMatrix, n);
    salvarMatrizEmArquivo(positiveMatrix, n);
    printf("\nAperte ENTER para continuar!\n");
    getchar();
    getchar();
}
// fim exercicio09E1
// Função para o exercício 09E2
// ler do teclado as quantidades de linhas e colunas de uma matriz,
// e montar uma matriz com a característica abaixo,
// a qual deverá ser gravada em arquivo, após o retorno.
// Exemplos:
// 16 15 14 13
// 9 8 7 12 11 10 9
// 4 3 6 5 4 8 7 6 5
// 2 1 3 2 1 4 3 2 1

void preencherMatrizInversa(int matriz[][TAM_STR], int n) {
    int valor = n*n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = valor;
            valor--;
        }
    }
}

void salvarMatrizInversaEmArquivo(int matriz[][TAM_STR], int n) {
    FILE* arquivo = fopen("extra02", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fprintf(arquivo, "%d\t", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
    printf("Matriz salva no arquivo \"extra02.txt\".\n");
}

void ex09E2()
{
    // identificacao
    printf( "\nExercicio 09E2:\n\n" );
    int n;
    printf("Digite o tamanho da matriz (n): ");
    scanf("%d", &n);
    if(n <= 0 || n > TAM_STR){
        printf("Tamanho inválido. Use um valor entre 1 e %d.\n", TAM_STR);
    }
    int positiveMatrix[TAM_STR][TAM_STR];
    preencherMatrizInversa(positiveMatrix, n);
    salvarMatrizInversaEmArquivo(positiveMatrix, n);
    printf("\nAperte ENTER para continuar!\n");
    getchar();
    getchar();
} // fim função 03E2

// Função principal
int main(void) {
    int opcao;

    do {
        menuOpcoes(); // Chama a função que exibe as opções

        printf("\nOpcao = ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        // Executar a opção escolhida
        switch (opcao) {
            case 0: break;
            case 1: ex0911(); break;
            case 2: ex0912(); break;
            case 3: ex0913(); break;
            case 4: ex0914(); break;
            case 5: ex0915(); break;
            case 6: ex0916(); break;
            case 7: ex0917(); break;
            case 8: ex0918(); break;
            case 9: ex0919(); break;
            case 10: ex0920(); break;
            case 11: ex09E1(); break;
            case 12: ex09E2(); break;
            default:
                printf("\nERRO: OPCAO INVALIDA\n\n");
                break;
        } // fim switch

    } while (opcao != 0);

    printf("\nAperte ENTER para terminar!\n");
    getchar();

    return 0;
} // Fim da função principal
