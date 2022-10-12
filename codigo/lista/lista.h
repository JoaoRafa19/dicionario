#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  int linha;
  
} Titem;
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
Titem criaTitem(int linha);
CelulaLista *criaCelula(Titem item);
void adicionarCelula(ListaDeOcorrencias *lista, CelulaLista *item);
void imprimeLista(ListaDeOcorrencias *l, FILE*);
void removeUltimaCelula(ListaDeOcorrencias *l);
void nitems(ListaDeOcorrencias *l, int *pres, FILE* output);
int listaEhVazia(ListaDeOcorrencias *lista);
