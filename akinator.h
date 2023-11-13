#pragma once
#include "stack_func.h"
const int text_len = 100;
struct akinator_element{
    char text[text_len];
    akinator_element * left;
    akinator_element * right;
};

struct akinator_tree{
    akinator_element * root;
    int size;
};

#define check_simbol(symbol)                              \
    fscanf(pfile, "%c", &check_char);                     \
    if (check_char != symbol) {                           \
        printf("syntax error %c\n", check_char);          \
        return 0;                                         \
    }                                                     \
    fscanf(pfile, "%c", &check_char);                     \
    if (check_char != '\n') {                             \
        ungetc(check_char, pfile);                        \
    }



akinator_element * question_ctor(char * text, int size);
int akinator_ctor(akinator_tree * tree);

int akinator_add_descendant(akinator_element ** ancestor, char * text, int size);

int read_node_akinator(akinator_element ** node, FILE * pfile, char * text, int size);
int read_data_akinator(akinator_tree * tree);

int akinator_characterize_node(akinator_element* elem, char * search_text, stack * stk);
int akinator_characterize_print(akinator_element* elem, char * search_text);
