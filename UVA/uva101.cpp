#include<iostream>
#include<vector>
using namespace std;

#define maxN 30
vector<int> pile[maxN];
int a,b,N;
string A,B;
int pa,ha,pb,hb;

//make the pile p's id and above h(uninclude)
//go to the original place
void mk_original(int p,int h)
{
	for(int i=h+1;i<pile[p].size();i++)
		pile[ pile[p][i] ].emplace_back( pile[p][i] );
	pile[p].resize(h+1);
	return;
}

//make all pile a's id above ha(include) onto b 
void pb_emplaceback_pa(int pa,int ha,int pb)
{
	for(int i=ha;i<pile[pa].size();i++)//all id above ha
		pile[pb].emplace_back(pile[pa][i]);
	pile[pa].resize(ha);
	return;
}

//find which pile has a,
//return its pile and height
int find_pile(int a,int &h)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<pile[i].size();j++)
			if(pile[i][j]==a)
			{
				h=j;//its height
				return i;//and pile id
			}
}
void print()
{
	for(int i=0;i<N;i++)
	{
		cout<<i<<':';
		for(int j=0;j<pile[i].size();j++)
			cout<<' '<<pile[i][j];
		cout<<'\n';
	}
	return;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	
	for(int i=0;i<N;i++)//Init
		pile[i].emplace_back(i);
		
	while(cin>>A&&A!="quit")
	{
		cin>>a>>B>>b;
		
		pb=find_pile(b,hb);
		pa=find_pile(a,ha);
		
		if(pa==pb)continue;
		
		if(A=="move")
			mk_original(pa,ha);
		if(B=="onto")
			mk_original(pb,hb);
		pb_emplaceback_pa(pa,ha,pb);
	}
	print();
	return 0;
}

