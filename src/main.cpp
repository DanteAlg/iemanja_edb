#include <iostream>
#include <fstream>
#include <string>

#include "expressao_validador.h"
#include "expressao_executor.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Bem vindo ao IEMANJÁ !!" << endl << endl;

	string teste;
	ExpressaoValidador ex_validador;
	ExpressaoExecutor ex_executor;

	// ifstream file(argv[1]);
	ifstream file("tests/teste.txt");

	if (file) {
		while(!file.eof())
		{
			getline(file, teste, '\n');

			if(ex_validador.validar(teste))
				cout << teste << " = " << ex_executor.resultado(teste) << endl;
		}
	}
	else
		cout << "Erro ao carregar o arquivo, verique a rota no parâmetro" << endl;

	return 0;
}
