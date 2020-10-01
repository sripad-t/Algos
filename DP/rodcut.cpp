#include<bits/stdc++.h>
using namespace std;
void maxcut(int a[],int n)
{
    int i,t[n+1]={0};
    for(i=1;i<=n;i++)
    {
        t[i] = a[i-1] + t[0]; 
        for(int j=i-2;j>=i/2;j--)
        {
            t[i] = max(t[i],t[j]+t[i-j]);
        }
    
    }
    cout<<"Max profit is "<<t[n]<<endl;
    
}
int main()
{
    int n,i;
    cout<<"Enter length :";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    maxcut(a,n);
    return 0;
}