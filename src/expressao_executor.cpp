#include "expressao_executor.h"

double ExpressaoExecutor::resultado(string _expressao)
{
    expressao = _expressao;

    converterPosFixa();

    return executarPosFixa();
}

// Private

int ExpressaoExecutor::operPriori(string operador)
{
  if (operador == "(" || operador == ")") return 4;
  else if (operador == "^") return 3;
  else if (operador == "*" || operador == "/") return 2;
  else return 1;
}

// O for itera a expressão inteira
// Verifica primeiro se é um número, caso seja adiciona no buffer
// Caso não seja um número o buffer é adicionado na lista que representa a expressão pos-fixada
// Em seguida, verifica se é um parênteses, caso seja de abertura é colocado na pilha
// Caso o parenteses seja de fechamento são desempilhados todos os valores até o parênteses de abertura
// Caso seja um operador é verificado sua prioridade e empilhado
// Caso seja espaço vazio nenhuma ação é tomada
// Por fim, caso exista algo na pilha ela é desempilhada para a lista
void ExpressaoExecutor::converterPosFixa()
{
  stack<string> operadores;
  string buffer = "";
  string oper_buffer = "";

  for(auto it = expressao.begin(); it != expressao.end(); ++it)
  {
    if (isdigit(*it) || *it == '.')
      buffer += *it;
    else
    {
      if (buffer != "") elementos.push(buffer);
      buffer = "";
      oper_buffer = *it;

      if (*it == '(')
        operadores.push(oper_buffer);
      else if (*it == ')')
      {
        while (operadores.top() != "(")
        {
          elementos.push(operadores.top());
          operadores.pop();
        }

        operadores.pop(); // Remover o "(" da pilha
      }
      else
      {
        if (*it != ' ')
        {
          if (!operadores.empty())
          {
            while (!operadores.empty() && operadores.top() != "(" && operPriori(operadores.top()) >= operPriori(oper_buffer))
            {
              elementos.push(operadores.top());
              operadores.pop();
            }
          }

          operadores.push(oper_buffer);
        }
      }
    }
  }

  if (buffer != "") elementos.push(buffer);

  while(!operadores.empty())
  {
    elementos.push(operadores.top());
    operadores.pop();
  }

  cout << endl;
  int n = elementos.size();
  for(int i = 0; i <= n ; i++) {
    cout << "-------> Teste pos-fixa: " << elementos.front() << endl;
    elementos.pop();
  }
}

double ExpressaoExecutor::executarPosFixa()
{
  return 0.0;
}
