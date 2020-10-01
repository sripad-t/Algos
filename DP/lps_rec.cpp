#include<bits/stdc++.h>
using namespace std;
int **tab;
int lps(string s,int i,int n)
{
	int l= s.length();
	if(i==n)
	return 1;
	if(i>=s.length() || n<0)
	return 0;
	if(s[i]==s[n])
	return 2 + lps(s,i+1,n-1);
	else return max(lps(s,i,n-1) , lps(s,i+1,n));
}
int main()
{	//longest palindromic subsequence reccursion
int i,m,n;
cout<<"Enter string : \n";
string s;
cin>>s;

//cout<<strlen(s);
cout<<"lps is of length "<<lps(s,0,s.length()-1)<<endl;

return 0;
}
