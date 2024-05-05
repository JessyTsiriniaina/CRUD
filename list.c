#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list_element* new_list(void)
{
    return NULL;
}

boolean is_empty(list_element* list)
{
    if(list == NULL) return true;
    return false;
}

int length_of(list_element* list)
{
    int length = 0;
    while(list != NULL)
    {
        length++;
        list = list->next;
    }
    return length;
}


void print(list_element* list)
{
    if(is_empty(list))
        printf("The list is empty");

    while(list != NULL)
    {
        printf("%s, %d an%c\n",list->name, list->age, list->age > 1 ? 's' : ' ');
        list = list->next;
    }
    printf("\n");
}


list_element* push_end(list_element* list)
{
    list_element *new;
    new = malloc(sizeof(*new));
    
    printf("Name: ");
    scanf(" %[^\n]", new->name);
    printf("Age: ");
    scanf("%d", &new->age);
    new->next = NULL;

    if(is_empty(list))
        return new;

    list_element *temp;
    temp = list;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new;

    return list;
}


list_element* push_start(list_element* list)
{
    list_element *new;
    new = malloc(sizeof(*new));

    printf("Name: ");
    scanf(" %[^\n]", new->name);
    printf("Age: ");
    scanf("%d", &new->age);

    if(is_empty(list))
    {
        new->next = NULL;
        return new;
    }

    new->next = list;
    
    return new;
}



list_element* pop_end(list_element* list)
{
    if(list->next == NULL || is_empty(list))
        return new_list();
    
    list_element* temp = list;
    list_element* before;

    while(temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }

    free(temp);
    temp = NULL;

    before->next = NULL;

    return list;
}

list_element* pop_start(list_element* list)
{
    if(list->next == NULL ||  is_empty(list))   
        return new_list();
    
    list_element* before = list;
    list = list->next;

    free(before);
    before = NULL;

    return list;
}


list_element* update_value(list_element* list)
{
    if(is_empty(list))
    {
        printf("The list is empty\n");
        return list;
    }
    
    printf("Enter name: ");
    char current[256];
    scanf(" %[^\n]", current);

    list_element* temp = list;
    while(temp != NULL)
    {
        if(strcmp(temp->name, current) == 0)
        {
            printf("Enter new name: ");
            char tmp[256];
            scanf(" %[^\n]", tmp);
            strcpy(temp->name, tmp);
            return list;
        }

        temp = temp->next;
    }

    printf("Element not found\n");
    return list;       
}