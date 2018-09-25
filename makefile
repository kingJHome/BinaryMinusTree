files = test.c BiMinusTree.c fileHander.c

test: $(files)
	gcc -o $@ $^

testdebugger: $(files)
	gcc -g $^ -o $@
