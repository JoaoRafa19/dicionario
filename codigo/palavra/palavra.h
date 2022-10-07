/**
 * @file palavra.h
 * @author your name (github.com/JoaoRafa19)
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../lista/lista.h"
typedef char *String;

typedef struct t_palavra
{

  String palavra;
  Lista *lista;

} Palavra;

void criaPalavraVazia(Palavra **palavra);
Palavra *criapalavra();
void preencheCadeiaDeCaracteres(Palavra *palavra, char * string);
void adicionaLinha (Palavra* palavra, Linha linha);
String retornaCadeiaDeCaracteres(Palavra *palavra);
void imprimeCadeiaDeCaracteres(Palavra *palavra);
void imprimePalavra(Palavra *palavra);