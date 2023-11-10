.PHONY: start
start: tree_test.o tree.o tree_dump.o
	clang++ tree_test.o tree.o  tree_dump.o -o tree && ./tree

tree_test.o: tree_test.cpp tree.h tree_dump.h
	clang++ -c tree_test.cpp
tree.o: tree.cpp tree.h
	clang++ -c tree.cpp
tree_dump.o: tree_dump.cpp tree.h tree_dump.h
	clang++ -c tree_dump.cpp