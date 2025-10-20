int tabuada(int n){
    int resultado = 0;
    for(int i = 0; i < 11; i++){
        resultado = n * i;
        printf("\n %d X %d = %d", n, i, resultado);
    }


}

int main(){
    for(int i = 1; i < 11; i++){
    printf("\n");
    printf("Tabuada do numero: %d", i);
    tabuada(i);
    }

}
