#ifndef LIST_H
#define LIST_H

typedef enum
{
    false, true
} boolean;

typedef struct list_element
{
    char name[256];
    int age;
    struct list_element *next;
} list_element;



boolean is_empty(list_element* list);

list_element* new_list(void);

int length_of(list_element* list);

void print(list_element* list);

list_element* push_end(list_element* list);

list_element* push_start(list_element* list);

list_element* pop_end(list_element* list);

list_element* pop_start(list_element* list);

list_element* update_value(list_element* list);

#endif