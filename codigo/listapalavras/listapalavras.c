#include "listapalavras.h"

void criaNovaListaDePalavrasVazia(ListaPalavras** lista){
    (*lista) = (ListaPalavras *) malloc(sizeof(ListaPalavras));
    (*lista)->nItens = 0;
    (*lista)->primeiro = (*lista)->ultimo = NULL;

}


void inserePalavra(ListaPalavras* lista, LPCell* celula){

    int i;
    Pointer aux;
    aux = lista->primeiro;
    if (aux == NULL)
    {
        lista->primeiro = lista->ultimo = celula;
        lista->nItens++;
        return;
    }
    else
    {
        while (1)
        {
            if (aux->prox == NULL)
            {
                break;
            }
            aux = aux->prox;
        }
        aux->prox = celula;
        lista->ultimo = celula;
        lista->nItens++;
    }
}



LPCell* criaCelulaListaPalavras(Palavra* palavra){
    LPCell *cell = (LPCell *) malloc(sizeof(LPCell));
    (*cell).palavra = palavra;
    (*cell).prox = NULL;

    return cell;

}
void popCelula(ListaPalavras *lista){

}
void removeCelula(ListaPalavras *lista, Palavra *palavra){

}
void verificaPalavraExisteNaLista(ListaPalavras *lista, String string){

}
int numeroDePalavras(ListaPalavras *lista){

}
void imprimelistapalavras(ListaPalavras *lista){
    if(lista->nItens ==0 && (lista->primeiro == lista->ultimo) &&( lista->primeiro == NULL)){
        puts("lista vazia");
        return;
    }
    int i;
    Pointer aux;
    aux = lista->primeiro;

    while (1)
    {

        if (aux->prox == NULL)
        {

            imprimePalavra(aux->palavra);
            break;
        }
        imprimePalavra(aux->palavra);
        
        aux = aux->prox;
    }
}
