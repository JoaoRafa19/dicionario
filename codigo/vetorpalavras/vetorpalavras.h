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


typedef struct sCelulaListaPalavra* PsCelulaListaPalavra;
typedef struct sCelulaListaPalavra {

    Palavra *palavra;
    PsCelulaListaPalavra prox;

} CelulaListaPalavra;

typedef struct {

    int nItens;
    PsCelulaListaPalavra vetor;

} ListaPalavras;


void criaNovaListaDePalavrasVazia(ListaPalavras** lista);
CelulaListaPalavra *criaCelulaListaPalavras(Palavra *palavra);
void inserePalavra(ListaPalavras* lista, CelulaListaPalavra *celula);
void popCelulaListaPalavras(ListaPalavras *lista);
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra);
int verificaPalavraExisteNaLista(ListaPalavras *, String , CelulaListaPalavra *);
int numeroDePalavras(ListaPalavras *lista);
void imprimelistapalavras(ListaPalavras *lista, FILE* output);
int compareString(String s1, String s2);
void bubbleSort(int n, CelulaListaPalavra * vetor);