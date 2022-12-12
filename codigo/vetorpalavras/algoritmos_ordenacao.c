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

void Refaz(int Esq, int Dir, VetorCelulaPalavra A)
{
    int j = Esq * 2;
    CelulaListaPalavra aux = A[Esq];
    while (j <= Dir){ 
    if ((j < Dir)&& strcmp(A[j].palavra->string , A[j+1].palavra->string) < 0) j++; 
    if (strcmp (aux.palavra->string,  A[j].palavra->string) >=0 ) break;
    A[Esq] = A[j];
        Esq = j; j = Esq * 2 ;
    }
    A[Esq] = aux;
}

void Constroi(VetorCelulaPalavra A, int *n)
{ 
    int Esq;
    Esq = *n / 2 + 1;
    while (Esq > 1)
    { 
        Esq--;
        Refaz(Esq, *n, A);
    }
}

void _Heapsort(VetorCelulaPalavra A, int *n)
{   int Esq, Dir;
    CelulaListaPalavra aux;
    Constroi(A, n); /* constroi o heap */
    Esq = 1; Dir = *n;
    while (Dir > 1)
    { /* ordena o vetor */
        aux = A[1]; A[1] = A[Dir]; A[Dir] = aux;
        Dir--;
        Refaz(Esq, Dir, A);
    }
}

void heapsort(int n, VetorCelulaPalavra A){
    int * pn;
    (*pn) = n;
    _Heapsort(A, pn);
}


// -----------------------


void particao(int Esq, int Dir, int *i, int *j, VetorCelulaPalavra A)
{
    CelulaListaPalavra aux, pivo;
    *i = Esq;
    *j = Dir;
    pivo = A[(*i + *j) / 2];
    do
    {
        while (strcmp(pivo.palavra->string,  A[*i].palavra->string) > 0) (*i)++;
        while (strcmp(pivo.palavra->string,  A[*i].palavra->string) < 0) (*j)--;
        if (*i <= *j)
        {
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;
            (*i)++; (*j)--;
        }

    } while (*i <= *j);
}

void ordena(int Esq, int Dir, VetorCelulaPalavra A)
{
    int i, j;
    particao(Esq, Dir, &i, &j, A);
    if (Esq < j)
        ordena(Esq, j, A);
    if (i < Dir)
        ordena(i, Dir, A);
}

void quickSort(int n, VetorCelulaPalavra vetor)
{
    int i, j;
    ordena(0, n-1, vetor);
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
