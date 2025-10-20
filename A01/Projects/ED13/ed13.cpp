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
    cout << "  1 - Exercicio 1311\n";
    cout << "  2 - Exercicio 1312\n";
    cout << "  3 - Exercicio 1313\n";
    cout << "  4 - Exercicio 1314\n";
    cout << "  5 - Exercicio 1315\n";
    cout << "  6 - Exercicio 1316\n";
    cout << "  7 - Exercicio 1317\n";
    cout << "  8 - Exercicio 1318\n";
    cout << "  9 - Exercicio 1319\n";
    cout << "  10 - Exercicio 1320\n";
    cout << "  11 - Exercicio 13E1\n";
    cout << "  12 - Exercicio 13E2\n";
} // fim menuOpcoes()

class Contato
{
private:
    string nome;
    string tel;
    string tel2;
    string residencial;
    string comercial;
    bool isPhoneNumberValid(string tel)
    {
        if (tel.empty())
        {
            return false;
        }
        for (size_t i = 0; i < tel.size(); ++i)
        {
            if (!isdigit(tel[i]) && tel[i] != '-')
            {
                return false;
            }
        }
        return true;
    }
public:
    void readName()
    {
        string novonome;
        cout << "Nome:" << endl;
        getline(cin, novonome);
        if (!novonome.empty())
        {
            nome = novonome;
        }
        else
        {
            cout << "Erro ao cadastrar nome.\n";

        }
    }
    void showName()
    {
        if (!nome.empty())
        {
            cout << "Nome: " << nome << endl;
        }
        else
        {
            cout << "Nome nao foi atribuido.\n";
        }
    }
    void readPhone()
    {
        string newphone;
        cout << "Telefone:" << endl;
        getline(cin, newphone);
        if (!newphone.empty())
        {
            tel = newphone;
        }
        else
        {
            cout << "Erro ao cadastrar telefone" << endl;
        }
    }

    void showPhone()
    {
        if (!tel.empty())
        {
            cout << "Telefone: " << tel << endl;
            bool teste = isPhoneNumberValid(tel);
            if(teste)
            {
                cout << "\nO numero eh valido!" << endl;
            }
            else
            {
                cout << "\nO numero digitado nao eh valido" << endl;
            }
        }
        else
        {
            cout << "Telefone nao foi atribuido.\n";
        }
    }
    void readFromFile(string nomearq)
    {
        ifstream file(nomearq);
        if (file.is_open())
        {
            getline(file, nome);
            getline(file, tel);
            getline(file, tel2);
            file.close();
        }
        else
        {
            cout << "Erro ao abrir o arquivo." << endl;
        }
    }

    void exibirContato()
    {
        if (!nome.empty() && !tel.empty())
        {
            cout << "Nome: " << nome << endl;
            cout << "Telefone: " << tel << endl;
            if (!tel2.empty())
            {
                cout << "Telefone 2: " << tel2 << endl;
            }
            else
            {
                cout << "Telefone 2: Nao informado" << endl;
            }
        }
        else
        {
            cout << "Contato nao encontrado" << endl;
        }
    }
    void writeToFile(string nomearq)
    {
        ofstream file(nomearq);
        if (file.is_open())
        {
            file << nome << endl;
            file << tel << endl;
            file << tel2 << endl;
            file << nome.size() << endl;
            file << tel.size() << endl;
            file.close();
        }
        else
        {
            cout << "Erro ao abrir o arquivo." << endl;
        }
    }

    int phones()
    {
        if(!tel2.empty() && !tel.empty())
        {
            return 2;
        }
        else if(!tel2.empty() && tel.empty())
        {
            return 1;
        }
        else if(tel2.empty() && !tel.empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void setPhone2a()
    {
        string newphone;
        if (tel2.empty())
        {
            char resposta;
            cout << "Deseja adicionar um segundo numero de telefone? (s/n): " << endl;
            cin >> resposta;
            cin.ignore();
            if (resposta == 's' || resposta == 'S')
            {
                cout << "Telefone 2: " << endl;
                getline(cin, newphone);
                tel2 = newphone;
                cout << "Segundo telefone adicionado com sucesso!" << endl;
            }
            else
            {
                cout << "Operação cancelada." << endl;
            }
        }
        else
        {
            cout << "O contato ja possui um segundo telefone: " << tel2 << endl;
        }
    }

    void setPhone2b()
    {
        string newphone;
        if (!tel2.empty())
        {
            cout << "Numero atual:" << tel2 << endl;
            cout << "\n";
            cout << "Escreva seu novo numero" << endl;
            cin >> newphone;
            cout << "\n";
            cout << "Numero atualizado: " << newphone << endl;
        }
        else
        {
            cout << "Erro" << endl;
        }
    }
    void setPhone2c()
    {
        if (!tel2.empty())
        {
            tel2 = "";
            cout << "Telefone deletado" << endl;
        }
        else
        {
            cout << "Erro" << endl;
        }
    }
    void read_adress()
    {
        string newadress1;
        string newadress2;
        cout << "Endereco comercial:" << endl;
        getline(cin, newadress1);
        if (!newadress1.empty())
        {
            comercial = newadress1;
        }
        else
        {
            cout << "Erro ao cadastrar endereco.\n";

        }
        cout << "\n";
        cout << "Endereco Residencial:" << endl;
        getline(cin, newadress2);
        if (!newadress2.empty())
        {
            residencial = newadress2;
        }
        else
        {
            cout << "Erro ao cadastrar endereco.\n";

        }

    }
    void show_newinfo()
    {
        cout << "\n";
        cout << "Nome: " << nome << endl;
        cout << "Telefones: " << tel << tel2 << endl;
        cout << "Endereco comercial:" << endl;
        cout << comercial << endl;
        cout << "Endereco Residencial:" << endl;
        cout << residencial << endl;

    }

};


int ex1311()
{
// identificacao
    cout << "\nExercicio 1311:\n\n";
    Contato contato1;
    contato1.readName();
    contato1.showName();
    close();
}





int ex1312()
{
    // Identifica��o
    cout << "\nExercicio 1312:\n\n";
    Contato contato1;
    contato1.readPhone();
    contato1.showPhone();
    close();


}



void ex1313()
{
// identificacao
    cout << "\nExercicio 1313:\n\n" ;
    Contato contato1;
    contato1.readPhone();
    contato1.showPhone();
    close();

}

void ex1314()
{
// identificacao
    cout << "\nExercicio 1314:\n\n" ;
    Contato contato1;
    contato1.readFromFile("contato.txt");
    contato1.exibirContato();
    close();
}



void ex1315()
{
// identificacao
    cout << "\nExercicio 1315:\n\n" ;
    Contato contato1;
    contato1.readName();
    contato1.readPhone();
    contato1.writeToFile("dados.txt");

    Contato contato2;
    contato2.readFromFile("dados.txt");
    cout << endl;
    cout << "Dados do arquivo: dados.txt" <<endl;
    contato2.exibirContato();
    close();
}


void ex1316()
{
// identificacao
    cout << "\nExercicio 1316:\n\n" ;
    Contato contato1;
    contato1.readFromFile("dados.txt");
    contato1.exibirContato();
    close();
}


void ex1317()
{
// identificacao
    cout << "\nExercicio 1317:\n\n" ;
    Contato contato1;
    contato1.readFromFile("dados.txt");
    int n = contato1.phones();
    cout << "O Contato possui: " << n << " numeros." << endl;
    close();
}



void ex1318()
{
// identificacao
    cout << "\nExercicio 1318:\n\n" ;
    Contato contato1;
    contato1.readName();
    contato1.readPhone();
    contato1.exibirContato();
    contato1.setPhone2a();
    contato1.exibirContato();
    close();
}



void ex1319()
{
    // identificacao
    cout << "\nExercicio 1319:\n\n";
    Contato contato1;
    contato1.readName();
    contato1.readPhone();
    contato1.exibirContato();
    cout << "\n";
    contato1.setPhone2a();
    cout << "\n";
    contato1.setPhone2b();
    getchar();
    close();
}



void ex1320()
{
// identificacao
    cout << "\nExercicio 1320:\n\n";
    Contato contato1;
    contato1.readName();
    contato1.readPhone();
    contato1.exibirContato();
    cout << "\n";
    contato1.setPhone2a();
    cout << "\n";
    contato1.exibirContato();
    cout << "\n";
    contato1.setPhone2c();
    cout << "\n";
    contato1.exibirContato();
    getchar();
    close();
}



void ex13E1()
{
    cout << "\nExercicio 13E1:\n\n";
    close();
}




void ex13E2()
{
    // identificacao
    cout << "\nExercicio 13E2:\n\n";
    Contato contato1;
    contato1.readFromFile("dados.txt");
    contato1.read_adress();
    contato1.show_newinfo();
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
            ex1311();
            break;
        case 2:
            ex1312();
            break;
        case 3:
            ex1313();
            break;
        case 4:
            ex1314();
            break;
        case 5:
            ex1315();
            break;
        case 6:
            ex1316();
            break;
        case 7:
            ex1317();
            break;
        case 8:
            ex1318();
            break;
        case 9:
            ex1319();
            break;
        case 10:
            ex1320();
            break;
        case 11:
            ex13E1();
            break;
        case 12:
            ex13E2();
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
