#pragma once

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
    fscanf(pfile, "%c", &check_symbol);                   \
    if (check_symbol != symbol) {                         \
        printf("syntax error %c\n", check_symbol);        \
        return 0;                                         \
    }



akinator_element * question_ctor(char * text, int size);
int akinator_ctor(akinator_tree * tree);

int akinator_add_descendant(akinator_element ** ancestor, char * text, int size);

int read_node_akinator(akinator_element ** node, FILE * pfile, char * text, int size);
int read_data_akinator(akinator_tree * tree);

