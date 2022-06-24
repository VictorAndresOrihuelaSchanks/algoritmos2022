#include <iostream>

using namespace std;

char opc;
char volver;
char valor;

struct nodo {
	int numero;
	struct nodo* sgte;
	struct arista* ady;
};

typedef struct nodo* Tnodo;
Tnodo puntero;

struct arista {
	struct nodo* destino;
	struct arista* sgte;
};

typedef struct arista* Tarista;

void insertar_nodo() {
	Tnodo t, nuevo = new struct nodo;
	cout << "Ingrese un numero para el nodo:" << endl;
	cin >> nuevo->numero;
	nuevo->sgte = NULL;
	nuevo->ady = NULL;

	if (puntero == NULL) {
		puntero = nuevo;
		cout << "Nodo ingresado" << endl;
	}
	else {
		t = puntero;
		while (t->sgte != NULL) {
			t = t->sgte;
		}
		t->sgte = nuevo;
		cout << "Nodo ingresado" << endl;
	}
}

void agregar_arista(Tnodo& aux, Tnodo& aux2, Tarista& nuevo) {
	Tarista q;
	if (aux->ady == NULL) {
		aux->ady == nuevo;
		nuevo->destino = aux2;
	}
	else {
		q = aux->ady;
		while (q->sgte != NULL) {
			q = q->sgte;
		}
		nuevo->destino = aux2;
		q->sgte = nuevo;
		cout << "Arista ingresada" << endl;
	}
}

void ingrese_arista() {
	int ini, fin;
	Tarista nuevo = new struct arista;
	Tnodo aux, aux2;

	if (puntero == NULL) {
		cout << "No hay Grafo" << endl;
		return;
	}

	nuevo->sgte = NULL;
	cout << "ingrese el nodo de inicio:" << endl;
	cin >> ini;
	cout << "ingrese el nodo final:" << endl;
	cin >> fin;

	aux = puntero;
	aux2 = puntero;

	while (aux2 != NULL) {
		if (aux2->numero == fin) {
			break;
		}
		aux2 = aux2->sgte;
	}
	while (aux != NULL) {
		if (aux->numero == ini) {
			agregar_arista(aux, aux2, nuevo);
			return;
		}
		aux = aux->sgte;

	}
}



void mostrar_grafo() {
	Tnodo ptr;
	Tarista ar;

	ptr = puntero;
	cout << "Nodo : Adyacencia" << endl;

	while (ptr != NULL) {
		cout << "   " << ptr->numero << " : ";
		if (ptr->ady != NULL) {
			ar = ptr->ady;

			while (ar != NULL) {
				cout << "  " << ar->destino->numero;
				ar = ar->sgte;
			}
		}
		ptr = ptr->sgte;
		cout << endl;
	}
}

void mostrar_arista() {
	Tnodo aux;
	Tarista ar;
	int var;
	cout << "Mostrar arista del nodo" << endl;
	cout << "Ingrese nodo:" << endl;;
	cin >> var;

	aux = puntero;
	while (aux != NULL) {
		if (aux->numero == var) {
			if (aux->ady == NULL) {
				cout << "El nodo no tiene Aristas" << endl;
				return;
			}
			else {
				cout << "Nodo: Adyacencia" << endl;
				cout << "     " << aux->numero << "/";
				ar = aux->ady;

				while (ar != NULL) {
					cout << ar->destino->numero << " ";
					ar = ar->sgte;
				}
				cout << endl;
				return;
			}

		}
		else {
			aux = aux->sgte;
		}
	}

}

int crear_menu() {
	cout << "** Administracion de Grafos **" << endl;
	cout << "** Dijite el numero de la accion que desea realizar **" << endl;
	cout << "1. Insertar Nodo. " << endl;
	cout << "2. Ingrese Arista." << endl;
	cout << "3. Mostrar Grafo" << endl;
	cout << "4. Mostrar Arista " << endl;
	cout << "5. Salir" << endl;
}



int main() {
	puntero = NULL;

	volver = 's';
	while (volver == 's') {
		crear_menu();
		cin >> opc;

		switch (opc) {
		case '1':
			insertar_nodo();
			break;

		case '2':
			ingrese_arista();
			break;
		case '3':
			mostrar_grafo();
			break;
		case '4':
			mostrar_arista();
			break;
		case '5':
			cout << "salir" << endl;
			return 0;
			break;

		default:
			cout << "opcion no valida" << endl;

		}
		cout << "para volver al menu principal dijite s/n";
		cin >> volver;
	}
	return 0;
}