#include "registrar.h"

void le_int(int *n){
    printf("Quantos produtos deseja registrar? ");
    scanf("%d", n);
}

void le_produto(produto *prod, int n){
    for(int i = 0; i < n; i++){
        printf("Digite o nome do %dº produto: ", i + 1);
        if(i == 0){
            getchar();  // Gambiarra :)
        }
        fgets(prod[i].nome, 42, stdin);
        prod[i].nome[strlen(prod[i].nome) - 1] = '\0';
    }
    for(int i = 0; i < n; i++){
        printf("Digite a quantidade de %s: ", prod[i].nome);
        scanf("%d", &prod[i].quantidade[i]);
    }
}

void le_relatorio(FILE *arqEntrada, produto *prod, int n){
    
}