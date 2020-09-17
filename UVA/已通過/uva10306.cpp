#include<iostream>
#include<cstring>
using namespace std;

#define MaxS 400

const int inf=2e9;
int DP[MaxS][MaxS];

//for test
void print(int w)
{
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<w;j++)
            cout<<DP[i][j]<<' ';
        cout<<endl;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        memset(DP,0,sizeof(int)*MaxS*MaxS);
        DP[0][0]=1;
        int m,S;
        int min=inf;

        cin>>m>>S;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            for(int j=x;j<=S;j++)
                for(int k=y;k<=S;k++)
                    if(DP[j-x][k-y]!=0)
                        if(DP[j][k]==0||DP[j][k]>DP[j-x][k-y]+1)
                        {
                            DP[j][k]=DP[j-x][k-y]+1;
                            if(j*j+k*k==S*S&&min>DP[j][k])
                                min=DP[j][k];
                        }
            //print(S+1);
        }
        if(min!=inf)
            cout<<min-1<<'\n';
        else
            cout<<"not possible\n";
        
    }
    return 0;
}