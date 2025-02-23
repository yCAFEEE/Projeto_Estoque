#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "include.h"
#include "dados.h"

void le_int(int *n);
void le_produto(produto *prod, int n);
void le_relatorio(FILE *arqEntrada, produto *prod, int n);

#endif