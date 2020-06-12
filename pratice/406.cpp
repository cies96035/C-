#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int three=1<<3;
ll S[4][three],n,s=0; 

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
		for(int j=0,in;j<3;j++)
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
		for(int j=0;j<three;j++)
		{
			int in=j|war[i].a;
			S[war[i].id][in]+=S[war[i].id-1][j];
		}
	}
	cout<<S[3][7]<<'\n';
	
	return 0;
}
