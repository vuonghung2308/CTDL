#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin>>n;
	int a[n+5];
	for(int i=0;i<n;i++)
	   cin>>a[i];
	sort(a,a+n);
	int m=(n-1)/2;
	cout<<a[m]<<endl;
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
