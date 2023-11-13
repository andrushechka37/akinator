#include <stdio.h>
#include "akinator.h"

#include <stdlib.h>  // should be deleted
#include <string.h>
#include "akinator_dump.h"

// going in the graph yes/no
// comparising
// charactirise
int graph_traversal(akinator_element* elem) {
    if (elem->left != NULL && elem->right != NULL) {
        printf("%s?", elem->text);
        char answer[10] = {};
        scanf("%s", answer);
        if (strcmp(answer, "да") == 1) {
            graph_traversal(elem->left);
        } else if(strcmp(answer, "нет") == 1) {
            graph_traversal(elem->right);
        }
    } else {
        printf("тебе следует %s", elem->text);
    }
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



int main(void) {
    akinator_tree tree = {};
    akinator_ctor(&tree);
    // akinator_add_descendant(&tree.root->left, "one", sizeof("one"));
    // akinator_add_descendant(&tree.root->right, "two", sizeof("two"));
    // akinator_add_descendant(&tree.root->right->right, "three", sizeof("three"));
    // akinator_add_descendant(&tree.root->right->right->left, "four", sizeof("four"));

    //graph_traversal(tree.root);

    
    read_data_akinator(&tree);

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





////////////


