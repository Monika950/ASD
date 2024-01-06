#include <stdlib.h>
#include <stdio.h>

typedef struct vector_tI
{
    int *arr;
    unsigned int size;
    unsigned int capacity;
} vector_tI;

vector_tI *init_vectorI()
{
    vector_tI *v = (vector_tI *)malloc(sizeof(vector_tI));
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;

    return v;
}

void resizeI(vector_tI *v, int newCapacity)
{
    int *tmp = (int *)realloc(v->arr, newCapacity * sizeof(int));
    if (tmp == NULL)
    {
        exit(1);
    }

    v->arr = tmp;
    v->capacity = newCapacity;
}

void push_backI(vector_tI *v, int val)
{
  
    if (v->size == v->capacity)
    {
        
        if (v->capacity == 0)
        {
            v->capacity = 2;
        }
        else
        {
            v->capacity *= 2;
        }

        resizeI(v, v->capacity);
    }

    v->arr[v->size] = val;
    v->size++;
}


int popI(vector_tI *v)
{
    if (v->size == 0)
    {
        return -1;
    }

    int val = v->arr[v->size - 1];
    v->size--;

    return val;
}

void clearI(vector_tI *v)
{
    free(v->arr);
    v->size = 0;
    v->capacity = 0;
}

int getAtI(vector_tI *v, int index)
{
    if (index >= v->size)
    {
        return -1;
        // exit(1);
    }

    return v->arr[index];
}

int getSizeI(vector_tI *v)
{
    return v->size;
}

void printVectorI(vector_tI *v)
{
    for (int i = 0; i < getSizeI(v); i++)
    {
        printf("%d ", getAtI(v, i));
    }
    printf("\n");
}