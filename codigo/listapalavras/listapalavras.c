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
void popCelulaListaPalavras(ListaPalavras *lista){

    Pointer aux;
    Pointer rem;
    aux = lista->primeiro;
    while (1)
    {
        if (aux->prox->prox == NULL) // eh o ultimo
        {
            rem = aux->prox;
            break;
        }

        aux = aux->prox;
    }
    lista->nItens--;
    lista->ultimo = aux;
    aux->prox = NULL;
    free(rem);
}
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra){
    Pointer aux;
    Pointer rem;
    aux = lista->primeiro;
    while (1)
    {
        if (aux->prox == NULL) // eh o ultimo
        {
            printf("palavra não encontrada");
            break;
        }
        

        aux = aux->prox;
    }
    lista->nItens--;
    lista->ultimo = aux;
    aux->prox = NULL;
    free(rem);

}
void verificaPalavraExisteNaLista(ListaPalavras *lista, String string){

}
int numeroDePalavras(ListaPalavras *lista){
    return lista->nItens;
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
