#include "vetorpalavras.h"
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
    (*lista)->vetor = (PsCelulaListaPalavra )calloc(1, sizeof(CelulaListaPalavra));
}

/**
 * @brief Insere a palavra no final da lista
 * 
 * @param lista ListaPalavras *
 * @param celula CelulaListaPalavra *
 */
void inserePalavra(ListaPalavras *lista, CelulaListaPalavra *celula)
{

    int nitems = lista->nItens;
    
    lista->vetor = (VetorCelulaPalavra ) reallocarray(lista->vetor, nitems+1, sizeof(CelulaListaPalavra));
    lista->vetor[nitems] = (* celula);
    lista->nItens++;
}

/**
 * @brief Cria e retorna uma nova CelulaListaPalavra
 * 
 * @param palavra Palavra *
 * @return CelulaListaPalavra* aka VetorCelulaPalavra 
 */
VetorCelulaPalavra criaCelulaListaPalavras(Palavra *palavra)
{
    VetorCelulaPalavra cell = (VetorCelulaPalavra)malloc(sizeof(CelulaListaPalavra));
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
    int nitems = lista->nItens;
    lista->vetor = (VetorCelulaPalavra ) reallocarray(lista->vetor, nitems-1, sizeof(CelulaListaPalavra));
    lista->nItens--;
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
    aux = &lista->vetor[0];
    if(compareString(aux->palavra->string, palavra)){
        rem = aux;
        
        lista->nItens--;
        free(rem);
        return;
    }
    while (true)
    {
        if (aux->prox == NULL) // eh o ultimo
        {
            printf("palavra não encontrada");
            return;
        }
        if(compareString(aux->prox->palavra->string, palavra)){
            rem = aux->prox;
            aux->prox = rem->prox;
            free(rem);
            lista->nItens--;
            return;
        }

        
        aux = aux->prox;
    }
    
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
    for (int i = 0; i < lista->nItens; i++)
    {

        if (compareString(string, lista->vetor[i].palavra->string))
        {
            if (ref != NULL)
            {
                (*ref) = lista->vetor[i];
            }
            return true;
        }
    }
    return false;
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
    if (lista->nItens == 0)
    {
        fputs("lista vazia", output);
        return;
    }
    int i;

    for(i=0; i< lista->nItens;i++)
    {
        imprimePalavra(lista->vetor[i].palavra, output);
    }
}
