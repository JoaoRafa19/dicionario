#include <stdio.h>
#include <stdlib.h>

typedef int Linha;

typedef struct
{
  Linha linha;
  
} Titem;
typedef struct sCelula *PsCelula;

typedef struct sCelula
{
  Titem Item;
  PsCelula pProx; /* Apontador pProx; */
} Celula;

typedef struct slista
{
  int nItens;
  PsCelula pPrimeiro;
  PsCelula pUltimo;

} Lista;

void fazListaVazia(Lista **);
Titem criaTitem(Linha linha);
Celula *criaCelula(Titem item);
void adicionarCelula(Lista *lista, Celula *item);
void imprimeLista(Lista *l);
void popCelula(Lista *l);
void nitems(Lista *l, int *pres, FILE* output);
int listaEhVazia(Lista *lista);
