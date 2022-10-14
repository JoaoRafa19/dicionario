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
  imprimeLista(lista, stdout); // 10 1200 2 13
  removeUltimaCelula(lista);
  imprimeLista(lista, stdout); // 10 1200 2
  removeUltimaCelula(lista); // 10 1200
  removeUltimaCelula(lista); //10
  removeUltimaCelula(lista); // (nao faz nada)
  imprimeLista(lista, stdout); // lista vazia

  // FILE *f;
  // int res;
  // f = fopen("teste.txt", "w");
  // nitems(lista, NULL,  stdout); // escreve na saida padrao
  // nitems(lista, &res, NULL); // escreve o resultado na variavel
  // nitems(lista, NULL, f); //escreve no arquivo 



  return 0;
}