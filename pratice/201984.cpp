#include<iostream>
#include<cstring>
using namespace std;
#define Maxb 10050

int phi[Maxb],T,a,b,c,ans;
int D[Maxb];

void Initphi()
{
    for(int i=1;i<Maxb;i++)
        phi[i]=i;
    for(int i=1;i<Maxb;i++)
        for(int x=i*2;x<Maxb;x+=i)
            phi[x]-=phi[i];
}
int P(long long a,int n)
{
    long long base=1;
    while(n)
    {
        if(n%2)
        {
            base=base*a%c;
        }
        a=a*a%c;
        a%=c;
        n/=2;
    }
    return base;
}
int D(int depth)
{
    if(de[depth])return de[depth];
    if(depth==0)
        return a;
    int up=D(depth-1)%phi[c]+phi[c];
    int base=D(depth-1)%c;
    return de[depth]=P(base,up)%c;
}
int main() {
    
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Initphi();
    
    cin>>T;
    while(T--)
    {
        memset(D,0,sizeof(D));
        cin>>a>>b>>c;
        D[0]=a;
        for(int i=1;i<=b;i++)
        {
            if(D[i-1]<phi[c])
                D[i]=P((D[i-1]%c),(D[i-1]%phi[c]))%c;
            else
                D[i]=P((D[i-1]%c),(D[i-1]%phi[c]+phi[c]))%c;
        }
        cout<<D[b]<<'\n';
    }
    return 0;
}
