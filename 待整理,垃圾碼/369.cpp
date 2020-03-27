#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N;
    while(cin>>N)
    {
    int a[N],b[N];
    for(int i=0;i<N;i++)cin>>a[i];
    for(int i=0;i<N;i++)cin>>b[i];
        int LCSlen[2][N+1];
        memset(LCSlen,0,sizeof(LCSlen));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(a[i]==b[j])
                    LCSlen[(i+1)%2][j+1]=LCSlen[i%2][j]+1;
                else
                    LCSlen[(i+1)%2][j+1] = max(LCSlen[i%2][j+1],
                                       LCSlen[(i+1)%2][j]);
                //cout<<LCSlen[(i+1)%2][j+1]<<' ';
            }
            //cout<<endl;
        }
        //LCSlen[As][Bs]³Ìªø¤l§Ç¦C 
        cout<<LCSlen[N%2][N]<<endl;
    }
    return 0;
}
