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
	bool validarCaractere();
	bool validarFormacao();
	bool validarParenteses();
	bool validarExpressao();

};

#endif
