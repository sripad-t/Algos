#include<bits/stdc++.h>
using namespace std;
bool comparator(const pair<int,int> &a, const pair<int,int> &b) 
{
	return (a.second < b.second);
}
int main()
{

//single processor activity selection problem
	int n,i,maxac=1; //first is always selected
	cout<<"Enter no.of activities:\n";
	cin>>n;
	int start,fin;

	
	vector<pair<int,int>>a;
	cout<<"Enter start,finish times of items:\n";
	for(i=0;i<n;i++)
	{
		cin>>start>>fin;
		a.push_back(make_pair(start,fin));
	}
	sort(a.begin(),a.end(),comparator);
	cout<<"The selected activities are:\n";
	cout<<a[0].first<<","<<a[0].second<<endl;
	for(i=1,start=a[0].first,fin=a[0].second;i<n;i++)
	{
		if(a[i].first>fin)
		{
			fin=a[i].second;
			maxac++;
			cout<<a[i].first<<","<<a[i].second<<endl;
		}
	}
	cout<<"Max no.of activities is:\n"<<maxac;
}
