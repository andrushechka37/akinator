#pragma once

#include "akinator.h"

inline int graph_number = 1;
const int command_len = 1000;


static void print_graph_arrows(akinator_element * element, FILE * pfile);
static void print_graph_node(akinator_element * element, FILE * pfile, int rank);
int print_akinator_preorder(akinator_element * root);

void akinator_visualize(akinator_tree * tree);
void create_new_graph(void);