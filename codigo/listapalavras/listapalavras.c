#include "listapalavras.h"
#include <string.h>
#include <stdbool.h>

void criaNovaListaDePalavrasVazia(ListaPalavras **lista)
{
    (*lista) = (ListaPalavras *)malloc(sizeof(ListaPalavras));
    (*lista)->nItens = 0;
    (*lista)->primeiro = (*lista)->ultimo = NULL;
}

void inserePalavra(ListaPalavras *lista, LPCell *celula)
{

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

LPCell *criaCelulaListaPalavras(Palavra *palavra)
{
    LPCell *cell = (LPCell *)malloc(sizeof(LPCell));
    (*cell).palavra = palavra;
    (*cell).prox = NULL;

    return cell;
}
void popCelulaListaPalavras(ListaPalavras *lista)
{

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
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra)
{
    Pointer aux;
    Pointer rem;
    aux = lista->primeiro;
    while (true)
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

/**
 * @brief Verifica se uma palavra passada como parametro ja existe na lista
 *
 * @param lista
 * @param string
 */
int verificaPalavraExisteNaLista(ListaPalavras *lista, String string)
{

    int i;
    Pointer aux;
    aux = lista->primeiro;
    for (aux = lista->primeiro; aux != NULL; aux=aux->prox)
    {
        
        if(compareString(string, aux->palavra->palavra)){
            return true;
        }
    }
    return false;
}


int compareString(String s1, String s2){
    if(strlen(s1) != strlen(s2)) return false;
    int i;
    for (i = 0; i < strlen(s1); i ++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

int numeroDePalavras(ListaPalavras *lista)
{
    return lista->nItens;
}

void imprimelistapalavras(ListaPalavras *lista, FILE* output)
{
    if (lista->nItens == 0 && (lista->primeiro == lista->ultimo) && (lista->primeiro == NULL))
    {
        fputs("lista vazia", output);
        return;
    }
    int i;
    Pointer aux;
    aux = lista->primeiro;

    while (1)
    {

        if (aux->prox == NULL)
        {

            imprimePalavra(aux->palavra, output);
            break;
        }
        imprimePalavra(aux->palavra, output);

        aux = aux->prox;
    }
    
}
