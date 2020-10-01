#include<bits/stdc++.h>
using namespace std;
int coinchange(int *d,int n,int change)
{
	int t[change+1];
	t[0]=0;
	for(int i=1;i<=change;i++) t[i] = INT_MAX;
	for(int i=1;i<=change;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[j]<= i && t[i-d[j]] + 1 < t[i])
			t[i] = 1+t[i-d[j]];
		}
	
	}
return t[change];
}
int main()
{
	int n,i;
	cout<<"Enter total no.of coins:\n";
	cin>>n;
	int d[n],ch;
	for(i=0;i<n;i++)
	cin>>d[i];
	cout<<"Enter change amount:\n";
	cin>>ch;
	cout<<coinchange(d,n,ch);
}
