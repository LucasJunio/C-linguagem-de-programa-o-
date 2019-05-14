#include<stdio.h>
#include<stdlib.h>

#define TAM 1

struct cadastro{

    int  voo;
    int  lugares;
    char origem[30];
    char destino[30];

};

int main(){

    int menu, submenu, reserva, nave;
    int i;
    int aux = 0;
    char cidade[30];


    struct cadastro c[TAM];

    for(i = 0;i < TAM;i++){
		printf("\n\nREALIZE O CADASTRO DO VOO PARA EXECUTAR TAREFAS DE 'Consulta' OU 'Reserva' DE VOO. ");
        printf("\n\nDIGITE O NUMERO DO VOO: ");
        scanf("%d", &c[i].voo);
        printf("\n\nDIGITE O NUMERO DE LUGARES: ");
        scanf("%d", &c[i].lugares);
        printf("\n\nDIGITE A ORIGEM DO VOO: ");
        fflush(stdin);
        gets(c[i].origem);
        printf("\n\nDIGITE O DESTINO DO VOO: ");
        gets(c[i].destino);
        system("cls");

    }


    while(1){

        printf("\n\n1 - Consultar;\n2 - Efetuar Reserva;\n3 - Sair.\n\n");
        scanf("%d", &menu);
        system("cls");

        switch(menu){

            case 1:

                printf("\n\n1 - Por numero de voo;\n2 - Por origem;\n3 - Por destino.\n4 - Voltar.\n\n");
                scanf("%d", &submenu);
                system("cls");

                switch(submenu){

                    case 1:

                        printf("\n\nQUAL O NUMERO DA AERONAVE DO VOO QUE DESEJA REALIZAR?\n\n");
                        fflush(stdin);
                        scanf("%d", &nave);

                        for(i = 0;i < TAM;i++){

                            if (nave == c[i].voo){

                                printf("\nO NUMERO DE LUGARES DISPONIVEIS NESTE VOO = %d\n", c[i].lugares);
                                printf("\nA ORIGEM DO VOO E %s\n", c[i].origem);
                                printf("\nO DESTINO DO VOO E %s\n\n", c[i].destino);

                            }   else    {
                                aux++;
                            }
                        }

                        if (aux == TAM){
                            printf("\n\nVoo inexistente\n\n");
                        }

                        aux = 0;

                        system("pause");
                        system("cls");

                        break;

                    case 2:

                        printf("\n\nDIGITE A CIDADE ORIGEM:\n\n");
                        fflush(stdin);
                        gets(cidade);

                        for(i = 0;i < TAM;i++){

                            if (strcmp(cidade, c[i].origem) == 0){
                                printf("\nA AERONAVE %d TEM ESTA ORIGEM\n", c[i].voo);
                                printf("\nO NUMERO DE LUGARES DISPONIVEIS NESTA AERONAVE = %d\n", c[i].lugares);
                                printf("\nO DESTINO DA AERONAVE E %s\n\n", c[i].destino);
                            }   else    {

                                aux++;
                            }
                        }

                        if (aux == TAM){
                            printf("\n\nOrigem inexistente\n\n");                                                        
                        }

                        aux = 0;

                        system("pause");
                        system("cls");

                        break;

                    case 3:

                        printf("\n\nDIGITE A CIDADE DESTINO:\n\n");
                        fflush(stdin);
                        gets(cidade);

                        for(i = 0;i < TAM;i++){

                            if (strcmp(cidade, c[i].destino) == 0){
                                printf("\nA AERONAVE %d TEM ESTE DESTINO\n", c[i].voo);
                                printf("\nO NUMERO DE LUGARES DISPONIVEIS NESTA AERONAVE = %d\n", c[i].lugares);
                                printf("\nA ORIGEM DA AERONAVE E %s\n\n", c[i].origem);
                            }   else    {

                                aux++;
                            }
                        }

                        if (aux == TAM){
                            printf("\n\nDestino inexistente\n\n");                            
                        }

                        aux = 0;

                        system("pause");
                        system("cls");

                        break;

                    case 4:
                    	break;
					default:

                        printf("\n\nESCOLHA INEXISTENTE.\n\n");
                        system("pause");
                        system("cls");
                }

            break;

            case 2:

                printf("\n\nQUAL O NUMERO DA AERONAVE DO VOO QUE DESEJA REALIZAR?\n\n");
                scanf("%d", &reserva);

                for(i = 0;i < TAM;i++){

                    if (reserva == c[i].voo){

                        if (c[i].lugares != 0){

                            printf("\n\nReserva confirmada!\n\n");
                            c[i].lugares--;
                        }   else    {

                            printf("\n\nVoo lotado!\n\n");
                        }

                        system("pause");
                        system("cls");
                    }   else    {

                        aux++;
                    }
                }

                if (aux == TAM){
                    printf("\n\nVoo inexistente\n\n");
                    system("pause");
                    system("cls");
                }

                aux = 0;

                break;

           case 3:

                exit(0);

           break;

           default:

                printf("\n\nOPCAO INEXISTENTE!\n\n");
        }
    }

    return 0;
}
