/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question3:Write an algorithm to find LCA of given two nodes of a binary tree
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* GetNewNode(int data)//Function to create and allocate memory for new node
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

// Though I am taking input tree as binary search tree as mentioned in the question,the  findLCA function works for any binary tree
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

// Function to find LCA in a binary tree
// This function returns pointer to LCA of two given values v and w assuming that v and w are present in Binary Tree

// Time Complexity of this algorithm is O(n) as this method is a simple tree traversal where n is number of nodes in the tree

struct node *findLCA(struct node* root, int v, int w)//call v and w as keys
{
// Base case
    if (root== NULL)//this comparison takes some constant time for 1 iteration
        return NULL;

// If either v or w matches with root's data, then return the root as root becomes LCA

    if (root->data== v || root->data== w)//this comparison also takes some constant time for 1 iteration
        return root;

// Look for keys in left and right subtrees
// The following 2 lines does not take constant time
    struct node *LeftLCA  = findLCA(root->left,v,w);
    struct node *RightLCA = findLCA(root->right,v,w);

//If both of the above calls return Non-NULL, then one key is present in one subtree and other is present in other,so this node is the LCA
    if (LeftLCA && RightLCA)//this comparison takes some constant time for 1 iteration
        return root;

// Otherwise check if left subtree or right subtree is LCA//this comparison also takes some constant time for 1 iteration
    return (LeftLCA!= NULL)? LeftLCA: RightLCA;
}

int main()
{
    int a[100],i,j;
    int v,w;
    int t=time(NULL);
    srand(t);
    for(i=0;i<50;i++)//loop repeats 50 times
    {
     clock_t begin=clock();
     struct node* root=NULL;

          for(j=0;j<100;j++)//loop repeats 100 times
            {
             a[j]=rand()%1000;
             root=Insert(root,a[j]);
            }

     printf("Round%d:\n",i+1);
     printf("List of Generated 100 numbers for Binary Tree %d:\n\n",i+1);
          for(j=0;j<100;j++)
             printf("%d\t",a[j]);

     printf("\n\n");
     printf("Enter 2 nodes v and w whose values are present in the Binary Tree %d :\t",i+1);
     scanf("%d%d",&v,&w);
     printf("\nLeast Common Ancestor of nodes %d and %d in Binary Tree %d is: %d\n\n",v,w,i+1,findLCA(root,v,w)->data);//calling findLCA function
     clock_t end=clock();
     double l=(double)(end-begin)/CLOCKS_PER_SEC;
     printf("%lf seconds is the running time of Round %d \n\n",l,i+1);
    }
     return 0;
}
//Time complexities of any simple tree traversal is O(n)
/*
Time Complexity of this algorithm is O(n) as this method is a simple tree traversal where n is number of nodes in the tree
Complexity function T(n)-for this problem can be written as:

            T(n) = T(k) + T(n-k-1) + c
where k is the number of nodes on one side of root and n-k-1 on the other side.
Assume value of running time of the  of all the constant time taking comparisons be some c in 1 iteration of findLCA function

[Boundary case analysis]:
Case 1: One of the subtrees is empty and other subtree is non-empty for each node

              k is 0 in this case.
              T(n) = T(0) + T(n-1) + c
              T(n) = 2T(0) + T(n-2) + 2c
              T(n) = 3T(0) + T(n-3) + 3c
              T(n) = 4T(0) + T(n-4) + 4c
              ............................

              T(n) = (n-1)T(0) + T(1) + (n-1)c
              T(n) = nT(0) + (n)c

Let the value of T(0) will be some constant say d.

              T(n) = n*(c+d)
       Hence  T(n) = O(n)


Case 2: Both left and right subtrees have equal number of nodes.

             We can write T(n) = 2T(n/2) + c

             T(n/2)=2T(n/4)+c     T(n)=4T(n/4)+3c
             T(n/4)=2T(n/8)+c     T(n)=8T(n/4)+7c
             T(n/8)=2T(n/16)+c    T(n)=16T(n/8)+15c
             T(n/16)=2T(n/8)+c    T(n)=32T(n/16)+31c

             .....................................
                       T(n)=2^k*T(n/(2^k))+(2^k-1) where k is a natural number

When (2^k)=n then k=log(n)[base 2]
                   then T(n)=nT(1)+(n-1)*c

Let the value of T(0) will be some constant say d.
          Then T(n)=(d)*n+(n-1)*c
                  =(c+d)*n-c=O(n)
          Hence T(n)=O(n)
Finally,
We can say findLCA function passes through each node some constant times,as there are n nodes,the running time will be O(n)
*/
//Submitted by REDDI HAREESH-150101051-CSE Branch-Phone No:7664817751
