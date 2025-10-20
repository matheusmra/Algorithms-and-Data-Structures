#include <stdio.h>
#define PI 3.14

double comprimento(double raio){
    double comp = 2 * PI * raio;
    return comp;

}

double area(double raio){
    double area = PI* (raio*raio);
    return area;
}

double volume(double raio){
    double v = (3.0 / 4.0) * PI * (raio*raio*raio);
    return v;
}

int main(){
    double raio = 0.0;
    scanf("%lf", &raio);
    printf("Raio = %.2f", raio);
    printf("\nComprimento = %.2f", comprimento(raio));
    printf("\nArea = %.2f", area(raio));
    printf("\nVolume = %.2f", volume(raio));

}
