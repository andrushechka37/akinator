#pragma once
#include "tree.h"

inline int graph_number = 1;
const int command_len = 1000;

int tree_print_preorder(tree_element * root);


void create_new_graph(void);
void tree_visualize(tree_graph * tree);