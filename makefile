all:
	gcc -g codigo/lista/lista.h lista.c palavra.h palavra.c listapalavras.h listapalavras.c dicionario.h dicionario.c main.c

testeLista: lista
	gcc -g testeLista.c 

palavra:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c ./testes/testepalavra.c

listapalavras:
	gcc -g codigo/lista/lista.h codigo/lista/lista.c codigo/palavra/palavra.h codigo/palavra/palavra.c  ./codigo/listapalavras/listapalavras.h ./codigo/listapalavras/listapalavras.c ./testes/testeListaDePalavras.c


clear:
	rm -f *.o *.h.gch *.out *.exe
