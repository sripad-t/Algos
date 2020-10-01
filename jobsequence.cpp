#include<bits/stdc++.h>
using namespace std;
bool comparator(const pair<int,int> &a, const pair<int,int> &b) 
{
	return (a.second >= b.second);
}
int main()
{

//given job's deadline and profits maximise profits(uniprocessor)
	int n,i,pro=0;
	cout<<"Enter no.of jobs\n";
	cin>>n;
	int dl,p,x;	
	vector<pair<int,int>>a;
	cout<<"Enter deadlines,profits of items:\n";
	for(i=0;i<n;i++)
	{
		cin>>dl>>p;
		a.push_back(make_pair(dl,p));
	}
	sort(a.begin(),a.end(),comparator);
	int maxfintime=a[0].first;
	for(i=0;i<n;i++)
	{
		if(a[i].first>maxfintime)
		maxfintime=a[i].first;
	}
	int flags[maxfintime]={0};
	for(i=0;i<n;i++)
	{
		if(flags[a[i].first-1]==0)
		{
		pro+=(a[i].second);
		flags[a[i].first-1]=1;
		}
		else{x=a[i].first-2;
		while(x>=0 && flags[x]!=0)
		x--;
		if(x>-1) flags[x]=1,pro+=a[i].second;
		}
	}
	cout<<"Max profit is:\n"<<pro;
}
