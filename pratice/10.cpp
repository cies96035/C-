#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int maxN=100010;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
map<int,vpii> link;
int price[maxN],fi,Max;
/*
1 3
1 2 1
2 3 2
QUERY 1 3
CHANGE 1 4
QUERY 1 3
*/
void dfs(int cur,int fa)
{
	//cout<<cur<<' ';
	for(int i=0;i<link[cur].size();i++)
	{
		//cout<<link[cur][i].first<<endl;
		dfs(link[cur][i].first,cur);
		if(fi==link[cur][i].first)
		{
			Max=max(Max,price[link[cur][i].second]);
			fi=cur;
			return;
		}
	}
	return;
}

void Q(int a,int b)
{
	Max=-2e9;
	fi=b;
	dfs(a,a);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a,b,c;
		for(int i=1;i<n;i++)
		{
			cin>>a>>b>>c;
			link[a].push_back(pii(b,i));//a連到b，是第i條
			price[i]=c;//第i條的權重為c 
		}
		/*
		for(int i=1;i<4;i++)
		{
			cout<<i<<endl;
			for(int j=0;j<link[i].size();j++)
				cout<<link[i][j].first<<' ';
				cout<<endl;
		}*/
		string S;
		while(cin>>S)
		{
			if(S[0]=='Q')
			{
				cin>>a>>b;
				Q(a,b);
				cout<<Max<<'\n';
			}
			else if(S[0]=='C')
			{
				cin>>a>>b;
				price[a]=b;
			}
			else
				break;
		}
	}
	return 0;
}

