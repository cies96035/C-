#include<iostream>
#include<iomanip>
using namespace std;

/*
b1右方，b2左方，b3上方，b4下方 
*/ 
#define b1 (sx>x1&&sx>x2)
#define b2 (sx<x1&&sx<x2)
#define b3 (sy>y1&&sy>y2)
#define b4 (sy<y1&&sy<y2)

int Abs(int x)//絕對值 
{
    if(x<0)return -x;
    return x;
}
int main()
{
	//取小數一位 
    cout<<fixed<<setprecision(1);
    
    float x1,x2,y1,y2,sx,sy;
    cin>>x1>>y1>>x2>>y2>>sx>>sy;
    float x=Abs(x1-x2),y=Abs(y1-y2),
    hx=max(x1,x2),hy=max(y1,y2),
    lx=min(x1,x2),ly=min(y1,y2);
    //x,y邊長,higher x,y和 lower x,y
    
    //九種狀況 
    if(b3) 
    {
        //S在上左方 
        if(b2)
            cout<<x*y+((sy-hy)*x+(lx-sx)*y)/2<<endl;
        else if(b1)
            cout<<x*y+((sy-hy)*x+(sx-hx)*y)/2<<endl;
        else
            cout<<x*y+((sy-hy)*x)/2<<endl;
    }
    else if(b4) 
    {
        if(b2)
            cout<<x*y+((ly-sy)*x+(lx-sx)*y)/2<<endl;
        else if(b1)
            cout<<x*y+((ly-sy)*x+(sx-hx)*y)/2<<endl;
        else
            cout<<x*y+((ly-sy)*x)/2<<endl;
    }
    else 
    {
        if(b2)
            cout<<x*y+((lx-sx)*y)/2<<endl;
        else if(b1)
            cout<<x*y+((sx-hx)*y)/2<<endl;
        else
            cout<<x*y<<endl;
    }
    return 0;
}
