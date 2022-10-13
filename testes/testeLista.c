#include <stdio.h>
#include <stdlib.h>
#include "../codigo/lista/lista.h"

int main()
{
  ListaDeOcorrencias* lista;

  fazListaVazia(&lista);
  imprimeLista(lista, stdout);

   
  CelulaLista * cell = criaCelula(criaTitem(10));
  adicionarCelula(lista, cell);
   cell = criaCelula(criaTitem(1200));
  adicionarCelula(lista, cell);
   cell = criaCelula(criaTitem(2));
  adicionarCelula(lista, cell);
  imprimeLista(lista, stdout); //
  cell = criaCelula(criaTitem(13));
  adicionarCelula(lista, cell);
  imprimeLista(lista, stdout); //
  removeUltimaCelula(lista);
  imprimeLista(lista, stdout); //
  removeUltimaCelula(lista);
  removeUltimaCelula(lista);
  removeUltimaCelula(lista);
  imprimeLista(lista, stdout); //

  // FILE *f;
  // f = fopen("teste.txt", "w");
  // nitems(lista, NULL,  stdout);
  // nitems(lista, NULL, f);
  
  return 0;


  return 0;
}