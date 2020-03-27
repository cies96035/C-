#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
#define maxnum 1000001
#define smaxnum 1001
#define primenum 78500

vector<int> Prime;
int N,ans=0,num,record,index=0,tmp;
bool isntprime[maxnum];
int set[primenum];
bool check[primenum],used[primenum];

void Init(int i){while(i)set[--i]=i;}
int find(int x){return set[x]==x?x:set[x]==find(set[x]);}
void Union(int x,int y){set[find(x)]=find(y);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    Init(primenum);
    for(int i=4;i<maxnum;i+=2)isntprime[i]=1;
    Prime.push_back(2);
    for(int i=3;i<maxnum;i+=2)
        if(!isntprime[i])
        {
        	if(i<smaxnum)
	            for(int j=i*i,k=i+i;j<maxnum;j+=k)
	                if(!isntprime[j])
	                    isntprime[j]=1;
   			Prime.push_back(i);
        }

    cin>>N;
    while(N--)
    {
        cin>>num;
        if(num==1)ans++;//¯S§P 
        tmp=-1;
        while(num!=1)
        {
        	if(tmp!=-1)record=tmp;
        	else
        	{
	        	for(int i=0;i<Prime.size();i++)
	        		if(!(num%Prime[i]))
	        		{
	        			record=i;
	            		if(!check[i])check[i]=1;
	        			break;
					}
			}
			
            while(!(num%Prime[record]))
                num/=Prime[record];
            
            if(num!=1)
            {
		    	for(int i=0;i<Prime.size();i++)
		    		if(!(num%Prime[i]))
		    		{
		    			tmp=i;
		        		if(!check[i])check[i]=1;
		    			break;
					}
            	Union(tmp,record);
			}
        }
    }
    
    for(int i=0;i<Prime.size();i++)
        if(check[i]&&!used[set[i]])
        {
            used[set[i]]=1;
            ans++;
        }
    
    cout<<ans<<'\n';
    return 0;
}
