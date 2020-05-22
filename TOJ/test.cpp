#include<iostream>
using namespace std;
#define MaxN 1000010
int E[MaxN],N;

int main() {
    
    for(int i=1;i<MaxN;i++)//¼Ú©Ô«Øªí 
        E[i]=i;
    
    for(int i=1;i<MaxN;i++)
        for(int x=i*2;x<MaxN;x+=i) 
            E[x]-=E[i];
    
    while(cin>>N)
        cout<<E[N]<<'\n';

    return 0;
}
