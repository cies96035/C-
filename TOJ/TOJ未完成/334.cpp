#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;

ll X1,Y1,X2,Y2,ans=0;
vector<ll> Edge,chocolate;
map<pll,ll> MCT;//memorychangetimes

ll LB(vector<ll> v,ll r)
{return lower_bound(v.begin(),v.end(),r)-v.begin();}
 
ll cake(ll r,ll d,ll edge)//代表要得到 1,1到r,d的巧克力數 
{
    if(r>d)swap(r,d);//具有對稱 
    
    if(MCT.find(pll(r,d))!=MCT.end())//重複的記錄下來可以加快速度 
        return MCT[pll(r,d)];
        
    ll num=0,m=edge/2;
    ll kr=LB(Edge,r),kd=LB(Edge,d); 
    
    //終止條件 
    if(d==Edge[kd]&&r==d)//二次方邊長的正方體 
        return MCT[pll(r,d)]=chocolate[kd];
    else if(r==Edge[kr]&&d==edge)//二次方寬,長為邊的長方體 
        return MCT[pll(r,d)]=chocolate[kr]*(edge/(r));
    else if(d==Edge[kd]&&r==edge)
        return MCT[pll(r,d)]=chocolate[kd]*(edge/(d));
        
    //遞迴 
    if(r>m&&d>m)//分四塊(一塊沒東西) 
    {
        num+=cake(m,m,m);//左上 
        num+=cake(r-m,m,m);//右上 
        num+=cake(m,d-m,m);//左下 
    }
    else if(r<=m&&d>m)//分兩塊 
    {
        num+=cake(r,m,m);//左上 
        num+=cake(r,d-m,m);//左下 
    }
    else//分一塊 
        num+=cake(r,d,m);//左上 
    return MCT[pll(r,d)]=num;
}
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    chocolate.push_back(1);
    Edge.push_back(1);
    cin>>X1>>Y1>>X2>>Y2;
    while(Edge.back()<max(X2,Y2))
    {
        Edge.push_back(Edge.back()*2);
        chocolate.push_back(chocolate.back()*3);
    }
    ans=cake(X2,Y2,Edge.back());
    
    
    if(X1>1)
    {
        ans-=cake(X1-1,Y2,Edge.back());
        if(Y1>1)
        	ans+=cake(X1-1,Y1-1,Edge.back())-cake(X2,Y1-1,Edge.back());
	}
    else if(Y1>1)
        ans-=cake(X2,Y1-1,Edge.back());
        
    cout<<ans<<'\n';
}
