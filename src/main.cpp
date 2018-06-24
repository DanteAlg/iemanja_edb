//Definição da função principal, exibindo o resultado das operações  
#include <iostream>
#include <fstream>
#include <string>

#include "expressao_validador.h"
#include "expressao_executor.h"

using namespace std;

// ./bin/iemanja caminho_do_arquivo
// Executa as validações e/ou operações em cada linha
// Caso seja a ultima linha (Linha em branco) não executa
int main(int argc, char const *argv[])
{
	cout << endl <<"Bem vindo ao IEMANJÁ !!" << endl << endl;

	string teste;
	ExpressaoValidador ex_validador;
	ExpressaoExecutor ex_executor;

	ifstream arquivo(argv[1]);

	if (arquivo) 
	{
		while(!arquivo.eof())
		{
			getline(arquivo, teste, '\n');

			if (teste != "") {
				cout << "Expressão " << teste << endl;

				if(ex_validador.validar(teste))
					cout << "Resultado = " << ex_executor.resultado(teste) << endl<<endl;
			}
		}
	
	}
	else
		cout << "Erro ao carregar o arquivo, verique a rota no parâmetro" << endl;

	return 0;
}
