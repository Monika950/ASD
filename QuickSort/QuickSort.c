#include<stdio.h>
#include"vector.h"

void swap(int *a,int *b)
{
    int tmp=*a;
    *a = *b;
    *b = tmp;
}

int partition(vector_t* v, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = v->arr[end];
    
    printVector(v);
    while(1)
    {
        while(v->arr[i]<pivot)
        {
            i++;
        }

        while(v->arr[j]> pivot)
        {
            j--;
        }

        if(i>=j)
            return i;

        swap(&(v->arr[i]), &(v->arr[j]));

        i++;
        j--;

    }
}

void quicksortR(vector_t* v, int start, int end) {
    if ((start >= end)) {
        return;
    }
    
    printf("%d %d ", start, end);
    int mid = partition(v, start, end);
    quicksortR(v, start, mid - 1);
    quicksortR(v, mid, end);
}

void quicksort(vector_t* v) {
    quicksortR(v, 0, getSize(v) - 1);
}

void main()
{
    vector_t *v1 = init_vector();
    push_back(v1,9);
    push_back(v1,-7);
    push_back(v1,2);
    push_back(v1,1);
    push_back(v1,4);
    push_back(v1,88);
    push_back(v1,-1);
    push_back(v1,34);

    quicksort(v1);
    printVector(v1);
}