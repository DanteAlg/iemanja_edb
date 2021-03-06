//Implentação dos métodos da classe expressao_validador
#include <iostream>
#include "expressao_validador.h"

using namespace std;
using namespace minhasTads;

//Construtor padrão
ExpressaoValidador::ExpressaoValidador(){}

//Destrutor padrão
ExpressaoValidador::~ExpressaoValidador(){}

// Método que irá fazer todas as verificações, através de métodos da classe
bool ExpressaoValidador::validar(string _expressao)
{
	expressao = _expressao;
	expressao_tam = expressao.size();

	return (validarCaractere() && validarFormacao() &&
			validarParenteses() && validarExpressao());
}

// Método que irá verficar os caracteres.
// Se encontrar algum invalido exibirá mensagem de erro e retornará false, senão, retornará true.
bool ExpressaoValidador::validarCaractere()
{
	for (unsigned i = 0; i < expressao_tam; i++)
	{
		if (!(isdigit(expressao[i]) || isspace(expressao[i]) || expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/' || expressao[i]=='^' || expressao[i]=='(' || expressao[i]==')' || expressao[i]=='.'))
		{
			cout << "Erro 1: Caracter invalido encontrado na posição " << i+1 << "!" <<  endl<<endl;
			return false;
		}
	}
	return true;
}

// Método que irá verficar a formação dos números.
// Se encontrar alguma invalida exibirá mensagem de erro e retornará false, caso não, retornará true.
// Vou verificando de caractere a caractere da expressão, caso tenha seja numéro ou ponto coloco na string numeros
// Caso seja ponto e esteja no final da expressão já exibo mensagem de erro
// Caso seja um espaço ou operando e a string numero não estiver vazia, significa que já encontrei um número
// Percorro essa string numeros para verificar sua formação, utilizei as possiblidades que não devem acontecer através dos pontos
// Se existir caractere ponto no começo ou fim já exibo mensagem de erro
// Caso só exista o ponto incremento em uma auxiliar de quantidade de pontos
// Assim, se no final da verficação daquela string tiver mais que um ponto também exibo erro, seria o caso de ter dois pontos no meio do número
// Caso passe por tudo, retorno verdadeiro
bool ExpressaoValidador::validarFormacao()
{
	string numeros = "";
	int qtdPontos = 0;
	int posicao;

	for (unsigned int i = 0; i < expressao_tam; i++)
	{
		if(isdigit(expressao[i]) || expressao[i] == '.')
		{
			numeros += expressao[i];
			if(expressao[i] == '.' && i == expressao_tam-1)
			{
				posicao = (expressao_tam - numeros.size() + 1);
				cout << "Erro 2: Número inválido encontrado a partir da posição " << posicao << "!"<<endl<<endl;
			    return false;
			}
		}
		else
		{
			if(isspace(expressao[i]) || expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/' || expressao[i]=='^' || expressao[i]=='(' || expressao[i]==')')
			{
				if(numeros != "")
				{
					for (unsigned int j = 0; j < numeros.size(); j++)
					{
						if(numeros[j] == '.' && (j == 0 || j == numeros.size()-1))
						{
							posicao = ((expressao_tam - (expressao_tam - i)) - numeros.size() + 1);
							cout << "Erro 2: Número inválido encontrado a partir da posição " << posicao << "!"<<endl<<endl;
			    			return false;
						}
						else
						{
							if(numeros[j] == '.')
								qtdPontos++;
						}
					}

					if(qtdPontos > 1)
					{
						posicao = ((expressao_tam - (expressao_tam - i)) - numeros.size() + 1);
						cout << "Erro 2: Número inválido encontrado a partir da posição " << posicao << "!"<<endl<<endl;
						return false;
					}

					numeros = "";
					qtdPontos = 0;
				}
			}
		}
	}

	return true;
}

//Método que irá verficar o balanceamento de parenteses
//Se encontrar parentese desbalanceado exibirá mensagem de erro e retornará false
//Senão retornará true
bool ExpressaoValidador::validarParenteses()
{
	pilha<char> parenteses;
	for (unsigned i = 0; i < expressao_tam; ++i)
	{
		if(expressao[i]=='(')
			parenteses.insere(expressao[i]);
		if(expressao[i]==')')
		{
			if(parenteses.vazia())
			{
				cout << "Erro 3: Os parênteses da expressão estão desbalanceados!" << endl<<endl;
				return false;
			}
			else
				parenteses.tira();
		}
	}
		if(!parenteses.vazia())
		{
			cout << "Erro 3: Os parênteses da expressão estão desbalanceados!" << endl<<endl;
			return false;
		}
		else
			return true;
}

// Método irá verificar se a forma infixa da expressão está correta
// Primeiramente retiro todos os espaços para facilitar a verficação
// Veerifico três situações que ocasiona erro na formação
// Primeira situação: ter operador no ínicio da expressão ou final
// Segunda situação: ter um operador no caracter anterior
// Terceira situação: ter um operador no caractere seguinte
// Essas duas últimas resulta em operadores seguidos na expressão, o que não é permitido
bool ExpressaoValidador::validarExpressao()
{
	string aux = expressao;

	for (auto i = aux.begin(); i != aux.end(); ++i)
	{
		if(std::isspace(*i))
			aux.erase(i--);
	}

	for (unsigned int i = 0; i < aux.length(); i++)
	{
		if((aux[i]=='+' || aux[i]=='-' || aux[i]=='*' || aux[i]=='/' || aux[i]=='^') && (i == 0 || i == aux.length() - 1))
		{
			cout << "Erro 4: Expressão infixa malformada!"<< endl<<endl;
			return false;
		}
		else
			if((aux[i]=='+' || aux[i]=='-' || aux[i]=='*' || aux[i]=='/' || aux[i]=='^') && (aux[i-1]=='+' || aux[i-1]=='-' || aux[i-1]=='*' || aux[i-1]=='/' || aux[i-1]=='^'))
			{
				cout << "Erro 4: Expressão infixa malformada!"<< endl<<endl;
				return false;
			}
			else
				if((aux[i]=='+' || aux[i]=='-' || aux[i]=='*' || aux[i]=='/' || aux[i]=='^') && (aux[i+1]=='+' || aux[i+1]=='-' || aux[i+1]=='*' || aux[i+1]=='/' || aux[i+1]=='^'))
				{
					cout << "Erro 4: Expressão infixa malformada!"<< endl<<endl;
					return false;
				}
	}

	return true;
}
