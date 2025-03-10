#include <stdio.h>
#include <stdlib.h>
    /**
     * Função para realizar gravação de dados em um arquivo
     * @param nomeArquivo - nome do arquivo no qual os dados serão gravados
     * @param n - Inteiro que representa a quantidade de numeros que serão gravados
     */
void file_add(const char *nomeArquivo, int n) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    // Lê e escreve os números doubles no arquivo
    for (int i = 0; i < n; i++) {
        double num;
        scanf("%lf", &num);
        fwrite(&num, sizeof(double), 1, arquivo);
    }

    fclose(arquivo);
}
    /**
     * Função para realizar a leitura e exibição de dados em um arquivo
     * @param nomeArquivo - nome do arquivo no qual os dados estão gravados
     * @param n - Inteiro que representa a quantidade de numeros que serão exibidos
     */
void file_read(const char *nomeArquivo, int n) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    // Move o ponteiro para o final do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tam = ftell(arquivo);
    long tamDouble = sizeof(double);
    long ptr = tam - tamDouble;
    // Realiza a leitura e imprime os números de trás para frente
    for (int i = 0; i < n && ptr >= 0; i++) {
        fseek(arquivo, ptr, SEEK_SET);  // Move o ponteiro para a posição desejada
        double num = 0.0;
        fread(&num, sizeof(double), 1, arquivo);
        if (num == (int)num){
            printf("%d\n", (int)num);
        }else{
            printf("%g\n", num);
        }
        ptr -= tamDouble;  // Move o ponteiro para o numero anterior
    }
    fclose(arquivo);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    // Grava os números no arquivo
    file_add("arquivo.bin", n);
    // Realize a leitura do arquivo
    file_read("arquivo.bin", n);
    return 0;
}
