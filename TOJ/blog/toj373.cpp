#include<iostream>
#include<iomanip>
using namespace std;

/*
b1�k��Ab2����Ab3�W��Ab4�U�� 
*/ 
#define b1 (sx>x1&&sx>x2)
#define b2 (sx<x1&&sx<x2)
#define b3 (sy>y1&&sy>y2)
#define b4 (sy<y1&&sy<y2)

int Abs(int x)//����� 
{
    if(x<0)return -x;
    return x;
}
int main()
{
	//���p�Ƥ@�� 
    cout<<fixed<<setprecision(1);
    
    float x1,x2,y1,y2,sx,sy;
    cin>>x1>>y1>>x2>>y2>>sx>>sy;
    float x=Abs(x1-x2),y=Abs(y1-y2),
    hx=max(x1,x2),hy=max(y1,y2),
    lx=min(x1,x2),ly=min(y1,y2);
    //x,y���,higher x,y�M lower x,y
    
    //�E�ت��p 
    if(b3) 
    {
        //S�b�W���� 
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
