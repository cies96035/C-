#include<iostream>
using namespace std;

typedef long long ll;
const ll mod=24851;
//最多跑24851次會break 

//這個東西有需要深刻體會!! 
ll findiv(ll num)
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
    
    ll N,M;
    ll ans=1,ansdiv=1;
    cin>>N>>M;
    if(M>N||M<1)
    {
    	cout<<"0\n";
    	return 0;
	}
    N--;
    M--;
    M=max(M,N-M);
    for(ll i=M+1,j=1;i<=N;i++,j++)
    {
        ans*=i;
        ansdiv*=j;
        ans%=mod;
        ansdiv%=mod;
        if(!ans)break;
    }
    cout<<(ans*findiv(ansdiv))%mod<<'\n';
    return 0;
}
