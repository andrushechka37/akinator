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