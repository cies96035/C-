#include<iostream>
#include<iomanip>
#include<algorithm> 
using namespace std;

struct Weapon
{
	long double X,W,D;
};

bool cmp(const Weapon &a,const Weapon &b)
{
	if(a.D>b.D)return 1;
	return 0;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
    int N,V,w=0,x=0;
    cin>>N>>V;
    //存放每個武器的密度,及每個武器的最大可用重量 
    
    Weapon weapon[N];
    
    //處理每個資料 
    for(int i=0;i<N;i++)
    {
        long double X,W;
        cin>>X>>W;
        weapon[i].X=X;
        weapon[i].W=W;
        weapon[i].D=X/W; 
    }
    
    sort(weapon,weapon+N,cmp);
    
    //每次迴圈把最大密度的放進去，直到重量超過題目要求 
    int y=-1;//最大武器殺傷力密度編號 
    while(w<V)
    {
        y++;
        //將編號y的重量全部加進去w、殺傷力全部加進去x 
        x+=weapon[y].X;
        w+=weapon[y].W;
    } 
    
    //把總價值扣掉多出來的重量*密度，輸出 
    cout<<fixed<<setprecision(3)<<x-(w-V)*weapon[y].D<<endl;
    
    return 0;
}
