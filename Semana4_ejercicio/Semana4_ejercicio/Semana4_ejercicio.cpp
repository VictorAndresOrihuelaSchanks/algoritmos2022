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

namespace Ejercicio1 {
    us tam = 1;
    void columnas(us cc, us t) {
        if (t == 0) return;
        cout << cc << " ";
        columnas(cc, t - 1);
    }

    void espacios(us cf) {
        if (cf == 0) return;
        cout << " ";
        espacios(cf - 1);

    }

    void filassup(us cf) {
        if (cf == 0) return;
        espacios(cf - 1);
        columnas(cf, tam++);
        cout << "\n";
        filassup(cf - 1);
    }

    void filasinf(us cf) {
        if (cf == 1) return;
        filasinf(cf - 1);
        espacios(cf - 1);
        columnas(cf, --tam);
        cout << endl;
    }

    void test() {
        us n = 5;
        filassup(n);
        --tam;
        filasinf(n);
    }
}

namespace Ejercicio2 {
    class Paciente {
    private:
        string nombre;
        us anio;

    public:
        Paciente(string nombre = " ", us anio = 2022) : nombre(nombre), anio(anio) {}
        string getnombre() { return nombre; }
        us getanio() { return anio; }
        string toString() { return nombre + " " + to_string(anio); }
    };

    class ListaPaciente {
    private:
        vector<Paciente> pacientes;

    public:
        void insertar(Paciente p) {
            pacientes.push_back(p);
        }

        void imprimir(function <bool(Paciente)> condicion) {
            for (size_t i = 0; i < pacientes.size(); i++) {
                if (condicion(pacientes[i])) {
                    cout << pacientes[i].toString() << endl;
                }
            }
        }
    };

    void test()
    {
        ListaPaciente registro;
        registro.insertar(Paciente("Miguel", 1980));
        //registro.insertar(Paciente("Luis", 2010));
        registro.imprimir([](Paciente p) { return true; });
    }
}

namespace Ejercicio3 {

}

int  main() {
    //Ejercicio1::test();
    Ejercicio2::test();
    //Ejercicio3::test();
}
