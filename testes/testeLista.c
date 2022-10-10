#include <stdio.h>
#include <stdlib.h>
#include "../codigo/lista/lista.h"

int main()
{
  ListaDeOcorrencias* lista;

  fazListaVazia(&lista);
  imprimeLista(lista);

   
  CelulaLista * cell = criaCelula(criaTitem(10));
  adicionarCelula(lista, cell);
   cell = criaCelula(criaTitem(1200));
  adicionarCelula(lista, cell);
   cell = criaCelula(criaTitem(2));
  adicionarCelula(lista, cell);
  imprimeLista(lista); //
  cell = criaCelula(criaTitem(13));
  adicionarCelula(lista, cell);
  imprimeLista(lista); //
  removeUltimaCelula(lista);
  imprimeLista(lista); //
  removeUltimaCelula(lista);
  removeUltimaCelula(lista);
  removeUltimaCelula(lista);
  imprimeLista(lista); //

  // FILE *f;
  // f = fopen("teste.txt", "w");
  // nitems(lista, NULL,  stdout);
  // nitems(lista, NULL, f);
  
  return 0;


  return 0;
}