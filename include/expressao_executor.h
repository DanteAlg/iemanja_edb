#ifndef _EXPRESSAO_EXECUTOR
#define _EXPRESSAO_EXECUTOR

#include <string>
#include <iostream>
#include <cctype>

#include "stack.h"
#include "queue.h"

using namespace std;
using namespace myTads;

class ExpressaoExecutor
{
private:
  queue<string> elementos;
  string expressao;

public:
  ExpressaoExecutor() {};
  ~ExpressaoExecutor() {};

  double resultado(string _expressao);

private:
  int operPriori(string operador);
  void converterPosFixa();
  // Verifica se uma string passada como argumento é um número 
  bool ehNuemro(std::string num);
  // Verifica se uma string passada como argumento é um operador 
  bool ehOperador(std::string  op);
  // Calcular uma operação binário passada com argumento, e dois valores para serem operados 
  double calcOperacao(std::string op, double valor_1, double valor_2);

  double executarPosFixa();
};

#endif
