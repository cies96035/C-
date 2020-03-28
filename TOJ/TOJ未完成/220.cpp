#include<iostream>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	 
	int T;
	cin>>T;
	while(T--)
	{
		int N,Lscore=0,Rscore=0,sp=0;
		cin>>N;
		for(int i=0;i<N;i++)
		{
			char race;
			cin>>race;
			if(race=='W')
			{
				Lscore+=2;
				Lscore+=sp;
				sp=0;
			}
			else if(race=='D')
			{
				Lscore++;
				Rscore++;
			}
			else
			{
				if(sp<5)sp++;
				Rscore+=2;
			}
		}
		cout<<Lscore*5<<' '<<Rscore*5<<'\n';
	} 
	return 0;
}

