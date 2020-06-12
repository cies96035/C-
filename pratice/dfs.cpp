#include<iostream>
#include<vector> 
using namespace std;
vector<int> a[1000];

void dfs(int cur,int fa)
{
	int n=a[cur].size();
	for(int i=0;i<n;i++)
	{
		if(a[cur][i]!=fa)
		{
			dfs(a[cur][i],cur);
		}
	}
	return;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int u,w;
		cin>>u>>w;
		a[u].push_back(w);
		a[w].push_back(u);
	}
	dfs(0,-1);
	return 0;
}

