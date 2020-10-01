#include<bits/stdc++.h>
using namespace std;
int n;
int *tab;
int fib(int n)
{
	int i;
	tab[0]=0;tab[1]=1;
	for(i=2;i<=n;i++)
	tab[i] = tab[i-1] + tab[i-2];
return tab[n];
}
int main()
{
int i;
cin>>n;
//fibonacci tabulation
tab = new int[n+1];

cout<<"fib(n) is "<<fib(n)<<endl;

return 0;
}
