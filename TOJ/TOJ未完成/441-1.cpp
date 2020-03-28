#include<iostream>
using namespace std;

const int mod=1000000007; 
typedef long long ll;

ll findr(ll num)
{
    ll d = mod, x = 0, s = 1, q, r, t;
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
	
	//m+n/m/n - m+n/m-1/n+1
	int N,M;
	cin>>N>>M;
	ll a=N+1,b=1,r=1;
	for(int j=1,i=N+2,k=M+N;i<=k;i++,j++)//°õ¦æM-1¦¸ 
	{
		a*=i;
		b*=i;
		r*=j;
		a%=mod;
		b%=mod;
		r%=mod;
	}
	/*cout<<a<<' '<<r*M<<' '<<a*findr(r*M)%mod<<endl;
	cout<<b<<' '<<r<<' '<<b*findr(r)%mod<<endl;*/
	cout<<((a*findr(r*M)-b*findr(r))%mod+mod)%mod<<'\n';
	return 0;
}

