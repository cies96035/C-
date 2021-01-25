#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
    #define MAX 300000
    ll one[MAX];
    ll two[MAX];
bool cmp(ll a,ll b)
{
    return a>b;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    ll n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>one[i];
        for(int i=0;i<n;i++)
            cin>>two[i];
        int on=0,tn=0;
        for(int j=0;j<n;j++)
        {
            if(two[j]==1)
                one[on++]=one[j];
            else
                two[tn++]=one[j];
        }
        sort(one,one+on,cmp);
        sort(two,two+tn,cmp);
        one[on]=0;
        two[tn]=0;
        /*
        for(int i=0;i<=on;i++)
            cout<<one[i]<<' ';
            cout<<endl;
        for(int i=0;i<=tn;i++)
            cout<<two[i]<<' ';
            cout<<endl;*/
        int cnt=0;
        int oi=0,ti=0;
        while(m>0)
        {
            //cout<<'A'<<oi<<' '<<ti<<' '<<m<<endl;
            if(oi<on && ti<tn)
            {
                if(one[oi]>=m)
                {
                    m-=one[oi];
                    cnt++;
                    oi++;
                }
                else if(one[oi]+one[oi+1] >= two[ti])
                {
                    m-=one[oi];
                    cnt++;
                    oi++;
                }
                else
                {
                    m-=two[ti];
                    cnt+=2;
                    ti++;
                }
                
            }
            else if(oi<on)
            {
                m-=one[oi];
                oi++;
                cnt++;
            }
            else if(ti<tn)
            {
                m-=two[ti];
                cnt+=2;
                ti++;
            }
            else
            {
                break;
            }
        }
        if(m>0)
            cout<<"-1\n";
        else
        {
            cout<<cnt<<'\n';
        }
        
    }
    return 0;
}