/*Submitted by
  Name:REDDI HAREESH Roll Number:150101051
  Question 4(b):To write O(n) algorithm using stacks to find array S
*/
#include<stdio.h>
#include<stdlib.h>
int isempty(int top)
{ if(top==-1)
    return 1;//return 1 if stack is empty
  else
    return 0;//return 0 if stack is not empty
}
void push(int stack[],int i,int X[],int *top)//function to push the elements into the stack
{
      (*top)=(*top)+1;//increment the top position by 1
       stack[(*top)]=X[i];
}
void pop(int *top)//function to pop the elements from the stack
{
  (*top)=(*top)-1;//decrement the top position by 1
}
void calculatespan(int *X,int n,int *S)
{
   int stack[n],i,j;//top refers to top position(index) in the stack
   int top=-1;//initialize top to -1 when the stack is empty
   push(stack,0,X,&top);
   S[0]=1;//value of S[0] is always 1
   for (i=1;i<n;i++)
      {  //Pop elements from stack while stack is not empty and  X[top] is less than or equal to X[i]

        while (!isempty(top)&&X[top]<=X[i])//it checks both isempty condition and X[top]<=X[i]
            pop(&top);//pop the top element from the stack

        if(isempty(top))//check whether stack is empty or not
           S[i]=i+1;//If stack becomes empty, then X[i] is greater or equal than all elements on left of it and also X[i]>=X[i];So i+1
        else
           S[i]=i-top;//X[i]is greater than elements after top of stack;So i-top

        for(j=top;j<=i;j++)//looping positions from top to i in the for loop
           push(stack,j,X,&top);
     }
//We can actually observe that every element of array is pushed into and popped out from stack at most once.
//So there are total 2n operations in worst case. Assuming that a stack operation takes constant time, we can say that the time complexity is O(n).
}
void printarray(int *S,int n)
{  int i;
   printf("The span array S is:\t");//printing the final Spanarray S;
   for(i=0;i<n;i++)
      printf("%d\t",*(S+i));
   printf("\n");
}
int main()
{   int i,n;
    printf("Enter the number of elements of the array X:");
    scanf("%d",&n);
    int *X=(int*)malloc(sizeof(int)*n);//allocating sufficient memory space to array X
    printf("Enter %d elements of the array X:",n);
    for(i=0;i<n;i++)
        scanf("%d",&X[i]);
    int *S=(int*)malloc(sizeof(int)*n);//allocating sufficient memory space to array S
    calculatespan(X,n,S);
    printarray(S,n);
    return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch

