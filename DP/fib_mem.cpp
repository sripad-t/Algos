#include<bits/stdc++.h>
using namespace std;
int n;
int *mem;
int fib(int n)
{
	if(mem[n]!=-1)
	return mem[n];
	if(n==0 || n==1)
	return n;
	mem[n] = fib(n-1)+fib(n-2);
	return mem[n];
}
int main()
{
int i;
cin>>n;
//fibonacci memoisation
mem = new int[n+1];
for(i=0;i<=n;i++)
mem[i]=-1;
cout<<"fib(n) is "<<fib(n)<<endl;

return 0;
}
