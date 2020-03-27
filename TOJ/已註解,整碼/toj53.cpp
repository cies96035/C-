#include<iostream>
using namespace std;

#define mod 1000000007

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char k;
	int sum=0,num=0;
	//sum紀錄總和，num紀錄每個數字 
	bool foo=0;//記得判斷負數 
	//用字元判斷跟直接getline其實都可以 
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

