#include "tad/tad.h"
#include <stdio.h>
#include <time.h>

void particao(int Esq, int Dir, int *i, int *j, Titem *A)
{
    Titem aux, pivo;
    *i = Esq;
    *j = Dir;
    pivo = A[(*i + *j) / 2];
    do
    {
        while (pivo.Chave > A[*i].Chave) (*i)++;
        while (pivo.Chave < A[*j].Chave) (*j)--;
        if (*i <= *j)
        {
            aux = A[*i];
            A[*i] = A[*j];
            A[*j] = aux;
            (*i)++; (*j)--;
        }

    } while (*i <= *j);
}

void ordena(int Esq, int Dir, Titem *A)
{
    int i, j;
    particao(Esq, Dir, &i, &j, A);
    if (Esq < j)
        ordena(Esq, j, A);
    if (i < Dir)
        ordena(i, Dir, A);
}

void quickSort(int n, Titem *vetor)
{
    int i, j;
    ordena(0, n-1, vetor);
}

// int main()
// {

//     int vetor[] = {27, 51, 58, 61, 86, 95, 84, 52, 90, 95, 50, 68, 66, 1, 93, 96, 49, 41, 38, 33, 27, 51, 58, 61, 86, 95, 84, 52, 90, 95, 50, 68, 66, 1, 93, 96, 49, 41, 38, 33, 27, 51, 58, 61, 86, 95, 84, 52, 90, 95, 50, 68, 66, 1, 93, 96, 49, 41, 38};
//     Titem vetortitem[60];
//     int i;
//     for (i = 0; i < 60; i++)
//     {
//         Titem item;
//         item.Chave = vetor[i];
//         vetortitem[i] = item;
//     }
//     for (i = 0; i < 60; i++)
//     {

//         printf("%d ", vetortitem[i].Chave);
//     }
//     printf("\n");

//     clock_t Ticks[2];

//     Ticks[0] = clock();

//     quickSort(60, vetortitem);

//     Ticks[1] = clock();

//     double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
//     long int Tempo2 = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;

//     printf("Tempo gasto: %g ms.\n", Tempo);
//     printf("Tempo gasto: %ld s.\n", Tempo2);

//     for (i = 0; i < 60; i++)
//     {

//         printf("%d ", vetortitem[i].Chave);
//     }
//     printf("\n");
// }