#include "expressao_executor.h"

double ExpressaoExecutor::resultado(string _expressao)
{
    expressao = _expressao;

    converterPosFixa();
    return executarPosFixa();
}

// Private

int ExpressaoExecutor::operPriori(char operador)
{
  if (operador == ')' || operador == '(')
    return 1;
  else if (operador == '^')
    return 2;
  else if (operador == '*' || operador == '/')
    return 3;
  else
    return 4;
}

void ExpressaoExecutor::converterPosFixa()
{
}

double ExpressaoExecutor::executarPosFixa()
{
  return 0.0;
}
