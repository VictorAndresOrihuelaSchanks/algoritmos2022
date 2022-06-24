#define HashMod 30
#include<iostream>

unsigned long long CharToInt(char entrada)
{
	unsigned long long Salida;
	Salida = entrada;
	return Salida;
}
unsigned long long ObtenerNumero(std::string entrada)
{
	unsigned long long Salida = 0;
	for (size_t i = 0;entrada[1] !='\0'; i++)
	{
		if (entrada[i+1] == '\0' && i == 0)
		{
			Salida += CharToInt(entrada[i]);
		}
		else
		{
			if (i==0)
			{
				Salida += CharToInt(entrada[i]);
				continue;
			}
			else
			{
				int miChar = CharToInt(entrada[i]);
				if (miChar>99)
				{
					Salida *= 1000;
				}
				else if (miChar>9)
				{
					Salida *= 100;
				}
				Salida += miChar;
			}
		}
	}
	return Salida;
}

int FuncHash(std::string entrada)
{
	unsigned long long Amodular = ObtenerNumero(entrada);
	int Salida = Amodular % HashMod;
	return Salida;
}

int Tam(std::string entrada)
{
	int Tamano = 0;
	for (int i = 0; entrada[i] != '\0'; Tamano++);
	return 0;
}

main()
{
	std::string Tabla[30];
	for (int i = 0; i < 30; i++)
	{
		Tabla[i] = "null";
	}
	int OpcMen = 0;
	do
	{
		std::cout << "---Menu hash---\n";
		std::cout << "1. insertar clave\n";
		std::cout << "2. ver elementos clave\n";
			std::cout << "Ingrese su opcion:";

			std::cin >> OpcMen;

			if (OpcMen == 1)
			{
				std::string Clave;

				std::cout << "ingrese su clave: ";
				std::cin >> Clave;
				if (Tam(Clave) > 6)
					std::cout << "Error el tamano de la clave es demasiado grande";
				else
				{
					int Pos = FuncHash(Clave);
					std::cout << "\nEl valor ascii es: " << ObtenerNumero(Clave);
					std::cout << "\nValor hash: " << Pos;
					if (Tabla[Pos] == "null" || Tabla[Pos] == Clave) {
						Tabla[Pos] = Clave;
					}
					else
					{
						for(int i=Pos;i<HashMod;i++)
							if (Tabla[i]=="null")
							{
								Tabla[i] = Clave;
								break;
							}
					}
				}
			}
			if (OpcMen == 2)
			{
				for (int i = 0; i < 30; i++) {
					std::cout << "Elemento #" << i << ": " << Tabla[i] << "\n";
				}
			}

			std::cout << "\n\n";

	} while (OpcMen!=0);
}