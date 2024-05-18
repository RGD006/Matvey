#include <stdio.h>
#include <stdlib.h>

typedef struct complex_t
{
    double real;
    double image;
} complex_t;

complex_t init_complex(double real, double image)
{
    complex_t tmp;

    tmp.real = real;
    tmp.image = image;

    return tmp;
}

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

void clean_node(node_t* node)
{
    free(node);
}

void print_node(node_t* node)
{
    printf("node: [%f %f]\n", node->value.real, node->value.real);
}

typedef struct linked_list_t
{
    node_t* head;
    node_t* tail;
    size_t size;
} linked_list_t;

void add_node_start(linked_list_t* list, node_t* node)
{
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    list->head->prev = NULL;

    list->size++;
}

void add_node_end(linked_list_t* list, node_t* node)
{
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->tail->next = NULL;

    list->size++;
}

linked_list_t* init_list(node_t* node)
{
    linked_list_t* tmp = (linked_list_t*)malloc(sizeof(linked_list_t));
    tmp->head = node;
    tmp->tail = node;
    tmp->size = 1;

    tmp->head->next = NULL;
    tmp->head->prev = NULL;
    tmp->tail->next = NULL;
    tmp->tail->prev = NULL;


    return tmp;
}

void clean_list(linked_list_t* list)
{
    free(list);
}

void print_list_from_start(linked_list_t* list)
{
    node_t* step = list->head;
    for ( ; step != NULL; step = step->next)
        print_node(step);
    printf("\n");
}

void print_list_from_end(linked_list_t* list)
{
    node_t* step = list->tail;
    for ( ; step != NULL; step = step->prev)
        print_node(step);
    printf("\n");
}

node_t* find_node_by_node(const linked_list_t* list, node_t* node)
{
    node_t* step = list->head;
    for ( ; step != NULL; step = step->next)
    {
        if (step == node)
            return step;
    }

    return NULL;
}

node_t* find_node_by_complex(const linked_list_t* list, complex_t number) {
    node_t *step = list->head;
    for (; step != NULL; step = step->next) {
        if (step->value.real == number.real && step->value.image == number.image)
            return step;
    }
    return NULL;
}

node_t* find_node_by_complex_max(const linked_list_t* list, size_t size_list)
{
    node_t* step = list->head;
    node_t* max_node = step;

    for (size_t i = 0; step != NULL && i < size_list; step = step->next, i++)
    {
        if (step->value.real >= max_node->value.real)
            max_node = step;
    }

    return max_node;
}

void swap_value_nodes(node_t* a, node_t* b)
{
    complex_t tmp = a->value;

    a->value = b->value;
    b->value = tmp;
}

void sort_list(linked_list_t* list)
{
    for (size_t i = 0; i < list->size; i++)
    {
        node_t* max = find_node_by_complex_max(list, list->size - i);
        node_t* end = list->tail;

        for (size_t j = 0; j != i; j++)
            end = end->prev;

        swap_value_nodes(max, end);
    }
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

    printf("list from the head node: \n");
    print_list_from_start(list);
    printf("list from the tail node: \n");
    print_list_from_end(list);

    node_t* found_node = find_node_by_node(list, node_4);
    print_node(found_node);
    if (found_node)
        printf("Found! [%f %f]\n", found_node->value.real, found_node->value.image);
    else
        printf("didn't find\n");

    node_t* node_which_cant_find = init_node(NULL, NULL, 10.5, 10.2);
    print_node(node_which_cant_find);
    node_t* node_not_find = find_node_by_node(list, node_which_cant_find);

    if (node_not_find)
        printf("Found! [%f %f]\n", node_not_find->value.real, node_not_find->value.image);
    else
        printf("didn't find\n");

    complex_t complex_number = init_complex(5.9, 5.1);
    printf("complex number: [%f %f]: \n", complex_number.real, complex_number.image);
    node_t* found_node_by_complex = find_node_by_complex(list, complex_number);

    if (found_node_by_complex)
        printf("Found! [%f %f]\n", found_node_by_complex->value.real, found_node_by_complex->value.image);
    else
        printf("didn't find\n");

    printf("\nsorted list: \n");
    sort_list(list);

    print_list_from_start(list);

    clean_list(list);
    clean_node(node_1);
    clean_node(node_2);
    clean_node(node_3);
    clean_node(node_4);
    clean_node(node_5);
    clean_node(node_6);
    clean_node(node_7);
    clean_node(node_8);
}