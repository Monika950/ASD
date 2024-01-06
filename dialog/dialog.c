#include <stdio.h>
#include <string.h>
#include "vector.c"

typedef struct Node
{
    char *NPC;
    vector_t *replies;
    struct Node **steps;

} Node;

/*char *line
 vector * answer
  Node ** next
  */

Node *init_node(char *NPC, vector_t *replies, Node **steps)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->NPC = strdup(NPC);
    node->replies = replies;
    node->steps = steps;

    return node;
}

void play_dialog(Node *root)
{
    printf("%s\n", root->NPC);
    if (root->replies == NULL || root->replies->size == 0)
    {
        if (root->steps == NULL)
            return;
        play_dialog(root->steps[0]);
    }
    else if (root->replies->size == 1)
    {
        printf("%s\n", root->replies->arr[0]);
        if (root->steps[0] == NULL)
            return;
        play_dialog(root->steps[0]);
    }
    else
    {
        int choice;
        printVector(root->replies);

        scanf("%d", &choice);
        while (choice < 1 && choice > root->replies->size)
        {
            printf("%d is not an available option\n", choice);
            scanf("%d", &choice);
        }
        printf("%s\n", root->replies->arr[choice - 1]);
        if(root->steps[choice - 1]==NULL)
            return;
        play_dialog(root->steps[choice - 1]);
    }
}

void main()
{
   
    Node *start = init_node("Welcome to Fantasytown. How can I help you?", NULL,NULL);

    vector_t *r = init_vector();
    push_back(r, "I want to buy armor.");
    push_back(r, "I have slain the dragon.");
    push_back(r, "Speak with the king.");

    Node *receiveA[] = { 
        init_node("Here is your armour.", NULL, NULL),
        init_node("Here is your armour.", NULL, NULL)
    };

    vector_t *armorR = init_vector();
    push_back(armorR, "Buy cheap Light armor.");
    push_back(armorR, "Buy expensive Heavy armor.");
    Node *armors = init_node("I have some armors.", armorR, receiveA);

    Node *array[]={start};
    Node *reward = init_node("Here is your reward. Anything else?", NULL,array );

    vector_t *king = init_vector();
    push_back(king, "To marry your daughter.");
    push_back(king, "To end your tyranny.");
    Node *kingN = init_node("I am the king. What do you want?", king, NULL);

    Node *steps[] = { 
       armors,
       reward,
       kingN 
    };
    start->replies=r;
    start->steps=steps;

    play_dialog(start);
}