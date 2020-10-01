#include<bits/stdc++.h>
using namespace std;
bool comparator(const pair<int,int> &a, const pair<int,int> &b) 
{
	double x,y;
	x=a.second/a.first;
	y=b.second/b.first;
	return (x>y);
	return (a.second >= b.second);
}
int main()
{

//given job's deadline and profits maximise profits(uniprocessor)
	int n,i,loss=0;
	cout<<"Enter no.of jobs\n";
	cin>>n;
	int exec,l,time;
	vector<pair<int,int>>a;
	cout<<"Enter deadlines,profits of items:\n";
	for(i=0;i<n;i++)
	{
		cin>>exec>>l;
		a.push_back(make_pair(exec,l));
	}
	sort(a.begin(),a.end(),comparator);
	
	for(i=1,time=a[0].first;i<n;i++)
	{
		loss+=(time*a[i].second);
		time+=(a[i].first);	
	}
	cout<<"Min loss is:\n"<<loss;
}
