#include <stdio.h>
#include <stdbool.h>

// ------------------ FUNÇÕES RECURSIVAS ------------------

bool isVogal(char linha[], int size) {
    if (size < 0) return true; // caso base: percorreu toda string
    char c = linha[size];
    if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
        return false;
    }
    return isVogal(linha, size - 1);
}

bool isConsoante(char linha[], int size) {
    if (size < 0) return true;
    char c = linha[size];
    bool letra = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    bool vogal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if (!(letra && !vogal)) return false;
    return isConsoante(linha, size - 1);
}

bool isInt(char linha[], int size) {
    if (size < 0) return true;
    char c = linha[size];
    if (!(c >= '0' && c <= '9')) return false;
    return isInt(linha, size - 1);
}

bool isRealAux(char linha[], int size, bool ponto) {
    if (size < 0) return ponto; // se terminou, tem que ter ponto
    char c = linha[size];
    if (!(c >= '0' && c <= '9')) {
        if ((c == '.' || c == ',') && !ponto) {
            return isRealAux(linha, size - 1, true);
        } else {
            return false;
        }
    }
    return isRealAux(linha, size - 1, ponto);
}

bool isReal(char linha[], int size) {
    return isRealAux(linha, size, false);
}

bool isFim(char linha[]) {
    return (linha[0] == 'F' && linha[1] == 'I' && linha[2] == 'M' && linha[3] == '\0');
}

// ------------------ AUXILIARES ------------------

int getSize(char linha[]) {
    int cont = 0;
    while (linha[cont] != '\0') cont++;
    return cont - 1; // ignora \0
}

void removeEnter(char linha[]) {
    int i = 0;
    while (linha[i] != '\0') {
        if (linha[i] == '\n') {
            linha[i] = '\0';
            break;
        }
        i++;
    }
}

// ------------------ MAIN ------------------

int main() {
    char linha[100];
    fgets(linha, sizeof(linha), stdin);
    removeEnter(linha);

    while (!isFim(linha)) {
        int length = getSize(linha);

        printf("%s ", isVogal(linha, length) ? "SIM" : "NAO");
        printf("%s ", isConsoante(linha, length) ? "SIM" : "NAO");
        printf("%s ", isInt(linha, length) ? "SIM" : "NAO");
        printf("%s\n", isReal(linha, length) ? "SIM" : "NAO");

        fgets(linha, sizeof(linha), stdin);
        removeEnter(linha);
    }

    return 0;
}
