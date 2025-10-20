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
using namespace std;
// Tamanho max string
const int TAM_STR = 80;
// Fun��o para mostrar o menu de op��es

void close()
{
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
}
void menuOpcoes()
{
    cout << "\nEscolha alguma das opcoes a seguir:\n\n";
    cout << "  0 - Encerrar programa\n";
    cout << "  1 - Exercicio 1411\n";
    cout << "  2 - Exercicio 1412\n";
    cout << "  3 - Exercicio 1413\n";
    cout << "  4 - Exercicio 1414\n";
    cout << "  5 - Exercicio 1415\n";
    cout << "  6 - Exercicio 1416\n";
    cout << "  7 - Exercicio 1417\n";
    cout << "  8 - Exercicio 1418\n";
    cout << "  9 - Exercicio 1419\n";
    cout << "  10 - Exercicio 1420\n";
    cout << "  11 - Exercicio 14E1\n";
    cout << "  12 - Exercicio 14E2\n";
} // fim menuOpcoes()

class Contato
{
private:
    string nome;
    int pos;
public:
    string sequencias[100];
    Contato(const string& nome, int pos) : nome(nome), pos(pos) {}
    Contato(const string& nome) : nome(nome)
    {
        sequencias[0] = nome;
    }
    int getInt()
    {
        try
        {
            int value = stoi(nome);
            return value;
        }
        catch (invalid_argument& e)
        {
            return -1;
        }
        catch (out_of_range& e)
        {
            return -1;
        }
    }

    double getDouble()
    {
        try
        {
            double value = stod(nome);
            return value;
        }
        catch (invalid_argument& e)
        {
            return 0.0;
        }
        catch (out_of_range& e)
        {
            return 0.0;
        }
    }
    bool getBoolean()
    {
        string lower = nome;
        for (size_t i = 0; i < lower.length(); ++i)
        {
            if (lower[i] >= 'A' && lower[i] <= 'Z')
            {
                lower[i] = lower[i] + ('a' - 'A');
            }
        }
        if (lower == "true" || lower == "t" || lower == "1")
        {
            return true;
        }
        else if (lower == "false" || lower == "f" || lower == "0")
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    bool contains(const string& texto)
    {
        if(nome.find(texto) != string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string toUpperCase()
    {
        string upper = nome;
        for (size_t i = 0; i < upper.length(); ++i)
        {
            if (upper[i] >= 'a' && upper[i] <= 'z')
            {
                upper[i] = upper[i] - ('a' - 'A');
            }
        }
        return upper;
    }
    string toLowerCase()
    {
        string lower = nome;
        for (size_t i = 0; i < lower.length(); ++i)
        {
            if (lower[i] >= 'A' && lower[i] <= 'Z')
            {
                lower[i] = lower[i] + ('a' - 'A');
            }
        }
        return lower;
    }

    string trocar(char procurado, char novo)
    {
        string modificar = nome;
        for(size_t i = 0; i < modificar.length(); i++)
        {
            if(modificar[i] == procurado)
            {
                modificar[i] = novo;
            }
        }
        return modificar;
    }

    string encrypt()
    {
        string encrypted = nome;
        for(int i = 0; i < encrypted.length(); i++)
        {
            if(isalpha(encrypted[i]))
            {
                char base = islower(encrypted[i]) ? 'a' : 'A';
                encrypted[i] = (encrypted[i] - base + pos) % 26 + base;
            }
        }
        return encrypted;

    }

    string decrypt()
    {
        string decrypted = nome;
        for(int i = 0; i < decrypted.length(); i++)
        {
            if(isalpha(decrypted[i]))
            {
                char base = islower(decrypted[i]) ? 'a' : 'A';
                decrypted[i] = (decrypted[i] - base - pos) % 26 + base;
            }
        }
        return decrypted;

    }
    int split()
    {
        int count = 0;
        string palavra = "";
        string entrada = sequencias[0];
        for (size_t i = 0; i < entrada.length(); ++i)
        {
            char c = entrada[i];
            if (c == ' ' || c == '\t' || c == '\n')
            {
                if (!palavra.empty())
                {
                    sequencias[++count] = palavra;
                    palavra = "";
                }
            }
            else
            {
                palavra += c;
            }
        }
        if (!palavra.empty())
        {
            sequencias[++count] = palavra;
        }
        return count;
    }
    int splitWithDelimiter(char delimitador)
    {
        int count = 0;
        string palavra = "";
        string entrada = sequencias[0];
        for (size_t i = 0; i < entrada.length(); ++i)
        {
            char c = entrada[i];
            if (c == delimitador)
            {
                if (!palavra.empty())
                {
                    sequencias[++count] = palavra;
                    palavra = "";
                }
            }
            else
            {
                palavra += c;
            }
        }
        if (!palavra.empty())
        {
            sequencias[++count] = palavra;
        }
        return count;
    }
    string getSequencia(int index)
    {
        return sequencias[index];
    }
    string inverter()
    {
        string invert = nome;
        int left = 0;
        int right = invert.length() - 1;
        while (left < right)
        {
            swap(invert[left], invert[right]);
            left++;
            right--;
        }

        return invert;
    }


};


int ex1411()
{
// identificacao
    cout << "\nExercicio 1411:\n\n";
    Contato c1("abc");
    Contato c2("123");
    Contato c3("1.5678");
    int resultado1 = c1.getInt();
    int resultado2 = c2.getInt();
    int resultado3 = c3.getInt();
    cout << "Teste de caracteres" << endl;
    cout << "Resultado = " << resultado1 << endl;
    cout << "Teste de inteiros" << endl;
    cout << "Resultado = " << resultado2 << endl;
    cout << "Teste de reais" << endl;
    cout << "Resultado = " << resultado3 << endl;
    close();
}





int ex1412()
{
    // Identifica��o
    cout << "\nExercicio 1412:\n\n";
    Contato c1("abc");
    Contato c2("123");
    Contato c3("1.5678");
    double resultado1 = c1.getDouble();
    double resultado2 = c2.getDouble();
    double resultado3 = c3.getDouble();
    cout << "Teste de caracteres" << endl;
    cout << "Resultado = " << resultado1 << endl;
    cout << "Teste de inteiros" << endl;
    cout << "Resultado = " << resultado2 << endl;
    cout << "Teste de reais" << endl;
    cout << "Resultado = " << resultado3 << endl;
    close();


}



void ex1413()
{
// identificacao
    cout << "\nExercicio 1413:\n\n" ;
    Contato c1("true");
    Contato c2("F");
    Contato c3("abc");
    bool resultado1 = c1.getBoolean();
    bool resultado2 = c2.getBoolean();
    bool resultado3 = c3.getBoolean();
    cout << "Teste de verdadeiro" << endl;
    cout << "Resultado = " << resultado1 << endl;
    cout << "Teste de falso" << endl;
    cout << "Resultado = " << resultado2 << endl;
    cout << "Teste de caracter" << endl;
    cout << "Resultado = " << resultado3 << endl;
    close();

}

void ex1414()
{
// identificacao
    cout << "\nExercicio 1414:\n\n" ;
    Contato c1("Matheus de Almeida");
    bool resultado = c1.contains("Almeida");
    cout << "A string possui Almeida?" << endl;
    if(resultado)
    {
        cout << "Sim" << endl;
    }
    else
    {
        cout << "Nao" << endl;
    }
    close();
}



void ex1415()
{
// identificacao
    cout << "\nExercicio 1415:\n\n" ;
    Contato c1("matheus");
    string resultado = c1.toUpperCase();
    cout << "String maiuscula = " << resultado << endl;
    close();
}


void ex1416()
{
// identificacao
    cout << "\nExercicio 1416:\n\n" ;
    Contato c1("MATHEUS");
    string resultado = c1.toLowerCase();
    cout << "String minuscula = " << resultado << endl;
    close();
}


void ex1417()
{
// identificacao
    cout << "\nExercicio 1417:\n\n" ;
    Contato c1("Matheus");
    string resultado = c1.trocar('s', 'b');
    cout << "String trocada = " << resultado << endl;
    close();
}



void ex1418()
{
// identificacao
    cout << "\nExercicio 1418:\n\n" ;
    Contato c1("Matheus", 3);
    string resultado = c1.encrypt();
    cout << "String criptografada = " << resultado << endl;
    close();
}



void ex1419()
{
    // identificacao
    cout << "\nExercicio 1419:\n\n";
    Contato c1("Matheus", 3);
    string resultado = c1.encrypt();
    cout << "String criptografada = " << resultado << endl;
    Contato c2(resultado, 3);
    string decodificado = c2.decrypt();
    cout << "String descriptografada = " << decodificado << endl;
    close();
}



void ex1420()
{
    // identificacao
    cout << "\nExercicio 1420:\n\n";
    Contato c1("Meu nome eh Matheus de Almeida e minha matricula eh 848813");
    int quantidade = c1.split();
    cout << "Quantidade de palavras: " << quantidade << endl;
    for (int i = 1; i <= quantidade; ++i)
    {
        cout << "Palavra " << i << ": " << c1.sequencias[i] << endl;
    }
    close();
}



void ex14E1()
{
    cout << "\nExercicio 14E1:\n\n";
    Contato c1("Matheus,Pedro,Artur,Gustavo,Claudio");
    char c = '0';
    cout << "Delimitador =" << endl;
    cin >> c;
    int quantidade = c1.splitWithDelimiter(c);
    cout << "Quantidade de palavras: " << quantidade << endl;
    for (int i = 1; i <= quantidade; ++i)
    {
        cout << "Palavra " << i << ": " << c1.getSequencia(i) << endl;
    }
    close();
}




void ex14E2()
{
    // identificacao
    cout << "\nExercicio 14E2:\n\n";
    Contato c1("Matheus");
    string invertida = c1.inverter();
    cout << "String invertida: " << invertida << endl;
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
            ex1411();
            break;
        case 2:
            ex1412();
            break;
        case 3:
            ex1413();
            break;
        case 4:
            ex1414();
            break;
        case 5:
            ex1415();
            break;
        case 6:
            ex1416();
            break;
        case 7:
            ex1417();
            break;
        case 8:
            ex1418();
            break;
        case 9:
            ex1419();
            break;
        case 10:
            ex1420();
            break;
        case 11:
            ex14E1();
            break;
        case 12:
            ex14E2();
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
