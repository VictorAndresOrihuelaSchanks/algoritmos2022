// Tarea_semana4_Pilas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Pila {
private:
    static const int MAX = 3;
    int tope;
    int valores[MAX];
public:
    Pila() {
        tope = -1;
    }
    int isempty() {
        if (tope == -1) {
              return 1;
        }
        else return 0;
    }
    int isfull() {
        if (tope == MAX - 1) {
            return 1; 
        }
        else return 0;
    }
    void push_back(int v) {
        if (!isfull()) {
            valores[++tope] = v;
        }
        else {
            cout << "No es posible agregar un elemento" << endl; system("pause");
        }
    }
    int pop_back() {
        if (!isempty()) {
            return (valores[tope--]);
        }
        else {
            cout << "No es posible extraer un elemento" << endl; system("pause");
                return (0);
        }
    }
    int peek() {
        return valores[0];
    }
    void font() {
        cout << "TODOS LOS ELEMENTOS:" << endl;
        for (int i = 0; i < MAX; i++)
        {
            cout << i+1 << ". " << valores[i] << endl;
        }
        system("pause");
    }
    void clear() {
        cout << "TODOS LOS ELEMENTOS FUERON ELEMINADOS DE LA LISTA...";
        for (int i = 0; i < MAX; i++)
        {
           valores[i] = NULL;
        }
        system("pause");
    }
};
int main()
{//font clear
    Pila p;
    size_t opc;
    size_t n_elem;
    do 
    {
        cout << "MENU: \n1. Agrear elemento a la pila\n2. Comprobar si la pila esta llena\n3. Comprobar si la pila esta vacia\n4. Extraer ultimo elemento\n5. Ver Primer elemento\n6. Mostrar todos los elementos\n7. Borrar todos los elementos\n8. Salir\n\nRespuesta:";
        cin >> opc;
        switch (opc)
        {
        case 1:system("cls");
            cout << "Que elemento desea ingresar?\nRespuesta:";
            cin >> n_elem;
            p.push_back(n_elem);
            system("cls");
            break;
        case 2:
            system("cls");
            if (p.isfull() == 1)
            {
                cout << "La pila esta llena...\n\n"; system("pause");
            } 
            else 
            {
                cout << "La pila no esta llena...\n\n"; system("pause");
            }
      
            system("cls");
            break;
        case 3:
            system("cls");
            if (p.isempty() == 1)
            {
                cout << "La pila esta vacia...\n\n"; system("pause");
            }
            else
            {
                cout << "La pila no esta vacia...\n\n"; system("pause");
            };
  
            system("cls");
            break;
        case 4:
            system("cls");
            p.pop_back();
            cout << "Ultimo elemento extraido exitosamente";
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
          cout << "El primer valor es: " <<  p.peek() <<endl;
          system("pause");
          system("cls");
          break;
        case 6:
            system("cls");
            p.font();
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            p.clear();
            system("pause");
            system("cls");
            break;
        default:
            break;
        }
    } while (opc != 8);
    
    return 0;
   /* p.push(1);
    p.push(2);
    p.push(3);
    int x = p.pop();
    if (x!=0)
    {
        cout << x << endl;
    }
    system("PAUSE");
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
