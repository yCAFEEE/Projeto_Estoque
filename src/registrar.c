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
        scanf("%d", &prod[i].quantidade);
    }
}

void modifica_nome(FILE *arqEntrada, produto *prod){
    arqEntrada = fopen("log.txt", "r");
    if(arqEntrada == NULL){
        printf("Erro ao abrir o arquivo log.txt\n");
        return;
    }

    int input;
    int cont = 0;
    char aux[100];

    // Conta a quantidade de produtos no arquivo
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

    //formata_quantidades();
    // Exibe menu com os produtos
    printf("\n--Produtos--\n\n");
    for(int i = 0; i < cont; i++){
        printf("%d %s\n", i + 1, prod[i].nome);
    }
    printf("Selecione um produto pelo seu respectivo número: ");
    scanf("%d", &input);

    if(input - 1 > cont || input - 1 < 0){
        printf("\nERRO! Número do produto inválido.\n\n");
        return;
    }

    printf("\nProduto %s selecionado.\n\n", prod[input - 1].nome);
    printf("Digite o novo nome para o produto: ");
    getchar();
    fgets(prod[input - 1].nome, sizeof(prod[input - 1].nome), stdin);
    prod[input - 1].nome[strcspn(prod[input - 1].nome, "\n")] = '\0';

    arqEntrada = fopen("log.txt", "w");

    for(int i = 0; i < cont; i++){
        fprintf(arqEntrada, "%s %04d\n", prod[i].nome, prod[i].quantidade);
    }
    fclose(arqEntrada);
}

void modifica_quantidade(FILE *arqEntrada, produto *prod){
    arqEntrada = fopen("log.txt", "r");
    if(arqEntrada == NULL){
        printf("Erro ao abrir o arquivo log.txt\n");
        return;
    }

    int input;
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

    // Exibe menu com os produtos
    printf("\n--Produtos--\n\n");
    for(int i = 0; i < cont; i++){
        printf("%d %s %d\n", i + 1, prod[i].nome, prod[i].quantidade);
    }
    printf("Selecione um produto pelo seu respectivo número: ");
    scanf("%d", &input);

    if(input - 1 > cont || input < 0){
        printf("\nERRO! Número do produto inválido.\n\n");
        return;
    }

    printf("\nProduto %s selecionado.\n\n", prod[input - 1].nome);
    printf("Digite a nova quantidade para o produto: ");
    scanf("%d", &prod[input - 1].quantidade);

    arqEntrada = fopen("log.txt", "w");
    for(int i = 0; i < cont; i++){
        fprintf(arqEntrada, "%s %04d\n", prod[i].nome, prod[i].quantidade);
    }
    fclose(arqEntrada);
}