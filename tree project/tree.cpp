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

void distribute_number(tree_element ** node, int value) {
    if (value <= (*node)->data) {
        if ((*node)->left != NULL) {
            distribute_number(&((*node)->left), value);
        } else {
            tree_add_descendant(&((*node)->left), value);
            return;
        }
    } else {
        if ((*node)->right != NULL) {
            distribute_number(&((*node)->right), value);
        } else {
            tree_add_descendant(&((*node)->right), value);
            return;
        }
    }
}

int tree_element_dtor(tree_element ** node) {
    (*node)->data = 0;
    (*node)->right = NULL;
    (*node)->left  = NULL;
    free(*node);
    return 0;
}

int tree_graph_dtor(tree_element ** root) {
    if ((*root)->left == NULL && (*root)->right == NULL) { 
        tree_element_dtor(root);
        return 0;
    }
    if ((*root)->left != NULL) {
        tree_graph_dtor(&((*root)->left));
    }

    if ((*root)->right == NULL) {
        tree_graph_dtor(&((*root)->right));
    }
    return 0;
}