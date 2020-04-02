#include<iostream>
#include<cstring>
using namespace std;

#define mod 10009

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,S,E,K;
    while(cin>>N>>S>>E>>K)
    {
        long long a[N][N],dp[K+1][N];
        memset(dp,0,sizeof(dp));
        
        dp[0][S]=1;//起點設為1
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>a[i][j];
        for(int k=1;k<=K;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                {
                    dp[k][j]+=dp[k-1][i]*a[i][j];
                    if(dp[k][j]>=mod)dp[k][j]%=mod;
                }        
        cout<<dp[K][E]<<'\n';
    }
    return 0;
}

