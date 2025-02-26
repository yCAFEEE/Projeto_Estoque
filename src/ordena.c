#include "ordena.h"

void ordena_alfabetico(produto * prod, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(prod[i].nome, prod[j].nome) > 0){
                produto temp;
                temp = prod[i];
                prod[i] = prod[j];
                prod[j] = temp;
            }
        }
    }
}

void ordena_crescente(produto *prod, int n){
    produto prod_aux;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(prod[i].quantidade < prod[j].quantidade){
                prod_aux = prod[i];
                prod[i] = prod[j];
                prod[j] = prod_aux;
            }
        }
    }
}

void ordena_decrescente(produto *prod, int n){
    produto prod_aux;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(prod[i].quantidade > prod[j].quantidade){
                prod_aux = prod[i];
                prod[i] = prod[j];
                prod[j] = prod_aux;
            }
        }
    }
}