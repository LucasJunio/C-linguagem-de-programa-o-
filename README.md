# Atividade: minimizar uma função 'f(x) = x²', com intervalo inteiro [-31,31], conforme número de iterações determinada pelo usuário.

> Conceitos envolvidos:

- Linguagem de programação C
- Biologia
- Bioinformática

O problema é fazer um algoritmo genético para minimizar a função 'f(x) = x²' o máximo possível,
com 'x' no intervalo inteiro de [-31,31], observando o exercício concluímos logo que o menor valor
inteiro dentro desse intervalo é zero (0).

O funcionamento do software é gerar uma matriz (população) arbitrária de vetores (cromossomos)
binário (vetores podem ter somente 0 ou 1). O tamanho desta população foi limitada a 6, o que quer
dizer que é uma matriz 6x6, composta de 6 vetores, vetores também de tamanho 6, no entanto o índice
zero (0) de cada vetor representa o bit de sinal, se um (1) n° negativo, se zero (0) positivo.

Os outros 5 índices (bits), representam o intervalo inteiro [0,31] em binário, de acordo com a 
conversão para inteiro. 

Etapas da implementação do software:

- Coleta do número de iterações do algoritmo genético (critério de parada);
- População inicial / conversão binário-inteiro;
- Cáculo do fitness;
- Operação de cruzamento (cross-over);
- Operação de mutação.
