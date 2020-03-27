#include<iostream>
using namespace std;

/*
A1*B1*A1*B2...A1*BN
A2*B1*...
...
AM*B1

排列整理後 
A1,A2...會有N次方=A1^N*A2^2
B1,B2...會有M次方=B1^M*B2^M

再整理又等於A1*A2...^N*B1*B2...^M

注意-3%4=1 
*/

const int mod=100000007;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int num,N,M;
	long long numN=1,numM=1,ans=1;
    cin>>N>>M;
    for(int n=0;n<N;n++)
    {
        cin>>num;
        numN*=num;
        if(numN>=mod||numN<=-mod)numN%=mod;
    }
    for(int m=0;m<M;m++)
    {
        cin>>num;
        numM*=num;
        if(numM>=mod||numM<=-mod)numM%=mod;
    }
    
    if(numN<0)numN+=mod;
    if(numM<0)numM+=mod;
    
    while(M)
	{
        if(M%2==1)
            ans*=numN;
        numN*=numN;
        if(ans>=mod)ans%=mod;
        if(numN>=mod)numN%=mod;
        M/=2;
    }
    while(N)
	{
        if(N%2==1)
            ans*=numM;
        numM*=numM;
        if(ans>=mod)ans%=mod;
        if(numM>=mod)numM%=mod;
        N/=2;
    }
    cout<<ans<<'\n';
    return 0;
}
