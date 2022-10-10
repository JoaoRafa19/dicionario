#include "../codigo/dicionario/dicionario.h"



int main(){
    Dicionario *dict;
    inicializaDicionario(&dict);
    controiDicionario("./text/input.txt", dict);

    return 0;
}