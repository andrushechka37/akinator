#pragma once


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