#include <stdio.h>

#include "akinator.h"
#include "akinator_dump.h"
#include "stack_func.h"


#include <stdlib.h>
#include <string.h>


// guess done without adding elements

// comparison

// difs in github number of commit adress sring gitlengs 
// read about asserts

int main(void) {
    akinator_tree tree = {};
    akinator_ctor(&tree);

    read_data_akinator(&tree);
    //akinator_characterize_print(tree.root, "����");


    
    //graph_traversal(tree.root);
    akinator_start(&tree);

    print_akinator_preorder(tree.root);
    akinator_visualize(&tree);
}