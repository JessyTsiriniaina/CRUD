/******************************************************************************
|   CRUD practice
|   CRUD stand for Create Read Update Delete
|   I'll use list data structure
|
|   by Jessy Tsiriniaina <tsiriniainajessy2@gmail.com>
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main(void)
{
    //initialize list
    list_element *mylist = new_list();

    printf("Use one of the prompts below to perform operation: \n"
            "\ta: add new element at the end\n"
            "\ts: add new element at the start\n"
            "\tr: remove element at the end\n"
            "\th: remove element at the start\n"
            "\tc: print list element count\n"
            "\tl: print list element\n"
            "\tu: update value"
            "\tq: quit\n\n");
    while(true)
    {
        char prompt;
        scanf(" %c", &prompt);

        switch(prompt)
        {
            case 'a': mylist = push_end(mylist);
                    break;
            case 's': mylist = push_start(mylist);
                    break;
            case 'r': mylist = pop_end(mylist);
                    break;
            case 'h': mylist = pop_start(mylist);
                    break;
            case 'c': printf("Element count: %d\n", length_of(mylist));
                    break;
            case 'l': print(mylist);
                    break;
            case 'u': mylist = update_value(mylist);
                    break;
            case 'q': exit(EXIT_FAILURE);
            default: printf("Unknown prompt\n");
        }

    }
    return 0;
}