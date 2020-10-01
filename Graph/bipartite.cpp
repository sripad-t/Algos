#include <bits/stdc++.h>

using namespace std;
void printpath(int *parent,int ver,int s,int nv){
    if(s==ver)
    cout<<s<<" ";
    else if(parent[ver-1]==-1)
    cout<<"No path exists ";
    else {printpath(parent,parent[ver-1],s,nv);
    cout<<ver<<" ";}
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
    }
    int s;
    cout<<"Enter source\n";
    cin>>s;
    queue<int>q;
    q.push(s);
    int parent[nv],f=0,dist[nv],color[nv]={-1};
    bool visited[nv];
    for(i=0;i<nv;i++)
    {
        parent[i]=-1;
        dist[i]=INT_MAX;
        visited[i]=0;
    }
    parent[s-1]=-1;
    visited[s-1]=1;
    dist[s-1]=0;
    color[s-1]=1;
    while(!q.empty())
    {
        u=q.front();
        cout<<u<<" ";
        q.pop();
        for(auto j=adj[u-1].begin();j!=adj[u-1].end();j++)
        {
            if(visited[*j-1]==0)
            {
                visited[*j-1]=1;
                color[*j-1]=(color[u-1]==1?2:1);
                q.push(*j);
            }
            else if(color[*j-1]==color[u-1])
            {
                f=1;
                break;
            }
        }
        
       // visited[u-1]=1;
    }
  if(f==0) cout<<"It is bipartite ";
  else  cout<<"It is not bipartite ";
    return 0;
}
