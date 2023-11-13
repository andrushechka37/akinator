#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "akinator.h"


int akinator_characterize_print(akinator_element* elem, char * search_text) {
    stack stk = {};
    Stack_Ctor(&stk);
    akinator_characterize_node(elem, search_text, &stk);
    for (int i = 0; i < stk.size; i++) {      // instead of that print function
        printf("%d\n", stk.data[i]);
    }
}
int akinator_characterize_node(akinator_element* elem, char * search_text, stack * stk) {
    if (elem->left == NULL && elem->right == NULL) {      
        if (strcmp(search_text, elem->text) == 0) {
            dump_stk(stk, "", 1, "");             // another output
            return 1;
        } else {
            int k = 0;
            stack_pop(stk, &k);
            return 0;
        }
    }
    stack_push(stk, 1);
    if (akinator_characterize_node(elem->left, search_text, stk) == 1) {
        return 1;
    }
    stack_push(stk, 0);
    if(akinator_characterize_node(elem->right, search_text, stk) == 1) {
        return 1;
    }

    return 0;
}

int graph_traversal(akinator_element* elem) { 
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
        printf("%s", elem->text);   // adding your variant
    }
    return 0;
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
    char check_char = '0';
    check_simbol('>');
    if (fscanf(pfile, "(<%[^>]s", text) == 1) {
        text[strcspn(text, "\n")] = '\0';
        read_node_akinator(&((*node)->left), pfile, text, sizeof(text));
    } else {
        check_simbol('*');
    }

    if (fscanf(pfile, "(<%[^>]s", text) == 1) {
        text[strcspn(text, "\n")] = '\0';
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
    fscanf(pfile, "(<%[^>]s", text);
    read_node_akinator(&(tree->root), pfile, text, sizeof(text));
    fclose(pfile);
    return 0;
}