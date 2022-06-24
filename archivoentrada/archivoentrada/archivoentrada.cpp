// archivoentrada.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void lectura() {
    vector<int> enteros;
    ifstream i("input.txt");
    short x;
    while (i >> x) {
        if (x >= 150)
            enteros.push_back(x);
    }
    cout << enteros.size() << " ";
}
int main()
{
    int a = 10;
    int b = 6;
    return 0;
}

