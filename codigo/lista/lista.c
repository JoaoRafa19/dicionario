
#include "lista.h"


/**
 * @brief Implementação lista encadeada vazia
 * 
 * @param lista 
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
CelulaLista *criaCelula(Titem item)
{
    CelulaLista *celula = (CelulaLista *)malloc(sizeof(CelulaLista));
    (*celula).Item = item;
    (*celula).pProx = NULL;
    return celula;
}
int itemExiste(ListaDeOcorrencias * lista, int item){
    PsCelula aux;
    aux = lista->pPrimeiro;
    if(aux->pProx == NULL)return 0;
    do{
        if(aux->Item.linha == item){
            return 1;
        }
        aux = aux->pProx;
    }while(aux->pProx != NULL);
    return 0;
}

/**
 * @brief Adiciona uma Celula a lista
 *
 * @param lista Lista onde a celula deve ser adicionada
 * @param item Ponteiro para a celula que deseja adicionar a lista
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
    }else if(itemExiste(lista, item->Item.linha)){
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
void imprimeLista(ListaDeOcorrencias *list)
{
    if (listaEhVazia(list))
    {
        printf("Lista vazia\n");
        return;
    }
    int i;
    PsCelula aux;
    aux = list->pPrimeiro;
    printf("Linhas: ");
    while (1)
    {

        if (aux->pProx == NULL)
        {

            if(list->nItens == 1){
                printf("|%d|", aux->Item.linha);
            }else{
                printf("%d|", aux->Item.linha);
            }
            break;
        }
        printf("|%d|", aux->Item.linha);

        aux = aux->pProx;
    }
    printf("\n");
}

/**
 * @brief Remove a ultima celula da lisa encadiada
 * 
 * @param l 
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

int listaEhVazia(ListaDeOcorrencias *lista){
    return (lista->nItens == 0 && (( lista->pPrimeiro == lista->pUltimo) && (lista->pUltimo == NULL) ));
}

/**
 * @brief Retorna / imprime o numero de celulas na lista 
 * 
 * @param l lista a 
 * @param pres parametro de retorno opcional
 * @param output stream de saída (arquivo ou saida padrão)
 */
void nitems(ListaDeOcorrencias *l, int *pres, FILE* output)
{   
    if(output != NULL){
        fprintf(output, "%d", l->nItens);
    }
    
    if (pres != NULL)
    {
        (*pres) = l->nItens;
    }
}
