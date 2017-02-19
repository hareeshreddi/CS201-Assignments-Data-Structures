/* Submitted by
       Name::REDDI HAREESH
       Roll Number::150101051
       Question Number::2
*/
//Algorithm to find Component Graph of given directed graph

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
// A structure to represent an adjacency list node
struct AdjListNode
{
int dest;
struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList
{
struct AdjListNode *head; // pointer to head node of list
int color;
int d;
int f;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of nodes of the graph)
struct Graph
{
int V;
struct AdjList* array;
};

//A Function to create a new adjacency list node

struct AdjListNode* newAdjListNode(int dest)
{
struct AdjListNode* newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
newNode->dest = dest;
newNode->next = NULL;
return newNode;
}
//A Function that creates a graph of V nodes
struct Graph* createGraph(int V)
{
struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
graph->V = V;

graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
//Initialize each adjacency list as empty by making head as NULL
int i;
for (i = 0; i < V; ++i)
{
graph->array[i].head = NULL;
graph->array[i].color=0;
}
return graph;
}
//Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
//Add an edge from src to dest. A new node is added to the adjacency list of src,The node is added at the beginning
struct AdjListNode* newNode = newAdjListNode(dest);
newNode->next = graph->array[src].head;
graph->array[src].head = newNode;
}

//DFS function
void dfs(struct Graph *graph,int i,int *t,int *a)
{
     printf("%d",i);
     static int k=0;
     *t=*t+1;
     graph->array[i].d=*t;
     graph->array[i].color=1;
     struct AdjListNode *temp=graph->array[i].head;
     while(temp!=NULL)
       {
       if(graph->array[temp->dest].color==0)
           {

            dfs(graph,temp->dest,t,a);
            }

            temp=temp->next;
       }
       graph->array[i].color=2;
       *t=*t+1;
       a[k]=i;
       k++;
       graph->array[i].f=*t;
}

void dfs2(struct Graph *graph,int i,int **scc,int m,int *k,int nodes)
{

     *(int*)(((int*)scc+m*nodes)+(*k))=i;//*(int*)(((int*)arr+row*number of cols) + col)
     (*k)=(*k)+1;
     printf("%d",i);
     graph->array[i].color=1;
     struct AdjListNode *temp=graph->array[i].head;
     while(temp!=NULL)
       {
       if(graph->array[temp->dest].color==0)
           {

            dfs2(graph,temp->dest,(int**)scc,m,k,nodes);
            }

            temp=temp->next;
       }
       graph->array[i].color=2;
}


int main()
{
printf("Enter number of Nodes the graph::");
int v,e,i,x,y;
scanf("%d",&v);
struct Graph* graph = createGraph(v);
struct Graph* graph1 = createGraph(v);
printf("\nEnter number of Edges of the graph::");
scanf("%d",&e);
int arr1[e],arr2[e];
printf("\nEnter %d Edges between values [0 to %d] and [0 to %d]:\n",e,v-1,v-1);

for(i=0;i<e;i++)
{
  scanf("%d %d",&x,&y);
  arr1[i]=x;arr2[i]=y;
  addEdge(graph,x,y);
  addEdge(graph1,y,x);
}

int t=0,a[v],b[v];
for(i=0;i<v;i++)
{
graph->array[i].color=0;
graph1->array[i].color=0;
}
//Calling DFS
printf("\nThe DFS traversal of the graph is::");
for(i=0;i<v;i++)
{
if(graph->array[i].color==0)
   dfs(graph,i,&t,a);
}

int scc[v][v];
int j=0;
for(i=0;i<v;i++)
{
    for(j=0;j<v;j++)
        {
            scc[i][j]=INT_MIN;
        }
}
int l=1;
int m=0;
int t1=v;
int pp;
printf("\n\nThe Strongly Connected Components::\n");
while(t1>0)
{
   if(graph1->array[a[t1-1]].color==0)
   {
   pp=0;
   printf("\nStrongly Connected component %d is::",l);
   dfs2(graph1,a[t1-1],(int**)scc,m,&pp,v);
   l=l+1;
   m=m+1;
   }
   t1--;
}

int arr[l-2][l-2],p,r,q;
for(i=0;i<l-1;i++)
{
    for(j=0;j<l-1;j++)
        arr[i][j]=0;
}
for(i=0;i<l-1;i++)
{
j=0;
while(scc[i][j]!=INT_MIN)
{
     for(p=0;p<e;p++)
    {
    if(arr1[p]==scc[i][j])
        {
        for(r=0;r<v;r++)
            for(q=0;q<l-1;q++)
        if(arr2[p]==scc[q][r]&&i!=q)
                   arr[i][q]=1;
        }
    }
    j++;
}
}
printf("\n\nThe graph of SCC of G with adjacency list representation is::\n\n");
for(i=0;i<l-1;i++)
{
    printf("Adjacency list of scc[%d] is:\nscc[%d]",i,i);

    for(j=0;j<l-1;j++)
        if(arr[i][j]==1)
          printf("->scc[%d]",j);

    printf("\n");
}
printf("\n");
return 0;
}
