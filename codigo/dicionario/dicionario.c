#include "dicionario.h"
#include "string.h"
#include "stdbool.h"

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
        if (*s != '\t' && *s != '\n' && *s != '\0' && *s != '\20' && *s != '\b' && *s != '\r' && *s != '\v' && *s != '\\' && *s != '\?' && *s != '\'' && *s != '\r')
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
        fprintf(output, "Letra:[%c]\n\n", palavradict->letra);
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
            if (item->letra < aux->letra)
            { // insere no inicio
                item->prox = aux;
                dict->primeiro = item;
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

        PsCelulaListaPalavra refCelula;

        Palavra *p;
        criaPalavraVazia(&p);
        removeTablaturasEFimDeLinha(palavraSeparadaPorEspacos);
        preencheCadeiaDeCaracteres(p, palavraSeparadaPorEspacos);
        CelulaListaPalavra *celula = criaCelulaListaPalavras(p);
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

void ordenar(DictSession **primeiro, int tam)
{
    int i = 0, retorno;
    DictSession *anterior, *proximo, *aux, *aux2;

    if (tam > 1)
    {
        anterior = *primeiro;
        proximo = anterior->prox;

        while (proximo != NULL)
        {
            retorno = anterior->letra > proximo->letra;

            if (retorno > 0)
            {
                aux = anterior;
                aux2 = proximo;
                anterior->prox = proximo->prox;
                proximo->prox = aux;
            }
            i++;
            anterior = anterior->prox;
            proximo = proximo->prox;
        }
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
    PsCelulaListaPalavra aux2;

    while (1)
    {

        if (aux->prox == NULL)
        {
            
            aux2 = aux->lista->primeiro;

            while (true)
            {

                if (aux2->prox == NULL)
                {

                    printf("%s \n", aux2->palavra->string);
                    break;
                }
                printf("%s ", aux2->palavra->string);

                aux2 = aux2->prox;
            }

            break;
        }
        aux2 = aux->lista->primeiro;

        while (true)
        {

            if (aux2->prox == NULL)
            {

                printf("%s \n", aux2->palavra->string);
                break;
            }
            printf("%s ", aux2->palavra->string);
            
            aux2 = aux2->prox;
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
