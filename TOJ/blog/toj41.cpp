#include<iostream>
#include<algorithm> 
using namespace std;

#define maxk 1000
#define maxM 500000

struct link
{
	//i到j的成本為w 
	int a,b,W;
}Link[maxM];

//依照成本由小排到大 
bool cmp(link x,link y){return x.W<y.W;}

int division[maxk];//每個點的分組 

//初始化，每個點自己一組 
inline void Init(int k){for(int i=0;i<k;i++)division[i]=i;} 
//尋找a的組別 
inline int find(int a){return division[a]==a ? a : division[a]=find(division[a]);}
//將a,b兩點的組別合併為b組別 
inline void Union(int a,int b){division[find(a)]=find(b);}
//判斷兩個人的組別是否一樣 
inline bool same(int a,int b){return find(a)==find(b);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int k,R,ans=0;
    bool can=1;
    cin>>k>>R;
    Init(k);
    for(int i=0;i<R;i++)
    {
    	cin>>Link[i].a>>Link[i].b>>Link[i].W; 
	}
	sort(Link,Link+R,cmp);
    for(int i=0;i<R;i++)
    {
    	//有環時不紀錄 
    	if(same(Link[i].a,Link[i].b))continue;
    	//無環時併一組 
    	Union(Link[i].a,Link[i].b);
    	//將該邊體力加進去 
    	ans+=Link[i].W;
    }
    
    for(int i=1;i<k;i++)
    {
    	if(same(division[i],division[i-1]))continue;
    	can=0;
    	break;
	}
	if(can)
    	cout<<ans<<endl;
    else
    	cout<<-1<<endl;
    
    return 0;
}
