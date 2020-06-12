#include<iostream>
#include<algorithm>
using namespace std;

#define MaxN 1010 
int N,s=1e9,e=0,ans=1;
struct Babysitter
{
    int start,end;
    void input()
    {
    	cin>>start>>end;
	}
}Time[MaxN];

Babysitter *index,*endid;

bool cmp(Babysitter x,Babysitter y)
{
    if(x.start!=y.start)return x.start<y.start;
    return x.end>y.end;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
    	Time[i].input();
        if(s>Time[i].start)s=Time[i].start;
        if(e<Time[i].end)e=Time[i].end;
    }
    sort(Time,Time+N,cmp);
    
    index=Time;
    
    //until find the last babysitter
    while(index->end!=e)
    {
    	//to find which's start is before t's end
        Babysitter t={index->end+1,0};
        int current_end=0;
        for(Babysitter *i=Time,*end=upper_bound(Time,Time+N,t,cmp);i<end;i++)
        {
            if(i->end>current_end)
            {
                current_end=i->end;
                endid=i;
            }
        }
        
        //if cannot find it,sometime cant babysit
        if(current_end==index->end)
        {
            cout<<"No\n";
            return 0;
        }
        index=endid;
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
