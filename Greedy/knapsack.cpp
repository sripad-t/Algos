#include<bits/stdc++.h>
using namespace std;
bool comparator(const pair<int,int> &a, const pair<int,int> &b) 
{
	double x,y;
	x=a.first/a.second;
	y=b.first/b.second;
	return (x>y);
}
int main()
{

//only for fractional knapsack
	int n,i;
	cout<<"Enter no.of items:\n";
	cin>>n;
	int p,v;
	
	int pro=0,maxvol,vol[n];
	cout<<"Enter max vol:\n";
	cin>>maxvol;
	vector<pair<int,int>>s;
	cout<<"Enter price , vol of items:\n";
	for(i=0;i<n;i++)
	{
		cin>>p>>v;
		s.push_back(make_pair(p,v));
	}
	sort(s.begin(),s.end(),comparator);
	for(i=0;i<n && maxvol>0;i++)
	{
		if(s[i].second<=maxvol)
		{
			pro+=(s[i].first);
			maxvol-=(s[i].second);
		}
		else{
		pro+=(maxvol*s[i].first/s[i].second);
		maxvol=0;
		}
	}
	cout<<"Total profit is:\n"<<pro;
}
