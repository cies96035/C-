#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll sum[63][6][6];

void matrixcpy(ll x[6][6],ll y[6][6])
{
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			x[i][j]=(y[i][j]>=mod?y[i][j]%mod:y[i][j]);
	return;
}

void matrixmul(ll x[6][6],ll y[6][6])//x*=y 
{
	ll tmp[6][6];
	memset(tmp,0,sizeof(tmp));
	
	for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            for(int k=0;k<6;k++)
                tmp[i][j]+=x[i][k]*y[k][j];
    matrixcpy(x,tmp);
    return;
}

void getsum()
{
	ll//初始化一些基本資料 
	base[6][6]=//經過題意得出的矩陣 
	{{1,1,0,1,0,0},
	{1,0,1,1,0,0},
	{1,0,0,1,0,0},
	{0,0,0,1,1,0},
	{0,0,0,1,0,1},
	{0,0,0,1,0,0}};
	
	//矩陣相乘
	for(int n=0;n<63;n++)
	{
		matrixcpy(sum[n],base);
		matrixmul(base,base);
	}			
}

void getans(ll n)
{
	ll Sum=0,index=0,
	ans[6][6]= //單位矩陣 
	{{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1}};
	
	//矩陣快速冪 
	while(n)
	{
		if(n&1)
			matrixmul(ans,sum[index]);
		n/=2;
		index++;
	}
	
	for(int i=0;i<6;i++)
	{
		Sum+=ans[0][i];
		if(Sum>=mod)Sum%=mod;
	}
	cout<<Sum<<'\n';
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0); 
	
	getsum();
    ll n;
    while(cin>>n) 
    	getans(n);
    return 0;
}
