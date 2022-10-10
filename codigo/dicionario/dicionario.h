#include "../listapalavras/listapalavras.h"

typedef struct sPalavraDict * PsPalavraDict;

typedef struct sPalavraDict{
    char letra;
    ListaPalavras *lista;
    PsPalavraDict prox;

} PalavraDict;

typedef PalavraDict* PPalavraDict;

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