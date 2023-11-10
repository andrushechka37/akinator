#include <stdio.h>
#include "tree.h"
#include "tree_dump.h"



// verificator get size not to be endless recursion
// 2 dtors recursion
//                    func read tree
// insert 12
// check of brackets
// save or not before exit

// int read_node(tree_element ** node, FILE * pfile) {
//     char number = '0';
//     fscanf(pfile, "%c", number);
// }
// int read_data(tree_graph * tree) {

// }

int main(void) {
    tree_graph tree = {};
    tree_graph_ctor(&tree);
    tree_add_descendant(&tree.root_element->left, 20);
    tree_add_descendant(&tree.root_element->right, 30);

    tree_print_preorder(tree.root_element);
    tree_visualize(&tree);
}