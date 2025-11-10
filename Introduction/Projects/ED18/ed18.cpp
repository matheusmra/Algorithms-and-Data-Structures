/*
 Estudo Dirigido 18 - v0.0. - 03 / 12 / 2024
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed18 ed18.c
 Windows: gcc -o ed18 ed18.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed18
 Windows: ed18
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

class intStack {
private:
    static int length;
    int* data;
public:
    intStack() {
        length = 0;
        data = nullptr;
    }

};

using ref_intStack = intStack*;

void close()
{
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
}
void menuOpcoes()
{
    cout << "\nEscolha alguma das opcoes a seguir:\n\n";
    cout << "  0 - Encerrar programa\n";
    cout << "  1 - Exercicio 1811\n";
    cout << "  2 - Exercicio 1812\n";
    cout << "  3 - Exercicio 1813\n";
    cout << "  4 - Exercicio 1814\n";
    cout << "  5 - Exercicio 1815\n";
    cout << "  6 - Exercicio 1816\n";
    cout << "  7 - Exercicio 1817\n";
    cout << "  8 - Exercicio 1818\n";
    cout << "  9 - Exercicio 1819\n";
    cout << "  10 - Exercicio 1820\n";
    cout << "  11 - Exercicio 18E1\n";
    cout << "  12 - Exercicio 18E2\n";
}


int ex1811()
{
// identificacao
    cout << "\nExercicio 1811:\n\n";
    close();
}



int ex1812()
{
    // Identifica��o
    cout << "\nExercicio 1812:\n\n";
    close();
}


void ex1813() {
    // Identificação
    cout << "\nExercicio 1813:\n\n";
    close();
}


void ex1814()
{
// identificacao
    cout << "\nExercicio 1814:\n\n" ;

    close();
}


void ex1815()
{
// identificacao
    cout << "\nExercicio 1815:\n\n" ;
    close();
}




void ex1816()
{
// identificacao
    cout << "\nExercicio 1816:\n\n" ;

    close();
}

void ex1817()
{
// identificacao
    cout << "\nExercicio 1817:\n\n" ;

    close();
}


void ex1818()
{
// identificacao
    cout << "\nExercicio 1818:\n\n" ;
    close();
}

void ex1819()
{
    // identificacao
    cout << "\nExercicio 1819:\n\n";
    close();
}


void ex1820()
{
    // identificacao
    cout << "\nExercicio 1820:\n\n";

    close();
}



void ex18E1()
{
    cout << "\nExercicio 18E1:\n\n";

    close();
}




void ex18E2()
{
    // identificacao
    cout << "\nExercicio 18E2:\n\n";

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
            ex1811();
            break;
        case 2:
            ex1812();
            break;
        case 3:
            ex1813();
            break;
        case 4:
            ex1814();
            break;
        case 5:
            ex1815();
            break;
        case 6:
            ex1816();
            break;
        case 7:
            ex1817();
            break;
        case 8:
            ex1818();
            break;
        case 9:
            ex1819();
            break;
        case 10:
            ex1820();
            break;
        case 11:
            ex18E1();
            break;
        case 12:
            ex18E2();
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
