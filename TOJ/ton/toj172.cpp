#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

//PI��
#define PI 3.141592653589793

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //��X��p�ƤG��
    cout<<fixed<<setprecision(2);
    
    //side_size�����Ѥp��j����, 
    //side_turn�����䪺���� 
    long double side_size[4],side_turn[4];
    
    while(cin>>side_turn[0]>>side_turn[1]>>side_turn[2]>>side_turn[3])
    {
    	for(int i=0;i<4;i++)
    		side_size[i]=side_turn[i];
    	
		//�ƧǤj�p
        sort(side_size,side_size+4);
        
        //�X�{�t�ƩάO�|�ӬҬ�0�A���X�k
        if(side_size[0]<0||side_size[3]==0)
            cout<<"Illegal Polygon -1"<<'\n';
            
        //�T���䬰�s�A�p��ꭱ�n
        else if(side_size[2]==0)
        {
            long double radius=side_size[3]/PI/2,area=radius*radius*PI;
            
            cout<<"Circle "<<area<<'\n';
        }
        
        //����䬰�s�A�p�⮰�έ��n
        else if(side_size[1]==0)
        {
            long double radius=side_size[2],Arc=side_size[3],
			area=(Arc/(radius*2*PI))*(radius*radius*PI);
			
            cout<<"Sector "<<area<<'\n';        
        }
        
        //�@���䬰�s�A�P�_�T���Ψíp�⭱�n
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
        
        //�����䤣���s�A�P�_�O��إ|���
        else
        {
            long double a=side_turn[0],b=side_turn[1],c=side_turn[2],d=side_turn[3],
			s=(a+b+c+d)/2,areas=sqrt((s-a)*(s-b)*(s-c)*(s-d));
            
            //���X�k(���n�X�{��ƩάO���n���s)
            if(isnan(areas)||areas==0)
                cout<<"Illegal Quadrilateral -1"<<'\n';
                
            //�|������� 
            else if(side_size[0]==side_size[3])
                cout<<"Rhombus "<<areas<<'\n';
                
            //����۵� 
            else if(a==c&&b==d)
                cout<<"Parallelogram "<<areas<<'\n';
                
            //�F��۵� 
            else if((a==b&&c==d)||(b==c&&a==d))
                cout<<"Kite "<<areas<<'\n';
            
            //��L�|��� 
            else
                cout<<"Other Quadrilateral "<<areas<<'\n';
        }
    }
    return 0;
}
