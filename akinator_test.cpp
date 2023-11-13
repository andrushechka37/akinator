#include <stdio.h>

#include "akinator.h"
#include "akinator_dump.h"
#include "stack_func.h"


#include <stdlib.h>
#include <string.h>


// guess done without adding elements

// comparison

int main(void) {
    akinator_tree tree = {};
    akinator_ctor(&tree);

    read_data_akinator(&tree);
    akinator_characterize_print(tree.root, "мышь");


    
    //graph_traversal(tree.root);

    print_akinator_preorder(tree.root);
    akinator_visualize(&tree);
}