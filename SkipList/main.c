#include<stdio.h>
#include"skiplist.h"

void main()
{
    SkipList* list = init_list();
    sl_insert(list,-10);
    sl_insert(list,-5);
    sl_insert(list,1);
    sl_insert(list,3);
    sl_insert(list,4);
    sl_insert(list,7);
    sl_insert(list,13);
    sl_insert(list,52);
    sl_insert(list,243);
    
    printList(list);
    sl_remove(list,52);
    sl_remove(list,1);

    printList(list);
    clear(list);
}