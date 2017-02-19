/* Submitted by
       Name::REDDI HAREESH
       Roll Number::150101051
       Question Number::3
*/
//Prim’s Minimum Spanning Tree(MST) algorithm
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

//A Function to find the node with minimum key value, from the set of nodes which are not yet included in MST
int FindminKey(int *key, int *SetMST, int n)
{
    int v;
//Initialize min value
    int min = INT_MAX;
    int  min_index;

    for ( v = 0; v < n; v++)
       if (SetMST[v] == 0 && key[v] < min)
         { min = key[v];
          min_index = v;
         }
    return min_index;
}


//A function to print the constructed MST stored in parent[]
int printMST(int parent[], int *graph[], int n)
{
    int i;
    printf("\n\nThe final Minimum Spanning Tree(MST) of the given graph is::\n\n");
    printf("Edge      Weight\n");

//*(int*)(( (int*)arr+ row*number of cols) + col) is the syntax for finding arr[row][col]
    for ( i = 1; i < n; i++)
       printf("%d - %d       %d \n", parent[i], i, *(int*)(((int*)graph+ i*n)+parent[i]));
}


//Function to construct and print MST for a graph represented using adjacency
void FindMST(int *graph[],int n)
{
     int i,count,v;
     int parent[n];//Array to store constructed MST
     int SetMST[n];//Represents set of nodes which are not yet included in MST
     int key[n];//Key values used to pick minimum weight edge in cut

//SetMST[i]=0 represents node i is not yet not included and SetMST[i]=1 represents node i is included in the SetMST

//Initialize all keys as INFINITE
     for ( i = 0; i < n; i++)
        {
        key[i] = INT_MAX;
        SetMST[i] = 0;
        }
     key[0] = 0;
     parent[0] = -1;
//The MST will have n-1 edges
     for ( count = 0; count < n-1; count++)
     {
//Pick the minimum key node from the set of nodes which are not yet included in MST
        int u = FindminKey(key, SetMST,n);
//Add the picked node to the MST Set
        SetMST[u] = 1;
//Update the key value and parent index of the adjacent nodes of the picked node
//Consider only those nodes which are not yet included in MST
        for ( v = 0; v < n; v++)
        {

          if(*(int*)(((int*)graph+(u)*n)+ v) && SetMST[v] == 0&& *(int*)(((int*)graph+(u)*n)+ v) <key[v])
              {
                parent[v]  = u;
                key[v] = *(int*)(((int*)graph+(u)*n)+ v);
              }
        }
     }
//Print the constructed MST
     printMST(parent,graph,n);
}


int main()
{
    int n,e,i,j,k;
    printf("Please enter proper Undirected, Connected Graph as input for finding MST of the graph::");
    printf("\n\nEnter number of nodes of the Graph::");
    scanf("%d",&n);
    int graph[n][n];
    printf("\nEnter number of edges of the Graph::");
    scanf("%d",&e);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }

    int x,y,w;
    if(n>0)
    {
        for(k=0;k<e;k++)
        {
         printf("\nEnter the %d edge of the graph between values [0,%d] and [0,%d]::",k+1,n-1,n-1);
         scanf("%d %d", &x, &y);
         printf("\nEnter the weight of the corresponding edge::");
         scanf("%d",&w);
//As the graph is undirected there will be edge from both x to y and y to x
         graph[x][y]=w;
         graph[y][x]=w;
         }
    }

    if(e>0 && n>0)
    {
//Function to construct and print MST for a graph
    FindMST((int**)graph,n);
    }
    else
          printf("\nInput the graph correctly");

    printf("\n");
    return 0;
}
