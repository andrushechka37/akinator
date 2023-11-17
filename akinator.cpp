#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "akinator.h"

const int text_right_answer_len = 100;


void akinator_start(akinator_tree * tree) {
    char answer = '0';
    do {
        //system("clear");
        printf("-----------------------------------------------------\n");
        printf("\n\nотгадайка - o\n\n\nхарактеристика - x\n\n\nсохранить данные - s\n\n\nпоказать дерево - t\n\n\nвыйти - E\n\n");
        scanf("%c%*c", &answer);
        if (answer == 'o') {
            graph_traversal(tree->root);
        } else if (answer == 'x') {
            printf("напишите характеристику чего вы хотите:\n\n");
            char characterise_object[text_right_answer_len] = {};
            scanf("%s%*c", &characterise_object);
            akinator_characterize_print(tree->root, characterise_object);
        } else if (answer == 's') {
            FILE * pfile = fopen("data.txt", "w");
            save_data(tree->root, pfile);
            fclose(pfile);
        } else if (answer == 't') {
            system("open /Users/anzhiday/Documents/akinator/graphs/graph1.png");
        } else if(answer != 'E'){
            printf("\nнекорректный ввод %d\n", answer);
            printf("-----------------------------------------------------\n");
        } 
        //system("clear");
    } while (answer != 'E');
}



static void add_new_variant(akinator_element** elem, char * right_answer, char * difference) {
    akinator_add_descendant(&((*elem)->right), (*elem)->text);
    akinator_add_descendant(&((*elem)->left), right_answer);
    strcpy((*elem)->text, difference);
    return;
}

void print_single_sign(akinator_element* elem, stack * stk, int number) {
    if (elem->left == NULL && elem->right == NULL) {
        return;
    }
    if (stk->data[number] == 1) {
        printf("%s ", elem->text);
        print_single_sign(elem->left, stk, ++number);
    } else {
        printf("НЕ %s", elem->text);
        print_single_sign(elem->right, stk, ++number);
    }
    return;
}
int akinator_characterize_print(akinator_element* elem, char * search_text) {
    stack stk = {};
    Stack_Ctor(&stk);
    if (akinator_characterize_node(elem, search_text, &stk) == 1) {
        print_single_sign(elem, &stk, 0);
    } else {
        printf("нет такого элемента\n");
    }
    return 0;
}
int akinator_characterize_node(akinator_element* elem, char * search_text, stack * stk) {
    int status = 0;
    if (elem->left == NULL && elem->right == NULL) {      
        if (strcmp(search_text, elem->text) == 0) {
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
        status = 1;
    }
    stack_push(stk, 0);
    if (akinator_characterize_node(elem->right, search_text, stk) == 1) {
        return 1;
        status = 1;
    }
    if (status == 1) {
        return 1;
    }
    return 0;
}

int graph_traversal(akinator_element* elem) {
    char answer[3] = {};
    if (elem->left != NULL && elem->right != NULL) {
        printf("%s?\n\n", elem->text);
        scanf("%s%*c", answer);
        if (strcmp(answer, "Y") == 0) {
            graph_traversal(elem->left);
        } else if(strcmp(answer, "N") == 0) {
            graph_traversal(elem->right);
        } else {
            printf("\nсинтанксическая ошибка\n");
        }
    } else {
        printf("это %s?\n\n", elem->text);   // adding your variant
        scanf("%s%*c", answer);
        if (strcmp(answer, "Y") == 0) {
            printf("хаха, я угадала\n\n");
        } else if(strcmp(answer, "N") == 0) {
            printf("чем это отличается от %s?\n\n", elem->text);
            char difference[text_right_answer_len] = {};
            char right_answer[text_right_answer_len] = {};

            scanf("%s%*c", difference);
            printf("что было загадано?\n\n");
            scanf("%s%*c", right_answer);
            add_new_variant(&elem, right_answer, difference);
        }
    }
    return 0;
}

akinator_element * question_ctor(char * text) {
    akinator_element * element = (akinator_element *) calloc(1, sizeof(akinator_element));
    //element->text = (char *) calloc(size, sizeof(char));
    strcpy(element->text, text);
    element->left = NULL;
    element->right = NULL;
    return element;

}

int akinator_add_descendant(akinator_element ** ancestor, char * text) {
    *ancestor = question_ctor(text);
    return 0;
}

int akinator_ctor(akinator_tree * tree) {
    char zero_elem[] = "zero";
    tree->root = question_ctor(zero_elem);  // bad
    return 0;
}

int read_node_akinator(akinator_element ** node, FILE * pfile, char * text) {
    akinator_add_descendant(node, text);
    char check_char = '0';
    check_symbol('>');
    if (fscanf(pfile, "(<%[^>]s", text) == 1) {
        text[strcspn(text, "\n")] = '\0';
        read_node_akinator(&((*node)->left), pfile, text);
    } else {
        check_symbol('*');
    }

    if (fscanf(pfile, "(<%[^>]s", text) == 1) {
        text[strcspn(text, "\n")] = '\0';
        read_node_akinator(&((*node)->right), pfile, text);
    } else {
        check_symbol('*');
    }
    check_symbol(')');
    return 0; 
}

int read_data_akinator(akinator_tree * tree) {
    FILE * pfile = fopen("data.txt", "rb");
    char text[text_len] = {};
    fscanf(pfile, "(<%[^>]s", text);
    read_node_akinator(&(tree->root), pfile, text);
    fclose(pfile);
    return 0;
}

int save_data(akinator_element * root, FILE * pfile) {
    if (root == NULL) {       
        fprintf(pfile, "*");
        return 0;
    }
    fprintf(pfile,"(");
    fprintf(pfile,"<%s>", root->text);
    save_data(root->left, pfile);
    save_data(root->right, pfile);
    fprintf(pfile,")");
    return 0;
}
