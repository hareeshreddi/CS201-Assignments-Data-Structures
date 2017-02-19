/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question1:Find level of the leaf node with largest level and the level of leaf node with smallest level
*/
//In the solution i am assuming level of root node(if there is only one node in the tree) to be 0
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* GetNewNode(int data)//Function allocate memory for new node
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

struct node* Insert(struct node* root,int data)//Function to insert node in binary search tree
{
    if(root==NULL)
         root=GetNewNode(data);//using GetNewNode function

    else if(data<=root->data)//if the number to be inserted is less than or equal to root->data
         root->left=Insert(root->left,data);

    else//if the number to be inserted is greater than root->data
         root->right=Insert(root->right,data);

    return root;//returns root which is of type struct node*
}

int max(int x, int y)
{
    return (x>y)? x : y;
}

int min(int x, int y)//if any of them is 0 then return the other number
{
     if(x==0)return y;
     if(y==0)return x;
     return (x<y)? x : y;//return x if x is less than y else y
}

int LargestLevelOfLeafNode(struct node* root,int maxlevel)//Function to find Maximum level of a leaf node
{      if(root==NULL)//Base case
         return 0;

       if(root->right==NULL&&root->left==NULL)//return maxlevel if the node is leaf node
         return maxlevel;

       return max(LargestLevelOfLeafNode(root->left,maxlevel+1),LargestLevelOfLeafNode(root->right,maxlevel+1));
}

int SmallestLevelOfLeafNode(struct node*root,int minlevel)//Function to find Smallest level of a leaf node
{   if(root==NULL)//Base case
         return 0;

    if(root->right==NULL&&root->left==NULL)//return minlevel if the node is leaf node
         return minlevel;

    return min(SmallestLevelOfLeafNode(root->left,minlevel+1),SmallestLevelOfLeafNode(root->right,minlevel+1));
}

int maximum_element(int *array,int size)//Function to get maximum element of the array
{
    int maximum = array[0],c;
    for (c = 1;c < size; c++)
    {
    if (array[c]>maximum)

       maximum  = array[c];
    }
    return maximum;//The function returns maximum in the given array
}

void PrintFrequency(int *arr,int size,int maximum)//This function prints the table
{
    printf("\t\t\t\t\t\t\t\tTable::\n\n");
    int i,j,count;
    int freq[maximum+1];
//size of the array should be maximum+1 as there may be differences from 0 to maximum i.e. a total of maximum+1 differences are possible

    for(i=0;i<maximum+1;i++)
        freq[i]=0;//initialize all elements of freq[maximum+1] array to 0 initially
//counts frequency of each element
    for(i=0;i<maximum+1;i++)
    {
     for(j=0;j<size;j++)
      {
         if(arr[j]==i)
         {
          freq[i]++;
         }
      }
    printf("\t\t\t\t\tNumber of runs which resulted in the difference of %d ::%d\n",i,freq[i]);
    }
   printf("\n\n");
}


int main()
{
    int a[100],i,j;
    int b[50][2],c[50];
    int t=time(NULL);
    srand(t);

    for(i=0;i<50;i++)//loop repeats 50 times
    {  struct node* root=NULL;
          for(j=0;j<100;j++)//loop repeats 100 times
            {
             a[j]=rand()%1000;
             root=Insert(root,a[j]);//passing arguments in Insert Function
            }
     printf("Round%d:\n",i+1);
     printf("List of Generated 100 numbers for Binary Tree %d are:\n",i+1);

          for(j=0;j<100;j++)
             printf("%d\t",a[j]);

     printf("\n\n");
     int maxlevel=0;//initialize maxlevel to 0
     int minlevel=0;//initialize minlevel to 0

     b[i][0]=LargestLevelOfLeafNode(root,maxlevel);
     b[i][1]=SmallestLevelOfLeafNode(root,minlevel);

     printf("Largest Level Of Leaf Node in binary tree %d is:%d\n",i+1,b[i][0]);
     printf("Smallest Level Of Leaf Node in binary tree %d is:%d\n",i+1,b[i][1]);
     c[i]=b[i][0]-b[i][1];
     printf("Difference between level of the leaf node with largest level and the level of leaf node with smallest level in binary tree %d is:%d\n\n",i+1,c[i]);
    }

    printf("\n\n");
    printf("Difference between level of the leaf node with largest level and the level of leaf node with smallest level in each of the 50 rounds :\n");
         for(i=0;i<50;i++)
            printf("\t\t\t\t\t\t\t\tRound %d:%d\n",i+1,c[i]);
    printf("\n\n");

    int maximum=maximum_element(c,50);//passing the  array c[50] to the function which returns the maximum value of the array c[50]

    PrintFrequency(c,50,maximum);//prints frequency of all the differences

    return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch-Phone No:7664817751
