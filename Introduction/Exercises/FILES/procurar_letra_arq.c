#include <stdio.h>
#include <stdlib.h>


int aparece(const char* Arq, char procurado){
    int total = 0;
    FILE *f = fopen(Arq, "r");
    char c;
    while(fscanf(f,"%c",&c)!=EOF){
        if(c == procurado){
            total++;
        }
    }
    fclose(f);
    return total;
}

int main(){
    char pro;
    printf("Letra que deseja procurar =");
    scanf("%c", &pro);
    int total = aparece("arq.txt", pro);
    if(total > 0){
        printf("Total de vezes que (%c) aparece = %d", pro, total);
    }else{
        printf("O caracter (%c) nao existe no arquivo", pro);
    }

}
