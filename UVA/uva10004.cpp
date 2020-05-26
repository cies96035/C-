#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

#define maxN 250
bool link[maxN][maxN];
int color[maxN];
int n,l,a,b;

bool bicolorable(int s)
{
	color[s]=0;
	stack<int> start;
	start.push(s);
	while(!start.empty())
	{
		int t=start.top(),c=color[t];
		start.pop();
		for(int i=0;i<n;i++)
			if(link[t][i])
			{
				if(color[i]==-1)
				{
					color[i]=(!c);
					start.push(i);
				}
				else if(color[i]==c)
					return false;
			}
	}
	return true;
	
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>n&&n)
	{
		cin>>l;
		memset(link,0,sizeof(link));
		memset(color,-1,sizeof(color[0])*n);
		while(l--)
		{
			cin>>a>>b;
			link[a][b]=link[b][a]=1;
		}
		if(bicolorable(a))
			cout<<"BICOLORABLE.\n";
		else
			cout<<"NOT BICOLORABLE.\n";
	}
	return 0;
}

