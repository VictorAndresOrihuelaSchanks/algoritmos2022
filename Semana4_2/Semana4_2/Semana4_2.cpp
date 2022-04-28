#include <iostream>

#include <string>

#include <functional>

using namespace std;

template <class G>

class Nodo {

public://TODO private, get, set

    Nodo<G>* sig;

    Nodo<G>* ant;

    G elemento;

    Nodo(G elemento) {

        this->elemento = elemento;

        sig = ant = nullptr;

    }

};

template <class G>

class ListaDoble {

    Nodo<G>* inicio;

    Nodo<G>* fin;

    size_t cantidad;

public:

    ListaDoble() {

        inicio = fin = nullptr;

        cantidad = 0;

    }

    void push_front(G g) {

        Nodo<G>* nuevo = new Nodo<G>(g);

        if (cantidad == 0) {

            inicio = nuevo;

            fin = nuevo;

        }

        else {

            nuevo->sig = inicio;

            inicio->ant = nuevo;

            inicio = nuevo;

        }

        cantidad++;

    }

    void push_back(G g) {

        Nodo<G>* nuevo = new Nodo<G>(g);

        if (cantidad == 0)

            inicio = fin = nuevo;

        else {

            fin->sig = nuevo;

            nuevo->ant = fin;

            fin = nuevo;

        }

        cantidad++;

    }



    void print(function<void(G)> imprime) {//Qué

        Nodo<G>* aux = inicio;

        while (aux != nullptr) {

            imprime(aux->elemento);

            //cout << aux->elemento << " ";

            aux = aux->sig;

        }

        cout << "\n";

    }

};

class Juego {

public:// to private

    string nombre;

    unsigned short anho;

    Juego(string nombre = " ", unsigned short anho = 2022) :nombre(nombre), anho(anho) {}

    string toString() { return nombre + " " + to_string(anho); }

};

class Alumno {

public:// to private

    string nombre;

    Alumno(string nombre = " ") :nombre(nombre) {}

    string getNombre() { return nombre; }

};

int main() {

    ListaDoble<int> enteros;

    enteros.push_front(10);

    enteros.push_front(15);

    enteros.push_front(8);

    enteros.push_front(7);

    enteros.push_front(12);

    enteros.push_front(11);

    enteros.print([](int i) {cout << i << endl; });//cómo

    cout << endl;

    ListaDoble<Juego> juegos;

    juegos.push_back(Juego("Futbol", 1890));

    juegos.push_back(Juego("Basquet", 1930));

    juegos.push_front(Juego("XYZ", 1940));

    juegos.print([](Juego j) {cout << j.toString() << endl; });

    cout << endl;

    ListaDoble<Alumno> alumnos;

    alumnos.push_back(Alumno("Alex"));

    alumnos.push_back(Alumno("Fidel"));

    alumnos.push_back(Alumno("Joaquin"));

    alumnos.print([](Alumno a) {cout << a.getNombre() << endl; });

    cin.get();

}