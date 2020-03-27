#include <iostream>
#include <cstring>

using namespace std;
#define mod 1000000007

//�����^�X�Ʊo���`�覡�ƶq 
void getsum(long long n)
{
	long long temp[6][6],sum=0,
	
	//��l�Ƥ@�ǰ򥻸�� 
	states[6]={1,0,0,0,0,0},//�Ĺs�^��¦���A 
	ans[6][6]=//�x�}��줸��:���F�﨤�u�H�~��L�Ҭ��s 
	{{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1}},
	base[6][6]=//�g�L�D�N�o�X���x�} 
	{{1,1,0,1,0,0},
	{1,0,1,1,0,0},
	{1,0,0,1,0,0},
	{0,0,0,1,1,0},
	{0,0,0,1,0,1},
	{0,0,0,1,0,0}};
	
	//�x�}�ֳt�� 
	while(n)
	{
		//ans*=base
		if(n%2)
		{
			//��l�� 
			memset(temp,0,sizeof(temp));
			
			//�x�}�ۭ��A�ۭ����G���temp 
			for(int i=0;i<6;i++)
				for(int j=0;j<6;j++)
					for(int k=0;k<6;k++)
						temp[i][j]+=base[i][k]*ans[k][j];
						
			//��temp���ans�A�p�G���W�Lmod�ȴN�� 
			for(int i=0;i<6;i++)
				for(int j=0;j<6;j++)
					ans[i][j]=(temp[i][j]>=mod?temp[i][j]%mod:temp[i][j]);
		}
		
		//base*=base
		
		//��l�� 
		memset(temp,0,sizeof(temp));
		
		//�ۭ� 
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				for(int k=0;k<6;k++)
					temp[i][j]+=base[i][k]*base[k][j];
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				base[i][j]=(temp[i][j]>=mod?temp[i][j]%mod:temp[i][j]);
		
		n/=2;
	}
	
	//�N�x�}�ֳt���᪺���G�A���W��¦���A���ƶq�A�����o���`�M 
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		{
			sum+=states[i]*ans[i][j];
			if(sum>=mod)sum%=mod;
		}
	cout<<sum<<endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
    long long n;
    while(cin>>n) 
    	getsum(n);
    return 0;
}
