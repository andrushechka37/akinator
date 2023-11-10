#include <stdio.h>
#include "tree.h"
#include "tree_dump.h"

#include <stdlib.h>  // should be deleted
#include <string.h>

// (later) verificator get size not to be endless recursion
// 2 dtors recursion
// insert 12
// (later) check of brackets
// save or not before exit



void distribute_number(tree_element ** node, int value) {
    if (value <= (*node)->data && (*node)->data != 0) {
        if ((*node)->left != 0) {
            distribute_number(&((*node)->left), value);
        } else {
            tree_add_descendant(&((*node)->left), value);
            return;
        }
    } else {
        if ((*node)->right != 0) {
            distribute_number(&((*node)->right), value);
        } else {
            tree_add_descendant(&((*node)->right), value);
            return;
        }
    }
}

int main(void) {
    tree_graph tree = {};
    tree_graph_ctor(&tree);
    tree_add_descendant(&tree.root_element->left, 20);
    tree_add_descendant(&tree.root_element->right, 30);
    tree_add_descendant(&(tree.root_element->right->right), 50);
    distribute_number(&tree.root_element, 35);
    //read_data(&tree);

    tree_print_preorder(tree.root_element);
    tree_visualize(&tree);
}





