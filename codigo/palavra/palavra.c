#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../listapalavras/listapalavras.h"

/**
 * @note sobrescreve
 * @warning sobrescreve a palavra anterior
 *
 * @brief Cria uma palavra na memória HEAP e escreve no endereço de memória passado como parâmetro
 * @param palavra Endereço de memória onde deve ser criada a palavra
 */
void criaPalavraVazia(Palavra **palavra)
{

    (*palavra) = (Palavra *)malloc(sizeof(Palavra));
    (*palavra)->palavra = NULL;
    FLVazia(&(*palavra)->lista);
}

/**
 * @brief Cria uma palavra na memória HEAP e escreve no endereço de memória passado como parâmetro
 * @param palavra Endereço de memória onde deve ser criada a palavra
 */
Palavra *criapalavra()
{
    Palavra *p;
    p = (Palavra *)malloc(sizeof(Palavra));
    p->palavra = NULL;
    FLVazia(&(p->lista));
    return p;
}

/**
 * @brief Copia o conteúdo da String passada como parâmetro para a propriedade [palavra] da
 * palava passada como parâmetro
 *
 * @param palavra Destino da cópia da string
 * @param string String a ser copiada
 */
void preencheCadeiaDeCaracteres(Palavra *palavra, String string)
{
    palavra->palavra = (String)malloc(strlen(string) * sizeof(char));
    strcpy(palavra->palavra, string);
}

void adicionaLinha(Palavra *palavra, Linha linha)
{
    adicionarCelula(palavra->lista, criaCelula(criaTitem(linha)));
}

/**
 * @brief Retorna a cadeia de caracteres de cada palvra
 *
 * @param palavra
 * @return String
 */
String retornaCadeiaDeCaracteres(Palavra *palavra)
{
    return palavra->palavra;
}

/**
 * @brief Imprime na saida padrão a cadeia de caracteres da palavra passada como parametro
 * @param palavra Endereço para a palavra que deseja imprimir
 */
void imprimeCadeiaDeCaracteres(Palavra *palavra)
{
    printf("%s  ", retornaCadeiaDeCaracteres(palavra));
}

/**
 * @brief cadeia de caracteres + TAD Lista de Números de
linha)
 * @param palavra Palavra *
 * @param output FILE *
 */
void imprimePalavra(Palavra *palavra, FILE *output)
{
    if (output == NULL)
        printf("%s ->", palavra->palavra);

    fprintf(output, "%s", palavra->palavra);
    imprimeLista(palavra->lista);
}
