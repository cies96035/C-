#include<iostream>
using namespace std;

typedef long long ll;
const int maxnum=1010000;
const int smaxnum=1005;

int prime[maxnum],set[maxnum];

void Init(){for(int i=0;i<maxnum;i++)set[i]=i;}
int find(int x){return (set[x]==x ? x : set[x]=find(set[x]));}
void Union(int x,int y){set[find(x)]=find(y);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Init();
    for(int i=2;i<maxnum;i+=2)prime[i]=2;
    for(int i=3;i<maxnum;i+=2)
        if(!prime[i])
        {
            prime[i]=i;
            if(i<smaxnum)
                for(int j=i*i,k=i+i;j<maxnum;j+=k)
                    if(!prime[j])
                        prime[j]=i;
        }
	int N,ans=0;
    cin>>N;
	bool check[maxnum]={0},used[maxnum]={0};
    while(N--)
    {
    	int num;
        cin>>num;
        if(num==1)ans++;//¯S§P 
        while(prime[num])//prime[1]=0
        {
            int record=prime[num];
            check[record]=1;
            while(!(num%record))
                num/=record;
            if(num>1)
    	        Union(prime[num],record);
        }
    }
    
    for(int i=0;i<maxnum;i++)
        if(check[i]&&!used[set[i]])
        {
            used[i]=1;
            ans++;
        }
    
    cout<<ans<<'\n';
    return 0;
}
