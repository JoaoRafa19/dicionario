/**
 * @file listapalavras.h   
 * @author João Pedro (github.com/JoaoRafa19)
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../palavra/palavra.h"

typedef struct TLPCell* Pointer;
typedef struct TLPCell {

    Palavra *palavra;
    Pointer prox;

} LPCell;

typedef struct t_lista_palavras {

    int nItens;

    Pointer primeiro;
    Pointer ultimo;

} ListaPalavras;


void criaNovaListaDePalavrasVazia(ListaPalavras** lista);
void inserePalavra(ListaPalavras* lista, LPCell *celula);
LPCell* criaCelulaListaPalavras(Palavra* palavra);
void popCelulaListaPalavras(ListaPalavras *lista);
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra);
void verificaPalavraExisteNaLista(ListaPalavras *lista, String string);
int numeroDePalavras(ListaPalavras *lista);
void imprimelistapalavras(ListaPalavras *lista);