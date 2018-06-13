# Iemanjao EDB

1. Run `make all`

## Test error saida:
```code
10 * (30 / ( 2 * 3 + 4) + 15@) = "Erro 1: Caracter invalido encontrado na posição 29."
25+(14-(25*4+40-(20/2+10)) = "Erro 3: Os parênteses da expressão estão desbalanceados"
2^3 + 3^2 - 1) = "Erro 3: Os parênteses da expressão estão desbalanceados."
1.25.8 + 2 = "Erro 2: Número invalido encontrado a partir da posição 5"
2 + 3 * = "Erro 4: Expressão infixa malformada"
1 + 2 = 3
```

## Test success saida:
```code
10 * (30 / ( 2 * 3 + 4) + 15) = 180
25 + (14 - (25 * 4 + 40 - (20/2 + 10))) = -81
2^3 + (3^2 - 1) = 16
3/1.5 + 0.5 = 2.5
```

