compiler: test_compiler.out
	mv $^ slc.out

tree: test_tree.out

test_%.out: tests/test_%/*.c src/*.c
	bison -d -o src/parser.c src/parser.y
	flex -i -o src/scanner.c src/scanner.l
	gcc -std=c99 -pedantic -g -o $@ $^

clean:
	rm -rf *.out
