#include<iostream>
#include<iomanip> 
using namespace std;
int y,m,d;
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string days=" Su Mo Tu We Th Fr Sa";
string divider="=====================";
int main()
{
	cin>>y>>m>>d;
	if(m<0||m>12||d<0||d>6)
		cout<<"invalid\n";
	else
	{
		//is leap?
		if((y%4==0&&y%100!=0)||y%400==0)
			md[2]++;
		cout<<days<<endl<<divider<<endl;
		for(int i=0;i<d;i++)
			cout<<"   ";
		for(int i=1,D=d;i<=md[m];i++)
		{	
			if(D++>6)
			{ 
				D%=7;
				cout<<endl;
			}
			cout<<setw(3)<<i;
		} 
		cout<<endl<<divider<<endl;
	}
	return 0;
}

