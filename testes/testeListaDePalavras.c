#include "../codigo/listapalavras/listapalavras.h"



int main(){

    ListaPalavras *lista;
    Palavra *p;
    criaNovaListaDePalavrasVazia(&lista);
    imprimelistapalavras(lista); // lista vazia

    p = criapalavra();
    preencheCadeiaDeCaracteres(p, "teste abc");
    adicionaLinha(p, 10);
    adicionaLinha(p, 25);
    adicionaLinha(p, 15);
    inserePalavra(lista, criaCelulaListaPalavras(p));

    p = criapalavra();
    preencheCadeiaDeCaracteres(p, "teste string");
    adicionaLinha(p, 14);
    inserePalavra(lista, criaCelulaListaPalavras(p));

    p = criapalavra();
    preencheCadeiaDeCaracteres(p, "string vazia");
    adicionaLinha(p, 11);
    inserePalavra(lista, criaCelulaListaPalavras(p));


    imprimelistapalavras(lista);

    return 0;
}