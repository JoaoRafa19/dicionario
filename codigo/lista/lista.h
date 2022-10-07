#include <stdio.h>
#include <stdlib.h>

typedef int Linha;

typedef struct
{
  Linha linha;
  
} Titem;

typedef struct Celula
{
  Titem Item;
  struct Celula *pProx; /* Apontador pProx; */
} TCelula;

typedef struct Celula *Apontador;
typedef struct t_lista
{
  int nItens;
  Apontador pPrimeiro;
  Apontador pUltimo;

} Lista;

void FLVazia(Lista **);
Titem criaTitem(Linha linha);
TCelula *criaCelula(Titem item);
void adicionarCelula(Lista *lista, TCelula *item);
void imprimeLista(Lista *l);
void popCell(Lista *l);
void nitems(Lista *l, int *pres, FILE* output);
