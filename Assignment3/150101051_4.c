/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question4:Write an algorithm find diameter of a tree
*/
//I am taking diameter as  the number of edges on the longest path between two leaves in the tree
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
};

//Though I am taking input tree as binary search tree as mentioned in the question,the diameter function works for any binary tree
struct node* Insert(struct node* root,int data)//Function to insert node in binary search tree
{
    if(root==NULL)
         root=GetNewNode(data);//using GetNewNode function

    else if(data<=root->data)//if the number to be inserted is less than or equal to root->data
         root->left=Insert(root->left,data);

    else//if the number to be inserted is greater than root->data
         root->right=Insert(root->right,data);

    return root;//returns root which is of type struct node*
};

int max(int x, int y)//This function returns maximum of x and y
{
    return (x>y)? x : y;
}

//Algorithm to find diameter of tree
//Time Complexity of this algorithm is O(n) as this method is a simple tree traversal where n is number of nodes in the tree

int diameter(struct node *root, int* height)
{
//left_h--Height of left subtree right_h--Height of right subtree
    int left_h = 0,right_h = 0;//this initialization takes some constant time

//ldiameter--diameter of left subtree rdiameter--Diameter of right subtree

    int ldiameter = 0, rdiameter = 0;//this initialization also takes some constant time for one iteration

//Base case
    if(root == NULL)//this comparison also takes some constant time for one iteration
    {
      *height = 0;
       return 0;
    }

//Get the heights of left and right subtrees in left_h and right_h and store the returned values in ldiameter and ldiameter
//The following 2 lines does not take constant time which increases the running time
    ldiameter = diameter(root->left, &left_h);
    rdiameter = diameter(root->right, &right_h);

//Height of current node is max of heights of left and right subtrees plus 1
   *height = max(left_h, right_h) + 1;//this  also takes some constant time for one iteration

    return max(left_h + right_h + 1, max(ldiameter, rdiameter));
}

int main()
{
    clock_t begin=clock();
    int a[100],j;
    int d,h;
    int t=time(NULL);
    srand(t);
    struct node* root=NULL;

    for(j=0;j<100;j++)//loop repeats 100 times
        {
            a[j]=rand()%1000;
            root=Insert(root,a[j]);//using Insert function
        }

    printf("List of Generated 100 numbers for Binary Tree :\n");
       for(j=0;j<100;j++)
          printf("%d\t",a[j]);

    printf("\n");
    d=diameter(root,&h);//here d is  the number of nodes on the longest path between two leaves in the tree
    printf("\n");
    printf("The Diameter of binary tree is:%d\n\n",d-1);//no of edges in longest path between two leaves in the tree b/n 2 nodes =d-1;

    clock_t end=clock();
    double l=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("%lf seconds is the running time of the program\n",l);
    return 0;
}
/*
Time Complexity of this algorithm is O(n) as this method is a simple tree traversal where n is number of nodes in the tree
Complexity function T(n)-for this problem can be written as:

            T(n) = T(k) + T(n-k-1) + c
where k is the number of nodes on one side of root and n-k-1 on the other side.
Assume value of running time of the  of all the constant time taking comparisons and the initializations  in 1 iteration be some c of the diameter function

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
                       T(n)=2^k*T(n/(2^k))+(2^k-1)c where k is a natural number
When (2^k)=n then k=log(n)[base 2]
                   then T(n)=nT(1)+(n-1)*c
Let the value of T(0) will be some constant say d.
         Then T(n)=(d)*n+(n-1)*c
                  =(c+d)*n-c=O(n)
          Hence T(n)=O(n)
Finally,
We can say diameter function passes through each node some constant times,as there are n nodes,the running time will be O(n)

*/
//Submitted by REDDI HAREESH-150101051-CSE Branch-Phone No:7664817751
