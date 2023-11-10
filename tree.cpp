#include <stdio.h>
#include <stdlib.h>

#include "tree.h"


tree_element * tree_element_ctor(int data) {
    tree_element * element = (tree_element *) calloc(1, sizeof(tree_element));
    element->left = NULL;
    element->right = NULL;
    element->data = data;
    return element;
}

int tree_add_descendant(tree_element ** ancestor, int value) {
    *ancestor = tree_element_ctor(value);
    return 0;
}

int tree_graph_ctor(tree_graph * tree) {
    tree->root_element = tree_element_ctor(0);
    return 0;
}

// i have a wish to read it to the buffer and work with array, but I don't know.



int read_node(tree_element ** node, FILE * pfile, int number) {
    tree_add_descendant(node, number);
    char check_symbol = '0';
    if (fscanf(pfile, "(%d", &number) == 1) {
        read_node(&((*node)->left), pfile, number);
    } else {
        check_simbol('*');
    }

    if (fscanf(pfile, "(%d", &number) == 1) {
        read_node(&((*node)->right), pfile, number);
    } else {
        check_simbol('*');
    }
    check_simbol(')');
    return 0; 
}

int read_data(tree_graph * tree) {
    FILE * pfile = fopen("data.txt", "r");
    int number = 0;
    fscanf(pfile, "(%d", &number);
    read_node(&(tree->root_element), pfile, number);
    fclose(pfile);
    return 0;
}