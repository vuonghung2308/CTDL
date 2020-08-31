#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++)
	{
	   cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>=a[i+1])
		{
			cout<<0<<endl;
			return;
		}
	}
	cout<<1<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
