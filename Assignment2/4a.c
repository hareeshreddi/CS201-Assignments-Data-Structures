/* Submitted by
   Name:REDDI HAREESH Roll Number:150101051
   Question 4(a):To write O(n*n) algorithm to find out array S for given array X
   */
#include<stdio.h>
#include<stdlib.h>
/*void findSpanarray(int *X,int *S,int n)
{   int i,j;
    for(j=0;j<n;j++)
    {  for(i=j;i>=0;i--)
         if(X[i]<=X[j])
           S[j]++;
         else//use break in this method to come out of inner for loop whenever X[i]>X[j]
           break;
    }
}*/ //alternative method to write the algorithm
void findSpanarray(int *X,int *S,int n)//function to find array S
{   int i,j;
    for(j=0;j<n;j++)
    {  i=j;//initialize i as j
       while(X[i]<=X[j]&&i>=0)// Traverse left in the array X while the next element on left is smaller or equal to X[j] and i has non negative value
        { S[j]++;
          i--;
        }
    }
}
void printSpanarray(int *p,int n)//to print the final output array S
{  int i;
   printf("The span array S is:\t");
   for(i=0;i<n;i++)
      printf("%d\t",*(p+i));//printing final array using pointer p
   printf("\n");
}
int main()
{
    int i,n;
    printf("enter the number of elements of array X:");
    scanf("%d",&n);//to enter the number of elements of array X
    int *X=(int*)malloc(sizeof(int)*n);
    int *S=(int*)malloc(sizeof(int)*n);//giving sufficient memory
    printf("enter the elements of X:");//giving sufficient memory
    for(i=0;i<n;i++)
       scanf("%d",&X[i]);
    for(i=0;i<n;i++)
        S[i]=0;
    findSpanarray(X,S,n);
    printSpanarray(S,n);
}
//Submitted by REDDI HAREESH-150101051-CSE Branch
