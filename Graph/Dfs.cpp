#include <bits/stdc++.h>

using namespace std;
int tim;
void dfs(vector<int> *adj,int nv,int tim,int *visited,int *parent,int *disc,int *finish,int i){
  tim++;
  disc[i]=tim;
  visited[i]=1;
  cout<<i+1<<" ";
  for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++)
  {
    if(visited[*j-1]==0)
    {
        parent[*j-1]=i+1;
        dfs(adj,nv,tim,visited,parent,disc,finish,*j-1);
    }
  }
  tim++;
  finish[i]=tim;
}
int main()
{
    int ne,i,nv,u,a,b;
    cin>>nv>>ne;
    vector<int> adj[nv];
    for(i=0;i<ne;i++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b);
        adj[b-1].push_back(a);
        
    }
    for(i=0;i<nv;i++)
    {
        for(auto j=adj[i].begin();j!=adj[i].end();j++)
        cout<<*j<<" ";
        cout<<"\n";
    }tim=0;
   int visited[nv]={0},parent[nv]={-1},disc[nv]={0},finish[nv]={0};
    for(i=0;i<nv;i++)
    {
        if(visited[i]==0)
        dfs(adj,nv,tim,visited,parent,disc,finish,i);
    }
    
//    dfs(adj,tim,visited,parent,disc,finish);


    return 0;
}
