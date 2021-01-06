test_tree.out: src/parser.y src/scanner.l src/*.c tests/*.c
	bison -d -o src/parser.c src/parser.y
	flex -i -o src/scanner.c src/scanner.l
	gcc -std=c99 -pedantic -o $@ src/*.c tests/*c
