#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;
#define size 100

struct infoalumno {
	char nombre[50];
	char carnet[10];
	char telefono[9];
	char direccion[50];
	int esAlta;
};
typedef struct infoalumno alumno;

struct tipotabla
{
	alumno* tabla[size];
	int elementos;
	double factorcarga;
};
typedef struct tipotabla tabladispersa;

void CrearTabla(tabladispersa*);
void insertar(tabladispersa*, alumno);
alumno* buscar(tabladispersa*, char*);
int eliminar(tabladispersa*, char*);
long transforma(char*);
int direccion(tabladispersa*, char*);
void flush();

main() {
	int  op, res, i, p;
	char clave[50];
	alumno datos, * prt;
	tabladispersa tabla[size], n;
	CrearTabla(tabla);
	system("cls");
	while (1) {
		cout << "MENU";
		cout << "\nSeleccione la operacion a realizar:\n";
		cout << "\n1.Insertar Elemento \t 2.Buscar un elemento";
		cout << "\n3-Eliminar un elemento \t 4-Salir\n";
		cout << "\n\nDigite una Opcion: ";
		scanf("%d", &op);
		switch (op) {
		case 1:
			system("cls");
			puts("\nNombre del estudiante: ");
			flush();
			gets(datos.nombre);
			puts("\nCarnet del estudiante:");
			flush();
			gets(datos.carnet);
			puts("\nNo de telefono del estudiante: ");
			flush();
			gets(datos.telefono);
			puts("\nDireccion del estudiante:");
			flush();
			gets(datos.direccion);

			p = direccion(tabla, datos.carnet);
			printf("\n\nLa clave hash generada es: %d", p);
			puts("\nInsercion exitosa!n");
			insertar(tabla, datos);
			break;
		case 2:
			system("cls");
			puts("\nIntroduzca el carnet del estudiante que desea buscar");
			flush();
			scanf("%s", &clave);
			if (prt)
			{
				system("cls");
				puts("\n\tDatos del estudiante:n");
				cout << ("\nNombre: %sn", prt->nombre);
				cout << ("\nCarnet %sn", prt->carnet);
				cout << ("\nNo de telefono %sn", prt->telefono);
				cout << ("\nDireccion: %sn", prt->direccion);
			}
			else
			{
				puts("nNo existe ese estudiante en este registronn");
			}break;
			
		case 3:
			system("cls");
			puts("nDigite el dato a eliminar de la tabla:");
			flush();
			scanf("%s", &clave);
			i = eliminar(tabla, clave);
			if (i!=1)
			{
				puts("nElimnacion con exiton");
			}
			else
			{
				puts("nError en la eliminacionn");
			}
			break;
		case 4:
			exit(0);
			break;
		}getch();
		return 0;
		}
	
}

void CrearTabla(tabladispersa* t) {
	int j;
	for (j = 0; j < size; j++)
	{
		t->tabla[j] == NULL;
	}
	t->elementos = 0;
	t->factorcarga = 0.0;
}
long transforma(char* clave) {
	int j;
	long d = 0;
	for ( j = 0; j < strlen(clave); j++)
	{
		d = d * 27 + clave[j];
	}
	return((d >= 0) ? d : -d);
}
int direccion(tabladispersa* t, char* clave) {
	int i = 0;
	long p, d;
	d = transforma(clave);
	p = d % size;
	while (t->tabla[p] != NULL && strcmp(t->tabla[p]->carnet, clave) != 0) {
		i++;
		p = p + i * i;
		p = p % size;
	}
	return (int)p;
}