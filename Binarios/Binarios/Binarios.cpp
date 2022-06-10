#include <iostream>

#include <functional>

using namespace std;

template <class T>

class Tree {

	template <class T>

	class Node {//inner class

	public:

		Node<T>* l;

		Node<T>* r;

		T e;

		Node(T e) { r = l = nullptr; this->e = e; }

	};

	Node<T>* root;

	function<bool(T, T)> compare;

	function<void(T)> fprint;

public:

	Tree(function<bool(T, T)> compare, function<void(T)> fprint) {

		this->compare = compare;

		this->fprint = fprint;

		root = nullptr;

	}

	void add(T e, Node<T>*& tmp) {

		if (tmp == nullptr)

			tmp = new Node<T>(e);

		//else if (e >= root->e) 	add(e, tmp->r);//inserta por la derecha

		else if (compare(e, root->e))

			add(e, tmp->r);//inserta por la derecha

		else add(e, tmp->l);//inserta por la izquierda

	}

	void print(Node<T>* tmp) {//recorrido en orden

		if (tmp == nullptr)return;

		print(tmp->l);//recursivamente a la izquierda

		//std::cout << tmp->e<<"-";//imprimes el valor

		fprint(tmp->e);

		print(tmp->r);//recursivamente a la derecha

	}

	void add(T e) {

		add(e, root);

	}

	void print() {

		print(root);

	}

};

int main() {

	auto compara = [](int a, int b) {return a >= b; };

	auto imprime = [](int a) {cout << a << " "; };

	Tree<int> enteros(compara, imprime);

	for (size_t i = 0; i < 10000; ++i)

		enteros.add(rand() % 300000);

	enteros.print();

	return 0;

}

/*

Asignación:

* probar la inserción de elementos numericos aleatorios, 10^6 registros.

* aplicar un lambda de comparación, éste debe ser enviado por el constructor

* aplicar un lambda de impresion, éste debe ser enviado por el constructor

* probar la inserción e impresión de 10 objetos de cualquier tipo de dato compuesto.


APARTE:
buscar valor dentro del arbol

crear un puntero a funcion para metodos de comparación

determinar el menor y mayor valor del arbol

calcular la altura del arbol(cantidad mayor de ramas desde la raiz hasta el ultimo nodo)

calcular la profundidad del arbol(cantidad mayor de nodos desde la raiz hasta el ultimo nodo==altura+1)

determinar el subarbol a partir de un nodo

eliminar por valor
*/