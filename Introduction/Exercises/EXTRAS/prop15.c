#include <stdio.h>

double despesa(double salario, double atraso1, double atraso2){
    double restante = 0.0;
    restante = salario - ((atraso1*1.02) + (atraso2*1.02));
    return restante;
}

int main(){
    double salario = 0.0, conta1 = 0.0, conta2 = 0.0;
    scanf("%lf %lf %lf", &salario, &conta1, &conta2);
    printf("Apos pagar as suas dividas, Joao possui: %.2f", despesa(salario, conta1, conta2));

}
