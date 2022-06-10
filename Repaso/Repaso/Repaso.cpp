#include <iostream>

#include <functional>

using namespace std;

class Demo {

	int a, b;

	//function<void(int, int)> f;//atributo de clase

	void(*f)(int, int);

public:

	//Demo(function<void(int, int)> f):f(f) {}//inicializo la funci?n por parametro

	Demo(void(*f)(int, int)) :f(f) {}//inicializo la funci?n por parametro

	void procesar() {

		a = 20; b = 10;

		f(a, b);

	}

};

int main() {



	Demo a([](int x, int y) {cout << x + y; });

	a.procesar();

	return 0;



}