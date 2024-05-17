#include <stdio.h>
#include <stdlib.h>

typedef struct complex_t
{
    double real;
    double image;
} complex_t;

struct node_t
{
    struct node_t* next;
    struct node_t* prev;
    complex_t value;
};

typedef struct node_t node_t;

node_t* init_node(node_t* prev, node_t* next, double real, double image)
{
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->next = next;
    tmp->prev = prev;
    tmp->value.real = real;
    tmp->value.image = image;

    return tmp;
}

typedef struct linked_list_t
{
    node_t* head;
    node_t* tail;
} linked_list_t;

void add_node_start(linked_list_t* list, node_t* node)
{
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    list->head->prev = NULL;
}

void add_node_end(linked_list_t* list, node_t* node)
{
    list->tail->next = node;
    list->tail = node;
    list->tail->prev = node;
    list->tail->next = NULL;
}

linked_list_t* init_list(node_t* node)
{
    linked_list_t* tmp = (linked_list_t*)malloc(sizeof(linked_list_t));
    tmp->head = node;
    tmp->tail = node;
    tmp->head->next = NULL;
    tmp->head->prev = NULL;
    tmp->tail->next = NULL;
    tmp->tail->prev = NULL;

    return tmp;
}

void print_list(linked_list_t* list)
{
    node_t* step = list->head;
    for ( ; step != NULL; step = step->next)
    {
        printf("%f.3 %f.3i -> \n", step->value.real, step->value.image);
    }
    printf("\n");
}

node_t* find_node(const linked_list_t* list, node_t* node)
{
    node_t* step = list->head;
    for ( ; step != NULL; step = step->next)
    {
        if (step == node)
            return step;
    }

    return NULL;
}

void sort_list(linked_list_t* list)
{
    
}

int main()
{
    node_t* node_1 = init_node(NULL, NULL, 1.5, 9.5);
    node_t* node_2 = init_node(NULL, NULL, 2.6, 8.4);
    node_t* node_3 = init_node(NULL, NULL, 3.7, 7.3);
    node_t* node_4 = init_node(NULL, NULL, 4.8, 6.2);
    node_t* node_5 = init_node(NULL, NULL, 5.9, 5.1);
    node_t* node_6 = init_node(NULL, NULL, 6.0, 4.0);
    node_t* node_7 = init_node(NULL, NULL, 7.1, 3.9);
    node_t* node_8 = init_node(NULL, NULL, 8.2, 2.8);

    linked_list_t* list = init_list(node_1);

    add_node_end(list, node_2);
    add_node_end(list, node_3);
    add_node_end(list, node_4);
    add_node_start(list, node_5);
    add_node_start(list, node_6);
    add_node_start(list, node_7);
    add_node_end(list, node_8);

    print_list(list);

    node_t* found_node = find_node(list, node_4);
    if (found_node)
        printf("Found! [%f %f]\n", found_node->value.real, found_node->value.image);
    else
        printf("didn't find\n");

    node_t* node_which_cant_find = init_node(NULL, NULL, 10.5, 10.2);
    node_t* node_not_find = find_node(list, node_which_cant_find);

    if (node_not_find)
        printf("Found! [%f %f]\n", node_not_find->value.real, node_not_find->value.image);
    else
        printf("didn't find\n");

    free(list);
    free(node_1);
    free(node_2);
    free(node_3);
    free(node_4);
    free(node_5);
    free(node_6);
    free(node_7);
    free(node_8);
}