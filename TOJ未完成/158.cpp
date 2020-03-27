//Debug�W��ɶ�=A=
//�j���W�L�t��... 

#include<iostream>
#include<algorithm>
using namespace std;

#define maxN 100001
int set[maxN];

inline void Init(int k){for(int i=0;i<k;i++)set[i]=i;}
inline int find(int x){return (set[x]==x?x:set[x]=find(set[x]));}
inline void Union(int x,int y){set[find(x)]=find(y);}


struct Bomb
{
	int X,Y,C,id;
};
 
bool Xcmp(Bomb x,Bomb y)
{
	if(x.X!=y.X)return x.X<y.X;
	return x.Y<y.Y;
}

bool Ycmp(Bomb x,Bomb y)
{
	if(x.Y!=y.Y)return x.Y<y.Y;
	return x.X<y.X;
} 

bool setcmp(Bomb x,Bomb y)
{
	if(find(x.id)!=find(y.id))return find(x.id)<find(y.id);
	return x.C<y.C;
}

bool anscmp(Bomb x,Bomb y)
{
	return find(x.id)<find(y.id);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	while(T--)
	{
		int N,R,ans=0;
		cin>>N>>R;
		
		Bomb bomb[N];
		for(int i=0;i<N;i++)
		{
			cin>>bomb[i].X>>bomb[i].Y>>bomb[i].C;
			bomb[i].id=i;
		}
		
		Init(N);
		sort(bomb,bomb+N,Xcmp);//����X�ƧǦA��Y�Ƨ� 
		for(int i=1;i<N;i++)
		{
			if(bomb[i-1].X!=bomb[i].X)continue;//�p�G���A�P�@��X�A���L 
			if(bomb[i].Y-bomb[i-1].Y>R)continue;//�p�G�Z��>R�A���L
			Union(bomb[i].id,bomb[i-1].id);//�p�G�|�v�T�A��b�P�@��set
		}
		
		sort(bomb,bomb+N,Ycmp);//����Y�ƧǦA��X�Ƨ� 
		for(int i=1;i<N;i++)
		{
			if(bomb[i-1].Y!=bomb[i].Y)continue;
			if(bomb[i].X-bomb[i-1].X>R)continue;
			Union(bomb[i].id,bomb[i-1].id);
		}
		
		sort(bomb,bomb+N,setcmp);
		int i=0;
		do
		{
			ans+=bomb[i].C;
			Bomb F={0,0,0,bomb[i].id};
			i=upper_bound(bomb,bomb+N,F,anscmp)-bomb;
		}while(i<N);
		cout<<ans<<'\n';
	}
	return 0;
}

