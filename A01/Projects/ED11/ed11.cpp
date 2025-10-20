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
using namespace std;
// Tamanho max string
const int TAM_STR = 80;
// Fun��o para mostrar o menu de op��es
void menuOpcoes() {
   cout << "\nEscolha alguma das opcoes a seguir:\n\n";
   cout << "  0 - Encerrar programa\n";
   cout << "  1 - Exercicio 1111\n";
   cout << "  2 - Exercicio 1112\n";
   cout << "  3 - Exercicio 1113\n";
   cout << "  4 - Exercicio 1114\n";
   cout << "  5 - Exercicio 1115\n";
   cout << "  6 - Exercicio 1116\n";
   cout << "  7 - Exercicio 1117\n";
   cout << "  8 - Exercicio 1118\n";
   cout << "  9 - Exercicio 1119\n";
   cout << "  10 - Exercicio 1120\n";
   cout << "  11 - Exercicio 11E1\n";
   cout << "  12 - Exercicio 11E2\n";
} // fim menuOpcoes()
class IntArray{
public:
    int  length = 0;
    int* data = NULL ;
    int  ix  = 0;
    ~IntArray(){
        delete[] data;
    }
 ////addInterval/////
int addInterval(int inicio, int fim){
    if (inicio < 0 || fim >= length || inicio > fim) {
        cout << "Erro: intervalo invalido.\n";
        return -1;
    }
    int soma = 0;
    for (int i = inicio; i <= fim; i++){
            soma += data[i];
    }
        return soma;
}

int averageInterval(int inicio, int fim){
    if (inicio < 0 || fim >= length || inicio > fim) {
        cout << "Erro: intervalo invalido.\n";
        return -1;
    }
    int soma = 0;
    int total = 0;
    for (int i = inicio; i <= fim; i++){
            soma += data[i];
            total++;
    }
        return soma/total;
}

bool searchInterval(int procurado, int inicio, int fim){
    if (inicio < 0 || fim >= length || inicio > fim) {
        cout << "Erro: intervalo invalido.\n";
        return -1;
    }
    for (int i = inicio; i <= fim; i++){
            if(data[i] == procurado){
                return true;
            }else{
                return false;
            }
    }
}

int searchFirstOdd(){
    int maior = 0;
    bool achou = false;
    for (int i = 0; i < length; i++){
        if (data[i] % 2 == 0){
        if (data[i] > maior) {
            maior = data[i];
            achou = true;
        }
    }
   }if(achou){
        return maior;
   }else{
        return -1;
   }
}

int searchFirstEvenx3(){
    int menor = INT_MAX;
    bool achou = false;
    for (int i = 0; i < length; i++){
        if (data[i] % 2 == 0 && data[i] % 3 == 0){
        if (data[i] < menor) {
            menor = data[i];
            achou = true;
        }
    }
   }
   if(achou){
        return menor;
   }else{
        return -1;
   }
}

int negatives(){
    bool achou = false;
    for (int i = 0; i < length; i++){
        if (data[i] < 0){
            achou = true;
        }
    }
   if(achou){
        return -1;
   }else{
        return 1;
   }
}

bool isDecrescent() {
        for (int i = 0; i < length - 1; i++) {
            if (data[i] < data[i + 1]) {
                return false;
            }
        }
        return true;
    }

void scalar(int constante, int inicio, int fim) {
        if (inicio < 0 || fim >= length || inicio > fim) {
            std::cout << "Erro: intervalo invalido.\n";
            return;
        }
        for (int i = inicio; i <= fim; i++) {
            data[i] *= constante;
        }
    }

void sortDown() {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (data[j] < data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }


};

// Fun��o para o exerc�cio 1111
// ler a quantidade de elementos ( N ) a serem gerados;
// gerar essa quantidade ( N ) de valores aleat�rios
// dentro do intervalo e armazen�-los em arranjo;
// grav�-los, um por linha, em um arquivo ("DADOS.TXT").
// A primeira linha do arquivo dever� informar a quantidade
// de n�meros aleat�rios ( N ) que ser�o gravados em seguida.
// DICA: Usar a fun��o rand( ), mas tentar limitar valores muito grandes.
// Exemplo: valor = arranjo.randomIntGenerate ( inferior, superior );
int RandomIntGenerate(int inferior, int superior) {
    return rand() % (superior - inferior + 1) + inferior;
}

void gravarEmArquivo(const char* nomeArquivo, int* arranjo, int n) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL){
        cout << "Erro ao abrir o arquivo.\n";
    }
    fprintf(arquivo, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(arquivo, "%d\n", arranjo[i]);
    }
    fclose(arquivo);
    cout << "Numeros gerados e gravados no arquivo \"" << nomeArquivo << "\".\n";

}

int ex1111() {
// identificacao
    cout << "\nExercicio 1111:\n\n";
    int inferior = 0, superior = 0, n = 0;
    srand(time(NULL));
    cout << "Inferior =";
    cin >> inferior;
    cout << "\nSuperior =";
    cin >> superior;
    cout << "\nQuantidade =";
    cin>> n;
    int arranjo[n];
    for(int i = 0; i < n; i++){
        arranjo[i] = RandomIntGenerate(inferior, superior);
    }
    gravarEmArquivo("DADOS.TXT", arranjo, n);
    getchar();
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
}
// fim exercicio1011

// Fun��o para o exerc�cio 1012
// procurar o maior valor par em um arranjo.
// Para testar, receber um nome de arquivo como par�metro e
// aplicar a fun��o sobre o arranjo com os valores lidos;
// DICA: Usar o primeiro valor par, se houver, como refer�ncia inicial.
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// maior = arranjo.searchFirstOdd ( );

IntArray readArrayFromFile(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rt");
    IntArray array;
    if (arquivo) {
        fscanf(arquivo, "%d", &array.length);
        fgetc(arquivo);  // Consume newline or any other delimiter

        if (array.length <= 0) {
            cout << "ERRO: Tamanho invalido." << endl;
            array.length = 0;
        } else {
            array.data = new int[array.length];
            if (array.data) {
                array.ix = 0;
                while (array.ix < array.length && fscanf(arquivo, "%d", &array.data[array.ix]) == 1) {
                    fgetc(arquivo);  // Consume any newline or delimiter
                    array.ix++;
                }
            } else {
                cout << "ERRO: Falha na alocacao de memoria." << endl;
                array.length = 0;
            }
        }
        fclose(arquivo);
    } else {
        cout << "ERRO: Falha ao abrir o arquivo." << endl;
    }
    return array;
}



int ex1112() {
    // Identifica��o
    cout << "\nExercicio 1112:\n\n";
    IntArray array = readArrayFromFile("DADOS.TXT");
    int resposta = array.searchFirstOdd();
    if(resposta != -1){
    cout << "O maior valor par encontrado no arranjo foi: " << resposta;
    }else{
    cout << "O arranjo nao possui valor par";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar(); // Pausa para esperar ENTER

    return 0; // Encerra com sucesso
}// Fim da fun��o ex1012

// Fun��o para o exerc�cio 1013
// procurar o menor valor par m�ltiplo de 3 em um arranjo.
// Para testar, receber um nome de arquivo como par�metro e
// aplicar a fun��o sobre o arranjo com os valores lidos;
// DICA: Usar o primeiro valor par m�ltiplo de 3, se houver, como refer�ncia inicial.
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// menor = arranjo.searchFirstEvenx3 ( );



void ex1113() {
// identificacao
    cout << "\nExercicio 1113:\n\n" ;
    IntArray array = readArrayFromFile("DADOS.TXT");
    int resposta = array.searchFirstEvenx3();
    if(resposta != -1){
    cout << "O menor valor par e multiplo de tres encontrado no arranjo foi: " << resposta;
    }else{
    cout << "O arranjo nao possui nenhum valor par e multiplo de tres";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar(); // Pausa para esperar ENTER

}// Fim da fun��o ex1013

// Fun��o para o exerc�cio 1014
// somar todos os valores em um arranjo entre duas posi��es dadas.
// Para testar, receber um nome de arquivo como par�metro e
// aplicar a fun��o sobre o arranjo com os valores lidos;
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// soma = arranjo.addInterval ( inicio, fim );

void ex1114() {
// identificacao
    cout << "\nExercicio 1114:\n\n" ;
    int inicio = 0, fim = 0;
    IntArray array = readArrayFromFile("DADOS.TXT");
    cout << "Inicio =";
    cin >> inicio;
    cout << "\nFim =";
    cin >> fim;
    int soma = array.addInterval(inicio, fim);
    if(soma != -1){
    cout << "A soma do arranjo eh: " << soma;
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
    getchar();
}// Fim da fun��o ex1014

// Fun��o para o exerc�cio 1015
// achar a m�dia dos valores em um arranjo entre duas posi��es dadas.
// Para testar, receber um nome de arquivo como par�metro e
// aplicar a fun��o sobre o arranjo com os valores lidos;
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// media = arranjo.averageInterval ( inicio, fim );



void ex1115() {
// identificacao
    cout << "\nExercicio 1115:\n\n" ;
    int inicio = 0, fim = 0;
    IntArray array = readArrayFromFile("DADOS.TXT");
    cout << "Inicio =";
    cin >> inicio;
    cout << "\nFim =";
    cin >> fim;
    int media = array.averageInterval(inicio, fim);
    if(media != -1){
    cout << "A media do intervalo eh: " << media;
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
    getchar();
}// Fim da fun��o ex0915

// Fun��o para o exerc�cio 0916
// verificar se todos os valores s�o positivos em um arranjo.
// Para testar, ler o arquivo ("DADOS.TXT")
// armazenar os dados em um arranjo.
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// teste = arranjo.negatives ( );


void ex1116() {
// identificacao
    cout << "\nExercicio 1116:\n\n" ;
    IntArray array = readArrayFromFile("DADOS.TXT");
    int resposta = array.negatives();
    if(resposta != -1){
    cout << "O Arranjo nao possui valores negativos ";
    }else{
    cout << "O arranjo possui valores negativos";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar(); // Pausa para esperar ENTER
}// Fim da fun��o ex1016

// Fun��o para o exerc�cio 1017
// dizer se est� ordenado, ou n�o, em ordem decrescente.
// DICA: Testar se n�o est� desordenado, ou seja,
// se existe algum valor que seja maior que o seguinte.
// N�o usar break !
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// teste = arranjo.isDecrescent ( );


void ex1117() {
// identificacao
    cout << "\nExercicio 1117:\n\n" ;
    IntArray array = readArrayFromFile("DADOS.TXT");
    bool teste = array.isDecrescent();
    if(teste){
    cout << "O Arranjo esta ordenado em ordem decrescente";
    }else{
    cout << "O arranjo nao esta ordenado em ordem decrescente";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar(); // Pausa para esperar ENTER
}// Fim da fun��o ex0917

// Fun��o para o exerc�cio 1018
// dizer se determinado valor est� presente em arranjo,
// entre duas posi��es indicadas.
// Para testar, ler o arquivo ("DADOS.TXT"),
// e armazenar os dados em arranjo;
// ler do teclado um valor inteiro para ser procurado;
// determinar se o valor procurado existe no arranjo.
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// existe = arranjo.searchInterval ( procurado, inicio, fim );



void ex1118() {
// identificacao
    cout << "\nExercicio 1118:\n\n" ;
    int inicio = 0, fim = 0, procurado = 0;
    IntArray array = readArrayFromFile("DADOS.TXT");
    cout << "Inicio =";
    cin >> inicio;
    cout << "\nFim =";
    cin >> fim;
    cout << "\nProcurado =";
    cin >> procurado;
    bool existe = array.searchInterval(procurado, inicio, fim);
    if(existe){
    cout << "O numero: " << procurado << " existe no intervalo " << inicio << " e " << fim;
    }else{
    cout << "Nao existe";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
    getchar();
}// Fim da fun��o ex1018

// Fun��o para o exerc�cio 0919
// escalar dados em arranjo, entre duas posi��es dadas,
// multiplicando cada valor por uma constante.
// Para testar, ler o arquivo ("DADOS.TXT"),
// e armazenar os dados em arranjo;
// ler do teclado um valor inteiro para indicar a constante.
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// novo = arranjo.scalar( constante, inicio, fim );



void ex1119() {
    // identificacao
    cout << "\nExercicio 1119:\n\n";
    IntArray array = readArrayFromFile("DADOS.TXT");
    int constante = 0, inicio = 0, fim = 0;
    cout << "Digite o valor da constante: ";
    cin >> constante;
    cout << "Digite o inicio do intervalo: ";
    cin >> inicio;
    cout << "Digite o fim do intervalo: ";
    cin >> fim;
    cout << "Arranjo original:\n";
    for (int i = 0; i < array.length; ++i) {
        cout << array.data[i] << " ";
    }
    array.scalar(constante, inicio, fim);
    cout << "\nArranjo modificado:\n";
    for (int i = 0; i < array.length; ++i) {
        cout << array.data[i] << " ";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
    getchar();
}// Fim da fun��o ex0919

// Fun��o para o exerc�cio 1020
// colocar valores em arranjo em ordem decrescente,
// mediante trocas de posi��es, at� ficar totalmente ordenado.
// Para testar, ler o arquivo ("DADOS.TXT"),
// e armazenar os dados em arranjo.
// Exemplo: arranjo = readArrayFromFile ( "DADOS.TXT" );
// arranjo.sortDown ( );



void ex1120() {
// identificacao
    cout << "\nExercicio 1120:\n\n";
    IntArray array = readArrayFromFile("DADOS.TXT");
    cout << "Arranjo original:\n";
    for (int i = 0; i < array.length; ++i) {
        cout << array.data[i] << " ";
    }
    array.sortDown();
    cout << "\nArranjo modificado:\n";
    for (int i = 0; i < array.length; ++i) {
        cout << array.data[i] << " ";
    }
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
    getchar();
}// Fim da fun��o ex0320

// Fun��o para o exerc�cio 10E1
// Incluir uma fun��o/operador (11E1) para
// dizer se dois arranjos s�o diferentes, pelo menos em uma posi��o.



void ex11E1(){
    cout << "\nExercicio 11E1:\n\n";

}
// fim exercicio09E1
// Fun��o para o exerc�cio 10E2
// calcular as diferen�as entre dois arranjos, posi��o por posi��o,
// caso tenham tamanhos iguais.



void ex11E2(){
    // identificacao
    cout << "\nExercicio 11E2:\n\n";
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
} // fim fun��o 03E2

// Fun��o principal
int main(void) {
    int opcao;

    do {
        menuOpcoes(); // Chama a fun��o que exibe as op��es

        cout << "\nOpcao = ";
        cin >> opcao;
        getchar(); // Limpar o buffer de entrada

        // Executar a op��o escolhida
        switch (opcao) {
            case 0: break;
            case 1: ex1111(); break;
            case 2: ex1112(); break;
            case 3: ex1113(); break;
            case 4: ex1114(); break;
            case 5: ex1115(); break;
            case 6: ex1116(); break;
            case 7: ex1117(); break;
            case 8: ex1118(); break;
            case 9: ex1119(); break;
            case 10: ex1120(); break;
            case 11: ex11E1(); break;
            case 12: ex11E2(); break;
            default:
                cout << "\nERRO: OPCAO INVALIDA\n\n";
                break;
        } // fim switch

    } while (opcao != 0);

    cout << "\nAperte ENTER para terminar!\n";
    getchar();

    return 0;
} // Fim da fun��o principal
