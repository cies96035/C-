#include<iostream>
#include<vector> 
using namespace std;

const int maxN=45100,maxangry=2000100;
int N,M,Q;
int a,b,c;
int num[maxangry];
struct R
{
	int v,w;
	R()
	{v=0,w=0;}
};
vector<R> road[maxN];
/*

*/
int main()
{
	cin>>N>>M>>Q;
	for(int i=0;i<M;i++)
	{
		cin>>a>>b>>c;
		if(road[a].empty()&&road[b].empty())
		{
			road[a].emplace_back(b,c);
			road[b].emplace_back(b,c);
			num[c]++;
		}
		else if(road[a].empty())
		{
			for(int i=0;i<road[b].size();i++)
			{
				int wei=max(road[b][i].w,c);
				road[a].emplace_back(road[b][i].v,wei);
				num[wei]++;
			}
			road[a].emplace_back(b,c);
			road[b].emplace_back(b,c);
			num[c]++;
		}
		else if(road[b].empty())
		{
			for(int i=0;i<road[a].size();i++)
			{
				int wei=max(road[a][i].w,c);
				road[b].emplace_back(road[a][i].v,wei);
				num[wei]++;
			}
			road[b].emplace_back(a,c);
			road[a].emplace_back(b,c);
			num[c]++;
		}
		else
		{
			for(int i=0;i<road[a].size();i++)
			{
				int wei=max(road[a][i].w,c);
				road[b].emplace_back(road[a][i].v,wei);
				num[wei]++;
			}
			for(int i=0;i<road[b].size();i++)
			{
				int wei=max(road[b][i].w,c);
				road[a].emplace_back(road[b][i].v,wei);
				num[wei]++;
			}
		}
	}
	return 0;
}

