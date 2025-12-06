#include <stdio.h>

double comissao(double vendas){
    double total = 0.0;
    total = (vendas)*1.04;
    return total;
}
int main(){
    double salarioi = 0.0, salariof = 0.0, vendas = 0.0;
    scanf("%lf %lf", &salarioi, &vendas);
    printf("Salario inicial = %.2f", salarioi);
    printf("\nTotal de vendas = %.2f", vendas);
    printf("\nComissao de 4 porcento nas vendas = %.2f", comissao(vendas));
    salariof = salarioi + comissao(vendas);
    printf("\nSalario final = %.2f", salariof);

}
