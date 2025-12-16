#include <stdio.h>
#include <math.h>

double hipotenusa(double c1,double c2){
    double hip = sqrt((c1*c1) + (c2*c2));
    return hip;
}

int main(){
    double cateto1 = 0.0, cateto2 = 0.0;
    scanf("%lf %lf", &cateto1, &cateto2);
    printf("A hipotenusa eh: %.2f", hipotenusa(cateto1,cateto2));
}
