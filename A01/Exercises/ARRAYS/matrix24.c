#include <stdio.h>


int media_linha(int matriz[5][5], int linha){
    int media = 0;
    for(int j = 0; j < 5; j++){
        media   += matriz[linha][j];
    }
    return media/5;

}

void imprimir_matriz(int matriz[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }

}

void preencher_matriz(int matriz[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("\nElemento [%d][%d] =", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void salvar(const char* NomeArquivo, int matriz[5][5]){
    FILE* f = fopen(NomeArquivo, "w");
    if(f == NULL){
        printf("ERRO");
    }
    fprintf(f, "MATRIZ PRINCIPAL\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            fprintf(f,"%d", matriz[i][j]);
        }
        fprintf(f, "\n");
    }
    printf("\nMATRIZ CRIADA COM SUCESSO!");
    fclose(f);

}

void ler(const char* NomeArquivo) {
    int f_matriz[5][5];
    FILE *f = fopen(NomeArquivo, "r");
    if (f) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (fscanf(f, "%d", &f_matriz[i][j]) != 1) {
                    printf("Erro ao ler o arquivo\n");
                    fclose(f);
                    return;
                }
            }
        }
        imprimir_matriz(f_matriz);
        fclose(f);
    } else {
        printf("Erro ao abrir o arquivo\n");
    }
}

int main(){
    int matriz[5][5];
    preencher_matriz(matriz);
    printf("\nMATRIZ:\n");
    imprimir_matriz(matriz);
    int n = 0;
    printf("\nLinha =");
    scanf("%d", &n);
    int media = media_linha(matriz,n);
    printf("\nA media dos elementos da linha (%d) eh %d", n, media);
    salvar("MATRIZ.TXT", matriz);
    ler("MATRIZE.TXT");



}
