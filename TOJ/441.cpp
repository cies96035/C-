#include<iostream>
using namespace std;

const int mod=1000000007; 
typedef long long ll;

ll fac[10000000];
ll rfac[5000000];

int findrfac(ll num)
{
    int d = mod, x = 0, s = 1, q, r, t;
    while (num != 0)
    {
        q = d / num;
		r = d % num;
        d = num;
		num = r;
        t = x - q * s;
		x = s;
		s = t;
    }
    return (x + mod) % mod;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N,M,O,len,rlen;
	cin>>N>>M;
	O=N-M;
	
	len=N+M;//階乘最大長度 
	rlen=max(N-M,M);//倒數階乘最大長度 
	fac[0]=1;
	rfac[0]=1; 
	for(ll i=1;i<=len;i++)//建造階乘，倒階乘 
	{
		fac[i]=fac[i-1]*i;
		if(fac[i]>=mod)fac[i]%=mod;
		if(i<=rlen)
			rfac[i]=findrfac(fac[i]);
	}
	
	ll ans=fac[N+M]*findrfac(fac[N])%mod*rfac[M]%mod;
	for(int m=1;m<=M;m++)
	{
		ans-=fac[M-m+M]*rfac[M-m]%mod*rfac[M]%mod*fac[O+m-1]%mod*rfac[O]%mod*rfac[m-1]%mod;
		ans+=mod;
		ans%=mod;
	}
	
	cout<<ans<<'\n';
	return 0;
}
