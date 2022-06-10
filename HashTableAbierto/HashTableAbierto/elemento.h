#include <iostream>
class nodo
{
public:
	nodo();
	~nodo();
	void setvalue(int value);
	void setkey(int key);
	int getvalue();
	int getkey();
	int id( int key);
private:
	int value, key;
	size_t size =0;
};
void nodo::setvalue(int value) {
	this->value = value;
	this->size++;
}
void nodo::setkey(int key){
	this->key = key;
}
int nodo::getvalue() {
	return this->value;
}
int nodo::getkey() {
	return this->key;
}
int nodo::id( int key) {
	int id;
	id = key % this->size;
	return id;
}
nodo::nodo()
{
}

nodo::~nodo()
{
}