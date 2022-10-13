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

typedef struct
{

  String string;
  ListaDeOcorrencias *lista;

} Palavra;

void criaPalavraVazia(Palavra **palavra);
void preencheCadeiaDeCaracteres(Palavra *palavra, char * string);
void adicionaOcorrecia (Palavra* palavra, int linha);
String retornaCadeiaDeCaracteres(Palavra *palavra);
void imprimeCadeiaDeCaracteres(Palavra *palavra);
void imprimePalavra(Palavra *palavra, FILE *output);