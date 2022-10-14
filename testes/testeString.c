#include <stdio.h>
#include <string.h>


int main(){

    char * s1 = "teste";
    char * s2 = "testf";
    char * s3 = "testa";

    printf("%d", strcmp(s1, s2)); //s1 < s2 : -1
    printf("%d", strcmp(s1, s3)); // s1 > s3 : > 0
    printf("%d", strcmp(s2, s3)); // s2 > s3 : > 0
    printf("%d", strcmp(s1, s1)); // s1 == s1 : == 0
}