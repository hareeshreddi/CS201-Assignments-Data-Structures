/*Submitted by
  Name:REDDI HAREESH Roll Number:150101051
  Question5:Round-Robin Scheduling using Queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct time//struct for time
{
	int r;
	struct time *link;
};
struct node//struct for each node
{
	int name;
	int arrivaltime;
	int executetime;
	struct node *next;
	struct time *p;
	int outtime;
	int intime;
};
void insertatend(struct node **temp,int a,struct node *m[])//Function to insert at end
{
	struct node *base=*temp;
	if(base== NULL)
	    *temp = m[a];
	else
	{
	 while(base->next != NULL)
		  base= base->next;
        base->next= m[a];
	}
}
void removeit(struct node **queue)
{
	struct node *b=*queue;
        (*queue)=(*queue)->next;
	b->next = NULL;//assigning NULL to b->next
}
void goBack(struct node *m[], struct node **temp)
{
	struct node *base=*temp;
	int index;
	index = base->name;
	base= base->next;
	m[index]->next= NULL;
	*temp=base;
	while(base->next!= NULL)
	    base= base->next;
	base->next = m[index];
}
struct time* reg(int a)
{
	struct time *queue=(struct time*)malloc(sizeof(struct time));
	queue->r= a;
	queue->link=NULL;
	return queue;
}
void areg(struct time **queue, int a)
{
    struct time *temp=*queue;
	if(temp== NULL)
	  *queue = reg(a);
	else
	{ while(temp->link!= NULL)
                temp= temp->link;
		temp->link= reg(a);
	}
}
int main()
{
	int quantumtime;
	printf("Enter the Quantum time:");
	scanf("%d",&quantumtime);
	int n,i;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	struct node *head[n];
	for(i = 0;i<n;i++)
	{
		head[i] = (struct node*)malloc(sizeof(struct node));
		head[i]->name = i;
		printf("process:P%d\n", i);
		printf("Enter ArrivalTime: ");
		scanf("%d",&(head[i]-> arrivaltime));
		printf("Enter ExecuteTime: ");
		scanf("%d", &(head[i]-> executetime));
		head[i]->next= NULL;
		head[i]->p= NULL;
		head[i]->outtime = 0;
		head[i]->intime = 0;
	}
	struct node *start;
	start = NULL;
        int time=0,location=0;
	int k,u=0;
	while(start!=NULL||location< n)
	{
		for(k=0;k<n;k++)
		{
		    if(head[k]->arrivaltime == time)
			{
			     if(start == NULL)
				{ head[k]->intime = time;
					u=1;
				}
			     insertatend(&start,k, head);
			      if(u == 1)
				  areg(&(start->p), time);
				     u= 0;
				     location++;
			}
		}
		if(start!= NULL)
		{
			if(start->outtime +(time-start->intime) >= start->executetime)
			{       areg(&(start->p), time);
				removeit(&start);
				if(start != NULL)
				{
					areg(&(start->p), time);
					start->intime = time;
				}
			}
		}
		if(start!= NULL&&start->next != NULL)
		{
			if(time -(start->intime) >= quantumtime)
			{
				areg(&(start->p), time);
				start->outtime += quantumtime;
				goBack(head, &start);
				areg(&(start->p), time);
				start->intime = time;
			}
		}
		time++;
	}
	struct time *Time;
        printf("The Output is:\n");
	for(k=0;k<n;k++)
	{       
		printf("P%d: ",k);
		Time = (head[k]->p);
		do
		{   printf("<%d-",Time->r);
		    printf("%d>",(Time->link)->r);
		    printf("  ");
                    Time = (Time->link)->link;
		}while(Time!= NULL);
    printf("\n");
	}
	return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch

