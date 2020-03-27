/*
對set不夠了解
找東西時一律用find()非set[]..
在搞什麼= = 
*/
#include<iostream>
#include<cstring> 
using namespace std;

typedef long long ll;
const int maxnum=1000001;
const int smaxnum=1001;

int prime[maxnum],set[maxnum];
bool check[maxnum],used[maxnum];//check[]紀錄要檢查的點，used紀錄是否計算過or該點主人是否檢查過

void Init(){for(int i=0;i<maxnum;i++)set[i]=i;}//初始化 
int find(int x){return (set[x]==x ? x : set[x]=find(set[x]));}//找目標的主人(? 
void Union(int x,int y){set[find(x)]=find(y);}//合併 

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //建表&初始化 
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
        
    int N,ans=0,num,record;
    cin>>N;
    while(N--)
    {
        cin>>num;
        if(num==1)ans++;//特判，每個1獨立連通塊 
        if(!used[num])//避免重複計算，加速? 
	    {
		    while(prime[num])//prime[1]=0，直到num為1 
	        {
	            record=prime[num];
	            if(!check[record])check[record]=1;//出現過的質數都要check 
	            while(!(num%record))
	                num/=record;
	            if(num>1)
	                Union(prime[num],record);//把同個數的質數合併起來 
	        }
	        used[num]=1;
    	}
    }
    memset(used,0,sizeof(used));
    for(int i=0;i<maxnum;i++)
        if(check[i]&&!used[find(i)])
        {
            used[find(i)]=1;//該主人已經被找過了，不能再計算 
            ans++;
        }
    
    cout<<ans<<'\n';
    return 0;
}
