// singly linked list (finished)
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

void push_end(node *head, float x)
{
  node *current;
  current = head;
  while (!current)
    current = current->next;
  
  current->next = (node *)malloc(sizeof(node));
  current->next->next = NULL;
  current->next->DATA = x;
}

void push_beg(node **head, float x)
{
	node *new;
	new = (node *)malloc(sizeof(node));

	new->DATA = x;
	new->next = (*head);
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
		i++;
	
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
  head->DATA = 5; // some random value
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
		 push_end(head, value);
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
