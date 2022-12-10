#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "palavra.h"
/**
 * @brief Cria uma palavra na memória HEAP e escreve no endereço de memória passado como parâmetro
 * @param palavra Endereço de memória onde deve ser criada a palavra
 */
void criaPalavraVazia(Palavra **palavra)
{

    (*palavra) = (Palavra *)malloc(sizeof(Palavra));
    (*palavra)->string = NULL;
    fazListaVazia(&(*palavra)->lista);
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
    palavra->string = (String)malloc(strlen(string) * sizeof(char));
    strcpy(palavra->string, string);
}

/// @brief Adiciona cada linha à lista de linhas em que a palavra aparece
/// @param palavra 
/// @param linha 
void adicionaOcorrecia(Palavra *palavra, int linha)
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
    return palavra->string;
}

/**
 * @brief Imprime na saida padrão a cadeia de caracteres da palavra passada como parametro
 * @param palavra Endereço para a palavra que deseja imprimir
 */
void imprimeCadeiaDeCaracteres(Palavra *palavra)
{
    printf("%s  \n", retornaCadeiaDeCaracteres(palavra));
}

/**
 * @brief cadeia de caracteres + TAD Lista de Números de
linha)
 * @param palavra Palavra *
 * @param output FILE *
 */
void imprimePalavra(Palavra *palavra, FILE *output)
{
    fputs("-----------------------\n", output);
    if (output == NULL){
        printf("Palavra: ");
        imprimeCadeiaDeCaracteres(palavra);
    }

    fprintf(output, "%-10s: %s\n", "Palavra", retornaCadeiaDeCaracteres(palavra));
    
    imprimeLista(palavra->lista, output);
    fputs("-----------------------\n", output);
}
