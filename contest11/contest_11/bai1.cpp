#include<bits/stdc++.h>
using namespace std;
struct node{
	char data;
	node *left,*right;
};
node* newNode(char c)
{
	node *tmp=new node;
	tmp->left=tmp->right=NULL;
	tmp->data=c;
	return tmp;
}
bool isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
	   return true;
	return false;
}
node* Tree(string s)
{
	node *t,*tmp1,*tmp2;
	stack<node *> st;
	for(int i=0;i<s.length();i++)
	{
		if(!isOperator(s[i]))
		{
			t=newNode(s[i]);
			st.push(t);
		}
		else
		{
			t=newNode(s[i]);
			tmp1=st.top(); st.pop();
			tmp2=st.top(); st.pop();
			t->left=tmp2;
			t->right=tmp1;
			st.push(t);
		}
	}
	t=st.top(); st.pop();
	return t;
}
void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
	int t;
	cin>>t;
	string s;
	//cin.ignore();
	while(t--)
	{
		cin>>s;
		node *x=Tree(s);
		inorder(x);
		cout<<endl;
	}
	return 0;
}
		
