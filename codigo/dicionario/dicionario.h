#include "../vetorpalavras/vetorpalavras.h"

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
int constroiDicionario(String filename, Dicionario *dict);
void imprimeDicionario (Dicionario *dict, FILE* output);
int verificaLetraExisteNoDicionario(String palavra, Dicionario *dict, PPalavraDict ref);
void imprimePalavraDict(DictSession *palavradict, FILE *output);
void mostraTodasAsPalavras(Dicionario *);
void removePalavraDicionario(Dicionario *, String);