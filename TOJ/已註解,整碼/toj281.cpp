#include <iostream>
using namespace std;

int Abs(int x)//絕對值 
{
   if(x<0)return -x;
   return x;
}

int gcd(int x,int y)//最大公因數 
{
    while((x%=y)&&(y%=x));
    return x+y;
}

struct point//座標 
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
        float A=0,b=0;//面積、邊上格子點數 
        point p[3];
        
        for(int i=0;i<3;i++)//輸入 
            cin>>p[i].x>>p[i].y;
            
        for(int i=0;i<3;i++)//鞋帶公式算面積 
            A+=p[i].x*p[(i+1)%3].y-p[(i+1)%3].x*p[i].y;
        A=Abs(A)*0.5;
        
        for(int i=0;i<3;i++)//分別取得兩兩座標邊上的格子點總和 
        {
            int x1=p[i].x,
			x2=p[(i+1)%3].x,
            y1=p[i].y,
			y2=p[(i+1)%3].y;
            
            if(x1==x2)
               b+=Abs(y1-y2);
            else if(y1==y2)
               b+=Abs(x1-x2);
            else
               b+=gcd(Abs(x1-x2),Abs(y1-y2));
        }
		//不知道為甚麼沒有轉換成int就會WA...
		//理論上A+b/2+1這個值一定是整數阿... 
		//可能我哪邊搞錯多了0.5... 
        cout<<(int)(A+b/2+1)<<endl; 
    }
    return 0;
}
