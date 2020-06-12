#include<iostream>
#include<cstring>
using namespace std;

const int maxK=110,maxP=1000010;
int N[maxK],F[maxK],W[maxK],H[5][maxP];

void clear()

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int K,P;
    cin>>K>>P;
    memset(H,0,sizeof(H));
    for(int i=0;i<K;i++)
        cin>>N[i]>>F[i]>>W[i];
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<P;j++)
        {
            for(int k=0;k<=N[i];k++)
            {
                if(j-k*W[i]<0)break;
                H[i+1][j]=max(H[i+1][j],H[i][j-k*W[i]]+F[i]*k);
                cout<<H[i+1][j]<<' ';
            }
            //cout<<endl;
        }
        //cout<<endl;
    }
    cout<<H[K-1][P-1]<<'\n';
    
    return 0;
}
