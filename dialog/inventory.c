#include <stdio.h>
#include <string.h>
#include "vector.c"
#include "vectorI.c"

typedef struct Inventory{
    vector_t *object;
    vector_tI *count;
}Inventory;

Inventory* init_inventory()
{   
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));
    inventory->object = init_vector();
    inventory->count = init_vectorI();
    return inventory;
}