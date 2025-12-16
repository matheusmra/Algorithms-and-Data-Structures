#include <stdio.h>
#include <stdlib.h>



int contar_vogais(const char* Nome){
    int count = 0;
    char letra;
    FILE *f = fopen(Nome, "r");
    if(f){
        while(fscanf(f, "%c", &letra)!=EOF){
                if(letra == 'A' || letra == 'a' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U'){
                    count++;
                }
            }
        }

    return count;

}

int main(){
    int total = contar_vogais("arq.txt");
    if(total > 0){
        printf("O total de vogais no arquivo eh: %d", total);
    }else{
        printf("O arquivo nao possui vogais");
    }



}
