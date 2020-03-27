#include <iostream>
#include <cstring>

using namespace std;
#define mod 1000000007

//給予回合數得到總方式數量 
void getsum(long long n)
{
	long long temp[6][6],sum=0,
	
	//初始化一些基本資料 
	states[6]={1,0,0,0,0,0},//第零回基礎狀態 
	ans[6][6]=//矩陣單位元素:除了對角線以外其他皆為零 
	{{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1}},
	base[6][6]=//經過題意得出的矩陣 
	{{1,1,0,1,0,0},
	{1,0,1,1,0,0},
	{1,0,0,1,0,0},
	{0,0,0,1,1,0},
	{0,0,0,1,0,1},
	{0,0,0,1,0,0}};
	
	//矩陣快速冪 
	while(n)
	{
		//ans*=base
		if(n%2)
		{
			//初始化 
			memset(temp,0,sizeof(temp));
			
			//矩陣相乘，相乘結果放到temp 
			for(int i=0;i<6;i++)
				for(int j=0;j<6;j++)
					for(int k=0;k<6;k++)
						temp[i][j]+=base[i][k]*ans[k][j];
						
			//把temp放到ans，如果有超過mod值就模 
			for(int i=0;i<6;i++)
				for(int j=0;j<6;j++)
					ans[i][j]=(temp[i][j]>=mod?temp[i][j]%mod:temp[i][j]);
		}
		
		//base*=base
		
		//初始化 
		memset(temp,0,sizeof(temp));
		
		//相乘 
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				for(int k=0;k<6;k++)
					temp[i][j]+=base[i][k]*base[k][j];
		for(int i=0;i<6;i++)
			for(int j=0;j<6;j++)
				base[i][j]=(temp[i][j]>=mod?temp[i][j]%mod:temp[i][j]);
		
		n/=2;
	}
	
	//將矩陣快速冪後的結果，乘上基礎狀態的數量，直接得到總和 
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
