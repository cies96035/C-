#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    while(cin>>T)
    {
        int n[T+1]={2147483647},N[T+1]={0},P[T+1]={0};
        memset(N,0,sizeof(N));
        for(int m=1;m<=T;m++)cin>>n[m];
        for(int i=1;i<=T;i++)
        {
            if(n[i]>n[i-1])
            {
                int k=(i-(P[i-1]+2));
                if(n[i]>=n[k])
                {
                    P[i]=P[k]+P[i-1]+2;
                }
                else
                {
                    P[i]=P[i-1]+1;
                }
                N[i]=P[i-1]+1;
            }
            else
            {
                if(n[i]==n[i-1])P[i]=P[i-1]+1;
                else P[i]==0;
                N[i]=0;
            }
        }
        for(int i=1;i<=T;i++)
        {
            cout<<N[i];
            if(i!=T)cout<<' ';
            else cout<<endl;
        }
    }
    return 0;
};
