#include<iostream>
using namespace std;

//���I²��A�S����n���Ѫ� 

typedef unsigned long long ull;

const int mxN=300010;
int N;
int F[2][mxN],O[2][mxN];//����,Origin
bool fg=0,flg,Ofg=0,Oflg;//�u�� 
ull K;//�`�N�d�� 

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
	
	while(K)//�ֳt�� 
	{
		if(K%2)
			OtimesF();
		FtimesF();
		K/=2;
	}
	
	//��X 
	for(int i=1;i<N;i++)
		cout<<O[Ofg][i]<<' ';
	cout<<O[Ofg][N]<<'\n';
	return 0;
}
