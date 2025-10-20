#include <stdio.h>

double fahrenheit(double celsius){
    double fah = 0.0;
    fah = (celsius * (9.0/5.0))+32;
    return fah;
}

int main(){
    double temp = 0.0;
    scanf("%lf", &temp);
    printf("%.2f Celsius = %.2f Fahrenheit", temp, fahrenheit(temp));

}
