#include <stdio.h>

void idade(int ano_nas, int ano_atual){
    int anos = ano_atual - ano_nas;
    printf("Idade em anos = %d", anos);
    int meses = anos * 12;
    printf("\nIdade em meses = %d", meses);
    int dias = meses * 30;
    printf("\nIdade em dias = %d", dias);

}
int main(){
    int nascimento = 0;
    scanf("%d", &nascimento);
    idade(nascimento,2024);

}
