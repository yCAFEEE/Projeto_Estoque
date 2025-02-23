#include "include.h"
#include "registrar.h"
#include "dados.h"
#include "saida.h"

int main(){
    int input;
    int n;
    produto *prod;
    do{
        printf("1 - Registrar e criar relatório\n");
        printf("2 - Modificar relatório pronto\n");
        printf("3 - Ordenar\n");
        printf("4 - Sair\n");
        scanf("%d", &input);

        if(input == 1){
            FILE *arqSaida = fopen("log.txt", "w");
            le_int(&n);
            prod = malloc(sizeof(produto) * n);
            le_produto(prod, n);
            imprime_arq(arqSaida, prod, n);
            fclose(arqSaida);
            free(prod);
        }

        else if(input == 2){
            int sub_input;
            FILE *arqEntrada = fopen("log.txt", "r");
            do{
            printf("1 - Imprimir relatório\n");
            printf("2 - Modificar nome do produto\n");
            printf("3 - Modificar quantidade do produto\n");
            printf("4 - Voltar\n");
            scanf("%d", &sub_input);
            
            }while(sub_input != 4);
        }
    }while(input != 4);
}