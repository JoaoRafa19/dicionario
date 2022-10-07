
#include "lista.h"

/**
 * @brief Implementação lista encadeada vazia
 * 
 * @param lista 
 */
void FLVazia(Lista **lista)
{

    (*lista) = (Lista *)malloc(sizeof(Lista));
    if ((*lista) == NULL)
    {
        printf("deu erro");
    }
    (*lista)->nItens = 0;
    (*lista)->pPrimeiro = (*lista)->pUltimo = NULL;
}

/*
 * @brief cria um Titem
 *
 * @param line integer value for the line
 * @retval Retorna um Titem com a linha passada como parametro
 * @return Titem*
 */
Titem criaTitem(int line)
{

    Titem ptItem;
    ptItem.linha = line;
    return ptItem;
}

/**
 * @brief Cria uma celula com um Titem dentro
 *
 * @param item Parametro por cópia que será copiado dentro da TCelula criada
 * @return TCelula*
 */
TCelula *criaCelula(Titem item)
{
    TCelula *celula = (TCelula *)malloc(sizeof(TCelula));
    (*celula).Item = item;
    (*celula).pProx = NULL;
    return celula;
}

/**
 * @brief Adiciona uma Celula a lista
 *
 * @param lista Lista onde a celula deve ser adicionada
 * @param item Ponteiro para a celula que deseja adicionar a lista
 */
void adicionarCelula(Lista *lista, TCelula *item)
{
    int i;
    Apontador aux;
    aux = lista->pPrimeiro;
    if (aux == NULL)
    {
        lista->pPrimeiro = lista->pUltimo = item;
        lista->nItens++;
        return;
    }
    else
    {
        while (1)
        {
            if (aux->pProx == NULL)
            {
                break;
            }
            aux = aux->pProx;
        }
        aux->pProx = item;
        lista->pUltimo = item;
        lista->nItens++;
    }
}


/**
 * @brief Imprime na saida padrão a lista de Titems
 * 
 * @param l 
 */
void imprimeLista(Lista *l)
{
    if (l->nItens == 0)
    {
        printf("Lista vazia\n");
        return;
    }
    int i;
    Apontador aux;
    aux = l->pPrimeiro;

    while (1)
    {

        if (aux->pProx == NULL)
        {

            printf("%d", aux->Item.linha);
            break;
        }
        printf("%d->", aux->Item.linha);

        aux = aux->pProx;
    }
    printf("\n");
}

/**
 * @brief Remove a ultima celula da lisa encadiada
 * 
 * @param l 
 */
void popCell(Lista *l)
{
    Apontador aux;
    Apontador rem;
    aux = l->pPrimeiro;
    while (1)
    {
        if (aux->pProx->pProx == NULL) // eh o ultimo
        {
            rem = aux->pProx;
            break;
        }

        aux = aux->pProx;
    }
    l->nItens--;
    aux->pProx = NULL;
    free(rem);
}


/**
 * @brief Retorna / imprime o numero de celulas na lista 
 * 
 * @param l lista a 
 * @param pres parametro de retorno opcional
 * @param output stream de saída (arquivo ou saida padrão)
 */
void nitems(Lista *l, int *pres, FILE* output)
{   
    if(output != NULL){
        fprintf(output, "%d", l->nItens);
    }
    
    if (pres != NULL)
    {
        (*pres) = l->nItens;
    }
}
