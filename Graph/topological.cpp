#include <bits/stdc++.h>

using namespace std;
int tim;

void dfs(vector<int> *adj,int nv,int *visited,int *parent,int *disc,int *finish,vector<int> *top,int i){
  tim++;
  disc[i]=tim;
  visited[i]=1;
  cout<<i+1<<" ";
  for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++)
  {
      if(visited[*j-1]==0)
      {
          parent[*j-1]=i+1;
          dfs(adj,nv,visited,parent,disc,finish,top,*j-1);
      }
     
  }
  tim++;
  finish[i]=tim;
  (*top).push_back(i+1);
}
int main()
{
    int ne,i,nv,u,a,b;
    cin>>nv>>ne;
    vector<int> adj[nv],trans[nv];
    vector<int>top,t;
    for(i=0;i<ne;i++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b);
        trans[b-1].push_back(a);    
    }
    for(i=0;i<nv;i++)
    {
        for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++)
        cout<<*j<<" ";
        cout<<"\n";
    }tim=0;
   int visited[nv]={0},parent[nv]={-1},disc[nv]={0},finish[nv]={0};
    for(i=0;i<nv;i++)
    {
        if(visited[i]==0)
        dfs(adj,nv,visited,parent,disc,finish,&top,i);
    }
    cout<<"Topological sorted list:\n";
    for(vector<int>::reverse_iterator j=top.rbegin();j!=top.rend();j++)
    cout<<*j<<" ";
     int vis2[nv]={0},count=0;
     cout<<"\n";
for(vector<int>::reverse_iterator j=top.rbegin();j!=top.rend();j++)
 {
 if(vis2[*j-1]==0)
 { dfs(trans,nv,vis2,parent,disc,finish,&t,*j-1);
 cout<<"\n";
count++;
 }

 
 }
 cout<<"Total comps are "<<count<<endl;
 
 
    return 0;
}
