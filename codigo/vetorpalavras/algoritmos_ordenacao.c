#include "./vetorpalavras.h"
#include <string.h>
#include <time.h>



void functionCopia(VetorCelulaPalavra orig, VetorCelulaPalavra  dest, int tam)
{
    
    for(int i = 0; i < tam; i++)
    {
        dest[i] = orig[i];
    }
}

void bubbleSort(int n, VetorCelulaPalavra vetor, int *mov, int* comp)
{
    int i, j;

    for (j = 0; j < n - 1; j++,(*comp) ++)
    {
        for (i = 0; i < n - 1; i++,(*comp) ++)
        {   
            (*comp) ++;
            if (strcmp(vetor[i].palavra->string , vetor[i + 1].palavra->string) > 0 )
            {
                (*mov)++;
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
    int movimentacoes, comparacoes;
    clock_t Ticks[2];
		clock_t Ticks2[2];
		
		Ticks[0] = clock();
		Ticks2[0] = clock();
		func(n, vetorAordenar, &comparacoes, &movimentacoes);

		Ticks[1] = clock();
		Ticks2[1] = clock();

        for(int i=0; i< n;i++)
        {
            imprimePalavra(vetorAordenar[i].palavra, stdout);
        }

		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		long int Tempo2 = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
		fprintf(stdout, "%gms %lds\n", Tempo, Tempo2);
		printf("Tempo gasto: %g ms.\n", Tempo);
		printf("Tempo gasto: %ld s.\n", Tempo2);
        printf("Numero de comparacoes: %d\n", comparacoes);
        printf("Numero de movimentacoes: %d\n", movimentacoes);
    
    
}




/***/

void insertionSort(int n, VetorCelulaPalavra vetor, int * comp, int* mov){
    int i,j;

    for (i = 1; i < n; i++) {
        (*comp++);
        CelulaListaPalavra key = vetor[i];
        for(j = i-1; j >= 0 && (strcmp(vetor[j].palavra->string , key.palavra->string) > 0); j--) 
        {
            (*comp++);
            (*mov)++;
            vetor[j + 1] = vetor[j];
        }
            
        (*mov)++;
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
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, comp, mov);
 
    for (int i = n - 1; i >= 0; i--) {
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
        for(j = i; j < n; j++)
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
