#include<stdio.h>
#include<stdlib.h>
#define NEWNODE (struct node *)malloc(sizeof(struct node))


struct node 
{
	int data;
	struct node *next;
};


struct node * create_circularsingly_linked_list(int n)
{
	struct node *f = NULL, *l = NULL, *t = NULL;
	int i;

	f = NEWNODE;
	printf("Enter the data :");
	scanf("%d",&f->data);
	f->next = NULL;
	l = f;

	for ( i = 2; i <= n; i++)
	{

		t = NEWNODE;
		printf("Enter the data :");
		scanf("%d",&t->data);
		t->next = NULL;
		l->next = t;
		l = l->next;
		
	}
	return f;
}

void display_linked_list(struct node *f)
{
	printf("Linked list : ");
	struct node *t;
	for ( t = f; t!=NULL; t=t->next )
	{
		printf(" %d-> ",t->data);
	}
	printf("NULL\n");
}

struct node * eraseall_node(struct node *f)
{
	struct node *t;
	t=f;
	f = f->next;
	t->next = NULL;
		
	while(f!=NULL)
	{
		t=f;
		f=f->next;
		free(t);
	}
	return f;
}


int main()
{
	int n;
	struct node *head;
	printf("Enter the size of link list :\n");
	scanf("%d",&n);
	if (n<=0)
	{
		printf("Invalid input...Linked list can not create!!! \n");
		exit(0);
	}

	head = create_circularsingly_linked_list(n);
	display_linked_list(head);
	head = eraseall_node(head);
}