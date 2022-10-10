#include "../codigo/listapalavras/listapalavras.h"
#include <string.h>


int main(){

    ListaPalavras *lista;
    Palavra *p;
    criaNovaListaDePalavrasVazia(&lista);
    // imprimelistapalavras(lista); // lista vazia

    //p = criapalavra();
    criaPalavraVazia(&p);
    preencheCadeiaDeCaracteres(p, "teste abc");
    adicionaLinha(p, 10);
    adicionaLinha(p, 25);
    adicionaLinha(p, 15);
    inserePalavra(lista, criaCelulaListaPalavras(p));

    criaPalavraVazia(&p);
    preencheCadeiaDeCaracteres(p, "teste string");
    adicionaLinha(p, 14);
    inserePalavra(lista, criaCelulaListaPalavras(p));

    criaPalavraVazia(&p);
    preencheCadeiaDeCaracteres(p, "string vazia");
    adicionaLinha(p, 11);
    inserePalavra(lista, criaCelulaListaPalavras(p));
    imprimelistapalavras(lista, stdout);

    
    printf("\n->%d<-", verificaPalavraExisteNaLista(lista, "string vazia"));
    
    

    popCelulaListaPalavras(lista);


    imprimelistapalavras(lista, stdout);

    return 0;
}