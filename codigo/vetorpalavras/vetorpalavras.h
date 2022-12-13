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

} CelulaListaPalavra;

typedef CelulaListaPalavra* VetorCelulaPalavra;

typedef struct {

    int nItens;
    VetorCelulaPalavra vetor;

} ListaPalavras;

typedef void (*SortFunction)(int,VetorCelulaPalavra, int*, int*);

void sort(int n, VetorCelulaPalavra vetor, SortFunction func, int* comparacoes, int * movimentacoes, clock_t * clock1, clock_t *clock2);
void bubbleSort(int n, VetorCelulaPalavra  vetor, int*, int*);
void insertionSort(int n, VetorCelulaPalavra  vetor, int*, int*);
void heapsort(int n, VetorCelulaPalavra  vetor, int*, int*);
void quickSort(int n, VetorCelulaPalavra  vetor, int*, int*);
void selectionSort(int n, VetorCelulaPalavra  vetor, int*, int*);
void shellSort(int n, VetorCelulaPalavra  vetor, int*, int*);

void criaNovaListaDePalavrasVazia(ListaPalavras** lista);
VetorCelulaPalavra criaCelulaListaPalavras(Palavra *palavra);
void inserePalavra(ListaPalavras* lista, VetorCelulaPalavra celula);
void popCelulaListaPalavras(ListaPalavras *lista);
void removeCelulaListaPalavra(ListaPalavras *lista, String palavra);
int verificaPalavraExisteNaLista(ListaPalavras *, String , VetorCelulaPalavra );
int numeroDePalavras(ListaPalavras *lista);
void imprimelistapalavras(ListaPalavras *lista, FILE* output);
int compareString(String s1, String s2);