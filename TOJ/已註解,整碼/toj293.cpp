#include<iostream>
using namespace std;

//最大公因數 
int gcd(int x,int y)
{
    while((x%=y)&&(y%=x));
    return x+y;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    unsigned long long a,b,x,y,t;//怕溢位開大點 
    while(cin>>a>>b>>x>>y)
    {
    	//將x,y約分，避免x,y>a,b導致結果出錯的狀況 
        t=gcd(x,y);
        x/=t;
        y/=t;
        
        t=min((a/x),(b/y));
        cout<<t*x<<' '<<t*y<<'\n';
        
    }
    return 0;
}
