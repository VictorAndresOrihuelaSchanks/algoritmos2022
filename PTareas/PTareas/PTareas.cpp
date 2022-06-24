#include "ArbolPrioridadez.h"

template<class T>
class Node {//inner class(composicion)
public:
	Node<T>* l, * r;
	T data;
	Node(T d) :data(d) { l = r = nullptr; }
};
Node<T>* root;

int main() {
	string tar;
	int num, op;
	PrioridadTareas Tarea;

	

			cout << "MENU\n 1. Agregar Tarea\n 2. Mostrar Tareas\n3. Salir\n\nRespuesta: "; cin >> op;
			system("cls");
			switch (op)
			{
			case 1:
				cout << "Ingrese Tarea: "; cin >> tar;
				Tarea.settarea(tar);
				cout << "Ingrese numero de prioridad del 1 a 10 (Mas alto el numero mas prioridad): "; cin >> num;
				Tarea.setnum(num);
				system("cls");

				Tree<int> enteros;
				enteros.insert(Tarea.getnum(),Tarea );






				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				break;
			}



	//enteros.print();
	return 0;
}








