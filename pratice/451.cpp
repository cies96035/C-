//polya�p�� 
#include<iostream>
using namespace std;

const int Mod=1000000007;
typedef long long ll;

int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}
ll P(ll a,int n)
{
	ll base=1;
	while(n)
	{
		if(n%2)
			base=base*a%Mod;
		a=a*a%Mod;
		n/=2;
	}
	return base;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	 
	int n,m,c,ans;
	cin>>n>>m>>c;
	c=P(c,n*n);//�C�ӭ���c�ؿ��
	//1/m(�Uc^gcd(i,m)) mod M
	
	for(int i=1;i<=m;i++)
		ans=(ans+P(c,gcd(i,m)))%Mod;
	cout<<ans*P(m,Mod-2)%Mod<<'\n';
	return 0;
}
