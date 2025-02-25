#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "include.h"
#include "dados.h"

void le_int(int *n);
void le_produto(produto *prod, int n);
void formata_quantidades();
void modifica_nome(FILE *arqEntrada, produto *prod);
void modifica_quantidade(FILE *arqEntrada, produto *prod);

#endif