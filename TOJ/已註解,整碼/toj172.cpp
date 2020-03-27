#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

//PI值
#define PI 3.141592653589793

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //輸出到小數二位
    cout<<fixed<<setprecision(2);
    
    //side_size紀錄由小到大的邊, 
    //side_turn紀錄邊的順序 
    long double side_size[4],side_turn[4];
    
    while(cin>>side_turn[0]>>side_turn[1]>>side_turn[2]>>side_turn[3])
    {
    	for(int i=0;i<4;i++)
    		side_size[i]=side_turn[i];
    	
		//排序大小
        sort(side_size,side_size+4);
        
        //出現負數或是四個皆為0，不合法
        if(side_size[0]<0||side_size[3]==0)
            cout<<"Illegal Polygon -1"<<'\n';
            
        //三個邊為零，計算圓面積
        else if(side_size[2]==0)
        {
            long double radius=side_size[3]/PI/2,area=radius*radius*PI;
            
            cout<<"Circle "<<area<<'\n';
        }
        
        //兩個邊為零，計算扇形面積
        else if(side_size[1]==0)
        {
            long double radius=side_size[2],Arc=side_size[3],
			area=(Arc/(radius*2*PI))*(radius*radius*PI);
			
            cout<<"Sector "<<area<<'\n';        
        }
        
        //一個邊為零，判斷三角形並計算面積
        else if(side_size[0]==0)
        {
			long double a=side_size[1],b=side_size[2],c=side_size[3],
			s=(a+b+c)/2,area=sqrt(s*(s-a)*(s-b)*(s-c));
			
            if(a+b<=c)
                cout<<"Illegal Triangle -1"<<'\n';
            else if(a*a+b*b>c*c)
                cout<<"Acute Triangle "<<area<<'\n';
            else if(a*a+b*b==c*c)
                cout<<"Right Triangle "<<area<<'\n';
            else
                cout<<"Obtuse Triangle "<<area<<'\n';
        }
        
        //全部邊不為零，判斷是何種四邊形
        else
        {
            long double a=side_turn[0],b=side_turn[1],c=side_turn[2],d=side_turn[3],
			s=(a+b+c+d)/2,areas=sqrt((s-a)*(s-b)*(s-c)*(s-d));
            
            //不合法(面積出現虛數或是面積為零)
            if(isnan(areas)||areas==0)
                cout<<"Illegal Quadrilateral -1"<<'\n';
                
            //四邊長等長 
            else if(side_size[0]==side_size[3])
                cout<<"Rhombus "<<areas<<'\n';
                
            //對邊相等 
            else if(a==c&&b==d)
                cout<<"Parallelogram "<<areas<<'\n';
                
            //鄰邊相等 
            else if((a==b&&c==d)||(b==c&&a==d))
                cout<<"Kite "<<areas<<'\n';
            
            //其他四邊形 
            else
                cout<<"Other Quadrilateral "<<areas<<'\n';
        }
    }
    return 0;
}
