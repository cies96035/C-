#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define M 1000000007

ll Pow(ll n)
{
    ll t=1;
    ll d=M-2;
    while(d)
    {
        if(d%2)
        {
            t*=n;
            t%=M;
        }
        n*=n;
        n%=M;
        d/=2;
    }
    return t;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll t;
    ll a,b;
    #define MAX 10000
    ll arr[MAX];
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(ll i=0;i<a;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+a);
        ll P=arr[a-b];
        ll pp=upper_bound(arr,arr+a,P)- lower_bound(arr,arr+a,P);
        ll PPP=b-(arr+a-upper_bound(arr,arr+a,P));
        ll tmp=1;
        for(ll i=pp,j=1;i>PPP;i--,j++)
        {
            tmp*=i;
            tmp%=M;
            tmp*=Pow(j);
            tmp %= M;
        }
        cout<<tmp<<'\n';
    }
    return 0;
}