#include <stdio.h>
#include <string.h>

#include "inventory.c"

typedef struct Node
{
    char *NPC;
    vector_t *replies;
    Inventory *requirements;
    struct Node **steps;

} Node;

Node *init_node(char *NPC, vector_t *replies, Node **steps, Inventory *requirements)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->NPC = strdup(NPC);
    node->replies = replies;
    node->steps = steps;
    node->requirements = requirements;
    return node;
}

void play_dialog(Node *root, Inventory *inventory)
{
    printf("%s\n", root->NPC);
    if (root->replies == NULL || root->replies->size == 0)
    {
        if (root->steps == NULL)
            return;
        play_dialog(root->steps[0], inventory);
    }
    else if (root->replies->size == 1)
    {
        printf("%s\n", root->replies->arr[0]);
        if (root->steps[0] == NULL)
            return;
        play_dialog(root->steps[0], inventory);
    }
    else
    {
        int choice;
        for (int i = 0; i < root->replies->size; i++)
        {
            printf("%d. %s\n", i + 1, root->replies->arr[i]);
            if (root->requirements == NULL)
                printf("    tax free\n");
            else if (root->requirements->object->arr[i] == NULL)
                printf("    tax free\n");
            else
                printf("    required -> %d %s\n", root->requirements->count->arr[i],root->requirements->object->arr[i]);
        }

        scanf("%d", &choice);
        while (choice < 1 || choice > root->replies->size)
        {
            printf("%d is not an available option\n", choice);
            scanf("%d", &choice);
        }
        choice--;
        int flag = 1;
        while (flag==1 && root->requirements!=NULL)
        {
            if (root->requirements->object->arr[choice] == NULL)
            {
                flag = 0;
                break;
            }
            else
            {
                for (int i = 0; i < inventory->object->size; i++)
                {
                    if (strcmp(root->requirements->object->arr[choice], inventory->object->arr[i]) == 0)
                        if (root->requirements->count->arr[choice] <= inventory->count->arr[i])
                        {
                            flag = 0;
                            break;
                        }
                }
            }
            if (flag)
            {
                printf("You do not meet the requirements. Choose another option\n");
                scanf("%d", &choice);
                while (choice < 1 || choice > root->replies->size)
                {
                    printf("%d is not an available option\n", choice);
                    scanf("%d", &choice);
                }
                choice--;
            }
        }
        printf("%s\n", root->replies->arr[choice]);
        if (root->steps[choice] == NULL)
            return;
        play_dialog(root->steps[choice], inventory);
    }
}

void main()
{
    Inventory *inventory = init_inventory();
    push_back(inventory->object, "dragon head");
    push_backI(inventory->count, 1);
    push_back(inventory->object, "coins");
    push_backI(inventory->count, 10);
    push_back(inventory->object, "books");
    push_backI(inventory->count, 2);

    Node *start = init_node("Welcome to Fantasytown. How can I help you?", NULL, NULL, NULL);

    vector_t *r = init_vector();
    push_back(r, "I want to buy armor.");
    push_back(r, "I have slain the dragon.");
    push_back(r, "Speak with the king.");

    Inventory *required = init_inventory();
    push_back(required->object, NULL);
    push_backI(required->count, 0);
    push_back(required->object, "dragon head");
    push_backI(required->count, 1);
    push_back(required->object, NULL);
    push_backI(required->count, 0);

    Node *receiveA[] = {
        init_node("Here is your armour.", NULL, NULL, NULL),
        init_node("Here is your armour.", NULL, NULL, NULL),
    };

    vector_t *armorR = init_vector();
    push_back(armorR, "Buy cheap Light armor.");
    push_back(armorR, "Buy expensive Heavy armor.");

    Inventory *required1 = init_inventory();
    push_back(required1->object, "coins");
    push_backI(required1->count, 10);
    push_back(required1->object, "coins");
    push_backI(required1->count, 15);

    Node *armors = init_node("I have some armors.", armorR, receiveA, required1);

    Node *array[] = {start};
    Node *reward = init_node("Here is your reward. Anything else?", NULL, array, NULL);

    vector_t *king = init_vector();
    push_back(king, "To marry your daughter.");
    push_back(king, "To end your tyranny.");
    Node *kingN = init_node("I am the king. What do you want?", king, NULL, NULL);

    Node *steps[] = {
        armors,
        reward,
        kingN};
    start->replies = r;
    start->steps = steps;
    start->requirements = required;

    play_dialog(start, inventory);
}