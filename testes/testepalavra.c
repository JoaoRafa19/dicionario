#include<stdio.h>
#include "../codigo/palavra/palavra.h"

int main(){


    Palavra *p;
    criaPalavraVazia(&p);

    preencheCadeiaDeCaracteres(p, "teste");

    
    printf("%s\n", retornaCadeiaDeCaracteres(p));
    imprimeCadeiaDeCaracteres(p);

    imprimePalavra(p);
    

}