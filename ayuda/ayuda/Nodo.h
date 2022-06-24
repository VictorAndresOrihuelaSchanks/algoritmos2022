#pragma once

template <typename G>
class Nodo
{
public:
    Nodo(G elemento) {
        sig = nullptr;
        this->elemento = elemento;
    }
    ~Nodo() {
    }

private:
    Nodo<G>* sig;
    G elemento;
};