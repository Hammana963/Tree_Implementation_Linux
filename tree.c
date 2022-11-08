#include "tree.h"


void *checked_malloc(int len) {
    void *p = malloc(len);
    
    if (p == NULL) {
        perror("\nRan out of memory!\n");
        exit(1);
    }
    return p;
}

struct list* array_list_new(){
    struct list *l = checked_malloc(sizeof(struct list)); //free
    l->array = checked_malloc(sizeof(char*) * 32);
    l->capacity = 32;
    l ->curr_len = 0;
    return l;
}

struct list* array_list_add_to_end(struct list *l, char *string) {
    //if not enough space - realloc
    if (l->curr_len == l->capacity) { //realloc l->internal array
        int increase_factor = l->capacity * 2;
        l->array = realloc(l->array, sizeof(char *) * increase_factor);
        l->capacity = increase_factor;
    }
    //append to l->array
    l->array[l->curr_len] = string;
    (l->curr_len)++;
    
    return l;

}


