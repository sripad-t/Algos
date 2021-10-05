#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
typedef struct node{
int data,w;
struct node *next;
}node;
node *insert(node *head,int x,int w)
{
node *n=(node *)malloc(sizeof(node));
n->data=x;
n->w=w;
n->next=NULL;
if(head==NULL)
return n;
node *temp=head;
while(head->next!=NULL)
head=head->next;
head->next=n;
return temp;
}
typedef struct hnode{
int key,v;
}hnode;
void swa(hnode heap[],int ind[],int i,int max)
{
int t,te;
t=ind[heap[i].v-1];
ind[heap[i].v-1]=ind[heap[max].v-1];
ind[heap[max].v-1] = t;
te = heap[i].key;
heap[i].key = heap[max].key;
heap[max].key = te;
te = heap[i].v;
heap[i].v = heap[max].v;
heap[max].v = te;

}
void movedown(hnode heap[],int ind[],int n,int i)
{
int max=i,l=2*i+1,r=2*i+2;
if(l<n && heap[l].key<heap[max].key)
max=l;
if(r<n && heap[r].key<heap[max].key)
max=r;
if(max!=i)
{
swa(heap,ind,i,max);
movedown(heap,ind,n,max);
}


}

void moveup(hnode heap[],int ind[],int i)
{
int p=(i-1)/2;
if(p>=0 && heap[p].key>heap[i].key)
{
swa(heap,ind,p,i);
moveup(heap,ind,p);

}


}
hnode min(hnode heap[],int ind[],int *n)
{
hnode t = heap[0];
swa(heap,ind,0,*n-1);
(*n)--;
movedown(heap,ind,*n,0);
ind[t.v-1]=-1;
return t;
}
int main()
{
int nv,ne;
cin>>nv>>ne;
node *adj[nv]={NULL};
int a,b,c,i;
for(i=0;i<ne;i++)
{
cin>>a>>b>>c;
adj[a-1] = insert(adj[a-1],b,c);
adj[b-1] = insert(adj[b-1],a,c);

}
//adj list is created
for(i=0;i<nv;i++)
{
for(node *j=adj[i];j!=NULL;j=j->next)
cout<<j->data<<","<<j->w<<" ";
cout<<endl;

}

hnode heap[nv];
int ind[nv];
for(i=0;i<nv;i++)
{
heap[i].key = 10000;
heap[i].v= i+1;
ind[i] = i;
}
heap[0].key = 0;
int n1=nv,n2=nv,co=0;
node *j=NULL;hnode u;

	for(i=0;i<n2;i++)
	{
	u = min(heap,ind,&nv);
	cout<<u.v<<","<<u.key<<"\n";

		for(j=adj[(u.v)-1];j!=NULL;j=j->next)
		{
			if(ind[j->data-1]!=-1 && u.key + j->w < heap[ind[j->data-1]].key)
			{
			heap[ind[j->data-1]].key = j->w + u.key;
			moveup(heap,ind,ind[j->data-1]);


			}

		}
	}

}
