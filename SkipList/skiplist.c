#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

Node *createnode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;

    for (int i = 0; i < MAXLEVEL; i++)
    {
        node->next[i] = NULL;
    }
    return node;
}

SkipList *init_list()
{
    Node *head = createnode(0);
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->head = head;

    return list;
}

void printList(SkipList *list)
{
    for (int i = 0; i < MAXLEVEL; i++)
    {
        Node *it = list->head;
        printf("lev %2d H -> %d ", i, it->value);
        while (it != NULL)
        {
            it = it->next[i];
            if (it != NULL)
            {
                printf("%d -> ", it->value);
            }
        }
        printf("NULL\n");
    }
}

void clear(SkipList *list)
{
    Node *it = list->head;
    while (it != NULL)
    {
        Node *tmp = it->next[0];
        it = it->next[0];
        free(tmp);
    }
    free(list);
}

void sl_insert(SkipList *list, int val)
{
    Node *it[MAXLEVEL] = {0};
    it[MAXLEVEL - 1] = list->head;
    for (int i = MAXLEVEL - 1; i >= 0; i--)
    {
        while (it[i]->next[i] != NULL && it[i]->next[i]->value < val)
        {
            it[i] = it[i]->next[i];
        }
        it[i - 1] = it[i];
    }

    Node *newNode = createnode(val);
    int connectLayer = 0;

    do
    {
        newNode->next[connectLayer] = it[connectLayer]->next[connectLayer];
        it[connectLayer]->next[connectLayer] = newNode;
        connectLayer++;
    } while (rand() < RAND_MAX / 2 && connectLayer < MAXLEVEL);
}

Node *sl_search(SkipList *list, int value)
{
    Node *it = list->head;
    for (int i = MAXLEVEL - 1; i >=0; i--)
    {
        while (it->next[i] != NULL && it->next[i]->value < value)
            it = it->next[i];
    }
    it = it->next[0];

    if (it != NULL && it->value == value)
        return it;
    else
        return NULL;
}

Node* sl_remove(SkipList* list, int value)
{

    Node *it[MAXLEVEL]={0};
    it[MAXLEVEL-1] = list->head;
    for (int i = MAXLEVEL - 1; i >=0; i--)
    {
        while (it[i]->next[i]!= NULL && it[i]->next[i]->value < value)
        {
                it[i] = it[i]->next[i];  
        } 
        if(i!=0)
            it[i-1]=it[i];
    }
    
    if(it[0]->next[0]!= NULL && it[0]->next[0]->value ==value)
    {
        Node* removed = it[0]->next[0];
        for(int i=0; i<MAXLEVEL;i++){
            if(it[i]->next[i]!=NULL)
            {
                it[i]->next[i] = it[i]->next[i]->next[i];
            }
            else 
                break;
        }
        return removed;

    } else
        return NULL;
    
    
    

}
