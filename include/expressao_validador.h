#ifndef EXPRESSAOVALIDADOR_H
#define EXPRESSAOVALIDADOR_H

#include <string>

using namespace std;

class ExpressaoValidador
{
private:
	string expressao;

public:
	ExpressaoValidador() {};
	~ExpressaoValidador() {};

	bool validar(string _expressao);
	bool validar_caractere();
	bool validar_formacao();
	bool validar_parenteses();
	bool validar_expressao();

}; 

#endif
