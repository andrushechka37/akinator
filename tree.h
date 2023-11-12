#pragma once

#define check_simbol(symbol)                              \
    fscanf(pfile, "%c", &check_symbol);                   \
    if (check_symbol != symbol) {                         \
        printf("syntax error %c\n", check_symbol);        \
        return 0;                                         \
    }

struct tree_element {
    int data;
    tree_element * left;
    tree_element * right;
};

struct tree_graph {
    tree_element * root_element;
    int size;
};

tree_element * tree_element_ctor(int data);
int tree_add_descendant(tree_element ** ancestor, int value);
int tree_graph_ctor(tree_graph * tree);
int read_node(tree_element ** node, FILE * pfile, int number);
int read_data(tree_graph * tree);
void distribute_number(tree_element ** node, int value);

int tree_element_dtor(tree_element ** node);
int tree_graph_dtor(tree_element ** root);