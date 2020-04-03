#include<iostream>
using namespace std;

const int maxX=32768;

int prime[32768]={1,1};

//快速冪
inline int Pow(int x,int n)
{
	int ans=1;
	while(n)
	{
		if(n%2)
		ans*=x;
		x*=x;
		n/=2;
	}
	return ans;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	//質數表
	for(int i=2;i<maxX;i++)
		if(!prime[i])
			for(int j=i;j<maxX;j+=i)
				prime[j]=i;
	char k;
	int sum=0,topow,num=1,tocount=1,temp;
	bool flag=1;
	
	while(cin.get(k))
	{
		if(!sum&&k=='0')return 0;
		if(k>='0'&&k<='9')
			sum=sum*10+k-'0';
		else if(k==' '||k=='\n')
		{
			if(flag)
				topow=sum;
			else 
			{
				num*=Pow(topow,sum);
				topow=0;
			}			
			
			sum=0;
			flag=!flag;
			
			if(k=='\n')
			{
				num--;
				temp=prime[num];
				do
				{
					num/=prime[num];
					if(temp!=prime[num])
					{
						cout<<temp<<' '<<tocount;
						if(prime[num]!=1)cout<<' ';
						else cout<<'\n';
						temp=prime[num];
						tocount=1;
					}
					else
						tocount++;
				}while(prime[num]!=1);
				tocount=1;
				num=1;
			}
		}
	}
	return 0;
}

