#include <stdio.h>

void tranform(int horas, int minutos){
    int th = horas*3600;
    int tm = minutos*60;
    printf("%d horas sao %d segundos", horas, th);
    printf("\n%d minutos sao %d segundos", minutos, tm);
}

int main(){
    int minutos = 0, horas = 0;
    scanf("%d %d", &horas, &minutos);
    tranform(horas, minutos);

}
