# all: #arquivo principal 
# 	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c codigo/dicionario/dicionario.h codigo/dicionario/dicionario.c codigo/main.c
	
all: #arquivo principal 
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras-tp3/listapalavras.h ./codigo/listapalavras-tp3/listapalavras.c codigo/dicionario/dicionario.h codigo/dicionario/dicionario.c codigo/main.c
	
testedicionario: 
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c codigo/dicionario/dicionario.h codigo/dicionario/dicionario.c testes/testedicionario.c
	
testeLista: 
	gcc codigo/lista/lista.h codigo/lista/lista.c testes/testeLista.c

testepalavra:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c ./testes/testepalavra.c

testelistapalavras:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c ./testes/testeListaDePalavras.c

testevetorpalavras:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/vetorpalavras/vetorpalavras.h ./codigo/vetorpalavras/vetorpalavras.c ./testes/testeVetorPalavras.c

clear:
	rm -f *.o *.h.gch *.out *.exe
