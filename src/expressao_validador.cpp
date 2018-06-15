#include <string>
#include <iostream>
#include <cctype>
#include <stack>
#include "expressaovalidador.h"

using namespace std;

ExpressaoValidador::ExpressaoValidador(string exp): expressao(exp){}

ExpressaoValidador::~ExpressaoValidador(){}

// Método que irá fazer todas as verificações, através de métodos estáticos da classe
bool ExpressaoValidador::Validar()
{
	if(!ValidarCaractere(expressao))
	 	return false; 
	if(!ValidarFormacao(expressao))
		return false;
	if(!ValidarParenteses(expressao))
		return false;
	if(!ValidarExpressao(expressao))
		return false;

	return true; 
}

// Método que irá verficar os caracteres.
// Se encontrar algum invalido exibirá mensagem de erro e retornará false, senão, retornará true.
bool ExpressaoValidador::ValidarCaractere(string expressao)
{
	for (unsigned i = 0; i<expressao.length();)
	{
		if(isdigit(expressao[i]) || isspace(expressao[i]) || expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/' || expressao[i]=='^' || expressao[i]=='(' || expressao[i]==')' || expressao[i]=='.')
			i++;
		else
		{
			cout << "Erro 1: Caracter invalido encontrado na posição " << i+1 << " da expressão " << expressao << endl;
			return false; 
		}
	}
	return true;
}

// Método que irá verficar a formação dos números.
// Se encontrar alguma invalida exibirá mensagem de erro e retornará false, caso não, retornará true.
// Vou verificando de caractere a caractere da expressão, caso tenha seja numéro ou ponto coloco na string numeros
// Caso seja um espaço ou operando e a string numero não estiver vazia, significa que já encontrei um número
// Percorro essa string numeros para verificar sua formação, utilizei as possiblidades que não devem acontecer através dos pontos
// Se existir caractere ponto no começo ou fim já exibo mensagem de erro
// Caso só exista o ponto incremento em uma auxiliar de quantidade de pontos
// Assim, se no final da verficação daquela string tiver mais que um ponto também exibo erro, seria o caso de ter dois pontos no meio do número
// Caso passe por tudo, retorno verdadeiro
bool ExpressaoValidador::ValidarFormacao(string expressao)
{
	string numeros = "";
	int qtdPontos = 0;
	int posicao;

	for (unsigned int i = 0; i < expressao.length(); i++)
	{
		if(isdigit(expressao[i]) || expressao[i] == '.')
			numeros += expressao[i];
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
							posicao = ((expressao.length() - (expressao.length() - i)) - numeros.size() + 1);
							cout << "Erro 2: Número inválido encontrado a partir da posição " << posicao << " da expressão " << expressao << endl;
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
						posicao = ((expressao.length() - (expressao.length() - i)) - numeros.size() + 1);
						cout << "Erro 2: Número inválido encontrado a partir da posição " << posicao << " da expressão " << expressao << endl;
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

bool ExpressaoValidador::ValidarParenteses(string expressao)
{
	stack<char> parenteses; 
	for (unsigned i = 0; i < expressao.length(); ++i)
	{
		if(expressao[i]=='(')
			parenteses.push(expressao[i]);
		if(expressao[i]==')')
		{
			if(parenteses.empty())
			{	
				cout << "Erro 3: Os parênteses da expressão estão desbalanceados" << endl;
				return false;
			}
			else
				parenteses.pop();
		}
	}
		if(!parenteses.empty())
		{
			cout << "Erro 3: Os parênteses da expressão estão desbalanceados" << endl;
			return false;
		}
		else	
			return true;
}

bool ExpressaoValidador::ValidarExpressao(string expressao)
{
	//cout<<expressao<<endl;
	return true;
}
