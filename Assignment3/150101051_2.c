/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question2:Write a program that counts the number of leaves of a binary tree
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node//struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* GetNewNode(int data)//Function to allocate memory for new node
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));//using malloc
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

//Though I am taking input tree as binary search tree as mentioned in the question,the  CountLeaves function works for any binary tree
struct node* Insert(struct node* root,int data)//Function to insert node in binary search tree
{
    if(root==NULL)
        root=GetNewNode(data);

    else if(data<=root->data)//if the number to be inserted is less than or equal to root->data
         root->left=Insert(root->left,data);

    else//if the number to be inserted is greater than root->data
         root->right=Insert(root->right,data);

    return root;
}

//Function to count number of leaves of a Binary Tree
int CountLeaves(struct node* root)
{
    if(root==NULL)//Base case i.e. if the root node is null
        return 0;

    else if(root->right==NULL&&root->left==NULL)//if there are no subtrees for the root node,then return 1
        return 1;

    else
        return CountLeaves(root->right)+CountLeaves(root->left);//return number of leaves of (left subtree+right subtree)
}

int main()
{
    int a[100];
    int Leaves[50],i,j;
    int t=time(NULL);
    srand(t);
    for(i=0;i<50;i++)//loop repeats 50 times
    {  struct node* root=NULL;//initially empty binary tree
          for(j=0;j<100;j++)//loop repeats 100 times
            {
             a[j]=rand()%1000;
             root=Insert(root,a[j]);
            }

     printf("Round%d:\n",i+1);
     printf("List of Generated 100 numbers for Binary Tree %d are:\n",i+1);
          for(j=0;j<100;j++)
           printf("%d\t",a[j]);
     printf("\n\n");

     Leaves[i]=CountLeaves(root);
     printf("Number of Leafs in Binary Tree %d are:%d\n\n\n",i+1,Leaves[i]);
    }
    return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch-Phone No:7664817751
