// doubly linked list (finished)
// compiler: GCC
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#define N 10

// defining bool because of error (commenting #include <stdbool.h>)
typedef int bool; 
#define false 0
#define true 1


typedef struct node 
{
  float DATA;
  struct node *prev;
  struct node *next;

} node;

void print_list(node *head)
{

  node *current;
  current = head;
  while (current != NULL)
  {
    printf("%f\t", current->DATA);
	current = current->next;
  }
}

/*void push_end(node **head, float x)
{
  node *new; 
  node *last = *head;
  new = (node *)malloc(sizeof(node));
  new->next = NULL;
  new->DATA = x;

  if (*head != NULL)
  {
    new->prev = NULL;
    *head = new;
   // return ;
  }
  while (last->next != NULL)
    last = last->next;
 
 last->next = new; 
  new->prev = last;

  //return ;
}*/

// geeks for geeks way

/* Given a reference (pointer to pointer) to the head 
   of a DLL and an int, appends a new node at the end  */
void append(struct node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct node* new_node = (struct Node*)malloc(sizeof(struct node)); 
  
    struct node* last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->DATA = new_data; 
  
    /* 3. This new node is going to be the last node, so 
          make next of it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new 
          node as head */
    if (*head_ref == NULL) { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = new_node; 
  
    /* 7. Make last node as previous of new node */
    new_node->prev = last; 
  
    return; 
} 
 

void push_beg(node **head, float x)
{
	node *new;
	new = (node *)malloc(sizeof(node));

	new->DATA = x;
	new->prev = NULL;
	new->next = (*head);
	
	if (!(*head))
		(*head)->prev = new;

	(*head) = new;
}

void search(node *head, float x)
{
	node *current;
	current = head;
	int isFound = false;
	int i =0;

	while (current != NULL && isFound == false)
	{
		if (current->DATA == x)
		{
			isFound = true;
			printf("\n The element with the value %.3f was found in no.%d spot! \n", x, i);
		}
		i    ;
	
	}

	if (isFound == false)
	{
		printf("\n The element with the value %.3f was not found in the list! \n", x);
		exit(1);
	}

}

int main() {
  node *head;
  head = (node *)malloc(sizeof(node)); 
  head->DATA = 5;
  head->prev = NULL;
  head->next = NULL;
	
 int user_choice, continue2;
 float value, data;

 do{
	 do {
		printf("\n1.Print the list. \n2.Add a node to the beginning. \n3.Add a node to the end. \n");
		printf("4.Search a specific data value in the list. \n99.Exit \n");
		scanf("%d", &user_choice);
	 }while (user_choice <1 || user_choice > 4 && user_choice != 99);
	 
	 switch(user_choice)
	 {
	 case 1: print_list(head);
			break;

	 case 2:
		 printf("\n Enter the value of the new node: \n");
		 scanf("%f", &value);
		 push_beg(&head, value);
		 break;

	 case 3:
		printf("\n Enter the value of the new node: \n");
		 scanf("%f", &value);
		 /*push_end(head, value);*/
     append(&head, value);
		 break;
	
	 case 4: 
		 printf("\n Enter the data to be searched: \n");
		 scanf("%f", &data);
		 search(head, data);
		 break;

	 case 99:
		 exit(0);
		 break;
	 };


	printf("\n Do you wish to continue (0 for no, 1 for yes)?\n");
    scanf("%d", &continue2);
 } while (continue2 == 1);
  
 
  system("pause");
  return 0;
}
