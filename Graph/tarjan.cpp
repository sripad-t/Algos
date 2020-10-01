#include <bits/stdc++.h>

using namespace std;
int tim;
void printcycle(int c,int p,int *parent)
{
if(c==parent[p-1])
{
cout<<"cycle is"<<c<<" ";
cout<<p<<" ";
return ;
}
else {
printcycle(c,parent[p-1],parent);
cout<<p<<" ";
}
}
void dfs(vector<int> *adj,int nv,int *visited,int *parent,int *disc,int *finish,int *low,int i){
  tim++;
  static int c=0;
  disc[i]=tim;
  low[i]=tim;
  visited[i]=1;
  cout<<i+1<<" ";
  for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++)
  {
      if(visited[*j-1]==0)
      {
          parent[*j-1]=i+1;
          dfs(adj,nv,visited,parent,disc,finish,low,*j-1);
          
      }
      if(visited[*j-1]==1 && parent[i]==*j)
      {
     	low[i] = low[i]<low[*j-1] ? low[i] : low[*j-1];
          if(disc[i]<=low[*j-1])
          	cout<<"\n"<<i+1<<"is a cut vertex\n";
          if(disc[i]<low[*j-1])
          {
          	cout<<"\n"<<i+1<<" "<<*j<<" is a cut edge\n";
          }
      }
      if(visited[*j-1]==1 && parent[i]!=*j){
          low[i] = low[i]<disc[*j-1] ? low[i] : disc[*j-1];
     
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
    }cout<<"\n Adjacency List is \n";
    for(i=0;i<nv;i++)
    {
        for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++)
        cout<<*j<<" ";
        cout<<"\n";
    }tim=0;cout<<"DFS is:\n";
   int visited[nv]={0},parent[nv]={-1},disc[nv]={0},finish[nv]={0},low[nv]={-1};
    for(i=0;i<nv;i++)
    {
        if(visited[i]==0)
        dfs(adj,nv,visited,parent,disc,finish,low,i);
    }

 
 
 
 
    return 0;
}
