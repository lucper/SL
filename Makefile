compiler: test_compiler.out
	mv $^ slc.out

tree: test_tree.out

parser: test_parser.out

scanner: test_scanner.out

test_%.out: tests/test_%/*.c src/*.c
	bison -d -o src/parser.c src/parser.y
	flex -i -o src/scanner.c src/scanner.l
	gcc -std=c99 -pedantic -o $@ $^

clean:
	rm -rf *.out
