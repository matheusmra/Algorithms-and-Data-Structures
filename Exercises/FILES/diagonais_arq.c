#include <stdio.h>
#include <stdlib.h>
void diagonal(const char* Arquivo, int matriz[3][3]){
 FILE *f = fopen(Arquivo, "w");
 if (f){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i==j){
                fprintf(f, "%d", matriz[i][j]);
            }else{
                fprintf(f, " ");
            }
        }
        fprintf(f, "\n");
    }
    printf("Arquivo criado com sucesso");
    fclose(f);
 }
}

void secundaria(const char* Arquivo, int matriz[3][3]){
 FILE *f = fopen(Arquivo, "w");
 if (f){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 3 - 1 - i){
                fprintf(f, "%d", matriz[i][j]);
            }else{
                fprintf(f, " ");
            }
        }
            fprintf(f, "\n");
    }
    printf("Arquivo criado com sucesso!");
    fclose(f);
 }
}


int main(){
    int matriz[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\nMATRIZ PRINCIPAL:\n");
    diagonal("DIAGONAL.TXT",matriz);
    printf("\nMATRIZ SECUNDARIA:\n");
    secundaria("SECUNDARIA.TXT",matriz);



}
