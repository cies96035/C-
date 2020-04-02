#include<iostream>
#include<algorithm> 
using namespace std;

#define maxk 1000001
#define maxM 3000001

struct link
{
    //連接點a點b的成本為w 
    int a,b,W;
}Link[maxM];

//依照成本由小排到大 
bool cmp(link x,link y){return x.W<y.W;}

int division[maxk];//每個點的分組 

//初始化，每個點自己一組 
void Init(int k){for(int i=1;i<=k;i++)division[i]=i;} 
//尋找點a的組別 
int find(int a){return division[a]==a ? a : division[a]=find(division[a]);}
//將a,b兩點的組別合併為b組別 
void Union(int a,int b){division[find(a)]=find(b);}
//判斷兩個點的組別是否一樣 
bool same(int a,int b){return find(a)==find(b);}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,c,d,ans=0;
        cin>>N>>M;
        Init(N);
        for(int i=0;i<M;i++)
        {
            cin>>Link[i].a>>Link[i].b>>c>>d;
            Link[i].W=c-d; 
        }
        sort(Link,Link+M,cmp);
        for(int i=0;i<M;i++)
        {
            //有環時不紀錄 
			//除非他建造後能賺到錢就建造，反正建越多成本越小 
            if(same(Link[i].a,Link[i].b)&&Link[i].W>0)continue;
            
            //建造橋樑:合併該連結兩點 
            Union(Link[i].a,Link[i].b);
            
            //將該邊成本加進去 
            ans+=Link[i].W;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
