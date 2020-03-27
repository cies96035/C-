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
	ll//��l�Ƥ@�ǰ򥻸�� 
	base[6][6]=//�g�L�D�N�o�X���x�} 
	{{1,1,0,1,0,0},
	{1,0,1,1,0,0},
	{1,0,0,1,0,0},
	{0,0,0,1,1,0},
	{0,0,0,1,0,1},
	{0,0,0,1,0,0}};
	
	//�x�}�ۭ�
	for(int n=0;n<63;n++)
	{
		matrixcpy(sum[n],base);
		matrixmul(base,base);
	}			
}

void getans(ll n)
{
	ll Sum=0,index=0,
	ans[6][6]= //���x�} 
	{{1,0,0,0,0,0},
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1}};
	
	//�x�}�ֳt�� 
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
