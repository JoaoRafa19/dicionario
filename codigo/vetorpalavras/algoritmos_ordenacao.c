#include "./vetorpalavras.h"
#include <string.h>
#include <time.h>

void swap(CelulaListaPalavra * a, CelulaListaPalavra * b)
{
 
    CelulaListaPalavra temp = *a;
 
    *a = *b;
 
    *b = temp;
}

void functionCopia(VetorCelulaPalavra orig, VetorCelulaPalavra  dest, int tam)
{
    for(int i = 0; i < tam; i++)
    {
        dest[i] = orig[i];
    }
}

void bubbleSort(int n, VetorCelulaPalavra vetor, int *comp, int* mov)
{
      int i, j;
    for (i = 0; i < n - 1; i++,(*comp)++){
        for (j = 0; j < n - i - 1; j++,(*comp)++)
        {
            (*comp)++;
            if  (strcmp(vetor[i].palavra->string , vetor[i + 1].palavra->string) > 0 ){
                (*mov)++;
                swap(&vetor[j], &vetor[j + 1]);
                
            }
        }
    }

    
}

void sort(int n, VetorCelulaPalavra vetor, SortFunction func, int* comparacoes, int * movimentacoes, clock_t * clock1, clock_t *clock2)
{
    
    VetorCelulaPalavra vetorAordenar = (VetorCelulaPalavra) calloc(n, sizeof(CelulaListaPalavra));
    functionCopia(vetor, vetorAordenar, n);
    
    
    (*clock1) = clock();
    func(n, vetorAordenar, comparacoes, movimentacoes);

    (*clock2) = clock();

    for(int i=0; i< n;i++)
    {
        imprimePalavra(vetorAordenar[i].palavra, stdout);
    }

    
    free(vetorAordenar);
}




/***/

void insertionSort(int n, VetorCelulaPalavra vetor, int * comp, int* mov){
    int i,j;

    for (i = 1; i < n; i++, (*comp)++) {
        CelulaListaPalavra key = vetor[i];
        for(j = i-1; j >= 0 && (strcmp(vetor[j].palavra->string , key.palavra->string) > 0); j--, (*comp)++, (*mov)++ ) 
            vetor[j + 1] = vetor[j];
        (*mov)++;
        vetor[j + 1] = key;
    }


}
/*------------------------------------------------------*/



 
void heapify(CelulaListaPalavra arr[], int N, int i, int* comp, int* mov)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    (*comp)++;
    if (left < N && strcmp(retornaCadeiaDeCaracteres(arr[left].palavra) ,retornaCadeiaDeCaracteres( arr[largest].palavra)) > 0)
        largest = left;
    (*comp)++;
    if (right < N &&strcmp(retornaCadeiaDeCaracteres(arr[right].palavra) ,retornaCadeiaDeCaracteres( arr[largest].palavra)) > 0)
        largest = right;
 
    (*comp)++;
    if (largest != i) {
        (*mov)++;
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, N, largest, comp, mov);
    }
}
 
void heapsort(int n, CelulaListaPalavra arr[], int* comp, int* mov)
{
    for (int i = n / 2 - 1; i >= 0; i--, (*comp)++)
        heapify(arr, n, i, comp, mov);
 
    for (int i = n - 1; i >= 0; i--, (*comp)++) {
        (*mov) ++;
        swap(&arr[0], &arr[i]);
 
        heapify(arr, i, 0, comp, mov);
    }
}

// -----------------------


void particao(int Esq, int Dir, int *i, int *j, VetorCelulaPalavra A, int* comp, int* mov)
{
    CelulaListaPalavra aux, pivo;
    *i = Esq;
    *j = Dir;
    int indicePivo = (*i + *j) / 2;
    pivo = A[indicePivo];
    
    do
    {
        while (strcmp(retornaCadeiaDeCaracteres(pivo.palavra),  retornaCadeiaDeCaracteres(A[*i].palavra)) > 0) 
        {
            (*comp)++;
            (*i)++;
        }
        while (strcmp(retornaCadeiaDeCaracteres(pivo.palavra),  retornaCadeiaDeCaracteres(A[*j].palavra)) < 0)
        {
            (*comp)++;
            (*j)--;
        } 
        if (*i <= *j)
        {
            (*mov)++;
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;
            (*i)++; (*j)--;
        }
        (*comp)++;
    } while (*i <= *j);
}



void Ordena(int Esq, int Dir, VetorCelulaPalavra A, int* comp, int* mov)
{ 
    int i,j;
    particao(Esq, Dir, &i, &j, A, comp, mov);
    (*comp)++;
    if (Esq < j) Ordena(Esq, j, A, comp, mov);
    (*comp)++;
    if (i < Dir) Ordena(i, Dir, A, comp, mov);
}


void quickSort( int n, VetorCelulaPalavra A, int* comp, int* mov)
{ 
 Ordena(0, n-1, A, comp, mov); 
}

// -------------------------------------------


void selectionSort(int n, VetorCelulaPalavra vetor, int* comp, int* mov){
    int i,j;

    for(i=0;i<=n;i++,(*comp)++)
    {
        int _comp = i;
        for(j = i; j < n; j++,(*comp)++)
        {   
            (*comp)++;
            if(strcmp(vetor[j].palavra->string,  vetor[_comp].palavra->string)<0){
                _comp = j;
            }
        }
        (*mov)++;
        CelulaListaPalavra aux;
        aux = vetor[i];
        vetor[i] = vetor[_comp];
        vetor[_comp] = aux;
    }

}

//----------------------------------------


void shellSort(int n, VetorCelulaPalavra vetor, int* comp, int* mov)
{
    int i,j,h = n / 2;
    CelulaListaPalavra aux;

    for(h=n/2; h>0 ; h = h/2, (*comp) ++)
    {
        for(i=h; i < n;i++, (*comp)++)
        {
            aux = vetor[i];
            for(j = i; j >= h  && (strcmp(aux.palavra->string , vetor[j-h].palavra->string) < 0) ;  j = j-h, (*comp) ++)
            {
                
                (*mov)++;
                vetor[j] = vetor[j-h];
            }
            (*mov)++;
            vetor[j] = aux;
        }
    }
}
