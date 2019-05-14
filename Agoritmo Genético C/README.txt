Atividade: minimizar uma fun��o 'f(x) = x�', com intervalo inteiro [-31,31], conforme n�mero 
de itera��es determinada pelo usu�rio.

Conceitos envolvidos:

Linguagem de programa��o C
Biologia
Bioinform�tica

O problema � fazer um algoritmo gen�tico para minimizar a fun��o 'f(x) = x�' o m�ximo poss�vel,
com 'x' no intervalo inteiro de [-31,31], observando o exerc�cio conclu�mos logo que o menor valor
inteiro dentro desse intervalo � zero (0).

O funcionamento do software � gerar uma matriz (popula��o) arbitr�ria de vetores (cromossomos)
bin�rio (vetores podem ter somente 0 ou 1). O tamanho desta popula��o foi limitada a 6, o que quer
dizer que � uma matriz 6x6, composta de 6 vetores, vetores tamb�m de tamanho 6, no entanto o �ndice
zero (0) de cada vetor representa o bit de sinal, se um (1) n� negativo, se zero (0) positivo.

Os outros 5 �ndices (bits), representam o intervalo inteiro [0,31] em bin�rio, de acordo com a 
convers�o para inteiro. 

Etapas da implementa��o do software:

- Coleta do n�mero de itera��es do algoritmo gen�tico (crit�rio de parada);
- Popula��o inicial / convers�o bin�rio-inteiro;
- C�culo do fitness;
- Opera��o de cruzamento (cross-over);
- Opera��o de muta��o.