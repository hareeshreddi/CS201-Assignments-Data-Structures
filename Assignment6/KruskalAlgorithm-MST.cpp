/* HackerEarth Kruskal Algorithm Solution
*/
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;//do not use variable names as union or rank as they are inbuilt-functions
int n,m;
int rank1[10001];//rank array
void initialize(int parent[])//disjoint sets initialization of parent array
{
    for(int i=0;i<n+1;i++)
    {
        parent[i]=i;
        rank1[i]=0;
    }
}
void union1(int parent[],int x,int y)//using union by rank heuristic
{
    if(rank1[x]>rank1[y])
        parent[y]=x;
    else
        parent[x]=y;
    if(rank1[x]==rank1[y])
        rank1[y]=rank1[y]+1;
}
int root(int parent[],int x)//root function is find_set function
{
    if(x!=parent[x])
    {
        parent[x]=root(parent,parent[x]);//using path compression heuristic
    }
    return parent[x];
}
int Kruskal(pair<int,pair<int,int> >p[],int* parent)
{
    int w,x,y,i,minCost=0;
    for(i=0;i<m;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        w=p[i].first;
        int ii=root(parent,x);
        int jj=root(parent,y);
        if(ii!=jj)
            {
                union1(parent,ii,jj);
                minCost+=w;
            }
    }
    return minCost;
}
int main()
{
    int i,x,y,w,minCost;
    cin>>n>>m;
    int parent[n+1];
    pair<int,pair<int, int> >p[m];//utility library
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        p[i]=make_pair(w,make_pair(x,y));
    }
     initialize(parent);
     sort(p,p+m);//algorithm library
     minCost=Kruskal(p,parent);
     cout<<minCost;
}
