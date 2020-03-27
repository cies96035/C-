#include<bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> v[32] ;
int num[]={0,0,0,31621,3979,997,369,174,96,58,38,26,18,13,9,6,4,2,1,0} ;
LL mp[]={120,720,5040,175560,17297280,19958400,259459200,20274183401472000} ;
LL mp2[]={6,210,0} ;

void pre_cal()
{
    for(int i=3;i<=30;i++) v[i].clear() ;
    for(int i=3;i<=18;i++) for(int j=2;j<=num[i];j++)
    {
        LL M=j ;
        for(int k=1;k<=i;k++) M*=(j+k) ;
        v[i].push_back(M) ;
    }
}

LL cal_1(LL x)
{
    if(x<=2) return x==2 ? 1 : 0 ;
    LL l=1 , r=1e9 ;
    while(r-l>1)
    {
        LL mid=(l+r)/2 ;
        if(mid*(mid+1)>x) r=mid ;
        else l=mid ;
    }
    return l ;
}

LL cal_2(LL x)
{
    if(x<=6) return x==6 ? 1 : 0 ;
    LL l=1 , r=1e6 ;
    while(r-l>1)
    {
        LL mid=(l+r)/2 ;
        if(mid*(mid+1)*(mid+2)>x) r=mid ;
        else l=mid ;
    }
    return l ;
}

LL solve(LL x)
{
    LL ret=cal_1(x)+cal_2(x) ;
    for(int i=3;i<=18;i++)
    {
        int j ;
        for(j=0;j<v[i].size() && v[i][j]<=x;j++) ;
        ret += j ;
    }
    int minu1,minu2 ;
    for(minu1=0;minu1<8 && mp[minu1]<=x;minu1++) ;
    for(minu2=0;mp2[minu2]!=0 && mp2[minu2]<=x;minu2++) ;
    return ret-minu1-minu2 ;
}

main()
{
        //freopen("input.txt","r",stdin) ;
        //freopen("output1.txt","w",stdout) ;
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL l,r ; scanf("%I64d%I64d",&l,&r) ;
        printf("%I64d\n",solve(r)-solve(l-1)) ;
    }
}
