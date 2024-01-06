
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct vector_t
{
    char **arr;
    unsigned int size;
    unsigned int capacity;
} vector_t;

vector_t *init_vector()
{
    vector_t *v = (vector_t *)malloc(sizeof(vector_t));
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;

    return v;
}

void resize(vector_t *v, int newCapacity)
{
    char **tmp = (char **)realloc(v->arr, newCapacity * sizeof(char*));
    if (tmp == NULL)
    {
        exit(1);
    }
    
    v->arr = tmp;
    v->capacity = newCapacity;
}

void push(vector_t *v, int index, char* value)
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

        resize(v, v->capacity);
    }
    v->size++;
    for (int i = v->size - 1; i > index; i--)
    {
        v->arr[i] = v->arr[i - 1];
    }
    strcpy(v->arr[index],value);
}

void push_back(vector_t *v, char* val)
{
    if(v==NULL)return;
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
        resize(v, v->capacity);
    }
    v->arr[v->size]=strdup(val);
    v->size++;
}


char* pop(vector_t *v)
{
    if (v->size == 0)
    {
        return NULL;
    }

    char* val;
    strcpy(val,v->arr[v->size - 1]);
    v->size--;

    return val;
}

void clear(vector_t *v)
{
    free(v->arr);
    v->size = 0;
    v->capacity = 0;
}

char* getAt(vector_t *v, int index)
{
    if (index >= v->size)
    {
        return NULL;
        // exit(1);
    }

    return v->arr[index];
}

int getSize(vector_t *v)
{
    return v->size;
}

void printVector(vector_t *v)
{
    for (int i = 0; i < getSize(v); i++)
    {
        printf("%d. %s\n",i+1, getAt(v, i));
    }
}