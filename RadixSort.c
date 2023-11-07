#include <stdio.h>
#include <stdlib.h>

int find_max(int* arr, int n)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
    {   
        if(max<arr[i])
            max=arr[i];
    }
    return max;
}

void countSort(int* input,int n,int num)
{
    int max = find_max(input,n);
    int count[19]={0};
    
 
    //колко започващи с тази цифра има
    for (int i = 0; i < n; i++)
    {
        count[((input[i]/num)%10)+9]++;//-9(0) -8 -7 -6 -5 -4 -3 -2 -1
                                       // 0(9)  1  2  3  4  5  6  7  8  9
    }
 
    //колко преди него има и откъде да започнат
    printf("count:\n");
    printf("count[%d] = %d\n",0,count[0]);
    for (int i = 1; i < 19; i++)
    {
        count[i] += count[i - 1];
        printf("count[%d] = %d\n",i,count[i]); //предишната кофа плюс колко са в тази
    }
    
    
 
    int* output =(int*)calloc(n, sizeof(int));
 
    for (int i=n-1; i>=0; i--)
    {
        int digit=(input[i]/num)%10 +9 ;
        output[count[digit] - 1]= input[i];
        count[digit]--;
    }

    for(int i=0; i<n; i++)
        input[i]=output[i];

    free(output);   

}



void radix_sort(int* arr,int n, unsigned int num)
{
    int max = find_max(arr,n);
    countSort(arr,n,num);

    if(max/num!=0)
    {
        printf("Array sorted %d:\n",num);
        for(int i=0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\n");
        radix_sort(arr,n,num*10);
    }

}

void printArr(int*arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main()
{
    int arr[10]= {52,32,-47,949,221,-27,56,4,-350,8}; //голям
    printArr(arr,10);
    radix_sort(arr, 10, 1);
    printArr(arr,10);
    printf("__________________\n\n");

    int arr2[4]= {52,32,47,94}; //малък
    printArr(arr2,4);
    radix_sort(arr2, 4, 1);
    printArr(arr2,4);
    printf("__________________\n\n");

    int arr3[4]= {10,20,40,79}; //сортиран
    printArr(arr3,4);
    radix_sort(arr3, 4, 1);
    printArr(arr3,4);
    printf("__________________\n\n");

    int arr4[5]= {70,40,33,25,14}; //обратен
    printArr(arr4,5);
    radix_sort(arr4, 5, 1);
    printArr(arr4,5);
    printf("__________________\n\n");

    int arr5[8]= {2,5,3,0,2,3,0,3}; //повтарящи се
    printArr(arr5,7);
    radix_sort(arr5, 7, 1);
    printArr(arr5,7);
    printf("__________________\n\n");

    int arr6[]= {}; //празен
    printArr(arr6,0);
    radix_sort(arr6, 0, 1);
    printArr(arr6,0);
    printf("__________________\n\n");


/*Обяснение относно сложността на алгоритъма  O(d * (n + b))= максималният брой на цифрите 
умножено по сбора на елементите в масива и бройната система (от нея зависи броя на кофите)*/

    

}