// C program to find the middle node of
// the singly linked list

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

void findMiddleNode(List* lp)
{
    Node* temp;

    int count = 0;
    int middle = 0;

    temp = lp->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    middle = count / 2;
    if (count % 2 != 0)
        middle += 1;
    count = 0;

    temp = lp->head;
    while (temp != NULL) {
        count++;
        if (count == middle) {
            printf("Middle node is: %d\n", temp->item);
            break;
        }
        temp = temp->next;
    }
}

//Main function to execute program.
int main()
{
    List* lp;

    lp = (List*)malloc(sizeof(List));

    initList(lp);

    addAtTail(lp, 101);
    addAtTail(lp, 102);
    addAtTail(lp, 103);
    addAtTail(lp, 104);
    addAtTail(lp, 105);

    printf("List:\n");
    printList(lp);

    findMiddleNode(lp);

    return 0;
}