#include "../codigo/dicionario/dicionario.h"




int main(){
    Dicionario *dict;
    inicializaDicionario(&dict);
    controiDicionario("./text/input.txt", dict);

    FILE * arquivo;
    arquivo = fopen("output2.txt", "w");
    if(!arquivo){
        printf("teste");
    }
    else{
        puts("Arquivo");
        imprimeDicionario(dict, arquivo);
    }
    //imprimeDicionario(dict, stdout);

    return 0;
}