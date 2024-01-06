#ifndef SKIP_H
#define SKIP_H

#define MAXLEVEL 16

typedef struct Node{
    int value;
    struct Node* next[MAXLEVEL];
}Node;

typedef struct{
    Node *head;
}SkipList;

SkipList* init_list();
void clear(SkipList* list);
void printList(SkipList* list);

void sl_insert(SkipList* list, int value);
Node* sl_remove(SkipList* list, int value);
Node* sl_search(SkipList* list, int value);
#endif