#include "include.h"
#include "registrar.h"
#include "dados.h"
#include "ordena.h"
#include "para_var.h"
#include "saida.h"


int main(){
    int input;
    int n;
    produto *prod;

    // Exibe menu principal
    do{
        printf("1 - Registrar e criar relatório\n");
        printf("2 - Modificar relatório pronto\n");
        printf("3 - Ordenar\n");
        printf("4 - Sair\n");
        scanf("%d", &input);

        switch(input){
            case 1:{
                FILE *arqSaida = fopen("log.txt", "w");
                le_int(&n);
                prod = malloc(sizeof(produto) * n);
                le_produto(prod, n);
                imprime_arq(arqSaida, prod, n);
                fclose(arqSaida);
                free(prod);
                break;
            }

            case 2: {
                int sub_input;
                FILE *arqEntrada = fopen("log.txt", "r");
                if(arqEntrada == NULL){
                    printf("Erro ao abrir o arquivo log.txt\n");
                    continue;
                }
                n = 0;
                char aux[100];
                while(fgets(aux, sizeof(aux), arqEntrada) != NULL){
                    n++;
                }
                prod = malloc(sizeof(produto) * n);

                // Exibe menu modificar
                do{
                    printf("1 - Modificar nome do produto\n");
                    printf("2 - Modificar quantidade do produto\n");
                    printf("3 - Voltar\n");
                    scanf("%d", &sub_input);
                    
                    switch(sub_input){
                        case 1:
                            modifica_nome(arqEntrada, prod);
                            break;
                        
                        case 2:
                            modifica_quantidade(arqEntrada, prod);
                            break;
                    }
                }while(sub_input != 3);
                fclose(arqEntrada);
                free(prod);
                break;
            }

            case 3: {
                int sub_input;
                FILE *arqEntrada = fopen("log.txt", "r");
                if(arqEntrada == NULL){
                    printf("Erro ao abrir o arquivo log.txt\n");
                    continue;
                }
                n = 0;
                char aux[100];
                while(fgets(aux, sizeof(aux), arqEntrada) != NULL){
                    n++;
                }
                rewind(arqEntrada);
                prod = malloc(sizeof(produto) * n);

                // Exibe menu de ordenação
                do{
                    printf("1 - Ordena por ordem alfabética\n");
                    printf("2 - Ordena as quantidades por ordem crescente\n");
                    printf("3 - Ordena as quantidades por ordem decrescente\n");
                    printf("4 - Voltar\n");
                    scanf("%d", &sub_input);

                    switch(sub_input){
                        case 1: {
                            arq_para_var(arqEntrada, prod);
                            ordena_alfabetico(prod, n);
                            FILE *arqSaida = fopen("log.txt", "w");
                            imprime_arq(arqSaida, prod, n);
                            fclose(arqSaida);
                            break;
                        }

                        case 2: {
                            arq_para_var(arqEntrada, prod);
                            ordena_crescente(prod, n);
                            FILE *arqSaida = fopen("log.txt", "w");
                            imprime_arq(arqSaida, prod, n);
                            fclose(arqSaida);
                            break;
                        }

                        case 3: {
                            arq_para_var(arqEntrada, prod);
                            ordena_decrescente(prod, n);
                            FILE *arqSaida = fopen("log.txt", "w");
                            imprime_arq(arqSaida, prod, n);
                            fclose(arqSaida);
                            break;
                        }
                    }
                }while(sub_input != 4);
                fclose(arqEntrada);
                free(prod);
                prod = NULL;
                break;
            }
        }
    }while(input != 4);
}