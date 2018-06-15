#include <iostream>
#include <fstream>
#include <string>
#include "expressao_validador.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "Bem vindo ao IEMANJÁ !!" << endl;

	string teste;
	ifstream in_file("../tests/teste.txt");

	ExpressaoValidador expressao;

	while(!in_file.eof())
	{
		getline(in_file, teste);

		if(expressao.validar(teste))
			cout << "Expressao " << teste << " ok!" << endl;
	}

	return 0;
}
