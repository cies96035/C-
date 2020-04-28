#include<iostream>
#include<map> 
using namespace std;

int num,power[3],amount[3],sum;
int two_power[31];
void Init()
{
	two_power[0]=1;
	for(int i=0;i<30;i++)
		two_power[i+1]=two_power[i]*2;
	return ;
}
bool f(int n,int a,int ap,int b,int bp,int c,int cp)//stack overflow
{
	bool k=0;
	if(n==0)
		return 1;
	if(n<0||(a==0&&b==0&&c==0))
		return 0;
	if(a>0)
		k=k||f(n-power[0],a-1,b,c);
	if(b>0)
		k=k||f(n-power[1],a,b-1,c);
	if(c>0)
		k=k||f(n-power[2],a,b,c-1);
	return k;
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		cin>>num;
		for(int i=0;i<3;i++)
		{
			cin>>amount[i];
			sum+=amount[i];
		}
		for(int i=0;i<3;i++)
			cin>>power[i];
		if(sum>30000)
		if(f(num,amount[0],amount[1],amount[2]))
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}

