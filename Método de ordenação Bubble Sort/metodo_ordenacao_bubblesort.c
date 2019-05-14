/*  Faça um programa em Linguagem C que receba até 20 nomes completos (com até 30 caracteres cada nome) e imprima-os em ordem crescente.
    Sugestão: armazene em array (multidimensional), e use um método de ordenação (Ex: bubblesort)   */

#include<stdio.h>
#include<string.h>

#define TAM 20

int main()
{
    int i, j, c;                                //  DECLARAÇÃO DA VARIÁVEL INTEIRA 'i', 'j' DE CONTROLE E 'c' PARA CONTAGEM.
    char nome[TAM][31], aux[31];                //  DECLARAÇÃO DE UM VETOR DE STRING DE TAMANHO 'TAM' COM CAPACIDADE PARA 30 CARACTERES.

    for(i = 0; i < TAM; i++)                    //  (LEITURA) DAS STRINGS DE QUANTIDADE TAM
    {
        gets(nome[i]);
    }

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j <  TAM; j++)
        {
            c = (i != 0) ? j: i + 1;
                                                // (PROCESSO) NESTA PARTE DO PROGRAMA, ELE VERIFICA A POSIÇÃO POSTERIOR 'c' COM A ANTERIOR 'i'.
            if(strcmp(nome[i], nome[c]) < 0)    //  SE A STRING ANTERIOR FOR MAIOR QUE O POSTERIOR. Ex: 'LUCAS' e 'JUNIO'
            {
                strcpy(aux, nome[i]);           //  ARMAZENA A STRING QUE ESTÁ NA POSIÇÃO ANTERIOR NA STRING 'aux'. Ex: aux = "LUCAS".
                strcpy(nome[i], nome[c]);       //  ARMAZENA A STRING DA POSIÇÃO POSTERIOR NA POSIÇÃO ANTERIOR. Ex: nome[i] = "LUCAS".
                strcpy(nome[c], aux);           //  ARMAZENA A STRING QUE ESTÁ NA VARIÁVEL 'aux' NA POSIÇÃO POSTERIOR. Ex. nome[c] = "JUNIO".
            }
        }
    }

	printf("\n\n\n");

    for(i = 0; i < TAM; i++)                    //  (SAÍDA) COMO O VETOR FICOU ORDENADO DE FORMA CRESCENTE NO PROCESSO, BASTA APENAS IMPRIMIR
    {
        printf("%s\n", nome[i]);                //  AS STRINGS ORDENADAMENTE CRESCENTE.
    }

    return 0;
}
