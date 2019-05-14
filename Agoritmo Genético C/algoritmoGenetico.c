#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int populacao[6][6], novaPopulacao[6][6], numeroInteiro[6], posicao[2], pais[2];
	int i, j, k, n, n2, aux, aux2, divisor, iteracoes = 0, geracao, menor = 31, condicao;
	
	srand( (unsigned)time(NULL) );
	
	//Gera a população incial.
	for(i = 0 ; i  < 6 ; i++){
		for(j = 0 ; j < 6 ; j++){			
			populacao[i][j] = rand() % 2;
		}
	}
	
	printf("Digite o numero de iteracoes : ");
	scanf("%d", &condicao);
		
	while(iteracoes != condicao){
		
		printf("\nPolulacao: %d\n", iteracoes);
		
		for(i = 0 ; i < 6 ; i++){
			for(j = 0 ; j < 6 ; j++){
				printf("%d ", populacao[i][j]);
			}			
			printf("\n");
		}
								
		// Converte o valor binário da matriz 'populacao[6][6]' para inteiro no vetor 'numeroInteiro[6]'.
		for(i = 0 ; i  < 6 ; i++){
			numeroInteiro[i] = 0;
			for(j = 1, divisor = 16 ; j < 6 ; j++, divisor /= 2){			
				numeroInteiro[i] += populacao[i][j] * divisor;
			}
			
			if(populacao[i][0] == 1){
				numeroInteiro[i] *= -1;
			}
		}
							
		// Verificar fitness segundo a fórmula 'f(x) = x²'.
		for(i = 0 ; i < 6 ; i++){
			if(pow(numeroInteiro[i], 2)	< pow(menor, 2)){
				menor = numeroInteiro[i];
				geracao = iteracoes;
			}			
		}
				
		// Operação de cruzamento.
		for(k = 0 ; k < 6 ; ){
			
			// Operação de atribuir um valor inteiro no intervalo de 0 a 5 (6 posições) ao vetor 'posicao[2]', para escolha aleatória dos pais.
			for(i = 0 ; i < 2 ; i++){
				for(j = 0 ; j < 2 ; j++){
					posicao[j] = rand() % 6;
				}
				
				// Atribuindo o valor a 'pais[2]' conforme o melhor fitness, em uma operação de torneio. 
				aux = posicao[0];
				aux2 = posicao[1];
				if(pow(numeroInteiro[aux], 2) <= pow(numeroInteiro[aux2], 2)){
					pais[i] = posicao[0];
				} else {
					pais[i] = posicao[1];
				}				 
			}
				
			// Operação de Crossover.
			for(i = 0 ; i < 2 ; i++, k++){
				for(j = 0 ; j < 6 ; j++){
										
					if(j < 3){
						aux = pais[i];
						novaPopulacao[k][j] = populacao[aux][j];												
					} else {
						if(i % 2 == 0){
							aux = pais[i+1];
							novaPopulacao[k][j] = populacao[aux][j];
						} else {
							aux = pais[i-1];
							novaPopulacao[k][j] = populacao[aux][j];
						}						 
					}	
				}
			}												
		}
				
		// Operação de mutação de 0,01%.		
		n = rand() % 6;
		n2 = rand() % 6;
		novaPopulacao[n][n2] = (novaPopulacao[n][n2] == 0) ? 1 : 0;
		
				
		// Passando 'novaPopulacao[6]' para 'Populacao[6]'.
		for(i = 0 ; i < 6 ; i++){
			for(j = 0 ; j < 6 ; j++){
				populacao[i][j] = novaPopulacao[i][j];
			}			
		}
		
		iteracoes++;
	}
	
	printf("A geracao que primeiro apresentou o menor fitness de acordo com o numero de iteracoes informado foi a geracao: %d\nValor de x = %d\n", geracao, menor);	
	
	return 0;
}
