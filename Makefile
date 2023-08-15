estoque:
	clang -lm -o ./bin/estoque trabalho1.c estoque.c 

estoque_windows:
	x86_64-w64-mingw32-gcc -o ./bin/estoque trabalho1.c estoque.c

gerar_listas:
	clang -lm -o ./bin/gerar_listas trabalho2.c lista.c

gerar_listas_windows:
	x86_64-w64-mingw32-gcc -o ./bin/gerar_listas trabalho2.c lista.c

clean:
	rm -rf estoque
	