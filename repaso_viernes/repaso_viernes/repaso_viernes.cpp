// repaso_viernes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
template <class T>
class lista
{
    class Nodo {
    public:
        T value;
        Nodo* next;
        Nodo(T valor, Nodo* next = nullptr) : valor(valor), next(next) {}
    };
    Nodo* inicio;
    Nodo* final;
    unsigned long size;
    function<void(T)> mostrar;
public:
    List(function<void(T)> mostrar) : mostrar(mostrar) {
        inicio = fin = nullptr;
        size = 0;
    }
    ~List() {
        while (size > 0) {
            popFront();
        }
        inicio = fin = nullptr;
    }

    void print() {
        cout << "\n";
        if (size == 0) {
            cout << "No hay elementos";
            return;
        }
        _print(inicio);
    }
private:
    void _print(Node* n) {
        if (n == nullptr) return;
        mostrar(n->value);
        _print(n->next);
    }
public:
    void pushBack(T value) {
        if (size == 0) {
            Nodo* n = new Nodo(value);
            inicio = n;
            fin = n;
            ++size;
        }
        else {
            Nodo* n = new Nodo(value);
            fin->next = n;
            fin = n;
            ++size;
        }
    }

    unsigned long Size() {
        return size;
    }
    Nodo* insertInRange(function<void(T)> insert, int i, int f, Nodo* n) {
        size_t init = i;
        Nodo* aux = n;
        for (init; init <= f; ++init) {
            insert(aux->value);
            aux = aux->next;
        }
        return aux;
    }
};
int main() {
    lista *N;

}