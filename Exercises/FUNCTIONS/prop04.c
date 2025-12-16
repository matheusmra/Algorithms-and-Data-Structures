#include <stdio.h>

double volume(double raio){
    double resultado = 0.0;
    resultado = (4.0/3.0)* (raio*raio*raio);
    return resultado;
}

int main(){
    double raio = 0.0;
    scanf("%lf", &raio);
    printf("VOLUME = %.2f", volume(raio));

}
