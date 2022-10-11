
#include "lista.h"


/**
 * @brief Implementação lista encadeada vazia
 * 
 * @param lista ListaDeOcorrencias **
 */
void fazListaVazia(ListaDeOcorrencias **lista)
{

    (*lista) = (ListaDeOcorrencias *)malloc(sizeof(ListaDeOcorrencias));
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
 * @param line int
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
 * @retval Retorna a celula a ser adicionada na lista
 */
CelulaLista *criaCelula(Titem item)
{
    CelulaLista *celula = (CelulaLista *)malloc(sizeof(CelulaLista));
    (*celula).Item = item;
    (*celula).pProx = NULL;
    return celula;
}

/**
 * @brief Adiciona uma Celula a lista
 *
 * @param lista ListaDeOcorrencias *
 * @param item CelulaLista *
 */
void adicionarCelula(ListaDeOcorrencias *lista, CelulaLista *item)
{
    int i;
    PsCelula aux;
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
            if(aux->Item.linha == item->Item.linha ){
                return; //sem repetição
            }
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
 * @param list ListaDeOcorrencias *
 * @param output FILE *
 */
void imprimeLista(ListaDeOcorrencias *list, FILE *output)
{
    if (listaEhVazia(list))
    {
        printf("Lista vazia\n");
        return;
    }
    int i;
    PsCelula aux;
    aux = list->pPrimeiro;
    fprintf(output, "Linhas: ");
    while (1)
    {

        if (aux->pProx == NULL)
        {

            if(list->nItens == 1){
                fprintf(output, "|%d|", aux->Item.linha);
            }else{
                fprintf(output, "%d|", aux->Item.linha);
            }
            break;
        }
        fprintf(output, "|%d|", aux->Item.linha);

        aux = aux->pProx;
    }
    fprintf(output,"\n");
}

/**
 * @brief Remove a ultima celula da lisa encadiada
 * 
 * @param l ListaDeOcorrencias *
 */
void removeUltimaCelula(ListaDeOcorrencias *l)
{
    if(listaEhVazia(l)) return;
    PsCelula aux;
    PsCelula rem;
    aux = l->pPrimeiro;
    while (1)
    {   
        if(aux->pProx == NULL){
            rem = aux;
            break;
        }
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
  * @brief Verifica se a lista é vazia
  * 
  * @param lista ListaDeOcorrencias *
  * @return int bool
  */
int listaEhVazia(ListaDeOcorrencias *lista){
    return (lista->nItens == 0 && (( lista->pPrimeiro == lista->pUltimo) && (lista->pUltimo == NULL) ));
}


/**
 * @brief Retorna / imprime o numero de celulas na lista 
 * 
 * @param lista ListaDeOcorrencias *
 * @param pres int *
 * @param output stream de saída (arquivo ou saida padrão)
 */
void nitems(ListaDeOcorrencias *lista, int *pres, FILE* output)
{   
    if(output != NULL){
        fprintf(output, "%d", lista->nItens);
    }
    
    if (pres != NULL)
    {
        (*pres) = lista->nItens;
    }
}
