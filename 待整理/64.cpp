//速度!!效率!!! 
#include<iostream>
#include<map> 
using namespace std;

const int maxA=10000001,smaxA=3163;
int prime[maxA];
typedef pair<int,int> pii;
map<int,pii> isinput;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i=3;i<maxA;i++)
    {
        if(i%2)
        {
            if(!prime[i])
            {
                if(i<smaxA)
                    for(int j=i*i,k=i+i;j<maxA;j+=k)
                    {
                        if(!prime[j])
                            prime[j]=i;
                    }
                else
                    prime[i]=i;
            }
        }
        else
            prime[i]=2;
    }
    
    int N,A;    
    cin>>N;
    while(N--)
    {
        cin>>A;
        if(isinput.find(A)!=isinput.end())cout<<isinput[A].second<<' '<<isinput[A].first<<'\n';
        else
        {
	        int first=1,second=1,Prime,a=A;
	        while(A!=1)
	        {
	            Prime=(prime[A]==0?A:prime[A]);
	            if(Prime>second)second=Prime;
	            if(second>first)swap(first,second);
	            while(!(A%Prime))A/=Prime;
	        }
	        cout<<second<<' '<<first<<'\n';
	        isinput[a]=pii(first,second);
		}
    }
    return 0;
}
