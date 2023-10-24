#include<stdio.h>
#include"vector.h"

void swap(int *a,int *b)
{
    int tmp =*a;
    *a = *b;
    *b = tmp;
}

int partition(vector_t* v, int start,int end)
{
    int i = start-1;
    int j = start;
    int pivot = v->arr[end];

    for ( j; j < end;j++)
    {
        if(v->arr[j]<=pivot)
        {
            i++;
            swap(&v->arr[i],&v->arr[j]);
        }
    }
    swap(&v->arr[end],&v->arr[i+1]);
    return (i+1);
}

void quicksortR(vector_t* v, int start, int end) {
    if ((start < end)) 
    {
        int NewP = partition(v, start, end);
        printVector(v);
        quicksortR(v, start, NewP-1);
        quicksortR(v, NewP+1, end);
    }
}

void quicksort(vector_t* v) {
    quicksortR(v, 0, getSize(v) - 1);
}

void main()
{
    vector_t *v1 = init_vector();
    push_back(v1,3);
    push_back(v1,4);
    push_back(v1,9);
    push_back(v1,1);
    push_back(v1,7);
    push_back(v1,0);
    push_back(v1,5);
    push_back(v1,2);
    push_back(v1,6);
    push_back(v1,8);

    quicksort(v1);
    printVector(v1);
}