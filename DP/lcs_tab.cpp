#include<bits/stdc++.h>
using namespace std;

int lcs(string x,string y)
{
	int i,j,m=0,n=0;
	while(x[m]) m++;
	while(y[n]) n++;
	int tab[m+1][n+1];
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			tab[i][j]=0;
			else if(x[i-1]==y[j-1])
			tab[i][j] = 1+tab[i-1][j-1];
			else if(tab[i][j-1] >tab[i-1][j])
			tab[i][j] = tab[i][j-1];
			else tab[i][j] = tab[i-1][j];
		}
	}
	return tab[m][n];
}
int main()
{
	string x,y;
	cout<<"Enter strings \n";
	cin>>x>>y;
	cout<<"length of lcs is "<<lcs(x,y);

return 0;
}