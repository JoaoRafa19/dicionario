#include "listapalavras.h"
#include <string.h>
#include <stdbool.h>

/**
 * @brief Cria uma nova lista de palavras vazia
 * 
 * @param lista ListaPalavras **
 */
void criaNovaListaDePalavrasVazia(ListaPalavras **lista)
{
    (*lista) = (ListaPalavras *)malloc(sizeof(ListaPalavras));
    (*lista)->nItens = 0;
    (*lista)->primeiro = (*lista)->ultimo = NULL;
}

/**
 * @brief Insere a palavra no final da lista
 * 
 * @param lista ListaPalavras *
 * @param celula CelulaListaPalavra *
 */
void inserePalavra(ListaPalavras *lista, CelulaListaPalavra *celula)
{

    int i;
    PsCelulaListaPalavra aux;
    aux = lista->primeiro;
    if (aux == NULL)
    {
        lista->primeiro = lista->ultimo = celula;
        lista->nItens++;
        return;
    }
    else
    {
        while (true)
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

/**
 * @brief Cria e retorna uma nova CelulaListaPalavra
 * 
 * @param palavra Palavra *
 * @return CelulaListaPalavra* 
 */
CelulaListaPalavra *criaCelulaListaPalavras(Palavra *palavra)
{
    CelulaListaPalavra *cell = (CelulaListaPalavra *)malloc(sizeof(CelulaListaPalavra));
    (*cell).palavra = palavra;
    (*cell).prox = NULL;

    return cell;
}

/**
 * @brief Remove a ultima celula da lista de palavras
 * 
 * @param lista ListaPalavras *
 */
void popCelulaListaPalavras(ListaPalavras *lista)
{

    PsCelulaListaPalavra aux;
    PsCelulaListaPalavra rem;
    aux = lista->primeiro;
    while (true)
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

/**
 * @brief Remove uma celula em que a palavra que for passada como parametro for igual a da celula 
 * 
 * @param lista ListaPalavras *
 * @param palavra String
 */
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra)
{
    PsCelulaListaPalavra aux;
    PsCelulaListaPalavra rem;
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
 * @param lista ListaPalavras *
 * @param string String
 * @param ref PsCelulaListaPalavra 
 */
int verificaPalavraExisteNaLista(ListaPalavras *lista, String string, PsCelulaListaPalavra ref)
{

    int i;
    PsCelulaListaPalavra aux;
    aux = lista->primeiro;
    for (aux = lista->primeiro; aux != NULL; aux = aux->prox)
    {

        if (compareString(string, aux->palavra->string))
        {
            if (ref != NULL)
            {
                (*ref) = (*aux);
            }
            return true;
        }
    }
    return false;
}

/**
 * @brief Ordena a lista de palavras
 * 
 * @param lista ListaPalavras *
 */
void ordena(ListaPalavras *lista){

    PsCelulaListaPalavra aux = lista->primeiro;

    while (aux != NULL)
    {
        PsCelulaListaPalavra aux2 = aux->prox;
        while (aux2 != NULL)
        {
            if (strcmp(aux2->palavra->string, aux->palavra->string) < 0)
            {
                Palavra *temp = aux->palavra; // agora troca só o info
                aux->palavra = aux2->palavra;
                aux2->palavra = temp;
            }
            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
}

/**
 * @brief Compara duas strings
 * 
 * @param s1 String
 * @param s2 String
 * @return int 
 */
int compareString(String s1, String s2)
{
    if (strlen(s1) != strlen(s2))
        return false;
    int i;
    for (i = 0; i < strlen(s1); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

/**
 * @brief Retorna o numero de palavras
 * 
 * @param lista ListaPalavras *
 * @return int 
 */
int numeroDePalavras(ListaPalavras *lista)
{
    return lista->nItens;
}

/**
 * @brief Imprime a lista de palavras
 * 
 * @param lista ListaPalavras *
 * @param output FILE *
 */
void imprimelistapalavras(ListaPalavras *lista, FILE *output)
{
    if (lista->nItens == 0 && (lista->primeiro == lista->ultimo) && (lista->primeiro == NULL))
    {
        fputs("lista vazia", output);
        return;
    }
    ordena(lista);
    int i;
    PsCelulaListaPalavra aux;
    aux = lista->primeiro;

    while (true)
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
