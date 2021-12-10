#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
}node;

void display(node *temp)
{
	//now temp1 is head basically
	node *temp1=temp; 
	printf("The list is as follows :\n%d->",temp->data);
	temp=temp->next;
	//which not circle back to head node 
	while(temp!=temp1) 
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp1->data);
	
	return;
}

int main(){
	node *head=NULL,*temp,*temp1;
	int choice,count=0,key;

	//Taking the linked list as input
	do
	{
		temp=(node *)malloc(sizeof(node));
		if(temp!=NULL)
		{
			printf("\nEnter the element in the list : ");
			scanf("%d",&temp->data);
			temp->next=NULL;
			if(head==NULL)
			{	
				head=temp;
			}
			else
			{
				temp1=head;
				while(temp1->next!=NULL)
				{
					temp1=temp1->next;
				}
				temp1->next=temp;
			}
		}
		else
		{
			printf("\nMemory not avilable...node allocation is not possible");
		}
		printf("\nIf you wish to add m ore data on the list enter 1 : ");
		scanf("%d",&choice);
	}while(choice==1);
	
	//In order to convert a singly linked list to a 
	//circular singly linked list we just need to copy 
	//the address of the head node to the next of the last node
	temp=head;
	//travarsing to the last node
	while(temp->next!=NULL)	
	{
		temp=temp->next;
	}
	//the address of the head is copied to the next part 
	//of the last node.....now it is a circular singly linked list
	temp->next=head;	
	display(head);
	
	return 0;
}