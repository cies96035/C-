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
int t(int n)
{
	if(n==0)return -1;
	int i=30;
	for(;n<two_power[i];i--);
	return i;
}

bool f(int n,int a,int ap,int b,int bp,int c,int cp)
//bool f(int n,int a,int b,int c)//stack overflow
{
	//cout<<n<<endl;
	bool k=0;
	if(n==0)
		return 1;
	if(n<0||(a==0&&b==0&&c==0))
		return 0;
	if(a>0)
	{
		for(int i=ap;i>=0;i++)
			k=k||f(n-power[0]*two_power[i],a-two_power[i],i-1,b,bp,c,cp);
	}
	if(b>0)
	{
		for(int i=bp;i>=0;i++)
			k=k||f(n-power[1]*two_power[i],a,ap,b-two_power[i],i-1,c,cp);
	}
	if(c>0)
	{
		for(int i=cp;i>=0;i++)
			k=k||f(n-power[2]*two_power[i],a,ap,b,bp,c-two_power[i],i-1);
	}
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
		if(f(num,amount[0],t(amount[0]),amount[1],t(amount[1]),amount[2],t(amount[2])))
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}

