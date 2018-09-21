files = test.c BiMinusTree.c

test: $(files)
	gcc -o $@ $^

testdebugger: $(files)
	gcc -g $^ -o $@
