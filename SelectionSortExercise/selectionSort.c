/*Използвайки вектор имплементацията от миналия час реализирайте Selection Sort алгоритъма. Selection sort работи като условно разделя масива на две части. Сортирана лява част, която в началото е празна, и несортирана дясна, която в началото е целия масив. Обхожда несоритраната част на масива и намира най-малкия (или най-големия) елемент в нея и го разменя с първия елемент от несортиранта част. Така вече този елемент е част от сортираната част. След N повторения масива е сортиран.*/

#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

vector_t* SelectionSort(vector_t* v)
{
    int minimum, tmp;
    for(int i = 0; i < v->size-1; i++)
    {
        minimum= i;
        tmp = v->arr[i];
        for(int j = i+1; j < v->size; j++)
        {
            if(v->arr[minimum]>v->arr[j])
            {
                minimum=j;
            }
        }
        if(minimum!=i){
            v->arr[i]=v->arr[minimum];
            v->arr[minimum]=tmp;
        }
    }
    return v;
}

vector_t* SortingTwoInOne(vector_t* v1, vector_t* v2)
{
    vector_t* v3 = init_vector();
    int i,j; 
    for(i=0,j=0; i<v1->size && j<v2->size;)
    {
        if(v1->arr[i]<v2->arr[j])
        {
            push_back(v3,v1->arr[i]);
            i++;
        }
        else
        {
            push_back(v3,v2->arr[j]);
            j++;
        }
    }
    for(i;i<v1->size;i++)
            push_back(v3,v1->arr[i]);

    for(j;j<v2->size;j++)
            push_back(v3,v2->arr[j]);
    
    
    return v3;
}

int vectorSum(vector_t* v,int currentIndex)
{
    if(currentIndex==v->size-1)
        return v->arr[currentIndex];
    return v->arr[currentIndex]+vectorSum(v,currentIndex+1);
}

void allVectorSums(vector_t *v, int currentIndex, int currentSum);

void main()
{
    vector_t *v1 = init_vector();
    push_back(v1,9);
    push_back(v1,5);
    push_back(v1,2);
    push_back(v1,1);
    push_back(v1,4);

    vector_t *v2 = init_vector();
    push_back(v2,10);
    push_back(v2,8);
    push_back(v2,7);
    push_back(v2,6);
    push_back(v2,3);

    vector_t *v3 = init_vector();
    v1=SelectionSort(v1);
    v2=SelectionSort(v2);
    v3=SortingTwoInOne(v1,v2);

    printVector(v1);
    printVector(v2);
    printVector(v3);

    
    vector_t *v4 = init_vector();
    push_back(v4,5);
    push_back(v4,6);
    push_back(v4,7);
    printVector(v4);
    printf("Sum = %d\n",vectorSum(v4,0));

}