#include <iostream>
#include <string.h>
using namespace std;
class Alumno

{
public:
	Alumno();
	~Alumno();
	size_t GetC1();
	size_t GetC2();
	size_t GetC3();
	size_t GetC4();
	string Getnombre();
	void SetC1(int c1);
	void SetC2(int c2);
	void SetC3(int c3);
	void SetC4(int c4);
	void Setnombre(string nom);
private:
	string nombre;
	size_t C1, C2, C3, C4;
};

Alumno::Alumno()
{
}

Alumno::~Alumno()
{
}

size_t Alumno::GetC1() {
	return this->C1;
}
size_t Alumno::GetC2() {
	return this->C2;
}
size_t Alumno::GetC3() {
	return this->C3;
}
size_t Alumno::GetC4() {
	return this->C4;
}
string Alumno::Getnombre() {
	return this->nombre;
}
void Alumno::SetC1(int c1) {
	this->C1 = c1;
}
void Alumno::SetC2(int c2) {
	this->C2 = c2;
}
void Alumno::SetC3(int c3) {
	this->C3 = c3;
}
void Alumno::SetC4(int c4) {
	this->C4 = c4;
}
void Alumno::Setnombre(string nom) {
	this->nombre = nom;
}