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

struct IntArray {
    int* data;
    int length;
};
typedef IntArray* ref_intArray;

void close()
{
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
}
void menuOpcoes()
{
    cout << "\nEscolha alguma das opcoes a seguir:\n\n";
    cout << "  0 - Encerrar programa\n";
    cout << "  1 - Exercicio 1611\n";
    cout << "  2 - Exercicio 1612\n";
    cout << "  3 - Exercicio 1613\n";
    cout << "  4 - Exercicio 1614\n";
    cout << "  5 - Exercicio 1615\n";
    cout << "  6 - Exercicio 1616\n";
    cout << "  7 - Exercicio 1617\n";
    cout << "  8 - Exercicio 1618\n";
    cout << "  9 - Exercicio 1619\n";
    cout << "  10 - Exercicio 1620\n";
    cout << "  11 - Exercicio 16E1\n";
    cout << "  12 - Exercicio 16E2\n";
} // fim menuOpcoes()


IntArray* array_push_back(IntArray* array, int value) {
    if (array == nullptr) {
        array = new IntArray;
        array->data = nullptr;
        array->length = 0;
    }

    int* new_data = (int*)calloc(array->length + 1, sizeof(int));
    if (new_data == nullptr) {
        cerr << "Erro ao alocar memoria!" << endl;
        return array;
    }
    for (int i = 0; i < array->length; ++i) {
        new_data[i] = array->data[i];
    }

    free(array->data);

    array->data = new_data;
    array->data[array->length] = value;
    array->length++;

    return array;
}



int ex1611()
{
// identificacao
    cout << "\nExercicio 1611:\n\n";
    IntArray* arr = nullptr;
    arr = array_push_back(arr, 10);
    arr = array_push_back(arr, 20);
    arr = array_push_back(arr, 30);
    cout << "Array: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr->data[i] << " ";
    }
    close();
}

IntArray* array_pop_back(IntArray* array) {
    if (array == nullptr || array->length == 0) {
        cout << "Array esta vazio, nada a remover." << endl;
        return array;
    }
    int* new_data = (int*)calloc(array->length - 1, sizeof(int));
    if (new_data == nullptr) {
        cerr << "Erro ao alocar memoria!" << endl;
        return array;
    }
    for (int i = 0; i < array->length - 1; ++i) {
        new_data[i] = array->data[i];
    }
    free(array->data);

    array->data = new_data;
    array->length--;

    return array;
}


int ex1612()
{
    // Identifica��o
    cout << "\nExercicio 1612:\n\n";
    IntArray* arr = nullptr;

    arr = array_push_back(arr, 10);
    arr = array_push_back(arr, 20);
    arr = array_push_back(arr, 30);

    cout << "Preenchendo o array com push_back:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;

    cout << "Alterando o array com pop_back:" << endl;
    for (int i = 0; i < 3; i++) {
        arr = array_pop_back(arr);
        for (int j = 0; j < 3 - i - 1; j++) {
            cout << arr->data[j] << " ";
        }
        cout << endl;
    }

    free(arr);
    close();
}



IntArray* array_push_front(IntArray* array, int value) {
    if (array == nullptr) {
        array = new IntArray;
        array->data = nullptr;
        array->length = 0;
    }
    int* new_data = (int*)calloc(array->length + 1, sizeof(int));
    if (new_data == nullptr) {
        cout << "Erro ao alocar memória!" << endl;
        return array;
    }
    new_data[0] = value;
    for (int i = 0; i < array->length; i++) {
        new_data[i + 1] = array->data[i];
    }
    free(array->data);
    array->data = new_data;
    array->length++;

    return array;
}

void ex1613() {
    // Identificação
    cout << "\nExercicio 1613:\n\n";

    IntArray* arr = nullptr;
    arr = array_push_front(arr, 30);
    cout << "Primeiro push front: " << arr->data[0] << endl;

    arr = array_push_front(arr, 20);
    cout << "Segundo push front: " << arr->data[0] << endl;

    arr = array_push_front(arr, 10);
    cout << "Terceiro push front: " << arr->data[0] << endl;

    cout << "Arranjo preenchido:" << endl;
    for (int i = 0; i < arr->length; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;
    close();
}

IntArray* array_pop_front(IntArray* array) {
    if (array == nullptr || array->length == 0) {
        cout << "Erro: Array vazio" << endl;
        return array;
    }
    int* new_data = (int*)calloc(array->length - 1, sizeof(int));
    if (new_data == nullptr) {
        cout << "Erro ao alocar memória!" << endl;
        return array;
    }
    for (int i = 0; i < array->length - 1; i++) {
        new_data[i] = array->data[i + 1];
    }
    free(array->data);
    array->data = new_data;
    array->length--;

    return array;
}

void ex1614()
{
// identificacao
    cout << "\nExercicio 1614:\n\n" ;
    IntArray* arr = nullptr;
    arr = array_push_front(arr, 30);
    arr = array_push_front(arr, 20);
    arr = array_push_front(arr, 10);
    cout << "Preenchendo o array com push_front:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;
    cout << "Realizando o pop front:" << endl;
    arr = array_pop_front(arr);
    cout << "Apos a primeira remocao:" << endl;
    for (int i = 0; i < arr->length; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;
    arr = array_pop_front(arr);
    cout << "Apos a segunda remocao:" << endl;
    for (int i = 0; i < arr->length; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;
    arr = array_pop_front(arr);
    cout << "Apos a terceira remocao:" << endl;
    if (arr->length == 0) {
        cout << "Array esta vazio." << endl;
    }
    close();
}


IntArray* array_push_mid(IntArray* array, int value) {
    if (array == nullptr) {
        array = new IntArray;
        array->data = nullptr;
        array->length = 0;
    }
    int* new_data = (int*)calloc(array->length + 1, sizeof(int));
    if (new_data == nullptr) {
        cout << "Erro ao alocar memoria!" << endl;
        return array;
    }
    int mid = array->length / 2;
    for (int i = 0; i < mid; i++) {
        new_data[i] = array->data[i];
    }
    new_data[mid] = value;
    for (int i = mid; i < array->length; i++) {
        new_data[i + 1] = array->data[i];
    }
    free(array->data);
    array->data = new_data;
    array->length++;

    return array;
}


void ex1615()
{
// identificacao
    cout << "\nExercicio 1615:\n\n" ;
    IntArray* arr = nullptr;
    arr = array_push_front(arr, 30);
    arr = array_push_front(arr, 10);
    arr = array_push_mid(arr, 20);

    // Exibir o resultado
    cout << "Array apos insercoes no meio:" << endl;
    for (int i = 0; i < arr->length; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;
    close();
}

IntArray* array_pop_mid(IntArray* array) {
    if (array == nullptr || array->length == 0) {
        cout << "Erro: Array vazio ou nulo" << endl;
        return array;
    }

    int* new_data = (int*)calloc(array->length - 1, sizeof(int));
    if (new_data == nullptr) {
        cout << "Erro ao alocar memoria!" << endl;
        return array;
    }
    int mid = array->length / 2;
    for (int i = 0; i < mid; i++) {
        new_data[i] = array->data[i];
    }
    for (int i = mid + 1; i < array->length; i++) {
        new_data[i - 1] = array->data[i];
    }

    free(array->data);
    array->data = new_data;
    array->length--;

    return array;
}

void ex1616()
{
// identificacao
    cout << "\nExercicio 1616:\n\n" ;
    IntArray* arr = nullptr;
    arr = array_push_front(arr, 10);
    arr = array_push_front(arr, 20);
    arr = array_push_front(arr, 30);
    cout << "Array inicial:" << endl;
    for(int i = 0; i < 3; i++){
        cout << arr->data[i] << " ";
    }
    cout << endl;
    arr = array_pop_mid(arr);
    cout << "Array apos remover o valor do meio:" << endl;
    for(int i = 0; i < 2; i++){
        cout << arr->data[i] << " ";
    }
    close();
}

int intArray_cmp(ref_intArray p, ref_intArray q) {
    int minLength = (p->length < q->length) ? p->length : q->length;
    for (int i = 0; i < minLength; i++) {
        if (p->data[i] != q->data[i]) {
            return p->data[i] - q->data[i];
        }
    }
    if (p->length == q->length) return 0;
    return (p->length < q->length) ? -1 : 1;
}
void imprimir_arr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ex1617()
{
// identificacao
    cout << "\nExercicio 1617:\n\n" ;
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 4};
    int arr3[] = {1, 2, 3};
    IntArray intArr1 = {arr1, 3};
    IntArray intArr2 = {arr2, 3};
    IntArray intArr3 = {arr3, 3};
    ref_intArray p1 = &intArr1;
    ref_intArray p2 = &intArr2;
    ref_intArray p3 = &intArr3;
    cout << "Array 1: " << endl;
    imprimir_arr(arr1, 3);
    cout << "Array 2: " << endl;
    imprimir_arr(arr2, 3);
    cout << "Array 3: " << endl;
    imprimir_arr(arr3, 3);
    cout << "Comparacao arr1 e arr2: " << intArray_cmp(p1, p2) << endl;
    cout << "Comparacao arr1 e arr3: " << intArray_cmp(p1, p3) << endl;
    cout << "Comparacao arr2 e arr3: " << intArray_cmp(p2, p3) << endl;
    close();
}

ref_intArray intArray_cat(ref_intArray p, ref_intArray q) {
    int newLength = p->length + q->length;
    int* newData = new int[newLength];
    for (int i = 0; i < p->length; i++) {
        newData[i] = p->data[i];
    }
    for (int i = 0; i < q->length; i++) {
        newData[p->length + i] = q->data[i];
    }
    ref_intArray result = new IntArray;
    result->data = newData;
    result->length = newLength;
    return result;
}

void imprimir_intArray(ref_intArray arr) {
    if (arr == nullptr || arr->length == 0) {
        cout << "Erro" << endl;
        return;
    }

    for (int i = 0; i < arr->length; i++) {
        cout << arr->data[i] << " ";
    }
    cout << endl;
}
void ex1618()
{
// identificacao
    cout << "\nExercicio 1618:\n\n" ;
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    IntArray intArr1 = {arr1, 3};
    IntArray intArr2 = {arr2, 3};
    ref_intArray p1 = &intArr1;
    ref_intArray p2 = &intArr2;
    ref_intArray result = intArray_cat(p1, p2);
    cout << "Array concatenado: ";
    imprimir_intArray(result);
    delete[] result->data;
    delete result;
    close();
}

ref_intArray intArray_seek(ref_intArray a, int x) {
    for (int i = 0; i < a->length; i++) {
        if (a->data[i] == x) {
            ref_intArray result = new IntArray;
            result->data = &a->data[i];
            result->length = a->length - i;
            return result;
        }
    }
    return nullptr;
}



void ex1619()
{
    // identificacao
    cout << "\nExercicio 1619:\n\n";
    int arr[] = {5, 10, 15, 10, 20};
    IntArray intArr = {arr, 5};
    ref_intArray a = &intArr;
    int x = 0;
    cout << "Valor procurado =";
    cin >> x;
    cout << "Array original:";
    imprimir_intArray(a);
    ref_intArray result = intArray_seek(a, x);
    if (result) {
        cout << "Imprimindo restante do array a partir da ocorrencia: ";
        imprimir_intArray(result);
        delete result;
    }else{
        cout << x << " nao existe no array" << endl;
    }
    getchar();
    close();
}

ref_intArray intArray_sub(ref_intArray a, int start, int size) {
    if (start < 0 || start >= a->length || size <= 0 || (start + size) > a->length) {
        return nullptr;
    }

    int* newData = new int[size];
    for (int i = 0; i < size; i++) {
        newData[i] = a->data[start + i];
    }
    ref_intArray result = new IntArray;
    result->data = newData;
    result->length = size;

    return result;
}

void ex1620()
{
    // identificacao
    cout << "\nExercicio 1620:\n\n";
    int arr[] = {5, 10, 15, 20, 25, 30};
    IntArray intArr = {arr, 6};
    ref_intArray a = &intArr;
    int start = 2;
    int size = 0;
    cout << "Digite o tamanho do subarray:" << endl;
    cin >> size;
    ref_intArray result = intArray_sub(a, start, size);
    if (result && size > 0 && size <= result->length) {
        cout << "Subarray: ";
        imprimir_intArray(result);
        delete[] result->data;
        delete result;
    } else {
        cout << "Erro" << endl;
    }
    getchar();
    close();
}



void ex16E1()
{
    cout << "\nExercicio 16E1:\n\n";

    close();
}




void ex16E2()
{
    // identificacao
    cout << "\nExercicio 16E2:\n\n";

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
            ex1611();
            break;
        case 2:
            ex1612();
            break;
        case 3:
            ex1613();
            break;
        case 4:
            ex1614();
            break;
        case 5:
            ex1615();
            break;
        case 6:
            ex1616();
            break;
        case 7:
            ex1617();
            break;
        case 8:
            ex1618();
            break;
        case 9:
            ex1619();
            break;
        case 10:
            ex1620();
            break;
        case 11:
            ex16E1();
            break;
        case 12:
            ex16E2();
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
