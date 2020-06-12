#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
#define MOD 1000000007

const int ten=1<<10;
ll S[6][1024],n,s=0; 

struct soldier
{
	int id,a;//½s¸¹¡Aª¬ºA 
};

bool cmp(soldier a,soldier b)
{
	return a.id<b.id;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	soldier war[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>war[i].id;
		int num=0;
		for(int j=0,in;j<10;j++)
		{
			cin>>in;
			num=(num<<1)+in;
		}
		if(war[i].id==1)
		{
			s++;
			S[1][num]++;
		}
		else
			war[i].a=num;
	}
	
	sort(war,war+n,cmp);//¥ý±Æ§Ç 

	for(int i=s;i<n;i++)
	{
		for(int j=0;j<ten;j++)
		{
			int in=j|war[i].a;
			S[war[i].id][in]+=S[war[i].id-1][j];
			if(S[war[i].id][in]>MOD)S[war[i].id][in]%=MOD;
		}
	}
	cout<<S[5][1023]<<'\n';
	
	return 0;
}
