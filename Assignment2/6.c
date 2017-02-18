/* Submitted by
   Name:REDDI HAREESH Roll Number:150101051
   Question6:Write an O(n) algorithm to determine if there is a cycle in a single link list.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 struct node
    {
    int data;
    struct node* link;
    };
struct node* createnode() //function to create a new node
    {
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    return temp;
    }
struct node* insertatend(struct node *head,int data)//function to insert new element at end of linked list
{
    if(head==NULL) //if head is NULL then new node is head
     {
      struct node *temp;
      temp=createnode();
      temp->data=data;
      temp->link=NULL;
      head=temp;
      return head;
     }
  else
    {
    struct node *temp1=createnode();//Creating new node
    struct node *temp=head;
    while(temp->link!=NULL)//While loop to reach the last element
       temp=temp->link;
    temp1->data=data;
    temp->link=temp1;
    temp1->link=NULL;
    return head;
    }
}
void printlist(struct node* head)
   {
     printf("The linked List created is:");
     while(head!=NULL)//
       {  printf("%d\t",head->data);
	      head=head->link;
       }
     printf("\n\n");
}
//Function which returns YES or NO while determining the loop
const char* detectloop(struct node *head)//taking return type as const char*
  {
 	struct node *slowpointer= head;
	struct node *fastpointer= head;

	//slowpointer is moving to next node whereas fastpointer is moving to next to next node
	while (slowpointer&&fastpointer&&fastpointer->link)
	{
		slowpointer = slowpointer->link;//moving slow pointer one step
		fastpointer = fastpointer->link->link;//moving fast pointer two steps
		if (slowpointer == fastpointer)
		   return "YES";//returns YES if the loop is found
	}

	return "NO";//returns NO if the loop is found
  }
  int main()
  {
    struct node* head = NULL ; //Empty List
    int i,n;
    printf("Enter number of elements of linked list:");
    scanf("%d",&n);
	int a[n];//randomly taking 8 elements
	for(i=0;i<n;i++)
		a[i]=rand()%1000;//taking the random elements initially through an array
    printf("List of randomly generated 8 elements is:");
	for(i=0;i<n;i++)
		 printf("%d\t",a[i]);
	printf("\n\n");
//creating singly linked list by passing the elements of array one by one through for loop
    for(i=0;i<n;i++)
         head=insertatend(head,a[i]);//looping insertatend function

    printlist(head);//printing the list of randomly generated elements

    struct node* temp=head;
    while(temp->link!=NULL)
        temp=temp->link;

    temp->link=head;//Randomly giving the last link in the linked list to head
    printf("The output should be YES as i am giving last link NULL to initial pointer head\n\n");
    const char* y=detectloop(head);

    if(y=="YES")
        printf("YES-The Cycle is detected");//the loop is detected
    
    else if(y=="NO")
        printf("NO-The Cycle is not detected");//the loop is detected
    printf("\n\n");
    return 0;
 }
//Submitted by REDDI HAREESH-150101051-CSE Branch
