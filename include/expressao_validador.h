//Definição da classe expressao_validador
#ifndef EXPRESSAOVALIDADOR_H
#define EXPRESSAOVALIDADOR_H

#include <string>
#include "listacircular.h"
#include "pilha.h"

class ExpressaoValidador
{
private:
	std::string expressao;

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
