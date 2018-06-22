//Definição da classe expressao_validador
#ifndef _EXPRESSAO_EXECUTOR
#define _EXPRESSAO_EXECUTOR

#include <string>
#include <iostream>
#include <cctype>

#include "pilha.h"
#include "fila.h"

using namespace minhasTads;

class ExpressaoExecutor
{
private:
  fila<string> elementos;
  std::string expressao;

public:
  ExpressaoExecutor();
  ~ExpressaoExecutor();

  double resultado(std::string _expressao);

private:
  int operPriori(std::string operador);
  void converterPosFixa();   
  bool ehNuemro(std::string num);  
  bool ehOperador(std::string  op);  
  double calcOperacao(std::string op, double valor_1, double valor_2);
  double executarPosFixa();
};

#endif
