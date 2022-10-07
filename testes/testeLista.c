#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
  Lista* lista;

  FLVazia(&lista);
  imprimeLista(lista);

   
  TCelula * cell = criaCelula(criaTitem(10));
  adicionarCelula(lista, cell);
   cell = criaCelula(criaTitem(1200));
  adicionarCelula(lista, cell);
   cell = criaCelula(criaTitem(2));
  adicionarCelula(lista, cell);
  imprimeLista(lista); //
  cell = criaCelula(criaTitem(13));
  adicionarCelula(lista, cell);
  imprimeLista(lista); //
  popCell(lista);
  imprimeLista(lista); //

  FILE *f;
  f = fopen("teste.txt", "w");
  nitems(lista, NULL,  stdout);
  nitems(lista, NULL, f);
  
  return 0;


  return 0;
}