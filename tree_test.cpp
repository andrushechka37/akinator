#include <stdio.h>
#include "tree.h"
#include "tree_dump.h"

#include <stdlib.h>  // should be deleted
#include <string.h>

// (later) verificator get size not to be endless recursion
// save or not before exit




int main(void) {
    tree_graph tree = {};
    tree_graph_ctor(&tree);
    tree_add_descendant(&tree.root_element->left, 20);
    tree_add_descendant(&tree.root_element->right, 30);
    tree_add_descendant(&(tree.root_element->right->right), 50);
    //read_data(&tree);
    // distribute_number(&tree.root_element, 55);
    // distribute_number(&tree.root_element, 12);
    // distribute_number(&tree.root_element, 25);
    // distribute_number(&tree.root_element, 34);
    // distribute_number(&tree.root_element, 76);
    // distribute_number(&tree.root_element, 24);
    // distribute_number(&tree.root_element, 90);

    tree_print_preorder(tree.root_element);
    tree_visualize(&tree);
    tree_graph_dtor(&tree.root_element);
}


