#pragma once
struct akinator_element{
    char * text;
    akinator_element * left;
    akinator_element * right;
};

struct akinator_tree{
    akinator_element * root;
    int size;
};

#define check_simbol(symbol)                              \
    fscanf(pfile, "%c", &check_symbol);                   \
    if (check_symbol != symbol) {                         \
        printf("syntax error %c\n", check_symbol);        \
        return 0;                                         \
    }



akinator_element * question_ctor(char * text, int size);
int akinator_add_descendant(akinator_element ** ancestor, char * text, int size);
int akinator_ctor(akinator_tree * tree);
