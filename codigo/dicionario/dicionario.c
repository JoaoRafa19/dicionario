#include "dicionario.h"
#include "string.h"
#include "stdbool.h"
#include <time.h>

#define first 0
/**
 * @brief Remove tabs e fim de linha de uma string
 *
 * @param s String
 */
void removeTablaturasEFimDeLinha(String s)
{
    String p2 = s;
    while (*s != '\0')
    {
        if (*s != '\t' && *s != '\n' && *s != '\0' && *s != '\20' && *s != '\b' && *s != '\r' && *s != '\v' && *s != '\\' && *s != '\?' && *s != '\'' && *s != '\r' && *s != '.' && *s != ',' && *s != '?' )
        {
            *p2++ = *s++;
        }
        else
        {
            ++s;
        }
    }
    *p2 = '\0';
}

/**
 * @brief Imprime a seção da letra no dicionario
 *
 * @param palavradict DictSession *
 * @param output FILE *
 */
void imprimePalavraDict(DictSession *palavradict, FILE *output)
{
    if (palavradict->lista->nItens > 0)
    {

        fputs("***********************************\n", output);
        fprintf(output, "Letra:[ %c ] numero de palavras:[%d]\n\n", palavradict->letra, palavradict->lista->nItens);
        imprimelistapalavras(palavradict->lista, output);
        fputs("***********************************\n\n", output);
    }
}

/**
 * @brief Cria uma PalavraDict e adiciona a letra correspondente
 *
 * @param palavraDict DictSession **
 * @param letra char
 */
void criaPalavraDictVazia(DictSession **palavraDict, char letra)
{
    (*palavraDict) = (DictSession *)malloc(sizeof(DictSession));
    criaNovaListaDePalavrasVazia(&(*palavraDict)->lista);
    (*palavraDict)->prox = NULL;
    (*palavraDict)->letra = letra;
}

/**
 * @brief Adiciona uma DictSession ao dicionario
 *
 * @param dict Dicionario *
 * @param item Ponteiro para a celula que deseja adicionar a lista
 */
void adicionarPalavraDict(Dicionario *dict, PsDictSession item)
{
    int i;
    PPalavraDict aux;
    aux = dict->primeiro;
    if (aux == NULL)
    {
        dict->primeiro = dict->ultimo = item;
        dict->nitens++;
        return;
    }
    else
    {
        while (true)
        {
            if (item->letra < aux->letra)
            { // insere no inicio
                item->prox = aux;
                dict->primeiro = item;
                dict->nitens++;
                return;
            }
            if (aux->prox == NULL) // insere no final
            {
                aux->prox = item;
                dict->ultimo = item;
                dict->nitens++;
                return;
            }
            // a->c  d
            if (item->letra > aux->letra && item->letra < aux->prox->letra) // insere no meio
            {
                item->prox = aux->prox;
                aux->prox = item;
                dict->nitens++;
                return;
            }
            
            aux = aux->prox;
        }
    }
}
int verificaLetraExisteNoDicionario(String palavra, Dicionario *dict, PPalavraDict ref)
{
    PPalavraDict aux;

    aux = dict->primeiro;

    if (aux == NULL)
        return false;
    
    while (true)
    {
        if (aux->letra == palavra[first])
        {
            (*ref) = (*aux);
            return true;
        }
        if (aux->prox == NULL)
        {
            return false;
        }
        aux = aux->prox;
    }

    return false;
}

void adicionaLinha(Dicionario *dict, int line, String palavraSeparadaPorEspacos)
{

    while (palavraSeparadaPorEspacos != NULL)
    {

        // adicionar palavra ao dicionario

        DictSession *session = (DictSession *)malloc(sizeof(DictSession));

        CelulaListaPalavra * celula;

        Palavra *p;
        criaPalavraVazia(&p);
        removeTablaturasEFimDeLinha(palavraSeparadaPorEspacos);
        preencheCadeiaDeCaracteres(p, palavraSeparadaPorEspacos);
        celula = criaCelulaListaPalavras(p);
        if (verificaLetraExisteNoDicionario(palavraSeparadaPorEspacos, dict, session))
        {

            if (verificaPalavraExisteNaLista(session->lista, palavraSeparadaPorEspacos, celula))
            {
                adicionaOcorrecia(celula->palavra, line);
            }
            else
            {
                adicionaOcorrecia(p, line);
                celula = criaCelulaListaPalavras(p);
                inserePalavra(session->lista, celula);
            }
        }
        else
        {
            DictSession *session;
            criaPalavraDictVazia(&session, p->string[first]);
            adicionarPalavraDict(dict, session);
            adicionaOcorrecia(p, line);
            celula = criaCelulaListaPalavras(p);
            inserePalavra(session->lista, celula);
        }
        session = NULL;
        free(session);
        palavraSeparadaPorEspacos = strtok(NULL, " ");
    }
}
/**
 * @brief Cria um dicionario a partir de um arquivo de texto
 *
 * @param filename nome do arquivo de deve ser lido
 */
int constroiDicionario(String filename, Dicionario *dict)
{

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return 0;
    }

    char *contents = NULL;
    int line = 1;
    size_t len = 0;
    while (getline(&contents, &len, file) != EOF)
    {

        char *palavraSeparadaPorEspacos;
        // contents = "o pato viu a vela e ficou com medo do fogo pois a vela era quente"
        palavraSeparadaPorEspacos = strtok(contents, " ");

        adicionaLinha(dict, line, palavraSeparadaPorEspacos);
        line++;
    }

    fclose(file);
    free(contents);
    return true;
}

void imprimeDicionario(Dicionario *dict, FILE *output)
{
    if (dict->nitens == 0 && (dict->primeiro == dict->ultimo) && (dict->primeiro == NULL))
    {
        puts("Dicionario vazio");
        return;
    }
    int i;
    PPalavraDict aux;
    aux = dict->primeiro;

    while (1)
    {

        if (aux->prox == NULL)
        {
            imprimePalavraDict(aux, output);
            break;
        }
        imprimePalavraDict(aux, output);

        aux = aux->prox;
    }
}
void imprimeDicionarioOrdenado(Dicionario *dict, char option)
{
    if (dict->nitens == 0 && (dict->primeiro == dict->ultimo) && (dict->primeiro == NULL))
    {
        puts("Dicionario vazio");
        return;
    }
    int i;
    DictSession * aux;
    aux = dict->primeiro;
    int movimentacoes = 0;
    int comparacoes = 0;
    double total_time = 0; 
    clock_t clock1;
    clock_t clock2;

    while (true)
    {

        if (aux->prox == NULL)
        {
            imprimeOrdenado(option, aux, &comparacoes, &movimentacoes, &clock1, &clock2);
            total_time += (clock2 - clock1) * 1000.0 / CLOCKS_PER_SEC;
            break;
        }
        imprimeOrdenado(option, aux, &comparacoes, &movimentacoes, &clock1, &clock2);
        total_time += (clock2 - clock1) * 1000.0 / CLOCKS_PER_SEC;
        aux = aux->prox;
    }
    printf("Tempo gasto: %g ms.\n", total_time);
    printf("Tempo gasto: %f s.\n", total_time / 1000);
    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de movimentacoes: %d\n", movimentacoes);
}


void imprimeOrdenado(char option, DictSession *session, int* comparacoes, int * movimentacoes, clock_t * clock1, clock_t *clock2)
{

    fputs("***********************************\n", stdout);
    fprintf(stdout, "Letra:[%c] [%c]\n\n", session->letra, option);
    
    switch (option)
    {
    case '1':
        sort(session->lista->nItens, session->lista->vetor, bubbleSort, comparacoes, movimentacoes, clock1, clock2); 
        break;
    case '2':
        sort(session->lista->nItens, session->lista->vetor, insertionSort, comparacoes, movimentacoes, clock1, clock2); 
        break;
    case '3':
        sort(session->lista->nItens, session->lista->vetor, heapsort, comparacoes, movimentacoes, clock1, clock2);
        break;
    case '4':
        sort(session->lista->nItens, session->lista->vetor, quickSort, comparacoes, movimentacoes, clock1, clock2);
        break;
    case '5':
        sort(session->lista->nItens, session->lista->vetor, selectionSort, comparacoes, movimentacoes, clock1, clock2);
        break;
    case '6':
        sort(session->lista->nItens, session->lista->vetor, shellSort, comparacoes, movimentacoes, clock1, clock2); 

        break;
    default:
        printf("algoritmo não correspondente");
    }
    puts("***********************************\n\n");
}

/**
 * @brief Mostra todas as palavras do TAD Dicionário, na sequência alfabética
 * @param dict Dicionario *
 */
void mostraTodasAsPalavras(Dicionario *dict)
{
    if (dict->nitens == 0 && (dict->primeiro == dict->ultimo) && (dict->primeiro == NULL))
    {
        puts("Dicionario vazio");
        return;
    }
    int i;
    PPalavraDict aux;
    aux = dict->primeiro;
    CelulaListaPalavra aux2;

    while (true)
    {

        if (aux->prox == NULL)
        {
            for(int i = 0; i< aux->lista->nItens; i++)
            {
                printf("%s ", aux->lista->vetor[i].palavra->string);
            }
            break;
        }

        for(int i = 0; i< aux->lista->nItens; i++)
        {
            printf("%s ", aux->lista->vetor[i].palavra->string);
        }

        aux = aux->prox;
    }
}

/**
 * @brief Cria um dicionario novo na memória
 *
 * @param dict
 */
void inicializaDicionario(Dicionario **dict)
{
    (*dict) = (Dicionario *)malloc(sizeof(Dicionario));
    (*dict)->nitens = 0;
    (*dict)->primeiro = (*dict)->ultimo = NULL;
}

/**
 * @brief Remove uma palavra específica do dicionário
 * 
 * @param dict 
 * @param string 
 */
void removePalavraDicionario(Dicionario *dict, String string){
    if (dict->nitens == 0 && (dict->primeiro == dict->ultimo) && (dict->primeiro == NULL))
    {
        puts("Dicionario vazio");
        return;
    }
    int i;
    PPalavraDict aux;
    aux = dict->primeiro;
    CelulaListaPalavra  *aux2;

    while (aux != NULL)
    {

        if(aux->letra == string[0]){
            printf("remove %s de  %c \n",string, aux->letra);
            removeCelulaListaPalavra(aux->lista, string);
            break;
        }
        aux = aux->prox;
    }
    

}