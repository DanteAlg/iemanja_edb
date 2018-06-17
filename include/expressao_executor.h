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
  double executarPosFixa();
};

#endif
