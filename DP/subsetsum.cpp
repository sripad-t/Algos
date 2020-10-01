#include<bits/stdc++.h>
using namespace std;
void subsetsum(int a[],int n,int s)
{
    int i,j,tab[n+1][s+1];
    for(i=0;i<=s;i++) tab[0][i] =0;
    for(i=0;i<=n;i++) tab[i][0] =1;
    for(i=1;i<n+1;i++)
    {
        for(j=1;j<s+1;j++)
        {
            if(a[i-1]>j)
            tab[i][j] = tab[i-1][j];
            else{
                tab[i][j] = tab[i-1][j] || tab[i-1][j-a[i-1]];
            }
        }
    }
    cout<<tab[n][s];
}
int main()
{
    int n,i;
    cout<<"Enter size:";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s;
    cout<<"Enter sum";
    cin>>s;
    subsetsum(a,n,s);
    return 0;
}