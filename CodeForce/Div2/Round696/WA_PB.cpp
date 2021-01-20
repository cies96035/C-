#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
#define MN 25000
typedef long long ll;
ll Prime[MN];
int pid=0;
bool isntprime[MN];
ll k[13000];
int T;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    isntprime[0]=1;
    isntprime[1]=1;
    for(ll i=2;i<MN;i++)
    {
        if(!isntprime[i])
        {
            Prime[pid++]=i;
            for(ll j=i*i;j<MN;j+=i)
            {
                isntprime[j]=1;
            }
        }
    }
    for(int i=0;i<pid;i++)
    {
        for(int j=i+1;j<pid;j++)
        {
            ll a=Prime[i]-1;
            ll b=Prime[j]-Prime[i];
            ll c=Prime[j]*Prime[i]-Prime[j];
            if(min(a,min(b,c))>=12000)
                break;
            if(k[min(a,min(b,c))]==0 || k[min(a,min(b,c))] > Prime[j]*Prime[i] )
                k[min(a,min(b,c))]=Prime[j]*Prime[i];
        }
    }
    for(int i=11000;i>0;i--)
    {
        if(k[i]<k[i-1]||k[i-1]==0)
            k[i-1]=k[i];
    }
    int t;
    int p;
    cin>>t;
    while(t--)
    {
        cin>>p;
        cout<<k[p]<<'\n';
    }
    return 0;
}