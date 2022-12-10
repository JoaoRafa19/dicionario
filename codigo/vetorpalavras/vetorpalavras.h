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

typedef CelulaListaPalavra* VetorCelulaPalavra;

typedef struct {

    int nItens;
    VetorCelulaPalavra vetor;

} ListaPalavras;

typedef void (*SortFunction)(int,VetorCelulaPalavra);

void sort(int n, VetorCelulaPalavra vetor, SortFunction func);
void bubbleSort(int n, VetorCelulaPalavra  vetor);
void insertionSort(int n, VetorCelulaPalavra vetor);
void heapsort(int n, VetorCelulaPalavra vetor);
void quickSort(int n, VetorCelulaPalavra vetor);
void selectionSort(int n, VetorCelulaPalavra vetor);
void shellSort(int n, VetorCelulaPalavra vetor);

void criaNovaListaDePalavrasVazia(ListaPalavras** lista);
VetorCelulaPalavra criaCelulaListaPalavras(Palavra *palavra);
void inserePalavra(ListaPalavras* lista, VetorCelulaPalavra celula);
void popCelulaListaPalavras(ListaPalavras *lista);
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra);
int verificaPalavraExisteNaLista(ListaPalavras *, String , VetorCelulaPalavra );
int numeroDePalavras(ListaPalavras *lista);
void imprimelistapalavras(ListaPalavras *lista, FILE* output);
int compareString(String s1, String s2);
void insertionSort(int n, VetorCelulaPalavra vetor);