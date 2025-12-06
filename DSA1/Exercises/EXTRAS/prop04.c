#include <stdio.h>
double prop04(double v1, double v2){
    double media = 0.0;
    media = ((v1*2)+(v2*3))/ 5;
    return media;
}

int main(){
    double n1 = 0.0, n2=0.0;
    scanf("%lf %lf", &n1, &n2);
    printf("Media ponderada de (%.2f) e (%.2f) = (%.2f)", n1, n2, prop04(n1, n2));

}
