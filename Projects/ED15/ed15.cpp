/*
 Estudo Dirigido 11 - v0.0. - 21 / 10 / 2024
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed11 ed11.c
 Windows: gcc -o ed11 ed11.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed11
 Windows: ed11
*/

// dependencias
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

void close()
{
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
}
void menuOpcoes()
{
    cout << "\nEscolha alguma das opcoes a seguir:\n\n";
    cout << "  0 - Encerrar programa\n";
    cout << "  1 - Exercicio 1511\n";
    cout << "  2 - Exercicio 1512\n";
    cout << "  3 - Exercicio 1513\n";
    cout << "  4 - Exercicio 1514\n";
    cout << "  5 - Exercicio 1515\n";
    cout << "  6 - Exercicio 1516\n";
    cout << "  7 - Exercicio 1517\n";
    cout << "  8 - Exercicio 1518\n";
    cout << "  9 - Exercicio 1519\n";
    cout << "  10 - Exercicio 1520\n";
    cout << "  11 - Exercicio 15E1\n";
    cout << "  12 - Exercicio 15E2\n";
} // fim menuOpcoes()


char* str_push_back(char* s, char c) {
    size_t len = strlen(s);
    char* new_str = new char[len + 2];
    for (size_t i = 0; i < len; ++i) {
        new_str[i] = s[i];
    }
    new_str[len] = c;
    new_str[len + 1] = '\0';

    delete[] s;

    return new_str;
}



int ex1511()
{
// identificacao
    cout << "\nExercicio 1511:\n\n";
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    char inserido = '\0';
    cout << "Digite o caractere a ser inserido na string" << endl;
    cin >> inserido;
    str = str_push_back(str,inserido);
    cout << "String final: " << str << endl;
    delete[] str;
    getchar();
    close();
}

char* str_pop_back(char* s) {
    size_t len = strlen(s);
    if (len == 0) {
        return s;
    }
    char* new_str = new char[len];
    for (size_t i = 0; i < len - 1; ++i) {
        new_str[i] = s[i];
    }
    new_str[len - 1] = '\0';
    delete[] s;
    return new_str;
}

int ex1512()
{
    // Identifica��o
    cout << "\nExercicio 1512:\n\n";
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    cout << "String original: " << str << endl;
    str = str_pop_back(str);
    cout << "String apos o pop back: " << str << endl;
    close();


}

char* str_push_front(char c, char* s) {
    size_t len = strlen(s);
    char* new_str = new char[len + 2];
    new_str[0] = c;
    for (size_t i = 0; i < len; ++i) {
        new_str[i + 1] = s[i];
    }
    new_str[len + 1] = '\0';
    delete[] s;
    return new_str;
}

void ex1513()
{
// identificacao
    cout << "\nExercicio 1513:\n\n" ;
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    char inserido = '\0';
    cout << "Digite o caractere a ser inserido na string" << endl;
    cin >> inserido;
    str = str_push_front(inserido, str);
    cout << "String apos o push front: " << str << endl;
    delete[] str;
    getchar();
    close();

}

char* str_pop_front(char* s) {
    size_t len = strlen(s);
    if (len == 0) {
        return s;
    }
    char* new_str = new char[len];
    for (size_t i = 1; i < len; ++i) {
        new_str[i - 1] = s[i];
    }
    new_str[len - 1] = '\0';
    delete[] s;
    return new_str;
}

void ex1514()
{
// identificacao
    cout << "\nExercicio 1514:\n\n" ;
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    cout << "String original: " << str << endl;
    str = str_pop_front(str);
    cout << "String apos o pop front: " << str << endl;
    close();
}

char* str_push_mid(char c, char* s) {
    size_t len = strlen(s);
    int mid = len / 2;
    char* new_str = new char[len + 2];
    for (size_t i = 0; i < mid; ++i) {
        new_str[i] = s[i];
    }
    new_str[mid] = c;
    for (size_t i = mid; i < len; ++i) {
        new_str[i + 1] = s[i];
    }
    new_str[len + 1] = '\0';
    delete[] s;
    return new_str;
}

void ex1515()
{
// identificacao
    cout << "\nExercicio 1515:\n\n" ;
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    char inserido = '\0';
    cout << "Digite o caractere a ser inserido na string" << endl;
    cin >> inserido;
    str = str_push_mid(inserido, str);
    cout << "String apos o push mid: " << str << endl;
    delete[] str;
    getchar();
    close();
}

char* str_pop_mid(char* s) {
    size_t len = strlen(s);
    int mid = len / 2;
    char* new_str = new char[len];
    for (size_t i = 0; i < mid; ++i) {
        new_str[i] = s[i];
    }
    for (size_t i = mid + 1; i < len; ++i) {
        new_str[i - 1] = s[i];
    }
    new_str[len - 1] = '\0';
    delete[] s;
    return new_str;
}
void ex1516()
{
// identificacao
    cout << "\nExercicio 1516:\n\n" ;
    char* str = new char[5];
    char inserido = '\0';
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    cout << "String original: " << str << endl;
    str = str_pop_mid(str);
    cout << "String apos o pop mid: " << str << endl;
    cout << "Digite o caractere a ser inserido na string" << endl;
    cin >> inserido;
    str = str_push_mid(inserido, str);
    cout << "String apos o push mid: " << str << endl;
    str = str_pop_mid(str);
    cout << "String apos o pop mid: " << str << endl;
    getchar();
    close();
}

char* str_insert(char c, char* s, int index) {
    size_t len = strlen(s);
    char* new_str = new char[len + 2];
    for (size_t i = 0; i < index; ++i) {
        new_str[i] = s[i];
    }
    new_str[index] = c;
    for (size_t i = index; i < len; ++i) {
        new_str[i + 1] = s[i];
    }
    new_str[len + 1] = '\0';
    delete[] s;
    return new_str;
}

void ex1517()
{
// identificacao
    cout << "\nExercicio 1517:\n\n" ;
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    char inserido = '\0';
    cout << "Digite o caractere a ser inserido na string" << endl;
    cin >> inserido;
    int index = 0;
    cout << "Digite a posicao que caractere vai ser inserido na string" << endl;
    cin >> index;
    int maxi = strlen(str);
    if(index >= 0 && index <= maxi){
    str = str_insert(inserido, str, index);
    cout << "String apos o insert: " << str << endl;
    delete[] str;
    getchar();
    }else{
    cout << "O valor do indice deve ser maior ou igual 0 e menor ou igual a: " << maxi << endl;
    }
    close();
}

char* str_remove(char* s, int index) {
    size_t len = strlen(s);
    char* new_str = new char[len];
    for (size_t i = 0; i < index; ++i) {
        new_str[i] = s[i];
    }
    for (size_t i = index + 1; i < len; ++i) {
        new_str[i - 1] = s[i];
    }
    new_str[len - 1] = '\0';
    delete[] s;
    return new_str;
}

void ex1518()
{
// identificacao
    cout << "\nExercicio 1518:\n\n" ;
    char* str = new char[5];
    str[0] = 'T',str[1] = 'e',str[2] = 's', str[3] = 't', str[4] = 'e';
    int index = 0;
    cout << "Digite a posicao que caractere vai ser removida da string" << endl;
    cin >> index;
    cout << "String original: " << str << endl;
    int maxi = strlen(str);
    if(index >= 0 && index < maxi){
    str = str_remove(str, index);
    cout << "String alterada: " << str << endl;
    }else{
    cout << "Erro" << endl;
    }
    getchar();
    close();
}

char* str_chr(char* s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }
    return nullptr;
}

void ex1519()
{
    // identificacao
    cout << "\nExercicio 1519:\n\n";
    char* str = "Exemplo de busca na string";
    char c = '\0';
    cout << "Caractere que deseja procurar =";
    cin >> c;
    char *result = str_chr(str, c);
    if (result != nullptr) {
        cout << "Caractere '" << c << "' encontrado em: " << result << endl;
    } else {
        cout << "Caractere '" << c << "' nao encontrado na string." << endl;
    }
    getchar();
    close();
}

char* str_tok(char* s, char delimiter) {
    static char* last_pos = nullptr;

    if (s != nullptr) {
        last_pos = s;
    }

    if (last_pos == nullptr || *last_pos == '\0') {
        return nullptr;
    }
    char* start = last_pos;
    while (*last_pos != '\0' && *last_pos != delimiter) {
        last_pos++;
    }
    if (*last_pos == delimiter) {
        *last_pos = '\0';
        last_pos++;
    }

    return start;
}

void ex1520()
{
    // identificacao
    cout << "\nExercicio 1520:\n\n";
    char str[] = "Matheus,de,Almeida,Moreira";
    char delimiter = ',';
    cout << "Delimitador =";
    cin >> delimiter;
    char* strings = str_tok(str, delimiter);
    int i = 1;
    while (strings != nullptr) {
        cout << "String " << "("<< i << ")" << " = " << strings << endl;
        strings = str_tok(nullptr, delimiter);
        i++;
    }
    getchar();
    close();
}



void ex15E1()
{
    cout << "\nExercicio 15E1:\n\n";

    close();
}




void ex15E2()
{
    // identificacao
    cout << "\nExercicio 15E2:\n\n";

    close();
}

// Fun��o principal
int main(void)
{
    int opcao;

    do
    {
        menuOpcoes(); // Chama a fun��o que exibe as op��es

        cout << "\nOpcao = ";
        cin >> opcao;
        getchar(); // Limpar o buffer de entrada

        // Executar a op��o escolhida
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            ex1511();
            break;
        case 2:
            ex1512();
            break;
        case 3:
            ex1513();
            break;
        case 4:
            ex1514();
            break;
        case 5:
            ex1515();
            break;
        case 6:
            ex1516();
            break;
        case 7:
            ex1517();
            break;
        case 8:
            ex1518();
            break;
        case 9:
            ex1519();
            break;
        case 10:
            ex1520();
            break;
        case 11:
            ex15E1();
            break;
        case 12:
            ex15E2();
            break;
        default:
            cout << "\nERRO: OPCAO INVALIDA\n\n";
            break;
        } // fim switch

    }
    while (opcao != 0);

    cout << "\nAperte ENTER para terminar!\n";
    getchar();

    return 0;
} // Fim da fun��o principal
