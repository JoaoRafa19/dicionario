#include "tad/tad.h"
#include <stdio.h>
#include <time.h>

void selectionSort(int n, Titem* vetor){
    int i,j;

    for(i=0;i<=n;i++)
    {
        int comp = i;
        for(j = i; j < n; j++)
        {
            if(vetor[j].Chave < vetor[comp].Chave){
                comp = j;
            }
        }
        Titem aux;
        aux = vetor[i];
        vetor[i] = vetor[comp];
        vetor[comp] = aux;
    }

}


// int main(){

//     int vetor[] = {27,51,58,61,86,95,84,52,90,95,50,68,66,1,93,96,49,41,38,33,27,51,58,61,86,95,84,52,90,95,50,68,66,1,93,96,49,41,38,33,27,51,58,61,86,95,84,52,90,95,50,68,66,1,93,96,49,41,38};
//     Titem vetortitem[60];
//     int i; 
//     for(i=0;i<60;i++)
//     {
//         Titem item;
//         item.Chave = vetor[i];
//         vetortitem[i] = item;

//     }
//     for(i=0;i<60;i++)
//     {
        
//         printf("%d ", vetortitem[i].Chave);

//     }printf("\n");

//     clock_t Ticks[2];
    
//     Ticks[0] = clock();

//     selectionSort(60, vetortitem);

//     Ticks[1] = clock();

//     double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
//     long int Tempo2 = (Ticks[1] - Ticks[0]) / CLOCKS_PER_SEC;
    
//     printf("Tempo gasto: %g ms.\n", Tempo);
//     printf("Tempo gasto: %ld s.\n", Tempo2);


//     for(i=0;i<60;i++)
//     {
        
//         printf("%d ", vetortitem[i].Chave);

//     }printf("\n");

// }