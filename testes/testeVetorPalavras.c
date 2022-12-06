#include "../codigo/vetorpalavras/vetorpalavras.h"
#include <string.h>

int main(){

    ListaPalavras *lista;
    Palavra *p;
    criaNovaListaDePalavrasVazia(&lista);
    // imprimelistapalavras(lista); // lista vazia

    //p = criapalavra();
    criaPalavraVazia(&p);
    preencheCadeiaDeCaracteres(p, "teste abc");
    adicionaOcorrecia(p, 10);
    adicionaOcorrecia(p, 25);
    adicionaOcorrecia(p, 15);
    inserePalavra(lista, criaCelulaListaPalavras(p));

    criaPalavraVazia(&p);
    preencheCadeiaDeCaracteres(p, "teste string");
    adicionaOcorrecia(p, 14);
    inserePalavra(lista, criaCelulaListaPalavras(p));

    criaPalavraVazia(&p);
    preencheCadeiaDeCaracteres(p, "string vazia");
    adicionaOcorrecia(p, 11);
    inserePalavra(lista, criaCelulaListaPalavras(p));
    imprimelistapalavras(lista, stdout);
    
    CelulaListaPalavra celula;
    
    //printf("\n->%d<-", verificaPalavraExisteNaLista(lista, "string vazia", &celula));
    
    bubbleSort(lista->nItens, lista->vetor);
    imprimelistapalavras(lista, stdout);
    

    //popCelulaListaPalavras(lista);


    imprimelistapalavras(lista, stdout);

    return 0;
}