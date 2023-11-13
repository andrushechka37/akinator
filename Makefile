CXXFLAGS =  -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations \
   -Wc++14-compat -Wmissing-declarations -Wcast-qual -Wchar-subscripts                \
   -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal           \
   -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline                   \
   -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked                     \
   -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo           \
   -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn                         \
   -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default               \
   -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast                    \
   -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing            \
   -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation             \
   -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192                  \
   -Wstack-usage=8192 -fsanitize=address -fsanitize=undefined -fPIE -Werror=vla

# .PHONY: tree

# tree: tree_test.o tree.o tree_dump.o
# 	clang++ tree_test.o tree.o  tree_dump.o -o tree && ./tree

# tree_test.o: tree_test.cpp tree.h tree_dump.h
# 	clang++ -c tree_test.cpp
# tree.o: tree.cpp tree.h
# 	clang++ -c tree.cpp
# tree_dump.o: tree_dump.cpp tree.h tree_dump.h
# 	clang++ -c tree_dump.cpp


.PHONY: akinator
akinator: akinator_test.o akinator_dump.o stack_func.o akinator.o
	clang++ akinator_test.o akinator_dump.o stack_func.o akinator.o $(CXXFLAGS) -o akinator && ./akinator
akinator_test.o: akinator_test.cpp akinator.h akinator_dump.h
	clang++ -c akinator_test.cpp
akinator_dump.o: akinator_dump.cpp akinator_dump.h
	clang++ -c akinator_dump.cpp

stack_func.o: stack_func.cpp stack_func.h
	clang++ -c stack_func.cpp

akinator.o: akinator.cpp akinator.h
	clang++ -c akinator.cpp