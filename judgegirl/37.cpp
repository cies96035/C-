#include<iostream>
#include<map>
using namespace std;

int ipt[4],ans;//storage 4 input number 
map<int,int> type;

int gcd(int a,int b)
{
	while((a%=b)&&(b%=a));
	return a+b;
}

void Init_type()
{
	type[79]=30;//gold
	type[47]=10;//silver
	type[29]=4;//copper
	type[82]=5;//lead
	type[26]=3;//iron
	type[22]=9;//Ti
	return;
}
int main()
{
	Init_type();
	
	//input part
	char k;
	bool f=0;
	int num=0,index=0;
	while(cin.get(k)&&k!='\n')
	{
		if(k>='0'&&k<='9')
		{
			num=num*10+k-'0';
			f=1;
		}
		else if(f)
		{
			ipt[index++]=num;
			num=f=0;
		}
	}
	if(type.find(ipt[0])==type.end())
		cout<<-1<<endl;
	else if(ipt[1]<=0||ipt[2]<=0||ipt[3]<=0)
		cout<<-2<<endl;
	else
	{
		ans=ipt[1]*ipt[2]*ipt[3]*type[ipt[0]];
		ipt[1]=gcd(ipt[1],ipt[2]);
		ipt[1]=gcd(ipt[1],ipt[3]);
		cout<<ans*ipt[1]*ipt[1]*ipt[1]<<endl;
	}
	return 0;
}

