#include <iostream>
using namespace std;

float Abs(float x)
{
   if(x<0)return -x;
   else return x;
}

int gcd(int x,int y)
{
    while((x%=y)&&(y%=x));
    return x+y;
}

struct point
{
   int x,y; 
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        float A=0,b=0;
        point p[3];
        
        for(int i=0;i<3;i++)
            cin>>p[i].x>>p[i].y;
        for(int i=0;i<3;i++)
            A+=p[i].x*p[(i+1)%3].y-p[(i+1)%3].x*p[i].y;
            
        A=Abs(A/2);
        
        for(int i=0;i<3;i++)
        {
            int x1=p[i].x,x2=p[(i+1)%3].x,
            y1=p[i].y,y2=p[(i+1)%3].y;
            
            if(x1==x2)
               b+=Abs(y1-y2);
            else if(y1==y2)
               b+=Abs(x1-x2);
            else
            {
               b+=gcd(Abs(x1-x2),Abs(y1-y2));
            }
        }
        cout<<(int)(A+(b+2)/2)<<endl;
    }
    return 0;
}
