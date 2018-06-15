#ifndef _EXPRESSAO_EXECUTOR
#define _EXPRESSAO_EXECUTOR

#include <iostream>
#include <string>

using namespace std;

class ExpressaoExecutor
{
  private:
    // Lista<std::string> elementos;
    string expressao;

  public:
    ExpressaoExecutor() {};
    ~ExpressaoExecutor() {};

    double resultado(string _expressao);

  private:
    int operPriori(char operador);
    void converterPosFixa();
    double executarPosFixa();
};

#endif
