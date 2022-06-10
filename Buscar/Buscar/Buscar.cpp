template <class T>

class Ejemplo {

    T a;

    T b;

    function<int(T, T)> f;//funcion como atributo de clase

public:

    Ejemplo(T a, T b, function<int(T, T)> f) :a(a), b(b), f(f) {}

    int funcion2() {

        return f(a, b);

    }

};



int main() {

    Ejemplo<int> ejmEnteros(20, 10, [](int a, int b) {return a % b; });

    cout << ejmEnteros.funcion2() << endl;



    Ejemplo<string> ejmCadenas("Ana", "Fidel", [](string a, string b) {return a.compare(b); });

    cout << ejmCadenas.funcion2() << endl;

    return 0;

}