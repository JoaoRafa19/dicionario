

void ordena(int h,int n, Titem *A)
{
    int i,j,k;
    printf("%d", h);
    for(i=h; i < n; i++)
    {
        printf("%d %d\n", i, i-h);
        if(A[i].Chave < A[i-h].Chave);
        {
            puts("eh menor\n");
            printf("%d %d\n", i, i-h);
            Titem aux;
            aux = A[i];
            A[i] = A[i-h];
            A[i-h] = aux;
        }
    }
    
}

void shellSort(int n, Titem *vetor)
{
    int i,j,h = n / 2;
    Titem aux;

    for(h=n/2; h>0 ; h = h/2)
    {
        for(i=h; i < n;i++)
        {
            aux = vetor[i];
            for(j = i; j >= h  && aux.Chave < vetor[j-h].Chave;  j = j-h)
                vetor[j] = vetor[j-h];
               
            vetor[j] = aux;
        }
    }
    return;
    for(h = n/2; h > 0; h = h/2)
        ordena(h, n, vetor);


}

// int main()
// {   
//     int n = 59;
//     int vetor[] = {27, 51, 58, 61, 86, 95, 84, 52, 90, 95, 50, 68, 66, 1, 93, 96, 49, 41, 38, 33, 27, 51, 58, 61, 86, 95, 84, 52, 90, 95, 50, 68, 66, 1, 93, 96, 49, 41, 38, 33, 27, 51, 58, 61, 86, 95, 84, 52, 90, 95, 50, 68, 66, 1, 93, 96, 49, 41, 38};
//     Titem vetortitem[n];
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         Titem item;
//         item.Chave = vetor[i];
//         vetortitem[i] = item;
//     }
//     for (i = 0; i < n; i++)
//     {

//         printf("%d ", vetortitem[i].Chave);
//     }
//     printf("\n");

//     clock_t Ticks[2];

//     Ticks[0] = clock();

//     shellSort(n, vetortitem);

//     Ticks[1] = clock();

//     double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
//     long int Tempo2 = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;

//     printf("Tempo gasto: %g ms.\n", Tempo);
//     printf("Tempo gasto: %ld s.\n", Tempo2);

//     for (i = 0; i < n; i++)
//     {

//         printf("%d ", vetortitem[i].Chave);
//     }
//     printf("\n");
// }