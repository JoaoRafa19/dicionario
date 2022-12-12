#include <stdio.h>
#include <stdlib.h>


#define true 1
#define false 0

typedef struct sCelula *PsCelula;

typedef struct
{
  int linha;
  
} Titem;
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





void fazListaVazia(ListaDeOcorrencias **lista);
Titem criaTitem(int line);
CelulaLista *criaCelula(Titem item);
void adicionarCelula(ListaDeOcorrencias *lista, CelulaLista *item);
void imprimeLista(ListaDeOcorrencias *list, FILE *output);
void removeUltimaCelula(ListaDeOcorrencias *l);
int listaEhVazia(ListaDeOcorrencias *lista);
void nitems(ListaDeOcorrencias *lista, int *pres, FILE* output);