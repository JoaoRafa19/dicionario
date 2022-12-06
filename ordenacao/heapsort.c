#include "../codigo/palavra/palavra.h"


void Refaz(int Esq, int Dir, Titem *A)
{
    int j = Esq * 2;
    Titem aux = A[Esq];
    while (j <= Dir){ 
        if ((j < Dir)&&(A[j].Chave < A[j+1].Chave)) j++; 
        if (aux.Chave >= A[j].Chave) break;
        A[Esq] = A[j];
        Esq = j; j = Esq * 2 ;
    }
    A[Esq]= aux;
}