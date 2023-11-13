#include <stdio.h>
#include "akinator.h"

#include <stdlib.h>  // should be deleted
#include <string.h>

#include "akinator_dump.h"
#include "stack_func.h"
// adding elements
// comparising
// charactirise
// save data in multiple strings in file

int akinator_characterize(akinator_element* elem, char * search_text, stack * stk) {
    if (elem->left == NULL && elem->right == NULL) {      
        if (strcmp(search_text, elem->text) == 0) {
            dump_stk(stk, "", 1, "");
            return 0;
        } else {
            int k = 0;
            stack_pop(stk, &k);
            return 0;
        }
    }
    stack_push(stk, 1);
    akinator_characterize(elem->left, search_text, stk);
    stack_push(stk, -1);
    akinator_characterize(elem->right, search_text, stk);
    return 0;
}

int graph_traversal(akinator_element* elem) {        // adding your variant
    if (elem->left != NULL && elem->right != NULL) {
        printf("%s?\n\n", elem->text);
        char answer[3] = {};
        scanf("%s", answer);
        if (strcmp(answer, "Y") == 0) {
            graph_traversal(elem->left);
        } else if(strcmp(answer, "N") == 0) {
            graph_traversal(elem->right);
        }
    } else {
        printf("%s", elem->text);
    }
    return 0;
}


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
    stack stk = {};
    Stack_Ctor(&stk);
    akinator_characterize(tree.root, "q5", &stk);


    
    //graph_traversal(tree.root);

    akinator_print_preorder(tree.root);
    tree_visualize(&tree);


}




akinator_element * question_ctor(char * text, int size) {
    akinator_element * element = (akinator_element *) calloc(1, sizeof(akinator_element));
    //element->text = (char *) calloc(size, sizeof(char));
    strcpy(element->text, text);
    element->left = NULL;
    element->right = NULL;
    return element;

}

int akinator_add_descendant(akinator_element ** ancestor, char * text, int size) {
    *ancestor = question_ctor(text, size);
    return 0;
}

int akinator_ctor(akinator_tree * tree) {
    tree->root = question_ctor("zero", sizeof("zero"));  // bad
    return 0;
}

int read_node_akinator(akinator_element ** node, FILE * pfile, char * text, int size) {
    akinator_add_descendant(node, text, size);
    char check_symbol = '0';
    check_simbol('>');
    if (fscanf(pfile, "(<%[^>]s", text) == 1) {
        read_node_akinator(&((*node)->left), pfile, text, sizeof(text));
    } else {
        check_simbol('*');
    }

    if (fscanf(pfile, "(<%[^>]s", text) == 1) {
        read_node_akinator(&((*node)->right), pfile, text, sizeof(text));
    } else {
        check_simbol('*');
    }
    check_simbol(')');
    return 0; 
}

int read_data_akinator(akinator_tree * tree) {
    FILE * pfile = fopen("data.txt", "rb");
    char text[text_len] = {};
    char check_symbol = '0';
    fscanf(pfile, "(<%[^>]s", text);
    read_node_akinator(&(tree->root), pfile, text, sizeof(text));
    fclose(pfile);
    return 0;
}



////////////////

