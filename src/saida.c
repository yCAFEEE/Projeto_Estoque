#include "saida.h"

void imprime_arq(FILE *arqSaida, produto *prod, int n){
    for(int i = 0; i < n; i++){
        fprintf(arqSaida, "%s %d\n", prod[i].nome, prod[i].quantidade[i]);
    }
}