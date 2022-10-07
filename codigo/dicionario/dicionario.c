#include "dicionario.h"
#include "string.h"

void readFile(String filename){

    FILE* input_file = fopen(filename, "r");
    if (!input_file)
        exit(EXIT_FAILURE);

    char *contents = NULL;
    int line = 0;
    size_t len = 0;
    while (getline(&contents, &len, input_file) != -1){
        
        
        
        char * pch;
        printf("\nline %d\n", line);
        pch = strtok (contents," ");
        while (pch != NULL)
        {
            printf ("%s|",pch);
            //adicionar palavra ao dicionario
            pch = strtok (NULL, " ");
        }
                
        line ++;
    }

    fclose(input_file);
    free(contents);

    exit(EXIT_SUCCESS);
   
}