#include<string>
#include<iostream>
#include<cctype>
#include<stack>
#include "expressao_validador.h"

using namespace std;

ExpressaoValidador::ExpressaoValidador(string exp): expressao(exp){}

ExpressaoValidador::~ExpressaoValidador(){}

// Método que irá fazer todas as verificações, através de métodos estáticos da classe
bool ExpressaoValidador::Validar()
{
	if(!ValidarCaractere(expressao))
	 	return false; //Ta dndo erro aqui não para!!
	if(!ValidarFormacao(expressao))
		return false;
	if(!ValidarParenteses(expressao))
		return false;
	if(!ValidarExpressao(expressao))
		return false;

	return true; 
}

//Método que irá verficar os caracteres.
//Se encontrar algum invalido exibirá mensagem de erro e retornará false, senão, retornará true.
bool ExpressaoValidador::ValidarCaractere(string expressao)
{
	for (unsigned i = 0; i<expressao.length();)
	{
		if(isdigit(expressao[i]) || isspace(expressao[i]) || expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/' || expressao[i]=='^' || expressao[i]=='(' || expressao[i]==')' || expressao[i]=='.')
			i++;
		else
		{
			cout<< "Erro 1: Caracter invalido encontrado na posição "<<i+1<< " da expressão "<<expressao<<endl;
			return false; 
		}
	}
	return true;
}

bool ExpressaoValidador::ValidarFormacao(string expressao)
{
	cout<<expressao<<endl;
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
				cout<<"Erro 3: Os parênteses da expressão estão desbalanceados"<<endl;
				return false;
			}
			else
				parenteses.pop();
		}
	}
		if(!parenteses.empty())
		{
			cout<<"Erro 3: Os parênteses da expressão estão desbalanceados"<<endl;
			return false;
		}
		else	
			return true;
}

bool ExpressaoValidador::ValidarExpressao(string expressao)
{
	cout<<expressao<<endl;
	return true;
}
