
#include <stdio.h>  
#include<stdlib.h>  
//Represent a node of the doubly linked list  
  
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};  
   
//Represent the head and tail of the doubly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node newNode = (struct node)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and tail will point to newNode  
        head = tail = newNode;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //tail's next will point to NULL, as it is the last node of the list  
        tail->next = NULL;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode's previous will point to tail  
        newNode->previous = tail;  
        //newNode will become new tail  
        tail = newNode;  
        //As it is last node, tail's next will point to NULL  
        tail->next = NULL;  
    }  
}  
   
//display() will print out the nodes of the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of doubly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer.  
        printf("%d \n", current->data);  
        current = current->next;  
    }  
}  
   
int main()  
{  int a=1,b; 
    //Add nodes to the list  
    while (a!=8)
    {printf("Enter data for node %d \n",a);
    scanf("%d",&b);
        addNode(b);  
    a++;
    }
    //Displays the nodes present in the list  
    display();  
   
    return 0;  
    }