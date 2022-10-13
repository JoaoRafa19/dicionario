#include "dicionario/dicionario.h"



int main(){



    Dicionario *dict;
    inicializaDicionario(&dict);

    controiDicionario("./input.txt", dict);
    imprimeDicionario(dict, stdout);
    

    return 0;
}