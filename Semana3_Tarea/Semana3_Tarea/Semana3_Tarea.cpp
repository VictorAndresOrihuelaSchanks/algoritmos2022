#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo* sig;
    size_t cantidad;
};

void Insertar(Nodo*&, int);
void Mostrar(Nodo*);
void BuscarPar(Nodo*);
void BuscarElemento(Nodo*, int);
void obtenerPos(Nodo*, int);
void eliminar_posicion(Nodo*, int);
void Eleminar_Final(Nodo*);

Nodo* lista = NULL;

int main()
{
    int opc, e;
    do
    {
        cout << "             MENU                 " << endl;
        cout << "1. Insertar en la lista           " << endl;
        cout << "2. Mostrar elementos de la lista  " << endl;
        cout << "3. Buscar elemento pares          " << endl;
        cout << "4. Buscar posicion por elemento   " << endl;
        cout << "5. Obtener objeto en posicion     " << endl;
        cout << "6. eliminar en posicion           " << endl;
        cout << "7. eliminar al final" << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "Digite un elemento: " << endl;
            cin >> e;
            Insertar(lista, e);
            break;
        case 2:
            Mostrar(lista);
            cout << endl;
            system("pause");
            break;
        case 3:
            cout << "Mostrar solo elementos pares: ";
            BuscarPar(lista);
            cout << endl;
            system("pause");
            break;
        case 4:
            cout << "Digite un elemento: ";
            cin >> e;
            BuscarElemento(lista, e);
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "Ingrese el valor del objecto que desea buscar su posicion:";
            cin >> e;
            obtenerPos(lista,e);
            cout << endl;
            system("pause");
            break;
        case 6:
            cout << "Ingrese la posicion que desea eliminar:";
            cin >> e;

            eliminar_posicion(lista, e);
            system("pause");
            break;
        case 7:
            cout << "Nodo final eliminado...\n\nPresione cualquier tecla para continuar";
            Eleminar_Final(lista);
            break;
        }

        system("cls");
    } while (opc != 5);
}
void BuscarPar(Nodo* lista)
{
    Nodo* act = new Nodo();
    act = lista;

    while (act != NULL)
    {
        if (act->dato % 2 == 0)
        {
            cout << act->dato << "  ";
        }
        act = act->sig;
    }

}
void BuscarElemento(Nodo* lista, int n)
{
    Nodo* act = new Nodo();
    act = lista;
    int cant = 1;
    bool b = false;

    while (act != NULL)
    {
        if (act->dato == n)
        {
            b = true;
            cout << "Elemento encontrado: " << n << " en la posicion " << cant << endl;
        }
        cant++;
        act = act->sig;
    }

}
void Insertar(Nodo*& lista, int n)
{
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo* aux1 = lista;
    Nodo* aux2 = 0;

    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->sig = nuevo_nodo;
    }
    nuevo_nodo->sig = aux1;
    cout << "Elemento: " << n << " guardado" << endl;
  
}
void Mostrar(Nodo* lista)
{
    Nodo* act = new Nodo();
    act = lista;

    while (act != NULL)
    {
        cout << act->dato << " ";
        act = act->sig;
    }
}




//2-eliminar en posicion(n) - Trabajar tambien
void eliminar_posicion(Nodo* lista, int pos) {
    Nodo* act = new Nodo();
    Nodo* act2 = new Nodo();
    act = lista;
    int cant = 1;
    int cont = 0;


    while (act != NULL)
    {
        cont++;
        if (cont == pos)
        {
            act2 = act->sig; 
            act->sig = NULL;
        }
        cant++;
        act->sig = act2;
        act = act->sig;//hasta el numero pos

    }
    lista = act;

}


//Trabajar en esto
void obtenerPos(Nodo* lista,int pos) {//1-obtener objeto en posicion = at()

    Nodo* aux2 = new Nodo();
    size_t contador = 0;

    Nodo* aux = lista;

    while (aux != nullptr) {
        contador++;
        aux=aux->sig;
            while (contador <= pos) {
                aux2 = aux;
                aux2 = aux2->sig;
            }
    }

    cout << "El valor del elemento del nodo en la posicion " << pos << " es: " << aux2->dato;
}
void Eleminar_Final(Nodo* lista) {
    Nodo* aux2 = new Nodo();
    size_t contador = 0;

    Nodo* aux = lista;

    while (aux != nullptr) {
        contador++;
        if (aux->sig=NULL)
        {

        }
    }

};