#include<iostream>
using namespace std;

#define maxN 500
#define maxM 50000

int city[maxN];

struct Road
{
	int u,v,w;
}road[maxM];

void Init(int a){for(int i=0;i<a;i++)city[i]=i;}
int find(int a){return city[a] == a ? a : city[a] = find(city[a]);}
bool same(int a,int b){return find(a)==find(b);}
void Union(int a,int b){city[find(a)]=find(b);}

int main()
{
	int N,M,num=0,sum=0;
	cin>>N>>M;
	bool cant[M]={0};
	for(int i=0;i<M;i++)
	{
		cin>>road[i].u>>road[i].v>>road[i].w;
		if(same(road[i].u,road[i].v))
		{
			cant[i]=1;
			continue;
		}
		Union(road[i].u,road[i].v);
	}
	for(int i=0;i<M;i++)
	{
		if(cant[i])continue;
		num++;
		sum+=road[i].w;
	}
	cout<<num<<sum<<endl;
	return 0;
}

