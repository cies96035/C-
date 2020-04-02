#include<iostream>
using namespace std;

//有點簡單，沒什麼好註解的 

typedef unsigned long long ull;

const int mxN=300010;
int N;
int F[2][mxN],O[2][mxN];//切排,Origin
bool fg=0,flg,Ofg=0,Oflg;//滾動 
ull K;//注意範圍 

void FtimesF()
{
	flg=fg;
	fg=!fg;
	for(int i=1;i<=N;i++)
		F[fg][i]=F[flg][F[flg][i]];
	return;
}

void OtimesF()
{	
	Oflg=Ofg;
	Ofg=!Ofg;
	for(int i=1;i<=N;i++)
		O[Ofg][F[fg][i]]=O[Oflg][i];
	return;
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>O[Ofg][i];
	for(int i=1;i<=N;i++)
		cin>>F[fg][i];
	cin>>K;
	
	while(K)//快速冪 
	{
		if(K%2)
			OtimesF();
		FtimesF();
		K/=2;
	}
	
	//輸出 
	for(int i=1;i<N;i++)
		cout<<O[Ofg][i]<<' ';
	cout<<O[Ofg][N]<<'\n';
	return 0;
}
