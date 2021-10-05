#include <bits/stdc++.h>

using namespace std;
typedef struct edges{
int s,d,w;

}edges;
int main()
{
int i,nv,ne,a,c,b;
cin>>nv>>ne;
edges edge[ne];
for(i=0;i<ne;i++)
{
cin>>a>>b>>c;
edge[i].s=a;
edge[i].d=b;
edge[i].w=c;
}
int d[nv],p[nv];
for(i=0;i<nv;i++)
{
d[i]=10000;
p[i]=-1;
}
d[0]=0;p[0]=-1;
for(i=0;i<nv-1;i++)
{
for(int j=0;j<ne;j++)
{
	if(d[edge[j].d-1]>d[edge[j].s-1]+ edge[j].w) 
	{
		d[edge[j].d-1]=d[edge[j].s-1]+ edge[j].w;
		p[edge[j].d-1]=edge[j].s-1;
	}
}


}
for(i=0;i<nv;i++)
{
cout<<" "<<i+1<<" "<<d[i]<<endl;


}

}
