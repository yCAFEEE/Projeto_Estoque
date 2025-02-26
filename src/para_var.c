#include "para_var.h"

void arq_para_var(FILE *arqEntrada, produto *prod){
    arqEntrada = fopen("log.txt", "r");
    if(arqEntrada == NULL){
        printf("Erro ao abrir o arquivo log.txt\n");
        return;
    }

    int cont = 0;
    char aux[100];

    // Conta a quantidade de produtos no arquivo e armazena seus dados nas variaveis
    while (fgets(aux, sizeof(aux), arqEntrada) != NULL) {
        char *ptr = aux;
        char *nomePtr = prod[cont].nome;
        while (*ptr != '\0' && !isdigit(*ptr)) {
            *nomePtr = *ptr;
            nomePtr++;
            ptr++;
        }
        *nomePtr = '\0'; 
        prod[cont].quantidade = 0;
        while (*ptr != '\0' && isdigit(*ptr)) {
            prod[cont].quantidade = prod[cont].quantidade * 10 + (*ptr - '0');
            ptr++;
        }
        prod[cont].nome[strlen(prod[cont].nome) - 1] = '\0';
        cont++;
    }
    fclose(arqEntrada);
}