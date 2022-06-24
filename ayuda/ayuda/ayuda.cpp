#include <iostream>

#include "Cola.h"

using namespace std;

int main() {
    Cola<int> numeros;
    numeros.pushcola(19);
    numeros.pushcola(18);
    numeros.pushcola(35);
    numeros.pushcola(24);
    numeros.pushcola(27);
    numeros.pushcola(28);
    cout << numeros.obtenerinicio();
    cout << numeros.obtenerinicio();
}