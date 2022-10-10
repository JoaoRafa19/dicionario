#include "dicionario.h"
#include "string.h"


void criaPalavraDictVazia(PalavraDict ** palavraDict, char letra)
{
    (*palavraDict) = (PalavraDict *) malloc (sizeof(PalavraDict));
    criaNovaListaDePalavrasVazia(&(*palavraDict)->lista);
    (*palavraDict)->prox = NULL;
}



void adicionaPalavraDict(Dicionario *,  PalavraDict * palavraDict);
void strip(char *);





/**
 * @brief Cria um dicionario a partir de um arquivo de texto
 * 
 * @param filename nome do arquivo de deve ser lido
 */
void controiDicionario(String filename, Dicionario *dict){

    FILE* input_file = fopen(filename, "r");
    if (!input_file)
        exit(EXIT_FAILURE);

    char *contents = NULL;
    int line = 0;
    size_t len = 0;
    while (getline(&contents, &len, input_file) != EOF){
          
        char * pch;
        pch = strtok (contents," ");
        while (pch != NULL)
        {

            
            
            Palavra *p;
            criaPalavraVazia(&p);

            strip(pch);
            preencheCadeiaDeCaracteres(p, pch);
            adicionaLinha(p, line);
            imprimePalavra(p, stdout);

            

            //adicionar palavra ao dicionario
            pch = strtok (NULL, " ");
        }
                
        line ++;
    }

    fclose(input_file);
    free(contents);

    exit(EXIT_SUCCESS);
   
}

/**
 * @brief Função que remove tablaturas e fim de linha de uma string
 * 
 * @param s 
 */
void strip(String s) {
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

void inicializaDicionario(Dicionario ** dict){
    (*dict) = (Dicionario *) malloc(sizeof(Dicionario));
    (*dict)->nitens = 0;
    (*dict)->primeiro = (*dict)->ultimo = NULL;
}

