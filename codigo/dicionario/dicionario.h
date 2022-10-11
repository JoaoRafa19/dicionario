#include "../listapalavras/listapalavras.h"

typedef struct sDictSession * PsDictSession;

typedef struct sDictSession{
    char letra;
    ListaPalavras *lista;
    PsDictSession prox;

} DictSession;

typedef DictSession* PPalavraDict;

typedef struct
{
    PPalavraDict primeiro;
    PPalavraDict ultimo;

    int nitens;

} Dicionario;




void inicializaDicionario(Dicionario ** dict);


void controiDicionario(String filename, Dicionario *dict);
void exibeListaPorLetra(Dicionario *dict, char * letra);
void exiteTodasAsPalavras(Dicionario* dict);


void imprimeDicionario (Dicionario *dict, FILE* output);