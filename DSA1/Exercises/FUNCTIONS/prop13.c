#include <stdio.h>



int media(int salario[15]){
    int total = 0;
    for(int i=0; i < 3; i++){
        total = total+salario[i];

    }
    total = total/15;
    return total;
}

int menor(int idade[15]) {
    int menor = idade[0];
    for (int i = 0; i < 14; i++) {
        if (idade[i] < menor) {
            menor = idade[i];
        }
    }
    return menor;
}

int maior(int idade[15]) {
    int maior = idade[0];
    for (int i = 0; i < 3; i++) {
        if (idade[i] > maior) {
            maior = idade[i];
        }
    }
    return maior;
}


int main(){
    int idade[15], salario[15], filhos[15];
    char sexo[15];
    for(int i =0; i < 3; i++){
    printf("Digite sua idade:");
    scanf("%d", &idade[i]);
    printf("\nDigite seu salario:");
    scanf("%d", &salario[i]);
    printf("\nDigite o seu numero de filhos:");
    scanf("%d", &filhos[i]);
    }
    printf("\nMEDIA = %d", media(salario));
    printf("\nMENOR IDADE = %d", menor(idade));
    printf("\nMAIOR IDADE = %d", maior(idade));


}
