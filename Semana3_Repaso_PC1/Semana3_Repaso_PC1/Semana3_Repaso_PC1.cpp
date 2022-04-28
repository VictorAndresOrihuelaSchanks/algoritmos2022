#include <functional>
#include <iostream>

using namespace std;

typedef unsigned short us;

namespace Ejercicio1
{

    us tam = 1;
    void columnas(us cc, us t)
    {
        if (t == 0) return;
        cout << cc << " ";
        columnas(cc, t - 1);
    }
    void espacios(us cf)
    {
        if (cf == 0) return;
        cout << " ";
        espacios(cf - 1);

    }
    void filassup(us cf)
    {
        if (cf == 0) return;
        espacios(cf - 1);
        columnas(cf, tam++);
        cout << "\n";
        filassup(cf - 1);
    }
    void filasinf(us cf)
    {
        if (cf == 1) return;
        filasinf(cf - 1);
        espacios(cf - 1);
        columnas(cf, --tam);
        cout << "\n";
    }

    void test()
    {
        us n = 5;
        filassup(n);
        --tam;
        filasinf(n);
    }

}
int  main()
{
    Ejercicio1::test();
}