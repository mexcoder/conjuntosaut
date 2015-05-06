all: compile
	

debug:
	mkdir build
	flex reglas.l
	clang lex.yy.c -o build/lexer.o
	clang++ conjuntos -g main.cpp conjuntos.cpp automata.cpp funciones.cpp -Wl,build/lexer.o -o  bin/conjunto.exe


compile:
	mkdir build
	flex reglas.l
	clang lex.yy.c -o build/lexer.o
	mkdir bin
	clang++ -ll main.cpp conjuntos.cpp automata.cpp funciones.cpp -Wl,build/lexer.o -o  bin/conjunto.exe
    
run: all
	./conjuntos
	
debugrun:debug
	./conjuntos

clean:
	$(RM) conjuntos
	$(RM) lex.yy.c