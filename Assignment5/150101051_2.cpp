/* Submitted by
     Name:REDDI HAREESH
     Roll Number:150101051
*/
//I am starting indexes of nodes from 0 and there is always a path from a node to itself
#include<iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adjacent;
    int isReachableUtil(int visited[], int a,int b);

public:
    Graph(int V);
    void addEdge(int v, int w);
    int isReachable(int a, int b);
};

Graph::Graph(int V)
{
    this->V = V;
    adjacent = new list<int>[V];
}

void Graph::addEdge(int a, int b)
{
    adjacent[a].push_back(b); // Add b to a list.
}

int Graph::isReachableUtil(int visited[], int a,int b)
{
    if(a==b)
    {
        return 1;
    }
    visited[a] = 1;

    list<int>::iterator itr;

    for(itr = adjacent[a].begin(); itr != adjacent[a].end(); ++itr)
    {
        if (!visited[*itr] && isReachableUtil(visited,*itr,b))
            return 1;
    }

    return 0;
}
int Graph::isReachable(int a, int b)
{
    int visited[V];

    for(int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    return isReachableUtil(visited,a,b);
}
int main()
{   int n,e,i,j,u,v;
//create a graph
    cout<<"Enter number of nodes of the graph:";
    cin>>n;
    cout<<"\n";
    Graph g(n);
    cout<<"Enter number of edges of the graph:";
    cin>>e;
    cout<<"\n";
    int matrix[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            matrix[i][j]=0;
        }
    }
    if(e>0)
    {
    cout<<"Enter the Edges:\n";
    }
    for(i=0;i<e;i++)
    {
    cin>>u>>v;
    matrix[u][v]=1;
    g.addEdge(u, v);
    }
    cout<<"\n";
//Matrix representation of the graph
    cout<<"The matrix representation of the graph is:\n";
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          cout<<matrix[i][j];
          cout<<"\t";
      }
      cout<<"\n";
    }

    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
    if(g.isReachable(i,j))
        cout<< "\nThere is a path from node " << i << " to node " << j;
    else
        cout<< "\nThere is no path from node " << i << " to node " << j;
      }
      cout<<"\n";
    }
    cout<<"\n\n";
    return 0;
}
