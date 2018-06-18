//Definição da classe expressao_validador
#ifndef EXPRESSAOVALIDADOR_H
#define EXPRESSAOVALIDADOR_H

#include <string>
#include "listacircular.h"
#include "stack.h"

class ExpressaoValidador
{
private:
	string expressao;

public:
	ExpressaoValidador();
	~ExpressaoValidador();

	bool validar(std::string _expressao);
	bool validarCaractere();
	bool validarFormacao();
	bool validarParenteses();
	bool validarExpressao();

};

#endif
