#ifndef EXPRESSAOVALIDADOR_H
#define EXPRESSAOVALIDADOR_H
#include "listacircular.h"

#include <string>

#include "stack.h"

using namespace std;
using namespace myTads;

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
