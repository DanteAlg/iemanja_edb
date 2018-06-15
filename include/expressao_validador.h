#ifndef EXPRESSAOVALIDADOR_H
#define EXPRESSAOVALIDADOR_H
#include <string>


class ExpressaoValidador
{
private:
	std::string expressao;
public:
	ExpressaoValidador(std::string exp);
	~ExpressaoValidador();
	bool Validar();
	bool ValidarCaractere(std::string expressao);
	bool ValidarFormacao(std::string expressao);
	bool ValidarParenteses(std::string expressao);
	bool ValidarExpressao(std::string expressao);
}; 
#endif
