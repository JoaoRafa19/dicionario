#include "./vetorpalavras.h"
#include <string.h>



void functionCopia(VetorCelulaPalavra orig, VetorCelulaPalavra  dest, int tam)
{
    
    for(int i = 0; i < tam; i++)
    {
        dest[i] = orig[i];
    }
}

void bubbleSort(int n, VetorCelulaPalavra vetor)
{
    int i, j;

    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (strcmp(vetor[i].palavra->string , vetor[i + 1].palavra->string) > 0 )
            {
                CelulaListaPalavra aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
    
    
}

void sort(int n, VetorCelulaPalavra vetor, SortFunction func)
{
    
    VetorCelulaPalavra vetorAordenar = (VetorCelulaPalavra) calloc(n, sizeof(CelulaListaPalavra));
    functionCopia(vetor, vetorAordenar, n);
    func(n, vetorAordenar);
    for(int i=0; i< n;i++)
    {
        imprimePalavra(vetorAordenar[i].palavra, stdout);
    }
    
}




/***/

void insertionSort(int n, VetorCelulaPalavra vetor){
    int i,j;

    for (i = 1; i < n; i++) {
        CelulaListaPalavra key = vetor[i];
        for(j = i-1; j >= 0 && (strcmp(vetor[j].palavra->string , key.palavra->string) > 0); j--) 
            vetor[j + 1] = vetor[j];
            
        vetor[j + 1] = key;
    }


}
/*------------------------------------------------------*/


void swap(CelulaListaPalavra * a, CelulaListaPalavra * b)
{
 
    CelulaListaPalavra temp = *a;
 
    *a = *b;
 
    *b = temp;
}
 
void heapify(CelulaListaPalavra arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && strcmp(retornaCadeiaDeCaracteres(arr[left].palavra) ,retornaCadeiaDeCaracteres( arr[largest].palavra)) > 0)
        largest = left;
    if (right < N &&strcmp(retornaCadeiaDeCaracteres(arr[right].palavra) ,retornaCadeiaDeCaracteres( arr[largest].palavra)) > 0)
        largest = right;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, N, largest);
    }
}
 
void heapsort(int n, CelulaListaPalavra arr[])
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
 
        heapify(arr, i, 0);
    }
}

// -----------------------


void particao(int Esq, int Dir, int *i, int *j, VetorCelulaPalavra A)
{
    CelulaListaPalavra aux, pivo;
    *i = Esq;
    *j = Dir;
    int indicePivo = (*i + *j) / 2;
    pivo = A[indicePivo];
    
    do
    {
        while (strcmp(retornaCadeiaDeCaracteres(pivo.palavra),  retornaCadeiaDeCaracteres(A[*i].palavra)) > 0) (*i)++;
        while (strcmp(retornaCadeiaDeCaracteres(pivo.palavra),  retornaCadeiaDeCaracteres(A[*j].palavra)) < 0) (*j)--;
        if (*i <= *j)
        {
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;
            (*i)++; (*j)--;
        }

    } while (*i <= *j);
}



void Ordena(int Esq, int Dir, VetorCelulaPalavra A)
{ 
int i,j;
 particao(Esq, Dir, &i, &j, A);
 if (Esq < j) Ordena(Esq, j, A);
 if (i < Dir) Ordena(i, Dir, A);
}


void quickSort( int n, VetorCelulaPalavra A)
{ 
 Ordena(0, n-1, A); 
}

// -------------------------------------------


void selectionSort(int n, VetorCelulaPalavra vetor){
    int i,j;

    for(i=0;i<=n;i++)
    {
        int comp = i;
        for(j = i; j < n; j++)
        {
            if(strcmp(vetor[j].palavra->string,  vetor[comp].palavra->string)<0){
                comp = j;
            }
        }
        CelulaListaPalavra aux;
        aux = vetor[i];
        vetor[i] = vetor[comp];
        vetor[comp] = aux;
    }

}

//----------------------------------------


void ordenaShell(int h,int n, VetorCelulaPalavra A)
{
    int i,j,k;
    printf("%d", h);
    for(i=h; i < n; i++)
    {
        printf("%d %d\n", i, i-h);
        if(strcmp(A[i].palavra->string , A[i-h].palavra->string) < 0)
        {
            CelulaListaPalavra aux;
            aux = A[i];
            A[i] = A[i-h];
            A[i-h] = aux;
        }
    }
    
}

void shellSort(int n, VetorCelulaPalavra vetor)
{
    int i,j,h = n / 2;
    CelulaListaPalavra aux;

    for(h=n/2; h>0 ; h = h/2)
    {
        for(i=h; i < n;i++)
        {
            aux = vetor[i];
            for(j = i; j >= h  && (strcmp(aux.palavra->string , vetor[j-h].palavra->string) < 0) ;  j = j-h)
                vetor[j] = vetor[j-h];
               
            vetor[j] = aux;
        }
    }
    return;
    for(h = n/2; h > 0; h = h/2)
        ordenaShell(h, n, vetor);


}
