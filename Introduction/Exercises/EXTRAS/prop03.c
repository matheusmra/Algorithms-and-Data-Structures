#include <stdio.h>

double prop03(double v1, double v2){
    double resultado = 0;
    if(v2 > 0){
    resultado = v1/v2;
    }
    return resultado;
}

int main(){
    double n1=0.0, n2=0.0;
    scanf("%lf %lf", &n1, &n2);
    printf("%.2f", prop03(n1, n2));
}
