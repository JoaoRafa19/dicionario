all: #arquivo principal 
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c codigo/dicionario/dicionario.h codigo/dicionario/dicionario.c codigo/main.c
	./a.out
	
testedicionario: 
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c codigo/dicionario/dicionario.h codigo/dicionario/dicionario.c testes/testedicionario.c
	./testedicionario.c
	./a.out
	
testeLista: 
	gcc codigo/lista/lista.h codigo/lista/lista.c testes/testeLista.c
	./a.out

testepalavra:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c ./testes/testepalavra.c
	./a.out

testelistapalavras:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c ./testes/testeListaDePalavras.c
	./a.out

clear:
	rm -f *.o *.h.gch *.out *.exe
