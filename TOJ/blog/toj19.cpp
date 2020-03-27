#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long double x,y,r,x1,x2,y1,y2,r1,r2;
    while(cin>>x1>>y1>>r1>>x2>>y2>>r2)
    {
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        //r¬°(x1,y1),(x2,y2)ªº¶ZÂ÷ 
        r=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
        if(r1+r2<r)cout<<"Nearly"<<endl;
        else cout<<"Quick in"<<endl;
    }
    return 0;
}
