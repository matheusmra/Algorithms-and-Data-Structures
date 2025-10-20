#include <stdio.h>

int main(){
    int n = 15;
    int compras[n];
    char compra[n];
    int v = 0, p = 0;
    for(int i = 0; i < n; i++){
        scanf("%c", &compra[i]);
        scanf("%d", &compras[i]);
    }
    for(int i = 0; i < n; i++){
        if(compra[i] == 'V'){
        v = v + compras[i];
        }else if(compra[i] == 'P'){
        p = p + compras[i];
        }
    }
    int total = p+v;
    printf("TOTAL DE COMPRAS A VISTA = %d", v);
    printf("\nTOTAL DE COMPRAS A PRAZO = %d", p);
    printf("\nTOTAL DAS COMPRAS = %d", total);
}
