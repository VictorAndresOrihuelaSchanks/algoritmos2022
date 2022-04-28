template <class G>

class Array {

	G* arr;

	long id;

	long size;

public:

	Array(long size = 10) :size(size), id(-1) {

		arr = new G[size];

	}

	void push_back(G v) {

		arr[++id] = v;

	}

	void swap(G* a, G* b)

	{

		G temp = *a;

		*a = *b;

		*b = temp;

	}

	void randomize()

	{

		srand(time(NULL));

		for (int i = id - 1; i > 0; i--)

		{

			int j = rand() % (i + 1);

			swap(&arr[i], &arr[j]);

		}

	}

	void iterate(function<void(G)> func)

	{

		for (int i = 0; i <= id; i++)

			func(arr[i]);

		printf("\n");

	}

};



struct Punto {

	short x, y;

	Punto(short x = 0, short y = 0) :x(x), y(y) {}

};



int main()

{

	Array<int> arrEnteros(10);

	for (int i = 0; i < 10; ++i) {

		arrEnteros.push_back(i);

	}

	arrEnteros.iterate([](int v) {printf("%d ", v); });

	arrEnteros.randomize();

	arrEnteros.iterate([](int v) {printf("%d ", v); });

	//-------------------------------------------------

	Array<Punto> arrPuntos(10);

	for (size_t i = 0; i < 10; ++i) {

		arrPuntos.push_back(Punto(i, i * 10));

	}

	arrPuntos.iterate([](Punto v) {printf("(%d,%d )", v.x, v.y); });

	arrPuntos.randomize();

	arrPuntos.iterate([](Punto v) {printf("(%d,%d )", v.x, v.y); });

	//-------------------------------------------------

	Array<string> arrNombre(10);

	for (size_t i = 0; i < 10; ++i) {

		string cadena;

		for (size_t i = 0; i < 8; ++i) {//crear la pseudo palabra

			char v = rand() % 26 + 65;

			string temp = string(1, v);

			cadena.append(temp);

		}

		arrNombre.push_back(cadena);

	}

	arrNombre.iterate([](string v) {printf("%s \n", v); });

	arrNombre.randomize();

	arrNombre.iterate([](string v) {printf("%s \n", v); });

	return 0;

}