#include <iostream>

using namespace std;

class PrioridadTareas
{
public:
	PrioridadTareas();
	~PrioridadTareas();
	void setnum(int num);
	void settarea(string tarea);
	int getnum();
	string gettarea();
    void radix_sort(PrioridadTareas arr);
private:
	int num;
	string tarea;
    int cont;
};
void PrioridadTareas::setnum(int num) {
	this->num = num;
    this->cont++;
}
void PrioridadTareas::settarea(string tarea) {
	this->tarea = tarea;
}
int PrioridadTareas::getnum() {
	return this->num;
}
string PrioridadTareas::gettarea() {
	return this->tarea;
}
PrioridadTareas::PrioridadTareas()
{
}

PrioridadTareas::~PrioridadTareas()
{
}

