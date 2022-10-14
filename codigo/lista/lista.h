
#include "item.h"


#define true 1
#define false 0

typedef struct sCelula *PsCelula;

typedef struct sCelula
{
  Titem Item;
  PsCelula pProx; /* Apontador pProx; */
} CelulaLista;

typedef struct slista
{
  int nItens;
  PsCelula pPrimeiro;
  PsCelula pUltimo;

} ListaDeOcorrencias;

void fazListaVazia(ListaDeOcorrencias **);
CelulaLista *criaCelula(Titem item);
void adicionarCelula(ListaDeOcorrencias *lista, CelulaLista *item);
void imprimeLista(ListaDeOcorrencias *l, FILE*);
void removeUltimaCelula(ListaDeOcorrencias *l);
void nitems(ListaDeOcorrencias *l, int *pres, FILE* output);
int listaEhVazia(ListaDeOcorrencias *lista);
