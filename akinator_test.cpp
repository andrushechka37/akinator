#include <stdio.h>

#include "akinator.h"
#include "akinator_dump.h"
#include "stack_func.h"


#include <stdlib.h>
#include <string.h>

// adding elements
// comparising
// save data in multiple strings in file WOW DONE!


int main(void) {
    akinator_tree tree = {};
    akinator_ctor(&tree);
    // akinator_add_descendant(&tree.root->left, "kishka", sizeof("one"));
    // akinator_add_descendant(&tree.root->left->left, "analgetiki", sizeof("one"));
    // akinator_add_descendant(&tree.root->left->left, "stress", sizeof("one"));
    // akinator_add_descendant(&tree.root->left->left->right, "utrom", sizeof("one"));
    // akinator_add_descendant(&tree.root->right, "rvota", sizeof("two"));
    // akinator_add_descendant(&tree.root->right->right, "berem", sizeof("three"));
    // akinator_add_descendant(&tree.root->right->right->left, "vrach", sizeof("four"));

    read_data_akinator(&tree);
    //akinator_characterize_print(tree.root, "q5");


    
    //graph_traversal(tree.root);

    print_akinator_preorder(tree.root);
    akinator_visualize(&tree);
}