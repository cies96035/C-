#include<iostream>
using namespace std;
#define MaxN 1000010
int E[MaxN],N;
long long sum[MaxN];

int main() {
	
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i=1;i<MaxN;i++)//¼Ú©Ô«Øªí 
        E[i]=i;
    
    for(int i=1;i<MaxN;i++)
    {
        for(int x=i*2;x<MaxN;x+=i) 
            E[x]-=E[i];
        sum[i]+=sum[i-1]+E[i];
        sum[i-1]=(sum[i-1]<<1)+1;
	}
    sum[0]=0;
    
    while(cin>>N)
        cout<<sum[N]<<'\n';

    return 0;
}

