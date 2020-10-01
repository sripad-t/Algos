#include<bits/stdc++.h>
using namespace std;
int main()
{

//only for coins like 1,2,5,10;
	int n,i,d,ch;
	cout<<"Enter no.of denomination coins:\n";
	cin>>d;
	int a[d],c[d];
	cout<<"Enter the denomination like 1,2,5,..:\n";
	for(i=0;i<d;i++)
	cin>>a[i];
	cout<<"Enter the amount :\n";
	cin>>n;
	for(i=d-1;i>-1;i--)
	{
		c[i]=(n/a[i]);
		n-=(c[i]*a[i]);
	}
	cout<<"No.of coins req are:\n";
	for(i=0;i<d;i++)
	cout<<c[i]<<" ";

}
