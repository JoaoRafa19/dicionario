#include "dicionario.h"
#include "string.h"


void criaPalavraDictVazia(PalavraDict ** palavraDict, char letra)
{
    (*palavraDict) = (PalavraDict *) malloc (sizeof(PalavraDict));
    criaNovaListaDePalavrasVazia(&(*palavraDict)->lista);
    (*palavraDict)->prox = NULL;
}



void adicionaPalavraDict(Dicionario *,  PalavraDict * palavraDict);
void removeTablaturasEFimDeLinha(char *);


/**
 * @brief Cria um dicionario a partir de um arquivo de texto
 * 
 * @param filename nome do arquivo de deve ser lido
 */
void controiDicionario(String filename, Dicionario *dict){

    FILE* file = fopen(filename, "r");
    if (!file)
        exit(EXIT_FAILURE);

    char *contents = NULL;
    int line = 1;
    size_t len = 0;
    while (getline(&contents, &len, file) != EOF){

        char * palavraSeparadaPorEspacos;
        // contents = "o pato viu a vela e ficou com medo do fogo pois a vela era quente"
        palavraSeparadaPorEspacos = strtok(contents," ");
        

        while (palavraSeparadaPorEspacos != NULL)
        {
            
            Palavra *p;
            criaPalavraVazia(&p);

            removeTablaturasEFimDeLinha(palavraSeparadaPorEspacos);
            preencheCadeiaDeCaracteres(p, palavraSeparadaPorEspacos);
            adicionaOcorrecia(p, line);
            imprimePalavra(p, stdout);

            

            //adicionar palavra ao dicionario
            palavraSeparadaPorEspacos = strtok (NULL, " ");
        }
                
        line ++;
    }

    fclose(file);
    free(contents);

    exit(EXIT_SUCCESS);
   
}

/**
 * @brief Remove tabs e fim de linha de uma string
 * 
 * @param s 
 */
void removeTablaturasEFimDeLinha(String s) {
    String p2 = s;
    while(*s != '\0') {
        if(*s != '\t' && *s != '\n') {
            *p2++ = *s++;
        } else {
            ++s;
        }
    }
    *p2 = '\0';
}

/**
 * @brief Cria um dicionario novo na memória
 * 
 * @param dict 
 */
void inicializaDicionario(Dicionario ** dict){
    (*dict) = (Dicionario *) malloc(sizeof(Dicionario));
    (*dict)->nitens = 0;
    (*dict)->primeiro = (*dict)->ultimo = NULL;
}

