// C program to print the even elements
// of linked list

#include <stdio.h>
#include <stdlib.h>

//Self-referential structure to create the node.
typedef struct tmp {
    int item;
    struct tmp* next;
} Node;

//structure for creating the linked list.
typedef struct
    {
    Node* head;
    Node* tail;

} List;

//Initialize List
void initList(List* lp)
{
    lp->head = NULL;
    lp->tail = NULL;
}

//Create node and return the reference of it.
Node* createNode(int item)
{
    Node* nNode;

    nNode = (Node*)malloc(sizeof(Node));

    nNode->item = item;
    nNode->next = NULL;

    return nNode;
}

//Add a new item at the end of the list.
void addAtTail(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    //if list is empty.
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        lp->tail->next = node;
        lp->tail = lp->tail->next;
    }
}

//Add a new item at the beginning of the list.
void addAtHead(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    //if list is empty.
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        node->next = lp->head;
        lp->head = node;
    }
}

//To print the list from start to end of the list.
void printList(List* lp)
{
    Node* node;

    if (lp->head == NULL) {
        printf("\nEmpty List");
        return;
    }

    node = lp->head;

    while (node != NULL) {
        printf("| %05d |", node->item);
        node = node->next;

        if (node != NULL)
            printf("--->");
    }
    printf("\n\n");
}

void printEvens(List* lp)
{
    Node* temp;

    temp = lp->head;

    while (temp != NULL) {
        if (temp->item % 2 == 0)
            printf("%d ", temp->item);

        temp = temp->next;
    }
}

//Main function to execute program.
int main()
{
    List* lp;

    lp = (List*)malloc(sizeof(List));

    initList(lp);

    addAtHead(lp, 101);
    addAtHead(lp, 102);
    addAtHead(lp, 103);
    addAtHead(lp, 104);
    addAtHead(lp, 105);

    printf("List:\n");
    printList(lp);

    printf("Even elements: \n");
    printEvens(lp);

    printf("\n");

    return 0;
}