#include <iostream>
#include <string>
#include <vector>
#include <functional>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::function;
using std::vector;
using std::to_string;

typedef unsigned short us;

namespace Ejercicio3 {
    template <typename T>


    class matri2D {
    private:
        T* dato;

    public:
        //Constructor
        matri2D(T dato) {
            this->dato = dato;
        }

        //Métodos
        void insertar(T dato) {
            dato.push_back(dato);
        }

        void mostrar(T dato) {
            cout << dato << endl;
        }
        /*
        T poblar() {}
        T buscar() {}
        */
    };

    void test() {
        typedef matri2D<int> Template;
        Template->insertar(10);
        //Template->mostrar(10);
    }
}

int main() {
    Ejercicio3::test();
}