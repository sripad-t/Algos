#include<bits/stdc++.h>
using namespace std;

int lps(string s,int **mem,int i,int n)
{
	int l= s.length();
	if(i==n)
	{
		if(mem[i][n] !=-1)
		return mem[i][n]
	}
	if(i>=s.length() || n<0)
	return 0;
	if(s[i]==s[n])
	{
		if(mem[][]==-1)
		 mem[][] = 2 + lps(s,i+1,n-1);
		return mem[][];
	}
	else return max(lps(s,i,n-1) , lps(s,i+1,n));
}
int main()
{	//longest palindromic subsequence memoization
int i,m,n;
cout<<"Enter string : \n";
string s;
cin>>s;
int mem[s.length()][s.length()];
//cout<<strlen(s);
cout<<"lps is of length "<<lps(s,mem,0,s.length()-1)<<endl;

return 0;
}
