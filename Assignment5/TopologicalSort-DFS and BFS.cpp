/*
Given a Directed and Acyclic Graph having N vertices and  M edges, print topological sorting of the vertices.
Input:
First line consists of two space separated integers denoting N and M.
Each of the following M lines consists of two space separated integers X and Y denoting there is an from X directed towards Y.
Output:
Print N space separated integers denoting the topological sort, if there are multiple ordering print the ****lexicographically smallest one.****
Constraints:
1≤N≤10
1≤M≤20
1≤X,Y≤N
*/
//HackerEarth Algorithms-Topological Sort Order Printing Solution
//           TOPOLOGICAL SORT USING DFS in lexicographic order
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
stack<int>t;//this stack is used for printing the order of topological sort
int time1=0;//time stamp which is not useful here and time is a global variable
//arrays d and f are also not useful for printing topological sort
void initialize(bool *p,int x)
{
    for(int i=0;i<x;i++)
      p[i]=false;
}
void dfsutil(vector<int>*adj,bool* visited,int x,int* d,int* f)
{
    vector<int>::iterator ii;
    visited[x]=true;
    time1=time1+1;
    d[x]=time1;
    //here sort is required for lexicographic order else not required
    sort(adj[x].begin(),adj[x].end(),greater<int>());
    for(ii=adj[x].begin();ii<adj[x].end();ii++)//for all the nodes in the adjacency list of x
    {
        if(!visited[*ii])
            dfsutil(adj,visited,*ii,d,f);
    }
    t.push(x);//push the node i.e. when the node is finished or color array becomes black
    time1=time1+1;
    f[x]=time1+1;
}
void dfs(vector<int>*adj,int p)//adj will be passed on to dfsutil function
{
    bool visited[p];//boolean visited array
    int d[p],f[p];//2 arrays
    initialize(visited,p);
    for(int i=p-1;i>0;i--)
        if(!visited[i])
            dfsutil(adj,visited,i,d,f);
}
int main()
{
    int n,m,i,x,y;
    cin>>n>>m;//n-nodes and m-edges
    vector<int>adj[n+1];
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);//directed graph
    }
    dfs(adj,n+1);
    while(!t.empty())//vector is not empty
    {
    cout<<t.top()<<" ";
    t.pop();
    }
}


/*           TOPOLOGICAL SORT USING BFS
//Use the idea of calculating indegrees of nodes of graph and
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<int>t;//queue is used for printing topological sort order
void bfs(vector<int>*adj,int* indegree,int p)//p is no of nodes+1
{
    vector<int>::iterator ii;
    for(int i=1;i<p;i++)
    {
        if(indegree[i]==0)
            t.push(i);
    }
    while(!t.empty())
    {
        int x=t.front();
        cout<<x<<" ";//printing the node
        for(ii=adj[x].begin();ii<adj[x].end();ii++)
            {
                indegree[*ii]--;
                if(indegree[*ii]==0)
                    t.push(*ii);
            }
        t.pop();
    }
}
int main()
{
    int n,m,i,x,y;
    cin>>n>>m;//n-nodes and m-edges
    vector<int>adj[n+1];
    int indegree[n+1];
    for(i=0;i<n+1;i++)
        indegree[i]=0;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);//directed graph
        indegree[y]++;

    }
    bfs(adj,indegree,n+1);
    }
}
*/
