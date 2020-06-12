#include<iostream>
#include<iomanip>
using namespace std;

float absmod(float x)
{
	if(x>360)x-=360;
	return x>0?x:-x;
}

int main()
{
	cout<<fixed<<setprecision(3);
	float H,M,Hangle,Mangle; 
	char colon;
	while(cin>>H>>colon>>M)
	{
		if(H==0&&M==0)break;
		Hangle=H*30+M/2;
		Mangle=M*6;
		float anglemin=absmod(Hangle-Mangle);
		cout<<(anglemin>180?360-anglemin:anglemin)<<endl;
	}
	return 0;
}

