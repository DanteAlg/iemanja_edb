#ifndef EXPRESSAOVALIDADOR_H
#define EXPRESSAOVALIDADOR_H
#include <string>


class ExpressaoValidador
{
public:
	ExpressaoValidador();
	~ExpressaoValidador();
	bool Validar(std::string expressao);
	bool ValidarCaractere(std::string expressao);
	bool ValidarFormacao(std::string expressao);
	bool ValidarParenteses(std::string expressao);
	bool ValidarExpressao(std::string expressao);
}; 
#endif
