#ifndef _EXPRESSAO_EXECUTOR
#define _EXPRESSAO_EXECUTOR

#include <iostream>
#include <string>

class ExpressaoExecutor {
  private:
    // Lista<std::string> elementos;
    std::string expressao;

  public:
    ExpressaoExecutor() {};
    ~ExpressaoExecutor() {};

    double calcular(std::string _expressao);

  private:
    int operPriori(char operador);
    void converterPosFixa();
    double executarPosFixa();
};

#endif
