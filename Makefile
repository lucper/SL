test_tree.out: src/* tests/test_tree/*.c
	bison -d -o src/parser.c src/parser.y
	flex -i -o src/scanner.c src/scanner.l
	gcc -std=c99 -pedantic -o $@ src/*.c tests/test_tree/*.c

slc.out: src/* tests/test_compiler/*.c
	bison -d -o src/parser.c src/parser.y
	flex -i -o src/scanner.c src/scanner.l
	gcc -std=c99 -pedantic -o $@ src/*.c tests/test_compiler/*.c

clean:
	rm -rf *.out
