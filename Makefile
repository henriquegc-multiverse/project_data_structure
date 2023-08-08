estoque:
	clang -lm -o estoque trabalho1.c estoque.c 

estoque_windows:
	x86_64-w64-mingw32-gcc -o estoque trabalho1.c estoque.c

clean:
	rm -rf estoque
	