#include <stdio.h>
#include "akinator_dump.h"

#include <stdlib.h>  // should be deleted
#include <string.h>
static void print_grapf_node(akinator_element * element, FILE * pfile, int rank);
static void print_graph_arrows(akinator_element * element, FILE * pfile);

static void print_graph_arrows(akinator_element * element, FILE * pfile) {
    if (element->left != NULL) {
        fprintf(pfile, "\t%d->%d [color = \"#22f230\"];\n", element, element->left);
        print_graph_arrows(element->left, pfile);
    }

    if (element->right != NULL) {
        fprintf(pfile, "\t%d->%d [color = \"orange\"];\n", element, element->right);
        print_graph_arrows(element->right, pfile);
    }
    return;
}

static void print_grapf_node(akinator_element * element, FILE * pfile, int rank) {
    fprintf(pfile, "\t%d[shape=Mrecord,style=filled, fillcolor=\"#7293ba\", rank = %d, label=\"%s\"];\n", 
                                            element, rank, element->text);
    if (element->left != NULL) {
        print_grapf_node(element->left, pfile, ++rank);
    }

    if (element->right != NULL) {
        print_grapf_node(element->right, pfile, ++rank);
    }
    return;
}



int akinator_print_preorder(akinator_element * root) {       // it is like a root for a chosen child node.  am i right?
    if (root == NULL) {       //         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        printf("*");
        return 0;
    }
    printf("(");
    printf("<%s>", root->text);
    akinator_print_preorder(root->left);
    akinator_print_preorder(root->right);
    printf(")");
    return 0;
}

void tree_visualize(akinator_tree * tree) {
    FILE * pfile = fopen("graph.dot", "w");
    fprintf(pfile, "digraph structs {\n");
    fprintf(pfile, "\trankdir=HR;\n");
    fprintf(pfile, "\tgraph [bgcolor=\"#31353b\"]\n");
    fprintf(pfile, "\tnode[color=\"black\",fontsize=14];\n");
    fprintf(pfile, "\tedge[color=\"darkgreen\",fontcolor=\"blue\",fontsize=12,  width=0.4];\n\n\n");

    fprintf(pfile, "\t99999 [shape=note,style=filled, fillcolor=\"#fdf39b\", label=\"SIZE: %d\", fontcolor = \"black\", fontsize = 20];\n", tree->size);

    print_grapf_node(tree->root, pfile, 1);

    fprintf(pfile, "\n\n\n\n");
    
    print_graph_arrows(tree->root, pfile);

    fprintf(pfile, "\n\n\n}");
    fclose(pfile);
    create_new_graph();  
}

void create_new_graph(void) {  // TODO: temporary files, hardcode of path
    char command1[command_len] = "dot -Tpng /Users/anzhiday/Documents/akinator/graph.dot  -o /Users/anzhiday/Documents/akinator/graphs/graph";
    char command2[] = ".png";
    char graph_number_str[2] = {};

    snprintf(graph_number_str, 2,  "%d", graph_number);
    strcat(command1, graph_number_str);
    strcat(command1, command2);
    system(command1);
    graph_number++;
}