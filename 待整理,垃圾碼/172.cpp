#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323846

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(2);
	long double side[4],A,B,C,D;
	while(cin>>A>>B>>C>>D)
	{
		side[0]=A;
		side[1]=B;
		side[2]=C;
		side[3]=D;
		sort(side,side+4);
		if(side[0]<0||side[3]==0)
		{
			cout<<"Illegal Polygon -1"<<endl;
		}
		else if(side[2]==0)
		{
			long double radius=side[3]/PI/2,area;
			area=pow(radius,2)*PI;
			
			cout<<"Circle "<<area<<endl;
		}
		else if(side[1]==0)
		{
			long double radius=side[2],Arc=side[3],area;
			area=(Arc/((radius*2)*PI))*pow(radius,2)*PI;
			
			cout<<"Sector "<<area<<endl;		
		}
		else if(side[0]==0)
		{
			long long a=side[1],b=side[2],c=side[3];
			long double area,p;
			p=(long double)(a+b+c)/2;
			area=sqrt(p*(p-a)*(p-b)*(p-c));
			
			if(a+b<=c)
				cout<<"Illegal Triangle -1"<<endl;
			else if(a*a+b*b>c*c)
				cout<<"Acute Triangle "<<area<<endl;
			else if(a*a+b*b==c*c)
				cout<<"Right Triangle "<<area<<endl;
			else
				cout<<"Obtuse Triangle "<<area<<endl;
		}
		else
		{
			long double areas,p=(A+B+C+D)/2;
			areas=(p-A)*(p-B)*(p-C)*(p-D);
			
			if(side[0]==side[3])
				cout<<"Rhombus "<<sqrt(areas)<<endl;
			else if(areas<=0)
				cout<<"Illegal Quadrilateral -1"<<endl;
			else if(A==C&&B==D)
				cout<<"Parallelogram "<<sqrt(areas)<<endl;
			else if((A==B&&C==D)||(B==C&&A==D))
				cout<<"Kite "<<sqrt(areas)<<endl;
			else
				cout<<"Other Quadrilateral "<<sqrt(areas)<<endl;
		}
	}
	return 0;
}
