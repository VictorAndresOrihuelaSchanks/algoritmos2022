#pragma once

template <typename G>
class Nodo
{
public:
    Nodo<G>* sig;
    G elemento;
    Nodo(G elemento) {
        sig = nullptr;
        this->elemento = elemento;
    }


};


template<class G>
class Cola
{
public:
    Node<G>* inicio;
    Nodo<G>* fin;
    size_t cantidad;
    Cola() {
        inicio = fin = nullptr;
        cantidad = 0;
    }
    void pushcola(G g) {
        Nodo<G>* nuevo = new Nodo<G>(g);
        if (cantidad == 0) {
            inicio = nuevo;
            fin = nuevo;
        }
        else {
            fin->sig = nuevo;
            fin = nuevo;
        }
        cantidad++;
    }
    G obtenerinicio() {
        G aux = inicio->elemento;
        inicio = inicio->sig;
        return aux;
    }
};