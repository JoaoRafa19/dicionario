#include "../codigo/dicionario/dicionario.h"



int main(){
    Dicionario *dict;
    inicializaDicionario(&dict);
    controiDicionario("./text/input.txt", dict);
    imprimeDicionario(dict, stdout);

    return 0;
}