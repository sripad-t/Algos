#include<bits/stdc++.h>
using namespace std;
void printlis(int p[],int a[],int max){

	if(p[max]!=max) printlis(p,a,p[max]);
	cout<<a[max]<<" ";
}
void lis(int *a,int n){
	int i=0,max=0;
	int p[n],l[n];
	for(i=0;i<n;i++)
	{	
		p[i]=i;
		l[i]=1;
	}	
	for(i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<a[i] && l[j]+1>l[i])
			l[i]=l[j]+1,p[i]=j;
			if(l[max]<l[i])
			max=i;
		}
	}

	cout<<"LIS is of size "<<l[max]<<"\n";
	cout<<"LIS is ";
	printlis(p,a,max);
}
int main()
{
int n,i;
cout<<"Enter size of array:\n";
cin>>n;
int a[n];
cout<<"Enter elemesnts:\n";
for(i=0;i<n;i++)
cin>>a[i];

lis(a,n);
}
