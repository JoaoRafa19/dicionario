#include "dicionario/dicionario.h"

#define ESC "\033["
#define CLEAR ESC "H" ESC "J"

void eval(const char *cd)
{
    printf("%s", cd);
}

void clear()
{
    eval(CLEAR);
}

void constroiDicionarioMenu(Dicionario *dict, char *filename)
{
    int dicionarioConstruido = 0;
    char * message = "digite o nome do arquivo :";
    while (!dicionarioConstruido)
    {
        printf("%s", message);
        scanf("%s", filename);
        dicionarioConstruido = constroiDicionario(filename, dict);
        printf("%c[2K", 27); //apaga a linha
        printf("\033[A"); //volta uma linha pra cima
        printf("\33[2K"); //volta o cursor pro começo da linha
        message = "\rarquivo não encontrado digite outro arquivo:";
    }
}
void pause(char * c){
            puts("ENTER para continuar");
            do{
                (*c) = getchar();
            } while ((*c) != '\n' && (*c) != EOF);
            (*c) = getchar();
}





int main()
{

    Dicionario *dict;
    inicializaDicionario(&dict);

    char filename[100];
    char op;

    while (op != 'q')
    {

        clear();
        puts("Digite o numero referente a opcao desejada e enter para confirmar ('q' para sair)\n");
        printf("1) Adicionar palavas de um texto ao dicionario a partir de um arquivo\n");
        printf("2) imprimir dicionario no console\n");
        printf("3) imprimir seção de uma letra no console\n");
        printf("4) imprimir todas as palavras \n");
        printf("5) limpar dicionario\n");
        printf("6) imprimir dicionario em um arquivo de saída \n(ao fim da execuçao por padrão será criado o arquivo output.txt com a saida)\n");

        printf("q - SAIR\n>");

        
        op = getchar();
        if (op == '1')
        {
            constroiDicionarioMenu(dict, filename);
        }
        if (op == '2')
        {
            imprimeDicionario(dict, stdout);
            pause(&op);
        }
        if(op == '3'){
            DictSession *session = (DictSession *)malloc(sizeof(DictSession));
            char letra[1];
            printf("digite a letra que deseja buscar: ");
            scanf("%s",letra);
            if(verificaLetraExisteNoDicionario(letra, dict, session)){
                imprimePalavraDict(session, stdout);
                pause(&op);
            }else{  
                printf("Letra não encontrada no dicionario.");
            }

        }

        if(op == '4'){
            mostraTodasAsPalavras(dict);
            pause(&op);
        }
        if(op == '5'){
            free(dict);
            inicializaDicionario(&dict);
        }
        if(op == '6'){
            puts("Digite o nome do arquivo que deseja imprimir a saida: ");
            scanf("%s", filename);
            FILE * outputfile = fopen(filename, "w");
            if (!outputfile)
            {
                puts("problema ao escrever arquivo");
            }
            else
            {
                imprimeDicionario(dict, outputfile);
            }
        }
    }

    FILE *file = fopen("./output.txt", "w");
    if (!file)
    {
        puts("problema ao escrever arquivo");
    }
    else
    {
        imprimeDicionario(dict, file);
    }

    free(dict);
    return 0;
}