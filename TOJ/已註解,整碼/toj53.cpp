#include<iostream>
using namespace std;

#define mod 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char k;
	int sum=0,num=0;
	//sum�����`�M�Anum�����C�ӼƦr 
	bool foo=0;//�O�o�P�_�t�� 
	//�Φr���P�_�򪽱�getline��곣�i�H 
	while(cin.get(k))
	{
		if(k=='-')foo=1;
		else if(k>='0'&&k<='9')
		{
			num=num*10+k-'0';
		}
		else
		{
			if(foo)
				sum-=num;
			else
				sum+=num;
			sum%=mod;
			num=0;
			foo=0;
			if(k=='\n')
			{
				cout<<sum<<endl;
				sum=0;
			}
		}
		
	}
	return 0;
}

