#include<bits/stdc++.h>
using namespace std;
int pre_id=0;
void postorder(int inorder[],int preorder[],int st,int en,map<int,int> m)
{
	if(st>en)
	   return;
	int id=m[preorder[pre_id++]];
	postorder(inorder,preorder,st,id-1,m);
	postorder(inorder,preorder,id+1,en,m);
	cout<<inorder[id]<<" ";
}
void solve()
{
	pre_id=0;
	int n;
	cin>>n;
	map<int,int> m;
	int inorder[n+5],preorder[n+5];
	for(int i=0;i<n;i++)
	{
	   cin>>inorder[i];
	   m[inorder[i]]=i;
	}
	for(int i=0;i<n;i++)
	   cin>>preorder[i];
	postorder(inorder,preorder,0,n-1,m);
	cout<<endl;
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
