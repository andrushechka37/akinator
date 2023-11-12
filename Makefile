.PHONY: tree
tree: tree_test.o tree.o tree_dump.o
	clang++ tree_test.o tree.o  tree_dump.o -o tree && ./tree

tree_test.o: tree_test.cpp tree.h tree_dump.h
	clang++ -c tree_test.cpp
tree.o: tree.cpp tree.h
	clang++ -c tree.cpp
tree_dump.o: tree_dump.cpp tree.h tree_dump.h
	clang++ -c tree_dump.cpp


.PHONY: akinator
akinator: akinator_test.o akinator_dump.o
	clang++ akinator_test.o akinator_dump.o -o akinator && ./akinator

akinator_test.o: akinator_test.cpp akinator.h akinator_dump.h
	clang++ -c akinator_test.cpp
akinator_dump.o: akinator_dump.cpp tree.h akinator_dump.h
	clang++ -c akinator_dump.cpp