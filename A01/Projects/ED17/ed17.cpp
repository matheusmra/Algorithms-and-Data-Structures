/*
 Estudo Dirigido 17 - v0.0. - 03 / 12 / 2024
 Author: Matheus de Almeida Moreira

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o ed17 ed17.c
 Windows: gcc -o ed17 ed17.c
 Para executar em terminal (janela de comandos):
 Linux : ./ed17
 Windows: ed17
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

typedef struct s_intStack {
    int length;
    int* data;
}intStack;

typedef intStack* ref_intStack;


typedef struct s_intQueue {
    int length;
    int* data;
} intQueue;

typedef intQueue* ref_intQueue;


void close()
{
    cout << "\nAperte ENTER para continuar!\n";
    getchar();
}
void menuOpcoes()
{
    cout << "\nEscolha alguma das opcoes a seguir:\n\n";
    cout << "  0 - Encerrar programa\n";
    cout << "  1 - Exercicio 1711\n";
    cout << "  2 - Exercicio 1712\n";
    cout << "  3 - Exercicio 1713\n";
    cout << "  4 - Exercicio 1714\n";
    cout << "  5 - Exercicio 1715\n";
    cout << "  6 - Exercicio 1716\n";
    cout << "  7 - Exercicio 1717\n";
    cout << "  8 - Exercicio 1718\n";
    cout << "  9 - Exercicio 1719\n";
    cout << "  10 - Exercicio 1720\n";
    cout << "  11 - Exercicio 17E1\n";
    cout << "  12 - Exercicio 17E2\n";
} // fim menuOpcoes()

void printStack(ref_intStack stack) {
    if (!stack || stack->length == 0) {
        cout << "Pilha está vazia." << endl;
        return;
    }
    cout << "Pilha (topo para base): ";
    for (int i = stack->length - 1; i >= 0; --i) {
        cout << stack->data[i] << " ";
    }
    cout << endl;
}
void printQueue(ref_intQueue queue) {
    if (!queue || queue->length == 0) {
        cout << "Fila esta vazia." << endl;
        return;
    }
    cout << "Fila: ";
    for (int i = 0; i < queue->length; i++) {
        cout << queue->data[i] << " ";
    }
    cout << endl;
}

ref_intStack intStack_push(ref_intStack stack, int value) {
    if (!stack) {
        stack = new intStack();
        stack->data = new int[4];
        stack->length = 0;
    }
    int capacity = (stack->length > 0) ? stack->length : 4;
    if (stack->length == capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < stack->length; ++i) {
            newData[i] = stack->data[i];
        }
        delete[] stack->data;
        stack->data = newData;
    }
    stack->data[stack->length++] = value;

    return stack;
}


int ex1711()
{
// identificacao
    cout << "\nExercicio 1711:\n\n";
    intStack* stack = nullptr;
    stack = intStack_push(stack, 10);
    stack = intStack_push(stack, 20);
    stack = intStack_push(stack, 30);
    printStack(stack);
    delete[] stack->data;
    delete stack;
    close();
}

ref_intStack intStack_pop(ref_intStack stack) {
    if (!stack || stack->length == 0) {
        cout << "Pilha vazia!" << endl;
        return nullptr;
    }
    stack->length--;
    return stack;
}


int ex1712()
{
    // Identifica��o
    cout << "\nExercicio 1712:\n\n";
    intStack* stack = nullptr;
    stack = intStack_push(stack, 20);
    stack = intStack_push(stack, 30);
    printStack(stack);
    stack = intStack_pop(stack);
    cout << "Topo da pilha apos remocao: " << stack->data[stack->length - 1] << endl;
    close();
}

ref_intStack intStack_dup(ref_intStack stack) {
    if (!stack || stack->length == 0) {
        cout << "Erro: Pilha vazia!" << endl;
        return stack;
    }
    int topValue = stack->data[stack->length - 1];
    stack = intStack_push(stack, topValue);
    return stack;
}

void ex1713() {
    // Identificação
    cout << "\nExercicio 1713:\n\n";
    intStack* stack = nullptr;
    stack = intStack_push(stack, 10);
    stack = intStack_push(stack, 20);
    stack = intStack_push(stack, 30);
    printStack(stack);
    cout << "Duplicando valor do topo da pilha: " << endl;
    stack = intStack_dup(stack);
    printStack(stack);
    close();
}

ref_intStack intStack_swap(ref_intStack stack) {
    if (!stack || stack->length < 2) {
        cout << "Erro: Pilha invalida ou com menos de dois elementos!" << endl;
        return stack;
    }
    int primeiro = stack->length - 1;
    int segundo = stack->length - 2;
    int temp = stack->data[primeiro];
    stack->data[primeiro] = stack->data[segundo];
    stack->data[segundo] = temp;
    return stack;
}

void ex1714()
{
// identificacao
    cout << "\nExercicio 1714:\n\n" ;
    intStack* stack = nullptr;
    stack = intStack_push(stack, 30);
    stack = intStack_push(stack, 20);
    printStack(stack);
    cout << "Trocando os valores da pilha: " << endl;
    stack = intStack_swap(stack);
    printStack(stack);
    close();
}

ref_intStack intStack_invert(ref_intStack stack) {
    if (!stack || stack->length < 2) {
        cout << "Erro: Pilha invalida ou com menos de dois elementos!" << endl;
        return stack;
    }
    int start = 0;
    int end = stack->length - 1;

    while (start < end) {
        int temp = stack->data[start];
        stack->data[start] = stack->data[end];
        stack->data[end] = temp;
        start++;
        end--;
    }
    return stack;
}


void ex1715()
{
// identificacao
    cout << "\nExercicio 1715:\n\n" ;
    intStack* stack = nullptr;
    stack = intStack_push(stack, 30);
    stack = intStack_push(stack, 20);
    stack = intStack_push(stack, 10);
    printStack(stack);
    cout << "Invertendo os valores da pilha: " << endl;
    stack = intStack_invert(stack);
    printStack(stack);
    close();
}


ref_intQueue intQueue_push(ref_intQueue queue, int value) {
    if (!queue) {
        queue = new intQueue();
        queue->data = new int[4];
        queue->length = 0;
    }
    int capacity = (queue->length > 0) ? queue->length : 4;
    if (queue->length == capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < queue->length; ++i) {
            newData[i] = queue->data[i];
        }
        delete[] queue->data;
        queue->data = newData;
    }
    queue->data[queue->length++] = value;

    return queue;
}


void ex1716()
{
// identificacao
    cout << "\nExercicio 1716:\n\n" ;
    ref_intQueue queue = nullptr;
    queue = intQueue_push(queue, 10);
    queue = intQueue_push(queue, 20);
    queue = intQueue_push(queue, 30);
    cout << "Fila apos insercoes:" << endl;
    printQueue(queue);
    cout << endl;
    delete[] queue->data;
    delete queue;

    close();
}

ref_intQueue intQueue_pop(ref_intQueue queue) {
    if (!queue || queue->length == 0) {
        cout << "Erro: Fila vazia ou invalida!" << endl;
        return nullptr;
    }
    for (int i = 1; i < queue->length; ++i) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->length--;
    if (queue->length == 0) {
        delete[] queue->data;
        delete queue;
        return nullptr;
    }
    return queue;
}

void ex1717()
{
// identificacao
    cout << "\nExercicio 1717:\n\n" ;
    ref_intQueue queue = nullptr;
    queue = intQueue_push(queue, 10);
    queue = intQueue_push(queue, 20);
    queue = intQueue_push(queue, 30);
    printQueue(queue);
    queue = intQueue_pop(queue);
    cout << "Fila apos remover o primeiro elemento:" << endl;
    printQueue(queue);
    delete[] queue->data;
    delete queue;
    close();
}

int intQueue_compare(ref_intQueue p, ref_intQueue q) {
    if (p->length != q->length) {
        return p->length - q->length;
    }
    for (int i = 0; i < p->length; ++i) {
        if (p->data[i] < q->data[i]) {
            return -1;
        } else if (p->data[i] > q->data[i]) {
            return 1;
        }
    }
    return 0;
}

void ex1718()
{
// identificacao
    cout << "\nExercicio 1718:\n\n" ;
    ref_intQueue queue1 = nullptr;
    ref_intQueue queue2 = nullptr;
    queue1 = intQueue_push(queue1, 10);
    queue1 = intQueue_push(queue1, 20);
    queue1 = intQueue_push(queue1, 30);
    queue2 = intQueue_push(queue2, 10);
    queue2 = intQueue_push(queue2, 20);
    queue2 = intQueue_push(queue2, 30);
    int result = intQueue_compare(queue1, queue2);
    if (result == 0) {
        cout << "As filas sao iguais." << endl;
    } else if (result < 0) {
        cout << "A primeira fila eh menor que a segunda fila." << endl;
    } else {
        cout << "A primeira fila eh maior que a segunda fila." << endl;
    }
    delete[] queue1->data;
    delete queue1;
    delete[] queue2->data;
    delete queue2;
    close();
}

ref_intQueue intQueue_join(ref_intQueue p, ref_intQueue q) {
    if (!p) {
        return q;
    }
    if (!q) {
        return p;
    }
    ref_intQueue result = new intQueue;
    result->length = p->length + q->length;
    result->data = new int[result->length];
    for (int i = 0; i < p->length; ++i) {
        result->data[i] = p->data[i];
    }
    for (int i = 0; i < q->length; ++i) {
        result->data[p->length + i] = q->data[i];
    }
    delete[] p->data;
    delete p;
    delete[] q->data;
    delete q;

    return result;
}

void ex1719()
{
    // identificacao
    cout << "\nExercicio 1719:\n\n";
    ref_intQueue queue1 = nullptr;
    ref_intQueue queue2 = nullptr;
    queue1 = intQueue_push(queue1, 10);
    queue1 = intQueue_push(queue1, 20);
    cout << "Primeira fila: " << endl;
    printQueue(queue1);
    cout << "Segunda fila: " << endl;
    queue2 = intQueue_push(queue2, 30);
    queue2 = intQueue_push(queue2, 40);
    printQueue(queue2);
    cout << "Unindo a duas filas:" << endl;
    ref_intQueue mergedQueue = intQueue_join(queue1, queue2);
    printQueue(mergedQueue);
    delete[] mergedQueue->data;
    delete mergedQueue;
    close();
}

int intQueue_search(ref_intQueue queue, int value) {
    if (!queue || queue->length == 0) {
        return -2;
    }
    for (int i = 0; i < queue->length; ++i) {
        if (queue->data[i] == value) {
            return i;
        }
    }

    return -1;
}

void ex1720()
{
    // identificacao
    cout << "\nExercicio 1720:\n\n";
    ref_intQueue queue = nullptr;
    queue = intQueue_push(queue, 10);
    queue = intQueue_push(queue, 20);
    queue = intQueue_push(queue, 30);
    printQueue(queue);
    int search = 0;
    cout << "Valor procurado =";
    cin >> search;
    int result = intQueue_search(queue, search);
    if (result > -1) {
        cout << "Valor encontrado na fila | Posicao: (" << result << ")" << "!" << endl;
    } else {
        cout << "O valor digitado nao existe na fila!" << endl;
    }
    delete[] queue->data;
    delete queue;
    getchar();
    close();
}

ref_intQueue intQueue_merge(ref_intQueue p, ref_intQueue q) {
    ref_intQueue result = new intQueue;
    result->length = 0;
    result->data = new int[(p ? p->length : 0) + (q ? q->length : 0)];
    int i = 0, j = 0;
    while ((p && i < p->length) || (q && j < q->length)) {
        if (p && i < p->length) {
            bool exists = false;
            for (int k = 0; k < result->length; ++k) {
                if (result->data[k] == p->data[i]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                result->data[result->length++] = p->data[i];
            }
            i++;
        }
        if (q && j < q->length) {
            bool exists = false;
            for (int k = 0; k < result->length; ++k) {
                if (result->data[k] == q->data[j]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                result->data[result->length++] = q->data[j];
            }
            j++;
        }
    }
    return result;
}


void ex17E1()
{
    cout << "\nExercicio 17E1:\n\n";
    ref_intQueue queue1 = nullptr;
    ref_intQueue queue2 = nullptr;
    queue1 = intQueue_push(queue1, 10);
    queue1 = intQueue_push(queue1, 20);
    queue1 = intQueue_push(queue1, 30);
    queue2 = intQueue_push(queue2, 20);
    queue2 = intQueue_push(queue2, 40);
    queue2 = intQueue_push(queue2, 50);
    cout << "Fila 1: ";
    printQueue(queue1);
    cout << "Fila 2: ";
    printQueue(queue2);
    ref_intQueue mergedQueue = intQueue_merge(queue1, queue2);
    cout << "Fila intercalada:";
    printQueue(mergedQueue);
    delete[] mergedQueue->data;
    delete mergedQueue;
    delete[] queue1->data;
    delete queue1;
    delete[] queue2->data;
    delete queue2;
    close();
}


ref_intQueue intQueue_mergeUp(ref_intQueue p, ref_intQueue q) {
    ref_intQueue result = new intQueue;
    result->length = 0;
    result->data = new int[(p ? p->length : 0) + (q ? q->length : 0)];
    int i = 0, j = 0;
    while((p && i < p->length) || (q && j < q->length)){
        int value;
        if(p && i < p->length && (!q || j >= q->length || p->data[i] < q->data[j])){
            value = p->data[i++];
        } else if (q && j < q->length && (!p || i >= p->length || q->data[j] < p->data[i])){
            value = q->data[j++];
        }else{
            value = p->data[i++];
            j++;
        }
        if(result->length == 0 || result->data[result->length - 1] != value){
            result->data[result->length++] = value;
        }
    }

    return result;
}


void ex17E2() {
    cout << "\nExercicio 17E2:\n\n";
    ref_intQueue queue1 = nullptr;
    ref_intQueue queue2 = nullptr;
    queue1 = intQueue_push(queue1, 10);
    queue1 = intQueue_push(queue1, 30);
    queue1 = intQueue_push(queue1, 50);
    queue2 = intQueue_push(queue2, 20);
    queue2 = intQueue_push(queue2, 30);
    queue2 = intQueue_push(queue2, 60);
    cout << "Fila 1: ";
    printQueue(queue1);
    cout << "Fila 2: ";
    printQueue(queue2);
    ref_intQueue mergedQueue = intQueue_mergeUp(queue1, queue2);
    cout << "Fila mesclada em ordem crescente (sem duplicatas): ";
    printQueue(mergedQueue);
    delete[] mergedQueue->data;
    delete mergedQueue;
    delete[] queue1->data;
    delete queue1;
    delete[] queue2->data;
    delete queue2;
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
            ex1711();
            break;
        case 2:
            ex1712();
            break;
        case 3:
            ex1713();
            break;
        case 4:
            ex1714();
            break;
        case 5:
            ex1715();
            break;
        case 6:
            ex1716();
            break;
        case 7:
            ex1717();
            break;
        case 8:
            ex1718();
            break;
        case 9:
            ex1719();
            break;
        case 10:
            ex1720();
            break;
        case 11:
            ex17E1();
            break;
        case 12:
            ex17E2();
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
