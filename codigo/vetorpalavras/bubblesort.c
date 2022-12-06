#include "./vetorpalavras.h"

void bubbleSort(int n, CelulaListaPalavra * vetor)
{
    int i, j;

    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (vetor[i].palavra->string[0] > vetor[i + 1].palavra->string[0] )
            {
                CelulaListaPalavra aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
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

//     bubbleSort(60, vetortitem);

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