#ifndef ORDENA_H
#define ORDENA_H

#include "include.h"
#include "dados.h"

void ordena_alfabetico(FILE *arqEntrada, produto *prod);
void ordena_crescente(FILE *arqEntrada, produto *prod);
void ordena_decrescente(FILE *arqEntrada, produto *prod);

#endif