# Iemanja EDB

1. Run `make all`
2. Exec `./bin/iemanja op/operacoes.txt`

## Colaboradores
- ANDRECIO COSTA BEZERRA
- DANTE ALIGHIERI MIRANDA DOS SANTOS
- FELIPE TIBERIO MACIEL BARBOSA
- MATHEUS ALLAN DE OLIVEIRA

## Saida do arquivo op/operacoes:
```
Na expressão 10 * (30 / ( 2 * 3 + 4) + 15@)
Erro 1: Caracter invalido encontrado na posição 29!

Na expressão 25+(14-(25*4+40-(20/2+10))
Erro 3: Os parênteses da expressão estão desbalanceados!

Na expressão 2^3 + 3^2 - 1)
Erro 3: Os parênteses da expressão estão desbalanceados!

Na expressão 1.25.8 + 2
Erro 2: Número inválido encontrado a partir da posição 1!

Na expressão 2 + 3 *
Erro 4: Expressão infixa malformada!

Na expressão 1 + 2
Resultado = 3

Na expressão 3/1.5 + 0.5
Resultado = 2.5

Na expressão 10 * (30 / ( 2 * 3 + 4) + 15)
Resultado = 180

Na expressão 25+(14-(25*4+40-(20/2+10)))
Resultado = -81

Na expressão 2^3 + (3^2 - 1)
Resultado = 16
```

## Tasks TODO:

[x] (1,0) Solução estruturada
- Utilizar estrutura de pastas com makefile para compilar a aplicação
---
[x]  (1,5) Criar classes de Pilha e Fila utilizando uma lista circular simples encadeada
- As classes devem ser feitas com templates para receber qualquer tipo de dado
[x] Lembrar de fazer o destrutor das classes (sempre tenho o hábito de esquecer essa parte)
---
[x]  (1,0) Criar uma classe ExpressaoValidador para receber uma lista de strings com expressoes
- O construtor da classe não precisa receber dados.
- Criar método "validarCaractere" que verifica se existem caracteres inválidos. [Válidos: númericos e de operações `() + - * / ^ .`]. Escreve "Erro 1 ..." e retorna "false"
- Criar método "validarFormacao" que verifica a formação dos números ex.: "1.25.8". Escreve "Erro 2 ..." e retorna "false"
- Criar método "validarParenteses" que verifica o balanceamento de parenteses. Escreve "Erro 3 ..." e retorna "false"
- Criar método "validarExpressao" que verifica a validade da expressão ex.: "2 + 5 -". Escreve "Erro 4 ..." e retorna "false"
- Criar método "validar" que recebe a string da expressão e executa todos os métodos da classe. Retorna "true" ou "false" para expressão
---
[x]  (4,5) Criar uma classe ExpressaoExecutor para receber uma string com as expressões corretas
- O construtor da classe não precisa receber dados.
- (1,0) Criar método "operPriori" que recebe uma operação `() + - * / ^ .` e retorna um valor para sua prioridade `1: (), 2: ^, 3: */, 4: +-`
- (2,0) Criar método "converterPosFixa" que converte a string com a expressão em forma infixa e retorna uma salva na lista com a expressão em forma pos-fixa
- (1,5) Criar método "executarPosFixa" que lê a lista da expressão pos-fixa e executa as operações. Retorna o resultado da expressão.
- Criar método "calcular" que recebe a string da expressão e executa os métodos da classe. Escreve o valor da expressão na tela e não retorna dado.
---
[x]  (1,0) Comentar os métodos e classes
---
[x]  (1,0) Efetividade do projeto
